import { gl, getWebGLResourceID } from "../../canvas/utils.js";

class Texture {
  constructor() {
    this.uniqueID = getWebGLResourceID();
    this.textureName = '';
    this.textureFilePath = '';
    this.textureWrapX = "CLAMP_TO_EDGE";
    this.textureWrapY = "CLAMP_TO_EDGE";
    this.texture;
  }

  // Generate a Texture
  async generate(textureName) {
    //set texture name
    this.textureName = textureName;
    //set texture path
    this.textureFilePath = "sckorpix/resources/textures/" + textureName + ".png";
    //Create a texture
    this.texture = gl.createTexture();

    //load image
    var image = new Image();
    image.src = this.textureFilePath;
    image.addEventListener('load', ()=> {
        //copy loaded image to texture
        gl.bindTexture(gl.TEXTURE_2D,this.texture);
        gl.texImage2D(
            gl.TEXTURE_2D,
            0,              // mip level
            gl.RGBA,        // internal format
            gl.RGBA,        // format
            gl.UNSIGNED_BYTE, // type
            image
        );
        gl.generateMipmap(gl.TEXTURE_2D);
    });

    //Set Texture Wrap
    this.setTextureWrap();
  }

  generatePixelTexture(){
    //bind texture
    gl.bindTexture(gl.TEXTURE_2D, this.texture);

    //1x1 pixel as image for texture
    gl.texImage2D(
        gl.TEXTURE_2D,
        0,              // mip level
        gl.RGBA,        // internal format
        2,              // width
        2,              // height
        0,              // border (must be 0)
        gl.RGBA,        // format
        gl.UNSIGNED_BYTE, // type
        new Uint8Array([
            255, 0, 0, 255,     // red
            0, 255, 0, 255,     // green
            0, 0, 255, 255,     // blue
            255, 255, 0, 255    // yellow
        ])
    );

    //Set Texture Wrap
    this.setTextureWrap();
    
    //gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
    //gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
  }

  setTextureWrapX(wrapValueX = "CLAMP_TO_EDGE"){
    this.textureWrapX = wrapValueX;
  }

  setTextureWrapY(wrapValueY = "CLAMP_TO_EDGE"){
    this.textureWrapY = wrapValueY;
  }

  setTextureWrap(){
    switch(this.textureWrapX){
        case "REPEAT": gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT); break;
        case "CLAMP_TO_EDGE": gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE); break;
        case "CLAMP_TO_EDGE": gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.MIRRORED_REPEAT); break;
    }
    switch(this.textureWrapY){
        case "REPEAT": gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT); break;
        case "CLAMP_TO_EDGE": gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE); break;
        case "CLAMP_TO_EDGE": gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.MIRRORED_REPEAT); break;
    }
  }

  //bind texture
  bind(){
    //console.log("Bind() Shader =",this.uniqueID);
    gl.bindTexture(gl.TEXTURE_2D, this.texture);
  }

  //bind texture
  unbind(){
    //console.log("UnBind() Shader =",this.uniqueID);
    gl.bindTexture(gl.TEXTURE_2D, null);
  }
}

export {
  Texture
}