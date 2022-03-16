# Makefile to who use Sudar's Arduino Makefile tool
# Sheck https://github.com/Sudar/Arduino-Makefile for more info

ARDUINO_DIR    = /usr/share/arduino
ARDUINO_PORT   = /dev/ttyACM0
MONITOR_PORT   = /dev/ttyACM0
USER_LIB_PATH  = /home/$(USER)/Arduino/libraries
ARDMK_VENDOR   = arduino
BOARD_TAG      = atmega328
BOARD_SUB      = atmega328

include /usr/share/arduino/Arduino.mk
