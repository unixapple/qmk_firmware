# 20260522

The previous firmware make the left half cannot enter DFU.

By reading the datasheet I force it enter to DFU by shortcut the
BOOT0 pin of WB32FQ95 to a 3.3V to force it enter DFU mode and
enable me to reinstall this new firmware.

Here it does:

1. change default layout to via
2. restore support for left half to enter DFU mode
3. increase the debounce time (5ms is okay to me) to solve the duplicate key issue(main reason i need do custome firmware)
4. also i remap the option in the right half to tilde key

Actually it's quite personal, the release is just for personal notes.

Hope it helps.


here are artifacts:

- the firmware with via enabled: leo_epomaker_split65_via.bin
- the via definition in v3 latest mode: epomaker_split65_via.json
  i use it to turn right cmd to a mute key:)
