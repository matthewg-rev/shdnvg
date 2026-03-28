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
    std::string command = "rpicam-vid --width 1920 --height 1080 --framerate 60 --shutter 16666 --gain 8 --denoise cdn_hq --awb auto --metering centre --ev 0.5 -t 0 ";
    system(command.c_str());
    return 0;
}