const puppeteer = require('puppeteer');
const jimp = require('jimp');

const url = 'https://www.google.ch';
const path = {in: './tmp/image.png', out: './tmp/image.bmp'};
const dimensions = {width: 1872, height: 1404};

(async () => {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    await page.setViewport(dimensions);
    await page.goto(url);
    await render(page);
    await browser.close();
})();

async function render(page) {
    await page.screenshot({path: path.in});
    const image = await jimp.read(path.in);
    await image.grayscale();
    await image.scan(0, 0, dimensions.width, dimensions.height, function (x, y, i) {
        this.bitmap.data[i] = Math.floor(this.bitmap.data[i] / 16) * 16;
        this.bitmap.data[i + 1] = this.bitmap.data[i];
        this.bitmap.data[i + 2] = this.bitmap.data[i];
    });
    await image.writeAsync(path.out);
    return image;
}
