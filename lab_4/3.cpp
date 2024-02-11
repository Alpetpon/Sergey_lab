// В вашем main.cpp

#include <iostream>
#include "Base.h"

int main() {
    // Создаем базу данных bd1
    Base bd1;

    // Заполняем базу данными
    bd1["Ivanov"] = MyData(MyData::MALE, 30, "Engineer", 40000);
    bd1["Petrova"] = MyData(MyData::FEMALE, 35, "Designer", 25000);
    bd1["Sidorov"] = MyData(MyData::MALE, 50, "Programmer", 50000);

    // Задание 3.1: Создаем копию базы данных bd1 с помощью перемещения
    Base bd4 = std::move(bd1);

    // Выводим информацию о сотрудниках в bd4
    std::cout << "Информация о сотрудниках в базе bd4:" << std::endl;
    std::cout << bd4 << std::endl;

    // Пытаемся вывести информацию о сотрудниках в bd1 (не должно быть данных)
    std::cout << "Информация о сотрудниках в базе bd1 после перемещения:" << std::endl;
    std::cout << bd1 << std::endl;

    // Создаем новую базу данных bd2 и заполняем ее данными
    Base bd2;
    bd2["Smith"] = MyData(MyData::MALE, 40, "Manager", 60000);
    bd2["Johnson"] = MyData(MyData::MALE, 45, "Accountant", 55000);

    // Задание 3.2: Присваиваем содержимое bd4 переменной bd3 с помощью перемещения
    Base bd3;
    bd3 = std::move(bd4);

    // Выводим информацию о сотрудниках в bd3
    std::cout << "Информация о сотрудниках в базе bd3 после перемещения:" << std::endl;
    std::cout << bd3 << std::endl;

    // Пытаемся вывести информацию о сотрудниках в bd4 (не должно быть данных)
    std::cout << "Информация о сотрудниках в базе bd4 после перемещения:" << std::endl;
    std::cout << bd4 << std::endl;

    return 0;
}
