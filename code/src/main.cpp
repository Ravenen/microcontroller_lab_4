#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <clock.h>
#include <buzzer.h>
#include <buttons.h>
#include <sevseg.h>

#undef F_CPU
#define F_CPU 4000000UL
#define F_DISPLAY (6*50)
#define TIMER_CYCLE_IN_SECONDS 1
#define PRESCALER_VALUE 64

void handleButton(ButtonType button);
void timeToString(Time time, char* result);

Clock clock;
Time* displayed_time = &clock.time;
uint8_t digit_number = 0;
bool is_alarm_activated = false;

char time_buffer[8];

ISR(TIMER1_COMPA_vect) {
	if (++clock.time.seconds > 59) {
		clock.time.seconds = 0;
		if (++clock.time.minutes > 59) {
			clock.time.minutes = 0;
			if (++clock.time.hours > 23) {
				clock.time.hours = 0;
			}
		}
	}
	if (clock.is_alarm_enabled &&
		clock.time.hours == clock.alarm.hours && clock.time.minutes == clock.alarm.minutes &&
		clock.time.seconds <= clock.alarm_duration_in_sec) {
		is_alarm_activated = true;
	}
	else if (is_alarm_activated) {
		is_alarm_activated = false;
	}
}

ISR(TIMER3_COMPA_vect) {
	SEGMENTS_PORT = 0xFF;
	ANODE_PORT = ~(1 << digit_number << ANODE_PINS_OFFSET);
	timeToString(*displayed_time, time_buffer);
	SEGMENTS_PORT = getCodeByDigitNumber(digit_number, time_buffer, clock.is_alarm_enabled);
	if (++digit_number == 6) {
		digit_number = 0;
	}
}

void init() {

	// 1 second timer initialization
	TCCR1A = 0x00;
	TCCR1B = (1 << WGM12) | (1 << CS10) | (1 << CS11); // CTC mode, prescaler 64 (PRESCALER_VALUE)
	TIMSK1 = (1 << OCIE1A); // allow interrupt on compare A
	OCR1A = (TIMER_CYCLE_IN_SECONDS * F_CPU / PRESCALER_VALUE) - 1;

	// seven segments display updating timer initialization
	TCCR3A = 0x00;
	TCCR3B = (1 << WGM32) | (1 << CS10); // CTC mode, prescaler 1
	TIMSK3 = (1 << OCIE3A); // allow interrupt on compare A
	OCR3A = (F_CPU / (1 * F_DISPLAY)) - 1;

	sei();

	sevenSegmentInit();
	buttonsInit();
	buzzerInit();
}

int main() {
	init();
	while (true) {
		ButtonType button_pressed = getPressedButton();
		if (button_pressed != NONE_BUTTON) {
			handleButton(button_pressed);
		}
		if (is_alarm_activated) {
			playSound(ALARM);
		}
	}
}

void handleButton(ButtonType button) {
	playSound(CLICK);
	if (button == INCREMENT_HOUR) {
		if (clock.function_mode == NONE_MODE) {
			clock.incrementTimeHour();
		}
		else if (clock.function_mode == SHOW_ALARM) {
			clock.incrementAlarmHour();
		}
	}
	if (button == INCREMENT_MINUTE) {
		if (clock.function_mode == NONE_MODE) {
			clock.incrementTimeMinute();
		}
		else if (clock.function_mode == SHOW_ALARM) {
			clock.incrementAlarmMinute();
		}
	}
	if (button == ALARM_SETTINGS) {
		if (clock.function_mode == NONE_MODE) {
			clock.function_mode = SHOW_ALARM;
			displayed_time = &clock.alarm;
		}
		else if (clock.function_mode == SHOW_ALARM) {
			clock.function_mode = NONE_MODE;
			displayed_time = &clock.time;
		}
	}
	if (button == TOGGLE_ALARM && clock.function_mode == SHOW_ALARM) {
		clock.toggleAlarm();
	}
}

void timeToString(Time time, char* result) {
	sprintf(result, "%02d%02d", time.hours, time.minutes);
}