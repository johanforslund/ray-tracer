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

void Camera::createImage() {
    double maxValue = 0;
    int image[800][800][3];
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {
            if (pixels[i][j].color.r > maxValue) maxValue = pixels[i][j].color.g;
            if (pixels[i][j].color.g > maxValue) maxValue = pixels[i][j].color.g;
            if (pixels[i][j].color.b > maxValue) maxValue = pixels[i][j].color.b;
        }
    }
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {
            image[i][j][0] = (pixels[i][j].color.r * 255.99)/maxValue;
            image[i][j][1] = (pixels[i][j].color.g * 255.99)/maxValue;
            image[i][j][2] = (pixels[i][j].color.b * 255.99)/maxValue;
        }
    }

    std::cout << image[0][0][0] << std::endl;
    std::cout << image[0][0][1] << std::endl;
    std::cout << image[0][0][2] << std::endl;

    // TODO: Write to file
}