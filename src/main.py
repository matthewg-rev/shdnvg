import libcamera
from picamera2 import Picamera2, Preview, controls
import time

picam2 = Picamera2()
camera_config = picam2.create_preview_configuration(main={"size": (1920, 1080)})
picam2.configure(camera_config)

picam2.start_preview(Preview.DRM, width=1920, height=1080)
picam2.start()
time.sleep(2)
picam2.set_controls({
    "ExposureTime": 16000,
    'AeEnable': True,
    'AeExposureMode': libcamera.controls.AeExposureModeEnum.Normal,
    'AeConstraintMode': libcamera.controls.AeConstraintModeEnum.Highlight,
    'NoiseReductionMode': libcamera.controls.draft.NoiseReductionModeEnum.HighQuality
})
time.sleep(1)

stopped_gracefully = False
try:
    while True:
        time.sleep(0.001) # A small sleep to prevent a tight loop
except KeyboardInterrupt:
    picam2.stop()
    picam2.stop_preview()
    stopped_gracefully = True

if not stopped_gracefully:
    picam2.stop()
    picam2.stop_preview()