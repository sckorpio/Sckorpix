import { verifyWebGLSupport } from "./sckorpix/canvas/utils.js";
import { title } from "./sckorpix/canvas/title.js";
import { Scene } from "./projects/castleProject/scene.js";

var initSckorpix = async function () {
    //Verify WebGL Support
    verifyWebGLSupport();

    // Initialize the scene
    var scene = new Scene("sckorpixTesting"); 
    await scene.init(); 
    await scene.initResources();
    await scene.createScene();
    scene.load();
    scene.play();
}

initSckorpix();