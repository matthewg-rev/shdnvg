#include <libcamera/libcamera.h>
#include <libcamera/camera.h>
#include <libcamera/camera_manager.h>
#include <libcamera/control_ids.h>
#include <libcamera/controls.h>
#include <libcamera/formats.h>
#include <libcamera/framebuffer.h>
#include <libcamera/request.h>
#include <libcamera/stream.h>
#include <libcamera/transform.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

const int OLED_WIDTH = 1920;
const int OLED_HEIGHT = 1080;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}