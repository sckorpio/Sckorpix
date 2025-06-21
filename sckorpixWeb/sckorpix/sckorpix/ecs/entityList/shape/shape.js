import { Entity } from "../../entity/entity.js";
import { TransformComponent } from "../../componentList/transformComponent.js";
import { MeshComponent } from "../../componentList/meshComponent.js";

class Shape extends Entity{
    constructor(){
        super();
        this.uid = 0;
        this.transformComponent = null;
        this.meshComponent = null;
        this.addTransformComponent();
    }

    addTransformComponent(){
        this.transformComponent = new TransformComponent();
        this.components.push(this.transformComponent);
    }

    setPosition(position){
        this.transformComponent.setPosition(position);
    }

    setScale(scale){
        this.transformComponent.setScale(scale);
    }

    setRotation(rotation){
        this.transformComponent.setRotation(rotation);
    }

    setVisible(visible){
        this.meshComponent.setVisible(visible);
    }

    addMeshComponent() {
        this.meshComponent = new MeshComponent();
    }

    setTextureRepeat(repeatX,repeatY){
        this.meshComponent.setTextureRepeat(repeatX,repeatY);
    }

    setMaterial(material){
        this.meshComponent.renderComponent.setMaterial(material);
    }

}

export{
    Shape
}