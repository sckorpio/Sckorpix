import { Box } from "../../sckorpix/ecs/entityList/shape/box.js";
import { Sphere } from "../../sckorpix/ecs/entityList/shape/sphere.js";
import { Scene } from "../../sckorpix/scene/scene.js";

class Project1 extends Scene{
    constructor() {
        super();
    }

    async createScene(){
        /*
        MESHES
        */
        
        // Basic box
        let basicBox = new Box({ mode: 'basic' });
        basicBox.setPosition(vec3.fromValues(0.0,0.0,0.0));
        basicBox.setMaterial("basicRed");
        this.entitiesList.push(basicBox);

        // Box with face colors
        let colorFaceBox = new Box({ mode: 'colorFace' });
        colorFaceBox.setPosition(vec3.fromValues(2.0,0.0,0.0))
        colorFaceBox.setMaterial("colorFace");
        this.entitiesList.push(colorFaceBox);

        // Box with vertex colors
        let colorVertexBox = new Box({ mode: 'colorVertex' });
        colorVertexBox.setPosition(vec3.fromValues(4.0,0.0,0.0));
        colorVertexBox.setMaterial("colorVertex");
        this.entitiesList.push(colorVertexBox);

        // Box with UVs
        let uvFaceBox = new Box({mode: 'textureFace'});
        uvFaceBox.setPosition(vec3.fromValues(6.0,0.0,0.0));
        uvFaceBox.setMaterial("uvVertex3D");
        this.entitiesList.push(uvFaceBox);

        // Textured Box
        let textureFaceBox = new Box({mode: 'textureFace'});
        textureFaceBox.setPosition(vec3.fromValues(8.0,0.0,0.0));
        textureFaceBox.setMaterial("wood");
        this.entitiesList.push(textureFaceBox);

        let textureFaceBox2 = new Box({mode: 'textureFace', uvRange: [0, 0, 2, 2]});
        textureFaceBox2.setPosition(vec3.fromValues(10.0,0.0,0.0));
        textureFaceBox2.setScale(vec3.fromValues(2.0,1.0,1.0));
        textureFaceBox2.setMaterial("brick");
        this.entitiesList.push(textureFaceBox2);

        // Sphere
        let sphere = new Sphere(0.5);
        sphere.setPosition(vec3.fromValues(-2.0,0.0,0.0));
        sphere.setMaterial("basicGreen");
        this.entitiesList.push(sphere);

        // uvFaceBox.setMaterial("colorFace");
        // uvFaceBox.setMode("colorFace");
        
    }
}

export{
    Project1
}