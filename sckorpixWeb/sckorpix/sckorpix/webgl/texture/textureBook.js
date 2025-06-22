import { Texture } from "./texture.js";

class TextureBook {
    constructor() {
        if (TextureBook._instance) {
            return TextureBook._instance;
        }

        this.defaultTextures = new Map();
        this.defaultTexturesName = [
            "wood",
            "brick"
        ];

        TextureBook._instance = this;
    }

    static getInstance() {
        if (!TextureBook._instance) {
            TextureBook._instance = new TextureBook();
        }
        return TextureBook._instance;
    }

    async generateDefaultTextures() {
        for (const textureName of this.defaultTexturesName) {
            //Using Texture class
            let texture = new Texture();
            await texture.generate(textureName);
            this.defaultTextures.set(textureName,texture);
        }
    }

    getTexture(textureName) {
        return this.defaultTextures.get(textureName) || null;
    }
}

export { TextureBook };