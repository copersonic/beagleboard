#!/bin/bash
opkg update
opkg install gcc
opkg install wpa-supplicant
opkg install wpa-gui
opkg install rt73-firmware
opkg install kernel-module-rt73usb
dhclient wlan0
ifup wlan0
