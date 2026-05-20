# EPOMAKER Split65 Build and Flash Notes

This document records how to build and flash the EPOMAKER Split65 firmware from this QMK fork on macOS.

## What Was Changed

The default keymap was changed so the right-side Option/Alt position sends the normal grave/backquote key:

- Base layer: `KC_RALT` was changed to `KC_GRV`.
- Mac base layer: `KC_RGUI` was changed to `KC_GRV`.

On a US/ANSI keyboard layout, `KC_GRV` outputs:

- `` ` `` when pressed normally
- `~` when pressed with Shift

An experimental right-half local bootloader shortcut was also added in `epomaker_split65.c`:

- Hold `Right Fn + R_Shift` for about 1.2 seconds.
- This is intended to make the right half jump to bootloader mode when it is running as the non-master half.
- This shortcut is optional and not required for flashing, because the hardware shorting method still works.

## Important Split Keyboard Rule

Flash both halves with the same firmware file.

The Split65 halves communicate with each other using split transport code. If only one half is flashed with this firmware and the other half is still running the original factory firmware, the right half may stop sending input or appear dead.

If the right half does not type after flashing, the first thing to check is whether the left half has also been flashed with the same `.bin`.

## macOS Build Setup

This fork is older than current upstream QMK and does not work cleanly with Python 3.14. Use Python 3.12 for QMK commands.

Install the required tools:

```sh
brew install uv
brew tap qmk/qmk
brew install osx-cross/arm/arm-none-eabi-gcc@8
```

Install this fork's Python requirements into your QMK Python environment if needed:

```sh
/Users/fortitude/.local/share/uv/tools/qmk/bin/python -m pip install -r /Users/fortitude/qmk_firmware_banroku/requirements.txt
```

Create a temporary QMK wrapper that runs QMK under Python 3.12:

```sh
mkdir -p /private/tmp/qmk12bin
cat > /private/tmp/qmk12bin/qmk <<'WRAPPER'
#!/bin/sh
exec uv run --python 3.12 --with qmk --with-requirements requirements.txt qmk "$@"
WRAPPER
chmod +x /private/tmp/qmk12bin/qmk
```

Build the firmware:

```sh
cd /Users/fortitude/qmk_firmware_banroku
env PATH=/private/tmp/qmk12bin:/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:/opt/homebrew/opt/arm-none-eabi-binutils/bin:/opt/homebrew/bin:/usr/bin:/bin:/usr/sbin:/sbin \
  make leo/epomaker_split65:default
```

The firmware output is copied to the QMK fork root:

```text
/Users/fortitude/qmk_firmware_banroku/leo_epomaker_split65_default.bin
```

There may also be build outputs under:

```text
/Users/fortitude/qmk_firmware_banroku/.build/
```

For flashing with QMK Toolbox, use the `.bin` file.

## Flashing With QMK Toolbox

Open QMK Toolbox and select:

```text
/Users/fortitude/qmk_firmware_banroku/leo_epomaker_split65_default.bin
```

When a half is in WB32 DFU mode, QMK Toolbox should show a device like:

```text
WB32 DFU device connected: Westberry Tech. WB Device in DFU Mode (342D:DFA0:0100)
```

Then click Flash.

A successful flash log should include:

```text
Writing ...
OK
Download completed!
Flash complete
```

## Flashing the Left Half

Use the normal bootloader method for the left half. The keyboard README lists these options:

- Hold the physical reset switch while connecting USB.
- Hold `Esc` while connecting USB.
- Use a bootloader keycode if one is available in the running firmware.

Flash the same `.bin` file:

```text
/Users/fortitude/qmk_firmware_banroku/leo_epomaker_split65_default.bin
```

## Flashing the Right Half

The right half must be flashed separately.

Hardware DFU procedure:

1. Disconnect the right half from USB.
2. Remove the `R_Shift` keycap.
3. Find the hidden toggle switch under `R_Shift`.
4. Toggle that switch to the other side for DFU mode.
5. Remove the right spacebar keycap.
6. Remove the right spacebar stabilizer assembly. Pull it toward your body side and the whole support assembly should come out.
7. Locate the two short rectangular gold pads under the right spacebar area.
8. Short those two rectangular gold pads with tweezers.
9. While keeping the pads shorted, plug the USB-C cable into the right half.
10. QMK Toolbox should detect a WB32 DFU device.
11. Flash the same `.bin` file.
12. After flashing, move the hidden switch under `R_Shift` back to the normal position.
13. Reinstall the stabilizer, switch, and keycaps.

Use the same firmware file as the left half:

```text
/Users/fortitude/qmk_firmware_banroku/leo_epomaker_split65_default.bin
```

## After Flashing

After both halves are flashed:

1. Disconnect power from both halves.
2. Reconnect the keyboard normally.
3. Confirm the right half sends input.
4. Confirm the former right Option/Alt key outputs `` ` ``.
5. Confirm `Shift` plus that key outputs `~`.

If the right half does not type:

- Confirm the hidden switch under `R_Shift` was returned to the normal position.
- Confirm both halves were flashed with the exact same `.bin`.
- Power-cycle both halves.
- If needed, put the right half back into DFU mode with the hardware shorting method and reflash it.


# prebuild firmware

./split65-firmwares/split65-firwarem-roptions-as-tilde-backquote-key.bin
