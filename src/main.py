import libcamera
from picamera2 import Picamera2, Preview, controls
import time

picam2 = Picamera2()
picam2.video_configuration.main.size = (1920, 1080)
picam2.video_configuration.controls.FrameRate = 60
picam2.video_configuration.lores = {"size": (1920, 1080), "format": "YUV420"}
picam2.video_configuration.display = "lores"
picam2.configure("video")

picam2.start_preview(Preview.DRM, width=1920, height=1080)
picam2.start()
picam2.set_controls({
    "AnalogueGain": 30,
    "ExposureTime": 16600,
    "Sharpness": 1.0,
    "Brightness": 0.4,
    "Contrast": 1,
    "Saturation": 0,
    "ColourGains": (32.0, 32.0),
    "NoiseReductionMode": libcamera.controls.draft.NoiseReductionModeEnum.HighQuality,
    "HdrMode": libcamera.controls.draft.HdrModeEnum.SingleExposure,
    "AeMeteringMode": libcamera.controls.draft.AeMeteringModeEnum.Spot,
    "AeEnable": False,
    "AwbEnable": False
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