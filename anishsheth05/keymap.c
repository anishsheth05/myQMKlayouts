
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _GAYMER
};
enum planck_keycodes {
    ALT_TAB = SAFE_RANGE,
    LOWER,
    RAISE,
    OSFT
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define OSFT OSM(MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Switch| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  OSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  ALT_TAB, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
  RESET,   MI_ON, MI_OFF, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
  RESET,   MI_ON, MI_OFF, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Gaymer [for gaming]
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   e  |   w  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   f  |   a  |   s  |   d  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   z  | shift|   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Switch| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAYMER] = LAYOUT_planck_grid(
  KC_ESC,  KC_Q,    KC_E,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_F,    KC_A,    KC_S,    KC_D,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_Z, KC_LSFT,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
  ALT_TAB, KC_LCTL, KC_LALT, KC_LGUI, _______,   KC_SPC,  KC_SPC,  _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


};

// variables needed for alt tab key
bool alt_tab_enabled;
uint32_t alt_tab_timer;
// variable for the space bar sound effect
#ifdef AUDIO_ENABLE

__int32_t coins = 0;
#endif
// variable for gaymer mode
bool gaymer_mode = false;

#ifdef AUDIO_ENABLE

#define ENTER_SOUND M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),  M__NOTE(_B2, 0.5),  M__NOTE(_F4, 0.5),
#define ENTER_SOUND2 M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),  M__NOTE(_F6, 1),  M__NOTE(_B2, 1),

#define COIN_EFFECT M__NOTE(_B5, 16),  M__NOTE(_E6, 112),
#define ONE_UP_EFFECT M__NOTE(_E5, 48),  M__NOTE(_G5, 48),  M__NOTE(_E6, 48),  M__NOTE(_C6, 48),  M__NOTE(_D6, 48),  M__NOTE(_G6, 48),
// first make songs, then put into float array to yeet skeet
float enter_sound[][2] = SONG(ENTER_SOUND2);
float coin[][2] = SONG(COIN_EFFECT);
float one_up[][2] = SONG(ONE_UP_EFFECT);

#endif

// layer shizzzz
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _GAYMER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_ENT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            PLAY_SONG(one_up);
        #endif
        return true;
      }
      break;
    case KC_SPACE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
            coins += 1;
            if (coins == 100)
            {
              coins = 0;
              PLAY_SONG(one_up);
            } else {
              PLAY_SONG(coin);
            }
        #endif
        return true;
      }
      break;
    case ALT_TAB:
      alt_tab_enabled = record->event.pressed;
      if (alt_tab_enabled) {
        alt_tab_timer = timer_read();
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else {
        unregister_code(KC_LALT);
      }
      break;

  }
  return true;
}

void matrix_scan_user(void) {
  if ( alt_tab_enabled && (timer_elapsed(alt_tab_timer) > 333) ) {
    tap_code(KC_TAB);
    alt_tab_timer = timer_read();
   }
   gaymer_mode = layer_state_is(_GAYMER);
}
