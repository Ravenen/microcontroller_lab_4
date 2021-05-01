#include "sevseg.h"

void sevenSegmentInit() {
    SEGMENTS_DDR = 0xFF;
    SEGMENTS_PORT = 0xFF;
    ANODE_DDR = 0xFF;
    ANODE_PORT = 0xFF;
}

uint8_t getCodeByDigitNumber(uint8_t digit_number, char* time, bool is_alarm_enabled) {
    uint8_t character_to_display = 0xFF;
    switch (digit_number) {
    case 0:
        character_to_display = DIGIT_CODE[time[0] - '0'];
        break;
    case 1:
        character_to_display = DIGIT_CODE[time[1] - '0'] & DOT_CODE;
        break;
    case 2:
        character_to_display = DIGIT_CODE[time[2] - '0'];
        break;
    case 3:
        character_to_display = DIGIT_CODE[time[3] - '0'];
        break;
    case 5:
        if (is_alarm_enabled) {
            character_to_display = ALARM_ICON_CODE;
        }
        break;
    }
    return character_to_display;
}