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

class IMX290Camera {
private: 
    std::unique_ptr<libcamera::CameraManager> cameraManager_;
    std::shared_ptr<libcamera::Camera> camera_;
public:
    IMX290Camera(std::string cameraId = "cam0") {
        cameraManager_ = std::make_unique<libcamera::CameraManager>();
        int result = cameraManager_->start();
        if (result != 0) {
            throw std::runtime_error("failed to start camera manager: " + std::to_string(result));
        }

        auto cameras = cameraManager_->cameras();
        if (cameras.empty()) {
            throw std::runtime_error("no cameras found");
        }

        camera_ = cameraManager_->get(cameraId);
        if (!camera_) {
            throw std::runtime_error("camera " + cameraId + " not found");
        }

        // attempt to acquire the camera
        result = camera_->acquire();
        if (result != 0) {
            throw std::runtime_error("failed to acquire camera: " + std::to_string(result));
        }
    }

    ~IMX290Camera() {
        if (cameraManager_) {
            cameraManager_->stop();
        }
    }
};

int main() {
    IMX290Camera camera("cam0");

    return 0;
}