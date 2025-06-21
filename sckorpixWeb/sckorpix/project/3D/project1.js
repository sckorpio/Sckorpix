import { Box } from "../../sckorpix/ecs/entityList/shape/box.js";
import { Sphere } from "../../sckorpix/ecs/entityList/shape/sphere.js";
import { Scene } from "../../sckorpix/scene/scene.js";
import { Material } from "../../sckorpix/webgl/material/material.js";
import { Texture } from "../../sckorpix/webgl/texture/texture.js";

class Project1 extends Scene{
    constructor() {
        super();
    }

    async createScene(){
        /*
        MATERIALS
        */
        const materialColorVertex = new Material("colorVertex3D")
        await materialColorVertex.setShader("colorVertex3D");

        const materialUVVertex = new Material("uvVertex3D")
        await materialUVVertex.setShader("uvVertex3D");

        const materialWood = new Material("wood");
        await materialWood.setShader("textureVertex3D");
        await materialWood.setTexture("wood","REPEAT","REPEAT");
        
    
        /*
        MESHES
        */
        
        // Basic box
        let basicBox = new Box({ mode: 'basic' });
        basicBox.setPosition(vec3.fromValues(0.0,0.0,0.0));
        basicBox.setMaterial(this.materialRed);
        this.entitiesList.push(basicBox);

        // Box with face colors
        let colorFaceBox = new Box({ mode: 'colorFace' });
        colorFaceBox.setPosition(vec3.fromValues(2.0,0.0,0.0))
        colorFaceBox.setMaterial(materialColorVertex);
        this.entitiesList.push(colorFaceBox);

        // Box with vertex colors
        let colorVertexBox = new Box({ mode: 'colorVertex' });
        colorVertexBox.setPosition(vec3.fromValues(4.0,0.0,0.0));
        colorVertexBox.setMaterial(materialColorVertex);
        this.entitiesList.push(colorVertexBox);

        // Box with UVs
        let textureFaceBox = new Box({mode: 'textureFace', uvRange: [0, 0, 1, 1]});
        textureFaceBox.setPosition(vec3.fromValues(6.0,0.0,0.0));
        textureFaceBox.setMaterial(materialUVVertex);
        this.entitiesList.push(textureFaceBox);

        let textureFaceBox2 = new Box({mode: 'textureFace', uvRange: [0, 0, 1, 1]});
        textureFaceBox2.setPosition(vec3.fromValues(8.0,0.0,0.0));
        textureFaceBox2.setMaterial(materialWood);
        this.entitiesList.push(textureFaceBox2);

        let textureFaceBox3 = new Box({mode: 'textureFace', uvRange: [0, 0, 2, 2]});
        textureFaceBox3.setPosition(vec3.fromValues(10.0,0.0,0.0));
        textureFaceBox3.setScale(vec3.fromValues(2.0,2.0,2.0));
        textureFaceBox3.setMaterial(materialWood);
        this.entitiesList.push(textureFaceBox3);

        //textureFaceBox3.setMode('colorVertex');

        let sphere = new Sphere(0.5);
        sphere.setPosition(vec3.fromValues(0.0,0.0,2.0));
        sphere.setMaterial(this.materialGreen);
        this.entitiesList.push(sphere);
    }
}

export{
    Project1
}