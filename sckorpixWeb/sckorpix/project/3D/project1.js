import { Box, BoxColorFace, BoxColorVertex, BoxUV } from "../../sckorpix/ecs/entityList/shape/box.js";
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
        const materialColorVertex = new Material("colorVertex3D")
        await materialColorVertex.setShader("colorVertex3D");

        const materialUVVertex = new Material("uvVertex3D")
        await materialUVVertex.setShader("uvVertex3D");

        /*
        MESHES
        */
        let boxRed = new Box();
        boxRed.setPosition(vec3.fromValues(0.0, 0.0, 0.0));
        boxRed.setMaterial(this.materialRed);
        this.entitiesList.push(boxRed);

        let colorFaceBox = new BoxColorFace();
        colorFaceBox.setPosition(vec3.fromValues(2.0,0.0,0.0))
        colorFaceBox.setMaterial(materialColorVertex);
        this.entitiesList.push(colorFaceBox);

        let colorVertexBox = new BoxColorVertex();
        colorVertexBox.setPosition(vec3.fromValues(4.0, 0.0, 0.0));
        colorVertexBox.setMaterial(materialColorVertex);
        this.entitiesList.push(colorVertexBox);

        let uvBox = new BoxUV();
        uvBox.setPosition(vec3.fromValues(6.0, 0.0, 0.0));
        uvBox.setMaterial(materialUVVertex);
        this.entitiesList.push(uvBox);
    }
}

export{
    Project1
}