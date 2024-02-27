//------------------------------------------------------------------------------
// Тестируем двухсвязный список
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "List.h"


const char* sep = "------------------------------------\n";


int main()
{
	//
	// 1. Создаем список
	//
	std::cout << 1 << std::endl;
	List ls1;
	ls1.addToTail(Circle(Point(1, 1), 1));
	ls1.addToTail(Circle(Point(5, 5), 5));
	ls1.addToTail(Circle(Point(2, 2), 2));
	ls1.addToTail(Circle(Point(4, 4), 4));
	ls1.addToTail(Circle(Point(2, 2), 2));
	ls1.addToTail(Circle(Point(3, 3), 3));
	
	std::cout << ls1;					//выводим список	
	ls1.remove(Circle(Point(5, 5), 5));			// удаляем первый элемент, равный заданному
	std::cout << ls1; 
	
	ls1.removeAll(Circle(Point(2, 2), 2));   // удаляем все элементы, равные заданному
	std::cout << ls1 << sep;	
	//
	// 2. Приведенный ниже код должен выполняться корректно	
	//
	std::cout << 2 << std::endl;
	List ls2 = ls1;
	std::cout << ls2; 
	List ls3 = ls2;
	std::cout << ls3; 

	ls2.addToHead(Circle(Point(2, 2), 2));
	ls2.addToHead(Circle(Point(5, 5), 5));
	
	std::cout << ls2;	
	ls1 = ls2;			// из "большого" списка в "маленький"
	std::cout << ls1;	
	
	ls1 = ls3;			// из "маленького" списка в "большой"
	std::cout << ls1 << sep;	
	
	//
	// 3. Вспоминаем про семантику перемещения	
	//
	std::cout << 3 << std::endl;
	List ls4 = std::move(ls2);
	std::cout << ls4; 
	std::cout << ls2; 	
	
	ls3 = std::move(ls4);
	std::cout << ls3; 
	std::cout << ls4 << sep;
	//
	//4.  Сортировка по возрастанию площади кружка
	//
	std::cout << 4 << std::endl;
	std::cout << ls3;
	ls3.sortList();
	std::cout << ls3 << sep;
	//
	// 5. Файловый ввод/вывод
	//
	std::cout << 5 << std::endl;
	std::ofstream fout("list.txt");
	fout << ls3;	// выводим список в файл
	fout.close();
	
	std::ifstream fin("list.txt");
	List ls5;		// читаем список из файла
	fin >> ls5;
	fin.close();
	
	std::cout << ls5;
	return 0;
}