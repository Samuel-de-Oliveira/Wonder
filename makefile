# Makefile to who use sudar's Arduino makefile

ARDUINO_DIR = /usr/share/arduino
ARDUINO_PORT = /dev/ttyACM*

ARDMK_VENDOR = arduino
BOARD_TAG = uno
BOARD_SUB = atmega328

include /usr/share/arduino/Arduino.mk
