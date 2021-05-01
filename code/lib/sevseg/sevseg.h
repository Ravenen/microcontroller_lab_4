#include <avr/io.h>

#define SEGMENTS_DDR DDRB
#define SEGMENTS_PORT PORTB
#define ANODE_DDR DDRC
#define ANODE_PORT PORTC
#define ANODE_PINS_OFFSET 1

const uint8_t DIGIT_CODE[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
const uint8_t DOT_CODE = 0x7F;
const uint8_t ALARM_ICON_CODE = 0x88;

void sevenSegmentInit();
uint8_t getCodeByDigitNumber(uint8_t digit_number, char* time, bool is_alarm_enabled);