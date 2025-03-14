import { getWebGLContext, getWebGLResourceID } from "../../canvas/utils.js";

class IndexBuffer {
    constructor() {
        this.uniqueID = getWebGLResourceID();
        this.indexBuffer;
        this.count = 0;
    }

    // Generates index buffer
    generate(data) {
        const gl = getWebGLContext();
        // index count
        this.count = data.length;
        // Create a new buffer
        this.indexBuffer = gl.createBuffer();
        // Bind the buffer
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
        // Provide the data to the buffer
        gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(data), gl.STATIC_DRAW);
    }

    // Binds
    bind() {
        //console.log("Bind() IB =",this.uniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
    }

    // unbinds
    unbind() {
        //console.log("UnBind() IB =",this.uniqueID);
        const gl = getWebGLContext();
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
    }
}

export {
    IndexBuffer
}