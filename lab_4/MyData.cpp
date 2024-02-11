#include "MyData.h"

// Определение конструктора класса MyData
MyData::MyData(Sex s, size_t a, const char* j, float sal) : sex(s), age(a), job(j), salary(sal) {}
// В конструкторе инициализируются члены данных класса MyData значениями аргументов конструктора

// Определение перегруженного оператора вывода
std::ostream& operator<<(std::ostream& os, const MyData& data) {
    // Оператор вывода выводит информацию о сотруднике в поток вывода
    os << "Sex: " << data.sex << ", Age: " << data.age << ", Job: " << data.job << ", Salary: " << data.salary;
    return os; // Возвращаем ссылку на поток вывода
}
