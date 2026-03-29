import libcamera
from picamera2 import Picamera2, Preview, controls
import time

picam2 = Picamera2()
camera_config = picam2.create_preview_configuration(main={"size": (1920, 1080)})
picam2.configure(camera_config)

picam2.start_preview()
time.sleep(2)
picam2.set_controls({
    "Denoise": "night",
    "ExposureTime": 16000,
    'AeEnable': True,
    'AeExposureMode': controls.AeExposureModeEnum.Normal,
    'AeConstraintMode': controls.AeConstraintModeEnum.Highlight
})
time.sleep(1)

stopped_gracefully = False
try:
    while True:
        time.sleep(0.001) # A small sleep to prevent a tight loop
except KeyboardInterrupt:
    picam2.stop_preview()
    picam2.stop()
    stopped_gracefully = True

if not stopped_gracefully:
    picam2.stop_preview()
    picam2.stop()