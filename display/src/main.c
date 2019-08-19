#include <stdio.h>
#include "it8951.h"

//const char* concat(const char* string, const char* appendix) {
//    char* extension;
//    extension = malloc(strlen(string)+1+4); /* make space for the new string (should check the return value ...) */
//    strcpy(extension, string); /* copy name into the new var */
//    strcat(extension, appendix); /* add the extension */
//    return extension;
//}

int main(int argc, char *argv[]) {

    const char* url = "https://pbs.twimg.com/media/CPsRqv0UwAE_Bzp?format=jpg&name=4096x4096";

    if (argc == 1) {
        url = argv[1];
    }

    //system(concat("chrome --headless --screenshot --window-size=1280,1696 ", url));

    if (IT8951_Init()) {
        printf("IT8951_Init error \n");
        return 1;
    }

    for (int i = 0; i < 1000; i++) {
        system("chromium-browser --disable-gpu --no-sandbox --headless --screenshot --window-size=1872,1404 https://donjon.bin.sh/fantasy/dungeon/labyrinth.cgi && wait");
        RENDER_THE_GOD_DAMN_PNG_SHINJI("screenshot.png");
    }

    IT8951_Cancel();

    //DASH_init();
    //DASH_clear(0xff);

    //DASH_flush();

    //load(argv[1]);
    //IT8951_BMP_Example(0, 0, );

    //DASH_destroy();
    return 0;
}