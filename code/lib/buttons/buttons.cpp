#include "buttons.h"

void buttonsInit() {
    BUTTONS_DDR = 0x00;
    BUTTONS_PORT = 0xFF;
}

ButtonType getPressedButton() {
    ButtonType button_pressed = NONE_BUTTON;
    if ((BUTTONS_PIN & BUTTONS_MASK) != BUTTONS_MASK) {
        uint8_t button_pressed_code = BUTTONS_PIN;
        while ((BUTTONS_PIN & BUTTONS_MASK) != BUTTONS_MASK) {}
        if ((button_pressed_code & (1 << BUTTON_1)) == 0) {
            button_pressed = INCREMENT_HOUR;
        }
        if ((button_pressed_code & (1 << BUTTON_2)) == 0) {
            button_pressed = INCREMENT_MINUTE;
        }
        if ((button_pressed_code & (1 << BUTTON_3)) == 0) {
            button_pressed = ALARM_SETTINGS;
        }
        if ((button_pressed_code & (1 << BUTTON_4)) == 0) {
            button_pressed = TOGGLE_ALARM;
        }
    }
    return button_pressed;
}