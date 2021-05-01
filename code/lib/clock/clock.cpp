#include "clock.h"

void Clock::incrementTimeHour() {
    if (++time.hours > 23) {
        time.hours = 0;
    }
}

void Clock::incrementTimeMinute() {
    if (++time.minutes > 59) {
        time.minutes = 0;
    }
}
void Clock::incrementAlarmHour() {
    if (++alarm.hours > 23) {
        alarm.hours = 0;
    }
}
void Clock::incrementAlarmMinute() {
    if (++alarm.minutes > 59) {
        alarm.minutes = 0;
    }
}

void Clock::toggleAlarm() {
    is_alarm_enabled = !is_alarm_enabled;
}
