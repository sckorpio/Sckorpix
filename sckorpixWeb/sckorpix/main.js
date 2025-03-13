
import { EmptyScene } from "./project/basic/emptyProject.js";
import { verifyWebGLSupport } from "./sckorpix/canvas/utils.js";
import { title } from "./sckorpix/canvas/title.js";
import { Project1 } from "./project/3D/project1.js";

var initSckorpix = async function () {
    //Verify WebGL Support
    verifyWebGLSupport();

    // Initialize the scene
    var scene = new Project1(); 
    await scene.init(); 
    await scene.createScene();
    scene.finish();
    scene.play();
}

initSckorpix();