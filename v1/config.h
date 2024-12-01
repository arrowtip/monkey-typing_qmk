#pragma once

// matrix size
#define MATRIX_ROWS 10
#define MATRIX_COLS 6
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS { D4, C6, D7, F4, F5, F6 }
#define MATRIX_COL_PINS_RIGHT { F6, F5, F4, D7, C6, D4 }
/*#define MATRIX_IO_DELAY 30*/
/*#define DEBOUNCE 5*/
/*#define USB_POLLING_INTERVAL_MS 10*/

#define USB_SUSPEND_WAKEUP_DELAY 0

#define WS2812_DI_PIN E6
#define WS2812_RGBW
#define RGBLED_NUM 6
#define RGBLED_SPLIT { 3, 3 }
#define RGBLIGHT_SPLIT




