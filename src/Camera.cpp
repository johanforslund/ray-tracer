#include <iostream>
#include "Camera.hpp"
#include <math.h>

Camera::Camera() {
    eye1 = glm::vec3(-1,0,0);
    eye2 = glm::vec3(-2,0,0);

    farEye = false;

    cameraPlane[0] = glm::vec3(0, -1, -1);
    cameraPlane[1] = glm::vec3(0, 1, -1);
    cameraPlane[2] = glm::vec3(0, 1, 1);
    cameraPlane[3] = glm::vec3(0, -1, 1);

    for (int i=0; i<800; i++) {
        for (int j=0; j<800; j++) {
            pixels[i][j] = Pixel(Color(rand() % 255, rand() % 255, rand() % 255)); // Test pixels
        }
    }
}

Camera::~Camera() {

}

void Camera::render() {
    for (int i=0; i<800; i++) {
        for (int j=0; j<800; j++) {
            Ray* ray = new Ray(eye1, glm::vec3(0, i*0.0025-0.99875, j*0.0025-0.99875), nullptr, false, 1);
            pixels[i][j].ray = ray;
        }
    }
}

void Camera::createImage() {
    

    float maxValue = 0;
    // Find max in matrix
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {

            pixels[i][j].color.r = sqrt(pixels[i][j].color.r);
            pixels[i][j].color.g = sqrt(pixels[i][j].color.g);
            pixels[i][j].color.b = sqrt(pixels[i][j].color.b);
            
            if (pixels[i][j].color.r > maxValue) maxValue = pixels[i][j].color.r;
            if (pixels[i][j].color.g > maxValue) maxValue = pixels[i][j].color.g;
            if (pixels[i][j].color.b > maxValue) maxValue = pixels[i][j].color.b;
        }
    }

    std::cout << "MAXVALUE: " << maxValue << std::endl;

    FILE *fp = fopen("images/image.ppm", "wb"); /* b - binary mode */
    (void) fprintf(fp, "P6\n%d %d\n255\n", 800, 800);

    for (int j = 799; j >= 0; j--) {
        for (int i = 799; i >= 0; i-- ) {
            static unsigned char color[3];
            color[0] = (pixels[i][j].color.r * 255.99)/maxValue;  /* red */
            color[1] = (pixels[i][j].color.g * 255.99)/maxValue;  /* green */
            color[2] = (pixels[i][j].color.b * 255.99)/maxValue;  /* blue */
            (void) fwrite(color, 1, 3, fp);
        }
    }

    (void) fclose(fp);
}