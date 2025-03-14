import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";

class VertexBuffer {
    constructor() {
        this.uniqueID = getWebGLResourceID();
        this.vertexBuffer;
    }

    // Generates vertex buffer
    generate(data) {
        const gl = getWebGLContext();
        // Create a new buffer
        this.vertexBuffer = gl.createBuffer();
        // Bind the buffer
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
        // Provide the data to the buffer
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(data), gl.STATIC_DRAW);
    }

    // Binds 
    bind() {
        //console.log("Bind() VB =",this.uniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
    }

    // unbinds
    unbind() {
        //console.log("Bind() VB =",this.uniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ARRAY_BUFFER, null);
    }
}

export {
    VertexBuffer
}