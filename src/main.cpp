#include <libcamera/libcamera.h>
#include <libcamera/camera.h>
#include <libcamera/camera_manager.h>
#include <libcamera/framebuffer.h>
#include <libcamera/formats.h>
#include <libcamera/controls.h>
#include <libcamera/request.h>
#include <libcamera/stream.h>
#include <libcamera/transform.h>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

const int OLED_WIDTH = 1920;
const int OLED_HEIGHT = 1080;

int main() {
    std::string command = "rpicam-vid -t 0 --framerate 60 --width " + std::to_string(OLED_WIDTH) + " --height " + std::to_string(OLED_HEIGHT) + " --awbgains 0.1,1,0.1 --denoise auto";
    system(command.c_str());
    return 0;
}