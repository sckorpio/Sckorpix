import { Component } from "../component/component.js";
import { RenderComponent } from "./renderComponent.js";

class MeshComponent extends Component{
    constructor() {
        super();
        this.visible = true;
        this.layout;
        this.verticesData = [];
        this.indexData = [];
        this.textureUV = [0.0, 0.0, 1.0, 1.0];
        this.material;
        this.renderComponent = new RenderComponent();
    }

    setVisible(visible = true){
        this.visible = visible;
    }

    isVisible(){
        return this.visible;
    }

    setVerticesData(verticesData){
        this.verticesData = verticesData;
    }

    setIndexData(indexData){
        this.indexData = indexData;
    }

    setLayout(layout){
        this.layout = layout;
    }

    setTextureRepeat(repeatX,repeatY){
        this.textureUV = [0.0,0.0,repeatX,repeatY];
    }

    setMaterial(material){
        this.material = material;
        this.renderComponent.setMaterial(this.material);
    }

    getMaterial(material){
        this.material = material;
    }

    getTextureUV(){
        return this.textureUV;
    }

    loadGPUData(){
        this.renderComponent.setData(this.layout,this.verticesData,this.indexData);
    }
}

export {
    MeshComponent
}