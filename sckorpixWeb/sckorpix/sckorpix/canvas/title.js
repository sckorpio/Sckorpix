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
            this.setTitle();
        });
    }
}

// To show title
export const title = new Title();