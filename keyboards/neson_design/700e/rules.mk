# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes		# Enable keyboard RGB underglow
NO_USB_STARTUP_CHECK = yes

QUANTUM_LIB_SRC += drivers/led/issi/is31fl3731.c
WS2812_DRIVER_REQUIRED = yes
I2C_DRIVER_REQUIRED = yes
