import { Box, ColorFaceBox, ColorVertexBox } from "../../sckorpix/ecs/entityList/shape/box.js";
import { Scene } from "../../sckorpix/scene/scene.js";
import { Material } from "../../sckorpix/webgl/material/material.js";

class Project1 extends Scene{
    constructor() {
        super();
    }

    async createScene(){
        /*
        MATERIALS
        */
        const materialColorVertex = new Material()
        await materialColorVertex.setShader("colorVertex3D");

        /*
        MESHES
        */
        let boxRed = new Box();
        boxRed.setPosition(vec3.fromValues(2.0, 0.0, -1.0))
        boxRed.setMaterial(this.materialRed);

        
        let boxGreen = new Box();
        boxGreen.setPosition(vec3.fromValues(2.0, 0.0, 2.0))
        boxGreen.setMaterial(this.materialGreen);

        let boxBlue = new Box();
        boxBlue.setPosition(vec3.fromValues(2.0, 0.0, -3.0))
        boxBlue.setMaterial(this.materialBlue);


        let colorFaceBox = new ColorFaceBox();
        colorFaceBox.setMaterial(materialColorVertex);

        let colorVertexBox = new ColorVertexBox();
        colorVertexBox.setPosition(vec3.fromValues(-2.0, 0.0, -1.0));
        colorVertexBox.setScale(vec3.fromValues(2.0, 1.0, 1.0));
        colorVertexBox.setMaterial(materialColorVertex);

        this.entitiesList.push(boxRed);
        this.entitiesList.push(boxGreen);
        this.entitiesList.push(boxBlue);
        this.entitiesList.push(colorFaceBox);
        this.entitiesList.push(colorVertexBox);
    }
}

export{
    Project1
}