#include QMK_KEYBOARD_H

enum layers {

    // Layer Ideas:
    // 
    // - Layers:           select a macro layer.
    // - Layers_Default:   copy, cut, paste, screenshots, etc.
    // - Layers_NumberPad: simple number pad, etc.
    // - Layers_Machine:   shutdown, sleep, lock, etc.
    // - Layers_Discord:   mute self, mute others, change audio, channels, etc.
    // - Layers_VSCode:    snippets, tools, etc.
    // 
    // - Game:             select a game layer.
    // - Game_MapleStory:  skills, potions, etc.
    // - Game_PSO2:        skill, potions, etc.
    // 
    // - Settings:         select a setting layer.
    // - Settings_RGB:     change RGB settings/modes, etc.
    // - Settings_OLED:    change OLED settings, etc.

    _LAYERS,
    _LAYERS_DEFAULT,
    _LAYERS_NUMPAD,
    _LAYERS_MACHINE,
    _LAYERS_DISCORD,
    _LAYERS_VSCODE,

    _GAME,
    _GAME_MAPLESTORY,
    _GAME_PSO2,

    _SETTINGS,
    _SETTINGS_RGB,
    _SETTINGS_OLED,
    
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER_DEFAULT] = LAYOUT_ortho_3x4(
        KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, MO(_LAYERS), 
        KC_NO, KC_NO, KC_NO, MO(_SETTINGS)
    ),

    [_LAYER_DISCORD] = LAYOUT_ortho_3x4(
        KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, MO(_LAYERS),
        KC_NO, KC_NO, KC_NO, MO(_SETTINGS)
    ),

    [_LAYER_VSCODE] = LAYOUT_ortho_3x4(
        KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, MO(_LAYERS),
        KC_NO, KC_NO, KC_NO, MO(_SETTINGS)
    ),

    [_LAYERS] = LAYOUT_ortho_3x4(
        KC_NO,
        TO(_LAYER_DEFAULT), KC_NO,       KC_NO, KC_NO,
        TO(_LAYER_DISCORD),  TO(_LAYER_VSCODE), KC_NO, MO(_LAYERS),
        KC_NO,        KC_NO,       KC_NO, MO(_SETTINGS)
    ),

    [_SETTINGS_RGB] = LAYOUT_ortho_3x4(
        RGB_TOG,
        RGB_MOD,        RGB_HUI,          RGB_VAI,        RGB_SAI,
        RGB_RMOD,       RGB_HUD,          RGB_VAD,        RGB_SAD,
        RGB_MODE_PLAIN, RGB_MODE_TWINKLE, RGB_MODE_SWIRL, TO(_LAYER_DEFAULT)
    ),

    [_SETTINGS] = LAYOUT_ortho_3x4(
        KC_NO,
        TO(_SETTINGS_RGB), KC_NO, KC_NO, KC_NO,
        KC_NO,    KC_NO, KC_NO, KC_NO,
        KC_NO,    KC_NO, KC_NO, TO(_LAYER_DEFAULT)
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_WH_U);
    } else {
        tap_code(KC_WH_D);
    }
    return false;
}

#ifdef OLED_ENABLE

//------------------------------------------------------------------------------------------------

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

// static void render_logo(void) {     // Render MechWild "MW" Logo
//     static const char PROGMEM logo_1[] = {0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x04, 0x06, 0x82, 0xc3, 0x43, 0x61, 0xa1, 0xa1,0xa1, 0xa1, 0x61, 0x43, 0xc3, 0x82, 0x06, 0x04, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00};
//     static const char PROGMEM logo_2[] = {0xf8, 0x1e, 0xc3, 0xf8, 0x5c, 0x76, 0x7b, 0x6d, 0x75, 0x55, 0x55, 0x75, 0x6d, 0x7b, 0x76, 0x5e,0x7e, 0x77, 0x5b, 0x6d, 0x75, 0x55, 0x55, 0x75, 0x4d, 0x7b, 0x66, 0x5c, 0xf0, 0xc3, 0x3e, 0xf0};
//     static const char PROGMEM logo_3[] = {0x1f, 0x78, 0xc1, 0x0f, 0x38, 0xe0, 0xc0, 0x00, 0x00, 0x02, 0x0e, 0x0e, 0x8e, 0xc6, 0xc0, 0x40,0x40, 0xc0, 0xc6, 0x8e, 0x0e, 0x0e, 0x02, 0x00, 0x80, 0xc0, 0x60, 0x38, 0x0f, 0xc0, 0x7c, 0x0f};
//     static const char PROGMEM logo_4[] = {0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x31, 0x23, 0x66, 0x44, 0x44, 0xc4, 0xc4, 0x84, 0x84,0x84, 0x84, 0xc4, 0xc4, 0x44, 0x46, 0x66, 0x23, 0x11, 0x18, 0x0c, 0x06, 0x03, 0x00, 0x00, 0x00};
//     oled_set_cursor(0,0);
//     oled_write_raw_P(logo_1, sizeof(logo_1));
//     oled_set_cursor(0,1);
//     oled_write_raw_P(logo_2, sizeof(logo_2));
//     oled_set_cursor(0,2);
//     oled_write_raw_P(logo_3, sizeof(logo_3));
//     oled_set_cursor(0,3);
//     oled_write_raw_P(logo_4, sizeof(logo_4));
// }
//-----------

bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Weekend_Ghost"), false);

    oled_set_cursor(0, 3);
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _LAYERS:
            oled_write_P(PSTR("LAYERS  "), false);
            break;
        case _LAYER_DEFAULT:
            oled_write_P(PSTR("DEFAULT "), false);
            break;
        case _LAYER_NUMPAD:
            oled_write_P(PSTR("NUMPAD    "), false);
            break;
        case _LAYER_MACHINE:
            oled_write_P(PSTR("MACHINE   "), false);
            break;
        case _LAYER_DISCORD:
            oled_write_P(PSTR("DISCORD   "), false);
            break;
        case _LAYER_VSCODE:
            oled_write_P(PSTR("VSCODE    "), false);
            break;
        case _GAME:
            oled_write_P(PSTR("GAME      "), false);
            break;
        case _GAME_MAPLESTORY:
            oled_write_P(PSTR("MAPLESTORY"), false);
            break;
        case _GAME_PSO2:
            oled_write_P(PSTR("PSO2      "), false);
            break;
        case _SETTINGS:
            oled_write_P(PSTR("SETTINGS  "), false);
            break;
        case _SETTINGS_RGB:
            oled_write_P(PSTR("RGB       "), false);
            break;
        case _SETTINGS_OLED:
            oled_write_P(PSTR("RGB       "), false);
            break;
        default:
            oled_write_P(PSTR("N/A       "), false);
            break;
    }
    return false;
}

#endif
