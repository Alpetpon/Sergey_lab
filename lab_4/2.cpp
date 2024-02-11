#include <iostream>
#include "Base.h"

int main() {
    // Создаем пустую базу данных
    Base bd1;

    // Добавляем несколько сотрудников в базу данных
    bd1["Ivanov"] = MyData(MyData::MALE, 30, "Engineer", 40000);
    bd1["Petrova"] = MyData(MyData::FEMALE, 35, "Designer", 25000);
    bd1["Sidorov"] = MyData(MyData::MALE, 50, "Programmer", 50000);

    // Задание 2.1: Создаем две копии базы данных bd1
    Base bd2 = bd1;
    Base bd3 = bd1;

    // Выводим информацию о сотрудниках из каждой копии
    std::cout << "Информация о сотрудниках в базе bd2:" << std::endl;
    std::cout << bd2 << std::endl;

    std::cout << "Информация о сотрудниках в базе bd3:" << std::endl;
    std::cout << bd3 << std::endl;

    // Задание 2.2: Добавляем сотрудников в базу bd2
    bd2["Smith"] = MyData(MyData::MALE, 40, "Manager", 60000);
    bd2["Johnson"] = MyData(MyData::MALE, 45, "Accountant", 55000);

    // Выводим информацию о сотрудниках в базе bd2 после добавления новых записей
    std::cout << "Информация о сотрудниках в базе bd2 после добавления новых записей:" << std::endl;
    std::cout << bd2 << std::endl;

    // Задание 2.3: Присваиваем содержимое базы bd3 базе bd1
    bd1 = bd3;

    // Выводим информацию о сотрудниках в базе bd1 после присваивания
    std::cout << "Информация о сотрудниках в базе bd1 после присваивания:" << std::endl;
    std::cout << bd1 << std::endl;

    return 0;
}
