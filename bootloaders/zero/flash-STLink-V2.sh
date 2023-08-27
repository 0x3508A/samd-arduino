#!/bin/bash
HEXFILE='samd21_sam_ba.hex'
openocd -d2 -s /usr/share/openocd/scripts/ -f interface/stlink-v2.cfg -f atsamd21g18.cfg -c "telnet_port disabled; init; reset init;at91samd chip-erase; load_image ${HEXFILE} 0 ihex;at91samd bootloader 8192;verify_image ${HEXFILE} 0 ihex; shutdown"
