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

const const char* configFile = "config.txt";

int main() {
    // read width, height, framerate, shutter speed, gain, denoise level, awbgains, metering mode, ev from config file
    int width, height, framerate, shutter, gain;
    std::string denoise, awbgains, metering;
    double ev;
    std::ifstream config(configFile);
    if (config.is_open()) {
        config >> width >> height >> framerate >> shutter >> gain >> denoise >> awbgains >> metering >> ev;
        config.close();
    } else {
        std::cerr << "Unable to open config file" << std::endl;
        return 1;
    }

    std::string command = "rpicam-vid --width " + std::to_string(width) + " --height " + std::to_string(height) + " --framerate " + std::to_string(framerate) + " --shutter " + std::to_string(shutter) + " --gain " + std::to_string(gain) + " --denoise " + denoise + " --awbgains " + awbgains + " --metering " + metering + " --ev " + std::to_string(ev) + " -t 0 ";
    system(command.c_str());
    return 0;
}