import { getTitleCanvas, getTitleContext } from "./utils.js";
class Title {
    constructor() {
        this.setEventlisteners();
    }

    setTitle() {
        const canvas = getTitleCanvas();
        const context = getTitleContext();
        context.clearRect(0, 0, canvas.width, canvas.height);

        context.font = '70px Arial';
        context.fillStyle = 'silver';
        context.textAlign = 'left';
        context.textBaseline = 'top';

        context.shadowColor = 'white';
        context.shadowBlur = 70;

        let titleString1 = "Sckor";
        context.fillText(titleString1, 10, 40);

        context.font = 'bold 70px Arial';
        context.fillStyle = 'cyan';
        context.textAlign = 'left';
        context.textBaseline = 'top';

        context.shadowColor = 'cyan';
        context.shadowBlur = 50;

        let titleString2 = "pix";
        context.fillText(titleString2, 190, 40);
    }

    setIconTitle() {
        const canvas = getTitleCanvas();
        const context = getTitleContext();
        context.clearRect(0, 0, canvas.width, canvas.height);
    
        // Load the image
        const img = new Image();
        img.src = "sckorpix/resources/textures/sckorpixIcon.png"; // Use correct path or URL
    
        img.onload = function () {
            // Draw the image first (before text if behind)
            context.drawImage(img, 5, 0, 80, 130);  // x, y, width, height
    
            context.font = '50px Arial';
            context.fillStyle = 'silver';
            context.textAlign = 'left';
            context.textBaseline = 'top';

            context.shadowColor = 'white';
            context.shadowBlur = 70;

            let titleString1 = "Sckor";
            context.fillText(titleString1, 80, 40);

            context.font = 'bold 50px Arial';
            context.fillStyle = 'cyan';
            context.textAlign = 'left';
            context.textBaseline = 'top';

            context.shadowColor = 'cyan';
            context.shadowBlur = 50;

            let titleString2 = "pix";
            context.fillText(titleString2, 210, 40);
        };
    }

    setTitle2() {
        const canvas = getTitleCanvas();
        const context = getTitleContext();
        context.clearRect(0, 0, canvas.width, canvas.height);

        context.font = '70px Arial';
        context.fillStyle = 'white';
        context.textAlign = 'left';
        context.textBaseline = 'top';

        context.shadowColor = 'black';
        context.shadowBlur = 100;
        context.shadowOffsetX = 0;
        context.shadowOffsetY = 0;

        let titleString1 = "Sckor";
        context.fillText(titleString1, 10, 40);

        context.font = 'bold 70px Arial';
        context.fillStyle = 'cyan';
        context.textAlign = 'left';
        context.textBaseline = 'top';

        context.shadowColor = 'white';
        context.shadowBlur = 60;
        context.shadowOffsetX = 30;
        context.shadowOffsetY = 0;

        context.fillStyle = 'red';
        context.fillText("p", 190, 40);
        context.fillStyle = 'green';
        context.fillText("i", 230, 40);
        context.fillStyle = 'blue';
        context.fillText("x", 250, 40);
    }

    setEventlisteners() {
        // For the Title
        document.addEventListener('DOMContentLoaded',()=>{
            this.setIconTitle();
        });
    }
}

// To show title
export const title = new Title();