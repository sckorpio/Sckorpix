import { Shape } from "./shape.js";

class Box extends Shape {
    /**
     * @param {Object} options - options for the box
     * @param {string} options.mode - Type of box ('basic' | 'colorFace' | 'colorVertex' | 'textureFace')
     * @param {Array<number>} [options.uvRange] - UV range [uMin, vMin, uMax, vMax] (required for 'textureFace' type)
     */
    constructor(options = { mode: 'basic' }) {
        super();
        this.mode = options.mode;
        this.uvRange = options.uvRange;
        this.addMeshComponent();
        this.setMeshComponentData();
    }

    setMeshComponentData(){
        switch (this.mode) {
            case 'basic': this.setBasicBoxMeshComponentData(); break;
            case 'colorFace': this.setColorFaceMeshComponentData(); break;
            case 'colorVertex': this.setColorVertexMeshComponentData(); break;
            case 'textureFace': this.setTextureFaceMeshComponentData(this.uvRange); break;
        }
    }

    setMode(mode){
        this.mode = mode;
        this.setMeshComponentData();
        this.meshComponent.loadGPUData();
    }

    setBasicBoxMeshComponentData(){
        this.meshComponent.layout = [
            { type: "float", count: 3, name: "vertPosition" }
        ];

        this.meshComponent.verticesData = [
            -0.5, -0.5, 0.5,
            0.5, -0.5, 0.5,
            0.5, 0.5, 0.5,
            -0.5, 0.5, 0.5,

            -0.5, -0.5, -0.5,
            0.5, -0.5, -0.5,
            0.5, 0.5, -0.5,
            -0.5, 0.5, -0.5
        ];

        this.meshComponent.indexData = this.getDefaultBoxIndices();
    }

    setColorFaceMeshComponentData(){
        this.meshComponent.layout = [
            { type: "float", count: 3, name: "vertPosition" },
            { type: "float", count: 3, name: "vertColor" }
        ];

        this.meshComponent.verticesData = 
        [
            -0.5, -0.5, -0.5,   1.0, 0.0, 0.0,
            0.5, -0.5, -0.5,    1.0, 0.0, 0.0,
            0.5,  0.5, -0.5,    1.0, 0.0, 0.0,
            0.5,  0.5, -0.5,    1.0, 0.0, 0.0,
            -0.5,  0.5, -0.5,   1.0, 0.0, 0.0,
            -0.5, -0.5, -0.5,   1.0, 0.0, 0.0,
    
            -0.5, -0.5,  0.5,   0.0, 1.0, 0.0,
            0.5, -0.5,  0.5,    0.0, 1.0, 0.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 0.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 0.0,
            -0.5,  0.5,  0.5,   0.0, 1.0, 0.0,
            -0.5, -0.5,  0.5,   0.0, 1.0, 0.0,
    
            -0.5,  0.5,  0.5,   0.0, 0.0, 1.0,
            -0.5,  0.5, -0.5,   0.0, 0.0, 1.0,
            -0.5, -0.5, -0.5,   0.0, 0.0, 1.0,
            -0.5, -0.5, -0.5,   0.0, 0.0, 1.0,
            -0.5, -0.5,  0.5,   0.0, 0.0, 1.0,
            -0.5,  0.5,  0.5,   0.0, 0.0, 1.0,
    
            0.5,  0.5,  0.5,    1.0, 1.0, 0.0,
            0.5,  0.5, -0.5,    1.0, 1.0, 0.0,
            0.5, -0.5, -0.5,    1.0, 1.0, 0.0,
            0.5, -0.5, -0.5,    1.0, 1.0, 0.0,
            0.5, -0.5,  0.5,    1.0, 1.0, 0.0,
            0.5,  0.5,  0.5,    1.0, 1.0, 0.0,
    
            -0.5, -0.5, -0.5,   1.0, 0.0, 1.0,
            0.5, -0.5, -0.5,    1.0, 0.0, 1.0,
            0.5, -0.5,  0.5,    1.0, 0.0, 1.0,
            0.5, -0.5,  0.5,    1.0, 0.0, 1.0,
            -0.5, -0.5,  0.5,   1.0, 0.0, 1.0,
            -0.5, -0.5, -0.5,   1.0, 0.0, 1.0,
    
            -0.5,  0.5, -0.5,   0.0, 1.0, 1.0,
            0.5,  0.5, -0.5,    0.0, 1.0, 1.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 1.0,
            0.5,  0.5,  0.5,    0.0, 1.0, 1.0,
            -0.5,  0.5,  0.5,   0.0, 1.0, 1.0,
            -0.5,  0.5, -0.5,   0.0, 1.0, 1.0
        ];
    }

