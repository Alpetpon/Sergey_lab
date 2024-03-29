// Темы:
// Перегрузка операторов.
// Встроенные объекты 

#include <iostream>
#include "Base.h"
#define	  stop __asm nop

int main()
{
	
	//////////////////////////////////////////////////////////////////////
	
	//Задание 1. Разработать "базу данных" о сотрудниках посредством ассоциативного
	//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
	//в базе быть не может), а данными: пол, возраст, должность, зарплата...
	//Реализуйте:
	//добавление сотрудников в базу
	//исключение сотрудника из базы
	//вывод информации о конкретном сотруднике
	//вывод всей (или интересующей) информации о всех сотрудниках
	//(подсказки по реализации базы в файле "База_данных-ооп.pdf")
	//Например:

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
    std::cout << "После удаления Petrova" << std::endl;
    std::cout << bd1 << std::endl;


	//Задание 2. Разработайте необходимые методы для того, чтобы код,
	// приведенный ниже выполнялся корректно

	//Задание 2.1. создайте 2 копии  базы  bd1
	Base bd2 = bd1;
	std::cout << "Информация о сотрудниках в базе bd2:" << std::endl;
	std::cout << bd2 << std::endl; //выводим информацию обо всех сотрудниках  из базы bd2
	Base bd3 = bd1;
	std::cout << "Информация о сотрудниках в базе bd3:" << std::endl;
	std::cout << bd3 << std::endl; //выводим информацию обо всех сотрудниках  из базы bd3

	//Задание 2.2.  
	//добавьте сотрудников в базу  bd2
	bd2["Smith"] = MyData(MyData::MALE, 40, "Manager", 60000);
	bd2["Johnson"] = MyData(MyData::MALE, 45, "Accountant", 55000);

	std::cout << "Информация о сотрудниках в базе bd2 после добавления новых записей:" << std::endl;
	std::cout << bd2 << std::endl;; //выводим информацию обо всех сотрудниках  из базы bd2
	bd1 = bd2;   //  из "большой" в "маленькую"
	std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd1

	//Задание 2.3.
	bd1 = bd3;   //  из "маленькой"  в "большую" 
	std::cout << "Информация о сотрудниках в базе bd1 после присваивания:" << std::endl;
	std::cout << bd1 << std::endl;; //выводим информацию обо всех сотрудниках  из базы bd1


	//Задание 3. вспоминаем про семантику перемещения
	//Задание 3.1.создайте копию  базы  bd1
	Base bd4 = std::move(bd1);
	std::cout << "Информация о сотрудниках в базе bd4:" << std::endl;
	std::cout << bd4 << std::endl; //выводим информацию обо всех сотрудниках  из базы bd4
	std::cout << "Информация о сотрудниках в базе bd1 после перемещения:" << std::endl;
	std::cout << bd2 << std::endl; //выводим информацию обо всех сотрудниках  из базы bd2

	//Задание 3.2.

	bd3 = std::move(bd4);

	std::cout << "Информация о сотрудниках в базе bd3 после перемещения:" << std::endl;
	std::cout << bd3 << std::endl;; //выводим информацию обо всех сотрудниках  из базы bd3
	std::cout << "Информация о сотрудниках в базе bd4 после перемещения:" << std::endl;
	std::cout << bd4 << std::endl;; //выводим информацию обо всех сотрудниках  из базы bd4

	//Задание 4.  Сортировка

	//Задание 4.1. Разработайте сортировку базы данных  по возрастанию ключа
	//подумайте, что надо перегрузить в классе MyString

	//Задание 4.2.Отсортируйте любую базу данных и выведите результат
	Base bd;

	bd["Ivanov"] = MyData(MyData::MALE, 30, "Engineer", 40000);
	bd["Petrova"] = MyData(MyData::FEMALE, 35, "Designer", 25000);
	bd["Sidorov"] = MyData(MyData::MALE, 50, "Programmer", 50000);

	// Выводим информацию о сотрудниках до сортировки
	std::cout << "Информация о сотрудниках до сортировки:" << std::endl;
	std::cout << bd << std::endl;

	bd.sort();
	std::cout << "Информация о сотрудниках после сортировки:" << std::endl;
	std::cout << bd << std::endl;

	bd1.clear();
	bd2.clear();
	bd3.clear();
	bd4.clear();

	return 0;

}
