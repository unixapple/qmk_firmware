# EPOMAKER Split65

* Keyboard Maintainer: [EPOMAKER](https://github.com/Epomaker)
* Hardware Supported: EPOMAKER Split65
* Hardware Availability: EPOMAKER Split65

Make example for this keyboard (after setting up your build environment):

    make leo/epomaker_split65:via
        
Flashing example for this keyboard:

    make leo/epomaker_split65:via

To reset the board into bootloader mode, do one of the following:

* Left half: hold `Esc` while connecting USB.
* Left half: hold `Esc` for about 1.5 seconds while the firmware is running.
* Right half: use the hardware DFU procedure documented in `SPLIT65-BUILD-FLASH-GUIDE.md`.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: on the left half, hold `Esc` and plug in USB. This firmware maps Bootmagic to matrix `[1, 0]`.
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

