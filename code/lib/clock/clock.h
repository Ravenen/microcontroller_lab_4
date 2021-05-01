#include <stdio.h>

struct Time {
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
};
enum FunctionModes {
    NONE_MODE,
    SHOW_ALARM
};

class Clock {
private:
public:
    Time time = { 0, 0, 0 };
    Time alarm = { 0, 0, 0 };
    bool is_alarm_enabled = false;
    const uint8_t alarm_duration_in_sec = 30;
    FunctionModes function_mode = NONE_MODE;
    void incrementTimeHour();
    void incrementTimeMinute();
    void incrementAlarmHour();
    void incrementAlarmMinute();
    void toggleAlarm();
};