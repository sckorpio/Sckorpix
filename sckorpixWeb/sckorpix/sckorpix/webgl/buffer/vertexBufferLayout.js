class VertexBufferElement {
    constructor(type, count, normalized) {  
      this.m_Type = type;
      this.m_Count = count;
      this.m_Normalized = normalized;
    }
  
    static getSizeOfType(type) {
      switch (type) {
        case WebGLRenderingContext.FLOAT:
          return 4;
        case WebGLRenderingContext.UNSIGNED_INT:
          return 4;
        case WebGLRenderingContext.UNSIGNED_BYTE:
          return 1;
        default:
          console.error("Unsupported type:", type);
          return 0;
      }
    }
  }
  
  class VertexBufferLayout {
    constructor() {
      this.m_Stride = 0; // Stride
      this.m_Elements = []; // vertex buffer elements
    }
  
    // get the elements of the layout
    getElements() {
      return this.m_Elements;
    }
  
    // get the stride 
    getStride() {
      return this.m_Stride;
    }
  
    // push elements(float) in layout
    pushFloat(count) {
        this.m_Elements.push(new VertexBufferElement(WebGLRenderingContext.FLOAT, count, WebGLRenderingContext.FALSE));
        this.m_Stride += VertexBufferElement.getSizeOfType(WebGLRenderingContext.FLOAT) * count;
    }

    // push elements(int) in layout
    pushUnsignedInt(count) {
        this.m_Elements.push(new VertexBufferElement(WebGLRenderingContext.UNSIGNED_INT, count, WebGLRenderingContext.FALSE));
        this.m_Stride += VertexBufferElement.getSizeOfType(WebGLRenderingContext.UNSIGNED_INT) * count;
    }

    // push elements(byte) in layout
    pushUnsignedByte(count) {
        this.m_Elements.push(new VertexBufferElement(WebGLRenderingContext.UNSIGNED_BYTE, count, WebGLRenderingContext.TRUE));
        this.m_Stride += VertexBufferElement.getSizeOfType(WebGLRenderingContext.UNSIGNED_BYTE) * count;
    }
  }

  export{
    VertexBufferElement,
    VertexBufferLayout
  }
