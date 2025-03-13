import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";
import { VertexBufferElement } from "./vertexBufferLayout.js";
class VertexArray {
    constructor() {
        this.m_UniqueID = getWebGLResourceID();
        this.m_VertexBuffer;
    }

    // Generates vertex array 
    generate() {
        const gl = getWebGLContext();
        // Create a new vertex array object
        this.m_VertexBuffer = gl.createVertexArray();
        // Bind the vertex array 
        gl.bindVertexArray(this.m_VertexBuffer);
    }

    // Adds a vertex buffer and its layout to the vertex array
    addBuffer(vb, layout) {
        const gl = getWebGLContext();
        // Bind the vertex buffer
        vb.bind();

        // Get the layout elements
        const elements = layout.getElements();
        let offset = 0;

        elements.forEach((element, i) => {
            gl.vertexAttribPointer(
                i,                      // attrib location
                element.m_Count,          // count of elements
                element.m_Type,           // type of element
                element.m_Normalized,     // normalise?
                layout.getStride(),     // stride
                offset                  // offset
            );

            //enable
            gl.enableVertexAttribArray(i);

            // Update the offset for the next attribute
            offset += element.count * VertexBufferElement.getSizeOfType(element.m_Type);
        });
    }

    // Binds
    bind() {
        //console.log("Bind() VA =",this.m_UniqueID);
        const gl = getWebGLContext();
        gl.bindVertexArray(this.m_VertexBuffer);
    }

    // unbinds
    unbind() {
        //console.log("Bind() VA =",this.m_UniqueID);
        const gl = getWebGLContext();
        gl.bindVertexArray(null);
    }
}

export {
    VertexArray
}

