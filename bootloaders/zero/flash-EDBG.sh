#!/bin/bash

openocd -d2 -s /usr/share/openocd/scripts/ -f interface/cmsis-dap.cfg -f atsamd21g18.cfg -c "telnet_port disabled; init; halt; at91samd bootloader 0; program samd21_sam_ba.bin verify reset; shutdown"
