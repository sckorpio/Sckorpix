import { Box } from "../ecs/entityList/shape/box.js";
import { Camera } from "../ecs/entityList/camera/camera.js";
import { Grid } from "../ecs/entityList/shape/grid.js";
import { Renderer } from "../ecs/system/renderer.js";
import { Material } from "../webgl/material/material.js";
import { ShaderBook } from "../webgl/shader/shaderBook.js";
import { MaterialBook } from "../webgl/material/materialBook.js";
import { TextureBook } from "../webgl/texture/textureBook.js";

class Scene {
    constructor(){
        this.uid = 0;
        this.renderer;
        this.camera;
        this.defaultEntitiesList = [];
        this.entitiesList = [];

        this.shaderBook;
        this.materialBook;

        this.grid;
        this.xAxis;
        this.yAxis;
        this.zAxis;
        this.isGridVisible = true;
        this.isAxisVisible = true;
    }

    async init(){
        /*
        RENDERER
        */
        this.renderer = new Renderer();

        /*
        CAMERA
        */
        this.camera = new Camera();
        this.renderer.setCamera(this.camera);

        /*
        SHADER_BOOK
        */
        this.shaderBook = ShaderBook.getInstance();
        await this.shaderBook.generateDefaultShaders();

        /*
        TEXTURE_BOOK
        */
        this.textureBook = TextureBook.getInstance();
        await this.textureBook.generateDefaultTextures();

        /*
        MATERIAL_BOOK
        */
        this.materialBook = MaterialBook.getInstance();
        this.materialBook.generateDefaultMaterials();
    
        /*
        ENTITIES
        */
        this.createDefaultEntities();

        /*
        EVENT_LISTENERS
        */
        this.setEventlisteners();
    }

    setEventlisteners() {
        // Add event listeners for keyboard
        window.addEventListener('keydown', (event) => {
          if (event.key === "G" || event.key === "g") {
            this.isGridVisible = !this.isGridVisible;
            this.setGridVisibility(this.isGridVisible);
          } else if (event.key === "Y" || event.key === "y") {
            this.isAxisVisible = !this.isAxisVisible;
            this.setAxisVisibility(this.isAxisVisible);
          }
        });
    }

    createDefaultEntities(){
        //Grid
        this.grid = new Grid(100,1.0);
        this.grid.setMaterial("basicGrey");

        //x-Axis
        this.xAxis = new Box();
        this.xAxis.setPosition(vec3.fromValues(50.0, 0.0, 0.0));
        this.xAxis.setScale(vec3.fromValues(100.0, 0.02, 0.02));
        this.xAxis.setMaterial("basicRed");

        //y-Axis
        this.yAxis = new Box();
        this.yAxis.setPosition(vec3.fromValues(0.0, 50.0, 0.0));
        this.yAxis.setScale(vec3.fromValues(0.02, 100.0, 0.02));
        this.yAxis.setMaterial("basicGreen");

        //z-Axis
        this.zAxis = new Box();
        this.zAxis.setPosition(vec3.fromValues(0.0, 0.0, 50.0));
        this.zAxis.setScale(vec3.fromValues(0.02, 0.02, 100.0));
        this.zAxis.setMaterial("basicBlue");

        //add meshes to default list
        this.defaultEntitiesList.push(this.grid);
        this.defaultEntitiesList.push(this.xAxis);
        this.defaultEntitiesList.push(this.yAxis);
        this.defaultEntitiesList.push(this.zAxis);
    }

    setGridVisibility(isVisible){
        this.grid.setVisible(isVisible);
    }

    setAxisVisibility(isVisible){
        this.xAxis.setVisible(isVisible);
        this.yAxis.setVisible(isVisible);
        this.zAxis.setVisible(isVisible);
    }

    load(){
        // load systems with entities according to components
        this.addEntitiesToRenderer();
    }

    addEntitiesToRenderer(){
        //Add Meshes to list'
        this.renderer.addEntityList(this.defaultEntitiesList);
        this.renderer.addEntityList(this.entitiesList);
        // load Data of entities from CPU to GPU
        this.renderer.loadEntityDataToGPU();
    }

    play(){
        /*
        RENDERER render()
        */
        this.renderer.render();


        //loop
        requestAnimationFrame(this.play.bind(this));
    }
}

export{
    Scene
}