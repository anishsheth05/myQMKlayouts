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

#include "planck.h"
#include "action_layer.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GREEK_LOWER,
  _GREEK_UPPER,
  _MIDI_FOR_FUN
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ~/Esc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |KeyLok|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |OSSHFT| Ctrl | Alt  | GUI  |Lower |    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LOCK, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_ENT ,
    OSM(MOD_LSFT), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Greek|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |Buton1|MouseU|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | MIDI |      |             |      | Next |MouseL|MouseD|MouseR|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    TT(_GREEK_LOWER), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_BTN1, KC_MS_U,  _______,
    _______, _______, _______, TG(_MIDI_FOR_FUN), _______, _______, _______, _______,    KC_MNXT,    KC_MS_L, KC_MS_D, KC_MS_R
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next |Pg Dwn| Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_VOLU, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_PGDN, KC_VOLD, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Unicode Greek Letters (Lowercase)
 * ,-----------------------------------------------------------------------------------.
 * |      |  rho |  psi|epsilon|sigma|upsilon|      |  phi | iota|omicron|  pi  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Union| alpha|  tao | delta| zeta |  eta | theta| kappa|lambda|  mu  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Intsct|      | omega| gamma|  chi | beta |  xi  |  nu  |      |      |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |OS-caps|      |      |      |      |    Space    |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* [_GREEK_LOWER] = LAYOUT_planck_grid(  
    TT(_GREEK_LOWER),  UC(0x03C1), UC(0x03C8), UC(0x03B5), UC(0x03C3), UC(0x03C5),XXXXXXX, UC(0x03C6), UC(0x03B9), UC(0x03BF), UC(0x03C0), KC_BSPC,
    UC(0x22C3), UC(0x03B1), UC(0x03C4), UC(0x03B4), UC(0x03B6), UC(0x03B7), UC(0x03B8), UC(0x03BA), UC(0x03BB), UC(0x03BC),XXXXXXX,XXXXXXX,
    UC(0x22C2),XXXXXXX, UC(0x03C9), UC(0x03B3), UC(0x03C7), UC(0x03B2), UC(0x03BE), UC(0x03BD), XXXXXXX, XXXXXXX, KC_UP, KC_ENT ,
    OSL(_GREEK_UPPER),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  KC_SPC,  KC_SPC,XXXXXXX,XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
), */
[_GREEK_LOWER] = LAYOUT_planck_grid(  
    TG(_MIDI_FOR_FUN),  X(17), X(23), X(5), X(18), X(20),XXXXXXX, X(21), X(9), X(15), X(16), KC_BSPC,
    X(49), X(1), X(19), X(4), X(6), X(7), X(8), X(10), X(11), X(12),XXXXXXX,XXXXXXX,
    X(50),XXXXXXX, X(24), X(3), X(22), X(2), X(14), X(13), XXXXXXX, XXXXXXX, KC_UP, KC_ENT ,
    OSL(_GREEK_UPPER),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  KC_SPC,  KC_SPC,XXXXXXX,XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Unicode Greek Letters (Uppercase)
 * ,-----------------------------------------------------------------------------------.
 * |      |  Rho |  Psi|Epsilon|Sigma|Upsilon|      |  Phi | Iota|Omicron|  Pi  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Union| Alpha|  Tao | Delta| Zeta |  Eta | Theta| Kappa|Lambda|  Mu  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Intsct|      | Omega| Gamma|  Chi | Beta |  Xi  |  Nu  |      |      |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* [_GREEK_UPPER] = LAYOUT_planck_grid(
    XXXXXXX,  UC(0x03A1), UC(0x03A8), UC(0x0395), UC(0x03A3), UC(0x03A5),XXXXXXX, UC(0x03A6), UC(0x0399), UC(0x30A0), UC(0x03A0), KC_BSPC,
    UC(0x22C3), UC(0x0391), UC(0x03A4), UC(0x0394), UC(0x0396), UC(0x0397), UC(0x0398), UC(0x039A), UC(0x039B), UC(0x039C),XXXXXXX,XXXXXXX,
    UC(0x22C2),XXXXXXX, UC(0x03A9), UC(0x0393), UC(0x03A7), UC(0x0392), UC(0x039E), UC(0x039D), XXXXXXX, XXXXXXX, KC_UP, KC_ENT ,
    OSL(_GREEK_UPPER),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  KC_SPC,  KC_SPC,XXXXXXX,XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
), */

 [_GREEK_UPPER] = LAYOUT_planck_grid(  
    TT(_GREEK_LOWER),  X(41), X(47), X(29), X(42), X(44),XXXXXXX, X(45), X(33), X(39), X(40), KC_BSPC,
    X(49), X(25), X(43), X(28), X(30), X(31), X(32), X(34), X(35), X(36),XXXXXXX,XXXXXXX,
    X(50),XXXXXXX, X(48), X(27), X(46), X(26), X(38), X(37), XXXXXXX, XXXXXXX, KC_UP, KC_ENT ,
    OSL(_GREEK_UPPER),XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  KC_SPC,  KC_SPC,XXXXXXX,XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
),

/* MIDI Layer (for FuUuUuN!)
 * ,-----------------------------------------------------------------------------------.
 * | Exit |  C#  |  D#  |      |  F#  |  G#  |  A#  |      |  C#  |  D#  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   C  |   D  |   E  |   F  |   G  |   A  |   B  |   C  |   D  |   E  |   F  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Vel1 | Vel2 | Vel3 | Vel4 | Vel5 | Vel6 | Vel7 | Vel8 | Vel9 | Vel10|      |    Mod changes the instrument.
 * |------+------+------+------+------+------+------+------+------+------+------+------|    Velocity changes volume (and tone I think)
 * |  MOD |      |      |      | Oct- |   Sustain   | Oct+ |      |      |      |      |    of the note.
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI_FOR_FUN] = LAYOUT_planck_grid(
    TG(_MIDI_FOR_FUN), MI_Cs, MI_Ds, XXXXXXX, MI_Fs, MI_Gs, MI_As, XXXXXXX, MI_Cs_1, MI_Ds_1, XXXXXXX, XXXXXXX,
    XXXXXXX,    MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_A,    MI_B,  MI_C_1,  MI_D_1,  MI_E_1,  MI_F_1,
    XXXXXXX, MI_VEL_1, MI_VEL_2, MI_VEL_3, MI_VEL_4, MI_VEL_5, MI_VEL_6, MI_VEL_7, MI_VEL_8, MI_VEL_9, MI_VEL_10, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

//Unicode Mapping Table, for future
#ifdef UNICODEMAP_ENABLE
 const uint32_t PROGMEM unicode_map[] = {0x03b1, 0x03b2, 0x03b3, 0x03b4, 0x03b5, 0x03b6, 0x03b7, 0x03b8, 0x03b9, 0x03ba,
 0x03bb, 0x03bc, 0x03bd, 0x03be, 0x03bf, 0x03c0, 0x03c1, 0x03c3, 0x03c4, 0x03c5, 0x03c6, 0x03c7, 0x03c8, 0x03c9, 0x0391,
 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397, 0x0398, 0x0399, 0x039a, 0x039b, 0x039c, 0x039d, 0x039f, 0x03a0, 0x03a1,
 0x03a0, 0x03a1, 0x03a3, 0x03a4, 0x03a5, 0x03a6, 0x03a7, 0x03a8, 0x03a9, 0x22c3, 0x22c2};
#endif  

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_LSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_LSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

/*
  What the below says is that:
  If muse mode is on, and the layer raise is on, it will increase or decrease the muse offset by one depending on the direction of the knob.
  If muse mode is not on, but either of the layers raise or lower are on, then it will increase or decrease the volume.
  If muse mode is not on, and but midi (the layer) is on, then it will mod wheel.
  Other wise, normally, it will page up or page down depending on the direction of the turning of the knob.

*/
void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  }
  else {
    if (IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_LOWER)) {
      if (clockwise){
       register_code(KC_VOLU);
       unregister_code(KC_VOLU);
      }
      else {
       register_code(KC_VOLD);
       unregister_code(KC_VOLD);
      }
    }
    else{
     if (clockwise){
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
     }
     else{
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
     }
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
