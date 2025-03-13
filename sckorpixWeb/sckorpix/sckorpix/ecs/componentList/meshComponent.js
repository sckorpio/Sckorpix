import { Component } from "../component/component.js";
import { RenderComponent } from "./renderComponent.js";

class MeshComponent extends Component{
    constructor() {
        super();
        this.visible = true;
        this.verticesData = [];
        this.indexData = [];
        this.material;
        this.renderComponent = new RenderComponent();
    }

    setVisible(visible = true){
        this.visible = visible;
    }

    isVisible(){
        return this.visible;
    }

    setMaterial(material){
        this.material = material;
        this.renderComponent.setMaterial(this.material);
    }

    getMaterial(material){
        this.material = material;
    }
}

export {
    MeshComponent
}