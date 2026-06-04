#include "clock.h"

void put_time(char *output, int hour, int minute) {

    output[0] = hour / 10 + '0';
    output[1] = hour % 10 + '0';
    output[2] = ':';
    output[3] = minute / 10 + '0';
    output[4] = minute % 10 + '0';
}

int get_hour(char *input) { return (input[0] - '0') * 10 + input[1] - '0'; }

int get_minute(char *input) { return (input[3] - '0') * 10 + input[4] - '0'; }

clock_t clock_create(int hour, int minute) {
    clock_t n = {"00:00"};
    minute += hour * 60;

    if (minute > 0) {
        n = clock_add(n, minute);
    } else {
        n = clock_subtract(n, -minute);
    }
    return n;
}
clock_t clock_add(clock_t clock, int minute_add) {
    int hour = get_hour(clock.text);
    int minute = get_minute(clock.text);

    minute += minute_add;

    while (minute > 59) {
        minute -= 60;
        hour++;
    }

    hour = hour % 24;

    put_time(clock.text, hour, minute);

    return clock;
}
clock_t clock_subtract(clock_t clock, int minute_subtract) {
    int hour = get_hour(clock.text);
    int minute = get_minute(clock.text);

    minute -= minute_subtract;

    while (minute < 0) {
        minute += 60;
        hour--;
    }

    while (hour < 0) {
        hour += 24;
    }

    put_time(clock.text, hour, minute);

    return clock;
}
bool clock_is_equal(clock_t a, clock_t b) {
    if (get_hour(a.text) == get_hour(b.text) &&
        get_minute(a.text) == get_minute(b.text))
        return true;
    return false;
}
