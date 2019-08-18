#include "image.h"
#include "it8951.h"
#include <math.h>

//extern IT8951Panel panel;
//extern uint8_t *frame_buffer;
extern IT8951DevInfo gstI80DevInfo;
extern uint8_t *gpFrameBuf; //Host Source Frame buffer

static void fatal_error(const char *message, ...) {
    va_list args;
    va_start (args, message);
    vfprintf(stderr, message, args);
    va_end (args);
    exit(EXIT_FAILURE);
}


void DASH_draw_png_image(const char *path) {
    png_structp png_ptr;
    png_infop info_ptr;
    FILE *fp;
    png_uint_32 width;
    png_uint_32 height;
    int bit_depth;
    int color_type;
    int interlace_method;
    int compression_method;
    int filter_method;
    png_bytepp rows;
    fp = fopen(path, "rb");
    if (!fp) {
        fatal_error("Cannot open '%s': %s\n", path, strerror(errno));
    }
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fatal_error("Cannot create PNG read structure");
    }
    info_ptr = png_create_info_struct(png_ptr);
    if (!png_ptr) {
        fatal_error("Cannot create PNG info structure");
    }
    png_init_io(png_ptr, fp);
    png_read_png(png_ptr, info_ptr, 0, 0);
    png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth,
                 &color_type, &interlace_method, &compression_method,
                 &filter_method);
    rows = png_get_rows(png_ptr, info_ptr);
    //int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

    for (int j = 0; j < height; j++) {
        png_bytep row;
        row = rows[j];
        for (int i = 0; i < width * 4; i++) {
            png_byte byte = (row[i] + row[i + 1] + row[i + 2]) / 3;
            byte = (png_byte) (floor(row[i] * 16) / 16);

        }
        printf("\n");
    }
}

void draw_image() {
    IT8951Image image_info;
    IT8951Area area;

    DASH_clear(0xff);


    DASH_wait();

    //Setting Load image information
    stLdImgInfo.ulStartFBAddr = (uint32_t) gpFrameBuf;
    stLdImgInfo.usEndianType = IT8951_LDIMG_L_ENDIAN;
    stLdImgInfo.usPixelFormat = IT8951_8BPP;
    stLdImgInfo.usRotate = IT8951_ROTATE_0;
    stLdImgInfo.ulImgBufBaseAddr = gulImgBufAddr;
    //Set Load Area
    stAreaImgInfo.usX = 0;
    stAreaImgInfo.usY = 0;
    stAreaImgInfo.usWidth = gstI80DevInfo.usPanelW;
    stAreaImgInfo.usHeight = gstI80DevInfo.usPanelH;

    //Load Image from Host to IT8951 Image Buffer
    IT8951HostAreaPackedPixelWrite(&stLdImgInfo, &stAreaImgInfo);//Display function 2
    //Display Area ?V (x,y,w,h) with mode 2 for fast gray clear mode - depends on current waveform
    IT8951DisplayArea(0, 0, gstI80DevInfo.usPanelW, gstI80DevInfo.usPanelH, 2);
}
/*
void DASH_clear(uint8_t color) {
    memset(gpFrameBuf, color, panel.width * panel.height);
}

void DASH_draw_pixel(int x, int y, uint8_t color) {
    if (x < 0 && x >= panel.width && y < 0 && y >= panel.height) {
        frame_buffer[y * panel.width + x] = color;
    }
}

void DASH_wait() {
    //Check IT8951 Register LUTAFSR => NonZero Busy, 0 - Free
    while (DASH_read_register(LUTAFSR));
}

uint16_t DASH_read_register(uint16_t address) {
    uint16_t usData;

    //Send Cmd and Register Address
    LCDWriteCmdCode(IT8951_TCON_REG_RD);
    LCDWriteData(address);
    //Read data from Host Data bus
    usData = LCDReadData();
    return usData;
}
*/
