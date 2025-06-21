import { getWebGLResourceID } from "../../canvas/utils.js";
import { Shader } from "../shader/shader.js";
import { Texture } from "../texture/texture.js";

class Material{
    constructor(name = "basic3D") {
        this.uniqueID = getWebGLResourceID();
        this.name = name;
        this.shader;
        this.texture;
    }

    async setShader(shaderName = "basic3D"){
        //Using shader class
        this.shader = new Shader();
        await this.shader.generate(shaderName);
    }

    setColor(r,g,b){
        //Set Color
        this.shader.setUniform3f("uColor",r,g,b);
    }

    async setTexture(
        textureName = "basicTexture",
        wrapX = "CLAMP_TO_EDGE",
        wrapY = "CLAMP_TO_EDGE"){
        //Using Texture class
        this.texture = new Texture();
        this.texture.setTextureWrapX(wrapX);
        this.texture.setTextureWrapY(wrapY);
        await this.texture.generate(textureName);
    }

    setTextureWrap(wrapX,wrapY){
        this.texture.setTextureWrapX(wrapX);
        this.texture.setTextureWrapY(wrapY);
    }

}

export{
    Material
}