import { Shader } from "../shader/shader.js";

class Material{
    constructor(name = "basic3D") {
        this.m_RendererID = null;
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

    setTexture(textureName){
        this.texture = textureName;
    }

}

export{
    Material
}