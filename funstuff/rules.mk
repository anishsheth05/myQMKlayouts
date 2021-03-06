SRC += muse.c

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = yes           # MIDI controls
AUDIO_ENABLE = yes          # Audio output on port C6
UNICODE_ENABLE = no         # Unicode, supporting everything up to 0xFFFF
UNICODEMAP_ENABLE = yes     # Uncode, except all characters are defined by a map, and the calling function calls the position of that map. however, all keycodes are supported, as long as in the table.
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
STENO_ENABLE = no					  # Enable TX Bolt protocol for Stenography, requires VIRTSER and may not work with mouse keys
KEY_LOCK_ENABLE = yes       # Enable key lock, which holds down the next key pressed until it is pressed again. (Only works with standard action keys and OSM keys)


                            # Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
