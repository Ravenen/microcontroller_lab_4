#include <avr/io.h>
#include "util/delay.h"

#define BUZZER_DDR DDRD
#define BUZZER_PORT PORTD
#define BUZZER PORTD4

enum SoundType {
    CLICK,
    ALARM
};

void buzzerInit();
void playSound(SoundType sound);