/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define SPACE_FN LT(3, KC_SPC)

enum {
  TD_LSHIFT_CAPS = 0,
  TD_QUOT_F12
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LSHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_QUOT_F12]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_F12)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Layer 0
	 * ,-----------------------------------------------------------------------------------.
	 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  -   |Enter |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Ctrl |  GUI | Caps |  Alt |Layer1|    Space    |Layer2| Left |  Up  | Down |Right |
	 * `-----------------------------------------------------------------------------------'
	 */
    [0] = LAYOUT_preonic_1x2uC(
    KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_BSPC, \
		KC_AUDIO_MUTE,      KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC,
		KC_TAB,             KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, TD(TD_QUOT_F12),
	  TD(TD_LSHIFT_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
		KC_LCTL,            KC_LGUI, XXXXXXX, KC_LALT, MO(1),    SPACE_FN,    MO(2), KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT
    ),

	/* Layer 1
	 * ,-----------------------------------------------------------------------------------.
	 * |   ;  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Ins |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |  F11 |  F12 |      |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |      |      |      |      |      |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * | Reset|      |      |      |      |             |      | Home | PgUp | PgUp |  End |
	 * `-----------------------------------------------------------------------------------'
	 */
	[1] = LAYOUT_preonic_1x2uC(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_INS, \
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, _______,
		_______, _______, _______, _______, _______,     _______,      _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
	),

	/* Layer 2
	 * ,-----------------------------------------------------------------------------------.
	 * |   ;  |   +  |   ě  |   š  |   č  |   ř  |   ž  |   ý  |   á  |   í  |   é  | del  |
	 * |------+------+------+------+------+-------------+------+------+------+------+------|
	 * |      |   ~  |   /  |   [  |   (  |   {  |   }  |   )  |   ]  |   \  |   ú  |   =  |
	 * |------+------+------+------+------+------|------+------+------+------+------+------|
	 * |      |      |  #   |   &  |   @  |   <  |   >  |      |      |      |      |      |
	 * |------+------+------+------+------+------+------+------+------+------+------+------|
	 * |      |      |      |      |      |             |      | Home | PgUp | PgUp | End  |
	 * `-----------------------------------------------------------------------------------'
	 */
	[2] = LAYOUT_preonic_1x2uC(
        KC_GRV,  RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8),    RALT(KC_9),    RALT(KC_0), KC_DEL,
		_______, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8),    RALT(KC_9),    RALT(KC_0), KC_DEL,
		_______, RALT(KC_A), S(KC_LBRC), RALT(KC_F), XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_RBRC), RALT(KC_BSLS), KC_LBRC,    KC_MINUS,
		_______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RALT(KC_B), RALT(KC_N), XXXXXXX,    RALT(KC_COMM), RALT(KC_DOT),  XXXXXXX,    _______,
		_______, _______,    _______,    _______,    _______,           _______,         _______,    KC_HOME,       KC_PGUP,       KC_PGDN,    KC_END
    ),

    [3] = LAYOUT_preonic_1x2uC(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,      KC_F11,    KC_F12,  \
        KC_PSCR, XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   XXXXXXX,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,    XXXXXXX,   XXXXXXX,
        _______, RGB_TOG, RGB_M_P, RGB_HUI,  RGB_HUD, RGB_SAI, RGB_SAD, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,   _______,
        RESET,   _______, _______, XXXXXXX,  RGB_VAD,      _______,     RGB_VAI, KC__MUTE, KC__VOLDOWN, KC__VOLUP, XXXXXXX
    ),

    [4] = LAYOUT_preonic_1x2uC(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,  KC_F7,  KC_F8, KC_F9,   KC_F10,  KC_F11,  S(KC_EQUAL),  \
        KC_PSCR, KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    S(KC_EQUAL),
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
        KC_LCTL, KC_LGUI, KC_CAPS, KC_LALT, _______,      _______,     _______, _______, _______, _______, _______
    )
};

static bool is_layer_up_pressed = false;
static bool is_layer_down_pressed = false;
static bool layer4_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // if (keycode == KC_LSFT || keycode == KC_SFTENT) {
  //   is_shift_pressed = record->event.pressed;
  //   return true;
  // }

  if (keycode == MO(1))
  {is_layer_down_pressed = record->event.pressed;}

  if (keycode == MO(2))
    {is_layer_up_pressed = record->event.pressed;}

  if (is_layer_down_pressed && is_layer_up_pressed)
  {
    if (!layer4_on)
    {
      layer4_on = true;
      layer_move(4);
    }
  }
  else if (layer4_on)
  {
    layer4_on = false;
    layer_move(0);
  }

  //if (false && record->event.pressed)
  //{
  //  if (keyboard_report->mods & MOD_BIT(KC_LGUI))
  //    return true;

  //  switch (keycode)
  //  {
  //    case KC_0:
  //    case KC_1:
  //    case KC_2:
  //    case KC_3:
  //    case KC_4:
  //    case KC_5:
  //    case KC_6:
  //    case KC_7:
  //    case KC_8:
  //    case KC_9:
  //      if (!is_shift_pressed)
  //      {
  //        uint8_t shift_kc = KC_LSFT;
  //        if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
  //          shift_kc = KC_RSFT;
  //        }

  //        register_code (shift_kc);
  //        register_code (keycode);
  //        unregister_code (keycode);
  //        unregister_code (shift_kc);
  //        return false;
  //    }
  //    else
  //    {
  //        uint8_t shift_kc = KC_LSFT;
  //        if (keyboard_report->mods & MOD_BIT(KC_RSFT)) {
  //          shift_kc = KC_RSFT;
  //        }

  //        unregister_code (shift_kc);
  //        register_code (keycode);
  //        unregister_code (keycode);
  //        register_code (shift_kc);
  //        return false;
  //    }
  //    break;
  //  }
  //}

	return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC__VOLUP);
    } else {
      tap_code(KC__VOLDOWN);
    }
}

// void dip_switch_update_user(uint8_t index, bool active) {
   // switch (index) {
   //     case 0:
   //         if (active) {
   //             layer_on(_ADJUST);
   //         } else {
   //             layer_off(_ADJUST);
   //         }
   //         break;
   //     case 1:
   //         if (active) {
   //             muse_mode = true;
   //         } else {
   //             muse_mode = false;
   //         }
   // }
//}


//void matrix_scan_user(void) {
//#ifdef AUDIO_ENABLE
//    if (muse_mode) {
//        if (muse_counter == 0) {
//            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//            if (muse_note != last_muse_note) {
//                stop_note(compute_freq_for_midi_note(last_muse_note));
//                play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                last_muse_note = muse_note;
//            }
//        }
//        muse_counter = (muse_counter + 1) % muse_tempo;
//    } else {
//        if (muse_counter) {
//            stop_all_notes();
//            muse_counter = 0;
//        }
//    }
//#endif
//}

// bool music_mask_user(uint16_t keycode) {
 // switch (keycode) {
 //   case RAISE:
 //   case LOWER:
 //     return false;
 //   default:
 //     return true;
 // }
//}
