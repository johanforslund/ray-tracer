#include <iostream>
#include "Camera.hpp"
#include <math.h>

Camera::Camera() {
    for (int i=0; i<800; i++) {
        for (int j=0; j<800; j++) {
            pixels[i][j] = Pixel(ColorDbl(rand() % 255, rand() % 255, rand() % 255)); // Test pixels
        }
    }
}

Camera::~Camera() {

}

void Camera::render() {
    
}

void Camera::createImage() {
    double maxValue = 0;
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {
            if (pixels[i][j].color.r > maxValue) maxValue = pixels[i][j].color.r;
            if (pixels[i][j].color.g > maxValue) maxValue = pixels[i][j].color.g;
            if (pixels[i][j].color.b > maxValue) maxValue = pixels[i][j].color.b;
        }
    }

    FILE *fp = fopen("images/image.ppm", "wb"); /* b - binary mode */
    (void) fprintf(fp, "P6\n%d %d\n255\n", 800, 800);

    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {
            static unsigned char color[3];
            color[0] = (pixels[i][j].color.r * 255.99)/maxValue;  /* red */
            color[1] = (pixels[i][j].color.g * 255.99)/maxValue;  /* green */
            color[2] = (pixels[i][j].color.b * 255.99)/maxValue;  /* blue */
            (void) fwrite(color, 1, 3, fp);
        }
    }

    (void) fclose(fp);
}