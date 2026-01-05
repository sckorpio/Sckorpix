import { logger } from "../../canvas/logger.js";
import { gl } from "../../canvas/utils.js";

class Renderer {
    constructor() {
        this.uid = 0;
        this.cameraEntity;
        this.entityList = [];
        this.clearColor = vec3.fromValues(0.1, 0.1, 0.1);
    }

    setCamera(cameraEntity) {
        this.cameraEntity = cameraEntity;
    }

    init() {
        this.clear();
        this.enableDepthTest();
    }

    enableDepthTest() {
        gl.enable(gl.DEPTH_TEST);
    }

    clear() {
        gl.clearColor(this.clearColor[0], this.clearColor[1], this.clearColor[2], 1.0);
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    }

    setClearColor(color) {
        this.clearColor = color;
    }

    addEntity(entity) {
        this.entityList.push(entity);
    }

    addEntityList(entityList) {
        this.entityList = this.entityList.concat(entityList);
    }

    loadEntityDataToGPU() {
        this.entityList.forEach((entity)=>{
            entity.meshComponent.loadGPUData();
        })
    }

    render() {
        // Clear the canvas and enable WebGL states
        this.init();

        // Render each mesh from the mesh list
        this.entityList.forEach(async (entity) => {
            
            if(entity.meshComponent.isVisible()){
                //get renderComponent
                const renderComponent = entity.meshComponent.renderComponent;
                //bind
                renderComponent.bind();

                //MVP
                renderComponent.setMVP(
                    entity.transformComponent.getModelMatrix(),
                    this.cameraEntity.cameraComponent.getViewMatrix(),
                    this.cameraEntity.cameraComponent.getProjectionMatrix()
                );

                renderComponent.setColor();

                //DrawCall
                if(renderComponent.useElements){
                    gl.drawElements(
                        renderComponent.topology, 
                        renderComponent.count, 
                        renderComponent.indexType, 
                        renderComponent.offset
                    );
                } else{
                    gl.drawArrays(
                        renderComponent.topology, 
                        renderComponent.offset, 
                        renderComponent.count
                    );
                }
            }
        });

        // show logger
        logger.show();
    }
}

export { 
    Renderer 
};
