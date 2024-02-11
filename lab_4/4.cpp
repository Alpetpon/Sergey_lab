#include <iostream>
#include "Base.h"

int main() {
    // Создаем базу данных
    Base bd;

    // Добавляем некоторые данные
    bd["Ivanov"] = MyData(MyData::MALE, 30, "Engineer", 40000);
    bd["Petrova"] = MyData(MyData::FEMALE, 35, "Designer", 25000);
    bd["Sidorov"] = MyData(MyData::MALE, 50, "Programmer", 50000);

    // Выводим информацию о сотрудниках до сортировки
    std::cout << "Информация о сотрудниках до сортировки:" << std::endl;
    std::cout << bd << std::endl;

    // Сортируем базу данных по возрастанию ключа
    bd.sort();

    // Выводим отсортированную информацию о сотрудниках
    std::cout << "Информация о сотрудниках после сортировки:" << std::endl;
    std::cout << bd << std::endl;

    return 0;
}
