import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";

class IndexBuffer {
    constructor() {
        this.m_UniqueID = getWebGLResourceID();
        this.m_IndexBuffer;
        this.m_Count = 0;
    }

    // Generates index buffer
    generate(data) {
        const gl = getWebGLContext();
        // index count
        this.m_Count = data.length;
        // Create a new buffer
        this.m_IndexBuffer = gl.createBuffer();
        // Bind the buffer
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.m_IndexBuffer);
        // Provide the data to the buffer
        gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(data), gl.STATIC_DRAW);
    }

    // Binds
    bind() {
        //console.log("Bind() IB =",this.m_UniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.m_IndexBuffer);
    }

    // unbinds
    unbind() {
        //console.log("UnBind() IB =",this.m_UniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
    }
}

export {
    IndexBuffer
}