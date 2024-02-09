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

// Операторы + и +=
WEEKDAY operator+(const WEEKDAY& day, int daysToAdd) {
    int result = (static_cast<int>(day) + daysToAdd) % 7;
    return static_cast<WEEKDAY>(result < 0 ? result + 7 : result);
}

WEEKDAY& operator+=(WEEKDAY& day, int daysToAdd) {
    day = day + daysToAdd;
    return day;
}

// Функция для преобразования перечисления в строку
const char* weekdayToString(WEEKDAY day) {
    switch (day) {
        case SUNDAY: return "Sunday";
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        default: return "Invalid day";
    }
}

int main() {
    WEEKDAY wd1 = SATURDAY;
    wd1 = wd1 + 2;

    WEEKDAY wd2 = wd1 + 1;
    wd2 += 2;

    std::cout << "wd1: " << weekdayToString(wd1) << std::endl;
    std::cout << "wd2: " << weekdayToString(wd2) << std::endl;

    return 0;
}
