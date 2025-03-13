import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";

class VertexBuffer {
    constructor() {
        this.m_UniqueID = getWebGLResourceID();
        this.m_VertexBuffer;
    }

    // Generates vertex buffer
    generate(data) {
        const gl = getWebGLContext();
        // Create a new buffer
        this.m_VertexBuffer = gl.createBuffer();
        // Bind the buffer
        gl.bindBuffer(gl.ARRAY_BUFFER, this.m_VertexBuffer);
        // Provide the data to the buffer
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(data), gl.STATIC_DRAW);
    }

    // Binds 
    bind() {
        //console.log("Bind() VB =",this.m_UniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.m_VertexBuffer);
    }

    // unbinds
    unbind() {
        //console.log("Bind() VB =",this.m_UniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ARRAY_BUFFER, null);
    }
}

export {
    VertexBuffer
}