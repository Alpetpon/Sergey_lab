#include <iostream>

enum WD {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

std::ostream& operator<<(std::ostream& os, const WD& day) {
    switch (day) {
        case SUNDAY:    os << "sunday"; break;
        case MONDAY:    os << "monday"; break;
        case TUESDAY:   os << "tuesday"; break;
        case WEDNESDAY: os << "wednesday"; break;
        case THURSDAY:  os << "thursday"; break;
        case FRIDAY:    os << "friday"; break;
        case SATURDAY:  os << "saturday"; break;
        default:        os.setstate(std::ios_base::failbit);
    }
    return os;
}

int main() {
    enum WD wd = SATURDAY;
    std::cout << wd << std::endl; 

    return 0;
}
