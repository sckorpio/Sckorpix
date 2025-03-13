import { Shape } from "./shape.js";
import { MeshComponent } from "../../componentList/meshComponent.js";

class Box extends Shape{
    constructor(){
        //constructor of Mesh Component
        super();

        //add Mesh Component
        this.addMeshComponent();
    }

    addMeshComponent(){
        this.meshComponent = new MeshComponent();

        //layout
        const layout = [{type:"float",count:3}];

        //vertices data
        this.meshComponent.verticesData = 
        [
            // Front face
            -0.5, -0.5, 0.5,    // Bottom-left
            0.5, -0.5, 0.5,     // Bottom-right
            0.5, 0.5, 0.5,      // Top-right
            -0.5, 0.5, 0.5,     // Top-left
    
            // Back face
            -0.5, -0.5, -0.5,   // Bottom-left
            0.5, -0.5, -0.5,    // Bottom-right
            0.5, 0.5, -0.5,     // Top-right
            -0.5, 0.5, -0.5,    // Top-left
        ];

        //indices data
        this.meshComponent.indexData = 
        [
            // Front face
            0, 1, 2,
            0, 2, 3,

            // Back face
            4, 5, 6,
            4, 6, 7,

            // Left face
            4, 0, 3,
            4, 3, 7,

            // Right face
            1, 5, 6,
            1, 6, 2,

            // Top face
            3, 2, 6,
            3, 6, 7,

            // Bottom face
            4, 5, 1,
            4, 1, 0
        ];

        //set data to renderComponent
        this.meshComponent.renderComponent.setData(
            layout,
            this.meshComponent.verticesData,
            this.meshComponent.indexData
        );
    }
}


class ColorFaceBox extends Shape{
    constructor(){
        //constructor of Mesh Component
        super();

        this.addMeshComponent();
    }

    addMeshComponent(){
        this.meshComponent = new MeshComponent();

        //layout
        const layout = [
            {type:"float",count:3},     //vertexPosition
            {type:"float",count:3}      //vertexColor
        ];

        //vertices data
        this.meshComponent.verticesData = 
        [
            -0.5, -0.5, -0.5,   1.0, 0.0, 0.0,
            0.5, -0.5, -0.5,    1.0, 0.0, 0.0,
            0.5,  0.5, -0.5,    1.0, 0.0, 0.0,
            0.5,  0.5, -0.5,    1.0, 0.0, 0.0,
            -0.5,  0.5, -0.5,   1.0, 0.0, 0.0,
            -0.5, -0.5, -0.5,   1.0, 0.0, 0.0,
    
            -0.5, -0.5,  0.5,   0.0, 1.0, 0.0,
            0.5, -0.5,  0.5,    0.0, 1.0, 0.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 0.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 0.0,
            -0.5,  0.5,  0.5,   0.0, 1.0, 0.0,
            -0.5, -0.5,  0.5,   0.0, 1.0, 0.0,
    
            -0.5,  0.5,  0.5,   0.0, 0.0, 1.0,
            -0.5,  0.5, -0.5,   0.0, 0.0, 1.0,
            -0.5, -0.5, -0.5,   0.0, 0.0, 1.0,
            -0.5, -0.5, -0.5,   0.0, 0.0, 1.0,
            -0.5, -0.5,  0.5,   0.0, 0.0, 1.0,
            -0.5,  0.5,  0.5,   0.0, 0.0, 1.0,
    
            0.5,  0.5,  0.5,    1.0, 1.0, 0.0,
            0.5,  0.5, -0.5,    1.0, 1.0, 0.0,
            0.5, -0.5, -0.5,    1.0, 1.0, 0.0,
            0.5, -0.5, -0.5,    1.0, 1.0, 0.0,
            0.5, -0.5,  0.5,    1.0, 1.0, 0.0,
            0.5,  0.5,  0.5,    1.0, 1.0, 0.0,
    
            -0.5, -0.5, -0.5,   1.0, 0.0, 1.0,
            0.5, -0.5, -0.5,    1.0, 0.0, 1.0,
            0.5, -0.5,  0.5,    1.0, 0.0, 1.0,
            0.5, -0.5,  0.5,    1.0, 0.0, 1.0,
            -0.5, -0.5,  0.5,   1.0, 0.0, 1.0,
            -0.5, -0.5, -0.5,   1.0, 0.0, 1.0,
    
            -0.5,  0.5, -0.5,   0.0, 1.0, 1.0,
            0.5,  0.5, -0.5,    0.0, 1.0, 1.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 1.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 1.0,
            -0.5,  0.5,  0.5,   0.0, 1.0, 1.0,
            -0.5,  0.5, -0.5,    0.0, 1.0, 1.0
        ];

    
        //set data to renderComponent
        this.meshComponent.renderComponent.setData(
            layout,
            this.meshComponent.verticesData
        );
    }
}

class ColorVertexBox extends Shape{
    constructor(){
        //constructor of Mesh Component
        super();

        this.addMeshComponent();
    }

    addMeshComponent(){
        this.meshComponent = new MeshComponent();

        //layout
        const layout = [
            {type:"float",count:3},     //vertexPosition
            {type:"float",count:3}      //vertexColor
        ];

        //vertices data
        this.meshComponent.verticesData =
        [
            // Front face 

            -0.5, -0.5, 0.5,   1.0, 0.0, 0.0, 
            // Bottom-left     //Red
            0.5, -0.5, 0.5,   0.0, 1.0, 0.0, 
            // Bottom-right     //Green
            0.5, 0.5, 0.5,   0.0, 0.0, 1.0, 
            // Top-right        //Blue
            -0.5, 0.5, 0.5,   1.0, 1.0, 0.0, 
            // Top-left         //Yellow

            // Back face

            -0.5, -0.5, -0.5,    1.0, 0.0, 1.0, 
            // Bottom-left      //magenta
            0.5, -0.5, -0.5,   0.0, 1.0, 1.0, 
            // Bottom-right     // Cyan
            0.5, 0.5, -0.5,   1.0, 0.5, 1.0, 
            // Top-right        //other
            -0.5, 0.5, -0.5,   0.3, 0.5, 1.0, 
            // Top-left         //other
        ];

        this.meshComponent.indexData =
        [
            // Front face
            0, 1, 2,
            0, 2, 3,

            // Back face
            4, 5, 6,
            4, 6, 7,

            // Left face
            4, 0, 3,
            4, 3, 7,

            // Right face
            1, 5, 6,
            1, 6, 2,

            // Top face
            3, 2, 6,
            3, 6, 7,

            // Bottom face
            4, 5, 1,
            4, 1, 0
        ];

        
        //set data to renderComponent
        this.meshComponent.renderComponent.setData(
            layout,
            this.meshComponent.verticesData,
            this.meshComponent.indexData
        );
    }
}

export{
    Box,
    ColorFaceBox,
    ColorVertexBox
}