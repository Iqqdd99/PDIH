#include "PDIH.h"

enum layer_names {
	_BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_ESC, KC_SLSH, KC_ASTR, KC_MINS, 
		KC_7, KC_8, KC_9, KC_PLUS, 
		KC_4, KC_5, KC_6, 
		KC_1, KC_2, KC_3, 
		KC_0, KC_DOT, KC_ENT
	)
};