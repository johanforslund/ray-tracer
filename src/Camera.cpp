#include "Camera.hpp"

Camera::Camera() {

}

Camera::~Camera() {

}

void Camera::createImage() {
    double maxValue = 0;
    int image[800][800];
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {
            if (pixels[i][j].color.r > maxValue) maxValue = pixels[i][j].color.g;
            if (pixels[i][j].color.g > maxValue) maxValue = pixels[i][j].color.g;
            if (pixels[i][j].color.b > maxValue) maxValue = pixels[i][j].color.b;
        }
    }
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 800; j++ ) {
            image[i][j] = (pixels[i][j].color.r * 255.99)/maxValue;
            image[i][j] = (pixels[i][j].color.g * 255.99)/maxValue;
            image[i][j] = (pixels[i][j].color.b * 255.99)/maxValue;
        }
    }
    // TODO: Write to file
}