#include <stdio.h>
#include "it8951.h"

int main(int argc, char *argv[]) {
    printf("Draw to display\n");

    if (IT8951_Init()) {
        printf("IT8951_Init error \n");
        return 1;
    }

    if (argc != 4) {
        printf("Error: argc!=4.\n");
        exit(1);
    }

    IT8951_BMP_Example(0, 0, argv[1]);

    IT8951_Cancel();
    return 0;
}