    setColorVertexMeshComponentData(){
        this.meshComponent.layout = [
            { type: "float", count: 3, name: "vertPosition" },
            { type: "float", count: 3, name: "vertColor" }
        ];

        this.meshComponent.verticesData = [
            -0.5, -0.5, 0.5, 1.0, 0.0, 0.0,
            0.5, -0.5, 0.5, 0.0, 1.0, 0.0,
            0.5, 0.5, 0.5, 0.0, 0.0, 1.0,
            -0.5, 0.5, 0.5, 1.0, 1.0, 0.0,

            -0.5, -0.5, -0.5, 1.0, 0.0, 1.0,
            0.5, -0.5, -0.5, 0.0, 1.0, 1.0,
            0.5, 0.5, -0.5, 1.0, 0.5, 1.0,
            -0.5, 0.5, -0.5, 1.0, 1.0, 1.0
        ];

        this.meshComponent.indexData = this.getDefaultBoxIndices();
    }

    setTextureFaceMeshComponentData(uvRange){
        this.meshComponent.layout = [
            { type: "float", count: 3, name: "vertPosition" },
            { type: "float", count: 2, name: "vertUV" }
        ];

        let [uMin, vMin, uMax, vMax] = uvRange;

        this.meshComponent.verticesData = [
            // back
            -0.5, -0.5, -0.5, uMin, vMin,
            0.5, -0.5, -0.5, uMin, vMin,
            0.5, 0.5, -0.5, uMin, vMax,
            0.5, 0.5, -0.5, uMin, vMax,
            -0.5, 0.5, -0.5, uMax, vMax,
            -0.5, -0.5, -0.5, uMax, vMin,

            // front
            -0.5, -0.5, 0.5, uMin, vMin,
            0.5, -0.5, 0.5, uMax, vMin,
            0.5, 0.5, 0.5, uMax, vMax,
            0.5, 0.5, 0.5, uMax, vMax,
            -0.5, 0.5, 0.5, uMin, vMax,
            -0.5, -0.5, 0.5, uMin, vMin,

            // left
            -0.5, -0.5, -0.5, uMin, vMin,
            -0.5, -0.5, 0.5, uMax, vMin,
            -0.5, 0.5, 0.5, uMax, vMax,
            -0.5, 0.5, 0.5, uMax, vMax,
            -0.5, 0.5, -0.5, uMin, vMax,
            -0.5, -0.5, -0.5, uMin, vMin,

            // right
            0.5, -0.5, -0.5, uMax, vMin,
            0.5, -0.5, 0.5, uMin, vMin,
            0.5, 0.5, 0.5, uMin, vMax,
            0.5, 0.5, 0.5, uMin, vMax,
            0.5, 0.5, -0.5, uMax, vMax,
            0.5, -0.5, -0.5, uMax, vMin,

            // bottom
            -0.5, -0.5, -0.5, uMin, vMin,
            0.5, -0.5, -0.5, uMax, vMin,
            0.5, -0.5, 0.5, uMax, vMax,
            0.5, -0.5, 0.5, uMax, vMax,
            -0.5, -0.5, 0.5, uMin, vMax,
            -0.5, -0.5, -0.5, uMin, vMin,

            // top
            -0.5, 0.5, -0.5, uMin, vMax,
            0.5, 0.5, -0.5, uMax, vMax,
            0.5, 0.5, 0.5, uMax, vMin,
            0.5, 0.5, 0.5, uMax, vMin,
            -0.5, 0.5, 0.5, uMin, vMin,
            -0.5, 0.5, -0.5, uMin, vMax
        ];
    }

    getDefaultBoxIndices() {
        return [
            // Front face
            0, 1, 2,
            0, 2, 3,

            // Back face
            4, 5, 6,
            4, 6, 7,

            // Left face
            4, 0, 3,
            4, 3, 7,

            // Right face
            1, 5, 6,
            1, 6, 2,

            // Top face
            3, 2, 6,
            3, 6, 7,

            // Bottom face
            4, 5, 1,
            4, 1, 0
        ];
    }
}

export { Box };
