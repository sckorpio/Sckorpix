import { VertexArray } from "../../webgl/buffer/vertexArray.js";
import { VertexBuffer } from "../../webgl/buffer/vertexBuffer.js";
import { IndexBuffer } from "../../webgl/buffer/indexBuffer.js";
import { VertexBufferLayout } from "../../webgl/buffer/vertexBufferLayout.js";
import { getWebGLContext } from "../../canvas/utils.js";

class RenderComponent{
    constructor() {
        const gl = getWebGLContext();
        this.uid = 0;
        this.vertexArray;
        this.vertexBuffer;
        this.layout;
        this.indexBuffer;
        this.useElements = false;
        this.indexType = gl.UNSIGNED_SHORT;
        this.topology = gl.TRIANGLES;
        this.offset = 0;
        this.count;

        this.material;
        this.shader;
        this.texture;
    }

    setData(layoutData,verticesData,indexData){
        //GPU buffers creation
 
        //vertex array
        this.vertexArray = new VertexArray()
        this.vertexArray.generate();

        //vertex buffer
        this.vertexBuffer = new VertexBuffer();
        this.vertexBuffer.generate(verticesData);

        //Vertex Buffer layout
        this.layout = new VertexBufferLayout();
        let layoutSize = 0;
        let attribLocation;
        layoutData.forEach((layoutDataElement) => {
            //finding attrib location from attached shader
            attribLocation = this.shader.getAttribLocation(layoutDataElement.name);
        
            //creating layout
            if(layoutDataElement.type == "float"){
                this.layout.pushFloat(layoutDataElement.count,attribLocation);
            } else if(layoutDataElement.type == "int"){
                this.layout.pushInt(layoutDataElement.count,attribLocation);
            }
            layoutSize += layoutDataElement.count;
        });
        
        //add vertex buffer & layout to vertex Array
        //console.log("passing",this.shader);
        this.vertexArray.addBuffer(this.vertexBuffer,this.layout);

        //set count to vertices size
        this.count = verticesData.length/layoutSize;
    
        //index buffer
        if(indexData.length > 0){
            //will use elements
            this.useElements = true;

            //set count to indices size
            this.count = indexData.length;
            
            //index buffer
            this.indexBuffer = new IndexBuffer();
            this.indexBuffer.generate(indexData);
        }
    }

    setTopology(topology){
        const gl = getWebGLContext();
        //set topology
        if(topology == "triangles"){
            this.topology = gl.TRIANGLES;
        } else if(topology == "lines"){
            this.topology = gl.LINES;
        }
    }

    setMaterial(material){
        //set material
        this.material = material;
        this.shader = material.shader;
        this.texture = material.texture;
    }

    setMVP(model,view,projection){
        // set MVP
        this.shader.setUniformMat4f("uModel",model);
        this.shader.setUniformMat4f("uView",view);
        this.shader.setUniformMat4f("uProjection",projection);
    }

    bind(){
        //bind GPU buffers (NOTE:Keep order stict like this)
        this.vertexArray.bind();
        this.vertexBuffer.bind();
        if(this.useElements){
            this.indexBuffer.bind();
        }
        
        //bind shader
        this.shader.bind();
    }

    unbind(){
        //Unbind GPU buffers (NOTE:Keep order stict like this)
        this.vertexArray.unbind();
        this.vertexBuffer.unbind();
        if(this.useElements){
            this.indexBuffer.unbind();
        }

        //Unbind shader
        this.shader.unbind();
    }
}

export{
    RenderComponent
}