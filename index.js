const puppeteer = require('puppeteer');
const jimp = require('jimp');

const url = 'https://pbs.twimg.com/media/CPsRqv0UwAE_Bzp?format=jpg&name=4096x4096';
const path = {in: './tmp/image.png', out: './tmp/image.bmp'};
const dimensions = {width: 1872, height: 1404};
const timer = 1000;

(async () => {
    const browser = await puppeteer.launch({executablePath: '/usr/bin/chromium-browser'});
    const page = await browser.newPage();
    await page.setViewport(dimensions);
    await page.goto(url);
    await render(page);
    //await loop(() => render(page));
    await browser.close();
})();

async function render(page) {
    console.log('Start render');
    await page.screenshot({path: path.in});
    console.log('Screenshot taken');
    const image = await jimp.read(path.in);
    await image.scan(0, 0, dimensions.width, dimensions.height, function (x, y, i) {
        this.bitmap.data[i] = (this.bitmap.data[i] + this.bitmap.data[i + 1] + this.bitmap.data[i + 2]) / 3;
        this.bitmap.data[i] = Math.floor(this.bitmap.data[i] / 16) * 16;
        this.bitmap.data[i + 1] = this.bitmap.data[i];
        this.bitmap.data[i + 2] = this.bitmap.data[i];
    });
    await image.writeAsync(path.out);
    console.log('Finish render');
    return image;
}

async function loop(exec, interval) {
    return new Promise(() => interval = setInterval(exec, timer));
    // this.stop = new Promise(() => clearInterval(interval));
}
