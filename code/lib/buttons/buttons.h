#include <avr/io.h>

#define BUTTONS_DDR DDRA
#define BUTTONS_PORT PORTA
#define BUTTONS_PIN PINA

#define BUTTON_1 PA4
#define BUTTON_2 PA5
#define BUTTON_3 PA6
#define BUTTON_4 PA7

#define BUTTONS_MASK ((1 << BUTTON_1) | (1 << BUTTON_2) | (1 << BUTTON_3) | (1 << BUTTON_4))

enum ButtonType {
    NONE_BUTTON,
    INCREMENT_HOUR,
    INCREMENT_MINUTE,
    ALARM_SETTINGS,
    TOGGLE_ALARM
};

void buttonsInit();
ButtonType getPressedButton();
