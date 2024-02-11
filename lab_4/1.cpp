#include <iostream>
#include "Base.h"

int main() {
    // Создаем пустую базу данных
    Base bd1;

    // Добавляем сотрудников в базу
    bd1["Ivanov"] = MyData(MyData::MALE, 30, "Engineer", 40000);
    bd1["Petrova"] = MyData(MyData::FEMALE, 35, "Designer", 25000);
    bd1["Sidorov"] = MyData(MyData::MALE, 50, "Programmer", 50000);

    // Выводим информацию обо всех сотрудниках
    std::cout << "Информация обо всех сотрудниках:" << std::endl;
    std::cout << bd1 << std::endl;

    // Выводим информацию о конкретном сотруднике
    std::cout << "Информация о сотруднике Ivanov:" << std::endl;
    std::cout << bd1["Ivanov"] << std::endl;

    // Исключаем сотрудника
    bd1.deletePair("Petrova");
    std::cout << "После удаления Petrova:" << std::endl;
    std::cout << bd1 << std::endl;

    return 0;
}
