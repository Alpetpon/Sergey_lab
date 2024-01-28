#include <iostream>

enum WEEKDAY {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};


WEEKDAY operator+(const WEEKDAY& day, int daysToAdd) {
    int result = (static_cast<int>(day) + daysToAdd) % 7;
    return static_cast<WEEKDAY>(result < 0 ? result + 7 : result);
}


WEEKDAY& operator+=(WEEKDAY& day, int daysToAdd) {
    day = day + daysToAdd;
    return day;
}

int main() {
    enum WEEKDAY wd1 = SATURDAY;
    wd1 = wd1 + 2;

    enum WEEKDAY wd2 = wd1 + 1;
    wd2 += 2;

    std::cout << "wd1: " << wd1 << std::endl;
    std::cout << "wd2: " << wd2 << std::endl;

    return 0;
}
