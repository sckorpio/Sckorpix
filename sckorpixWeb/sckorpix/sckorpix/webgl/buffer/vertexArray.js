import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";
import { VertexBufferElement } from "./vertexBufferLayout.js";
class VertexArray {
    constructor() {
        this.uniqueID = getWebGLResourceID();
        this.vertexArray;
    }

    // Generates vertex array 
    generate() {
        const gl = getWebGLContext();
        // Create a new vertex array object
        this.vertexArray = gl.createVertexArray();
        // Bind the vertex array 
        gl.bindVertexArray(this.vertexArray);
    }

    // Adds a vertex buffer and its layout to the vertex array
    addBuffer(vb, layout) {
        const gl = getWebGLContext();
        // Bind the vertex buffer
        vb.bind();

        // Get the layout elements
        const elements = layout.getElements();

        // offset
        let offset = 0;

        elements.forEach((element) => {
            gl.vertexAttribPointer(
                element.attribLocation,  // attrib location
                element.count,          // count of elements
                element.type,           // type of element
                element.normalized,     // normalise?
                layout.getStride(),     // stride
                offset                  // offset
            );

            //enable
            gl.enableVertexAttribArray(element.attribLocation);

            // Update the offset for the next attribute
            offset += element.count * VertexBufferElement.getSizeOfType(element.type);
        });
    }

    // Binds
    bind() {
        const gl = getWebGLContext();
        gl.bindVertexArray(this.vertexArray);
    }

    // unbinds
    unbind() {
        const gl = getWebGLContext();
        gl.bindVertexArray(null);
    }
}

export {
    VertexArray
}

