// Темы:
// Перегрузка операторов.

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных файлов, раскомментируйте эту строчку
#include <tchar.h>



//Класс для 1 задания
class Point {
private:
	int x;
	int y;
	
public:
	Point(int x, int y) : x(x), y(y) {}
	
	// Перегрузка оператора +=
	Point& operator+=(const Point& other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	
	// Перегрузка оператора +=
	Point& operator+=(int value) {
		this->x += value;
		this->y += value;
		return *this;
	}
	
	// Перегрузка оператора -= (в виде глобальной функции)
	friend Point operator-=(Point& pt1, const Point& pt2) {
		pt1.x -= pt2.x;
		pt1.y -= pt2.y;
		return pt1;
	}
	
	// Перегрузка оператора -= (в виде глобальной функции)
	friend Point operator-=(Point& pt, int value) {
		pt.x -= value;
		pt.y -= value;
		return pt;
	}
	
	// Дополнительный метод для вывода координат точки
	void printCoordinates() const {
		std::cout << "X: " << x << ", Y: " << y << std::endl;
	}
};


//Класс для 2 задания 
class Point {
private:
	int x, y;
	
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	
	Point operator+(const Point& other) const {
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		return result;
	}
	
	friend Point operator-(const Point& left, const Point& right) {
		Point result;
		result.x = left.x - right.x;
		result.y = left.y - right.y;
		return result;
	}
	

	Point operator+(int scalar) const {
		Point result;
		result.x = this->x + scalar;
		result.y = this->y + scalar;
		return result;
	}
	

	friend Point operator-(int scalar, const Point& point) {
		Point result;
		result.x = scalar - point.x;
		result.y = scalar - point.y;
		return result;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
};


//Класс для 3 задания
class Point {
private:
	int x, y;
	
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	
	// Перегрузка унарного оператора +
	Point operator+() const {
		// Возвращаем текущий объект, т.к. оператор + не меняет значения
		return *this;
	}
	
	// Перегрузка унарного оператора -
	Point operator-() const {
		Point result;
		result.x = -this->x;
		result.y = -this->y;
		return result;
	}
	
	// Перегрузка оператора вывода для удобного вывода точек
	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
};


//Класс для 4 задания
class Point {
private:
	int x, y;
	
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	
	// Перегрузка унарного оператора +
	Point operator+() const {
		return *this;
	}
	
	// Перегрузка унарного оператора -
	Point operator-() const {
		Point result;
		result.x = -this->x;
		result.y = -this->y;
		return result;
	}
	
	// Перегрузка оператора вывода
	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
		os << "x=" << point.x << ", y=" << point.y;
		return os;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////


	//Задание 1
	//Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//1a. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	// (!) Перегрузку выполните с помощью метода класса (оператор +=)
	//Проверьте корректность работы перегруженного оператора
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 += pt1;
		pt2.printCoordinates();
		pt2 += 1;
		pt2.printCoordinates();
		Point pt3(3, 3);
		pt2 += pt1 += pt3;
		pt2.printCoordinates();
	}
	//1b. "Перегрузите" оператор -= так, чтобы при выполнении
	//операции типа pt2-=pt1; вычитались
	//одноименные переменные объектов pt1 и pt2, а разность
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2-=1; обе переменные объекта pt2 уменьшались на
	// указанное значение
	//(!) Перегрузку выполнитес помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора
	{
		Point pt1(1, 1);
		Point pt2(2, 2);
		pt2 -= pt1;
		pt2.printCoordinates();
		pt2 -= 1;
		pt2.printCoordinates();
		Point pt3(3, 3);
		pt2 -= pt1 -= pt3;
		pt2.printCoordinates();
	}


 	//Задание 2
	//2a. Перегрузите оператор + 
	//с помощью методов класса, где это возможно 
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		Point pt1(1,1);
		Point pt2(2,2);
		Point pt3;

//		pt3 = pt1 + 5;
//      pt3 = 2 + pt1;
//		pt3 = pt1 + pt2;


	}
	//2b. Перегрузите оператор -
	// с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		Point pt1(1,1);
		Point pt2(2,2);
		Point pt3;

//		pt3 = pt1 - 5;
//      pt3 = 2 - pt1;
//		pt3 = pt1 - pt2;

	}
	//Задание 3
	// Перегрузите унарный оператор +/- 
	{
		Point pt1(1,1);
		Point pt3;

//		pt3 = -pt1;  // с помощью глобальной функции,
//		pt3 = +pt1;  // с помощью метода класса
	}
	//Задание 4. Перегрузите оператор << (вывода в поток) для
	// класса Point  таким образом, чтобы при выводе отображались координаты точки
	{
		Point pt(10,20);
		std::cout << pt << std::endl;//например, так:x=10, y=20
	}



	//Задание 5.Перегрузка оператора  =.

//Подключите к проекту файлы MyString.cpp и MyString.h
//класса MyString, разработанного Вами на предыдущем занятии
// Перегрузите оператор присваивания для класса MyString
//Проверьте корректность работы перегруженного оператора

	{
		MyString s1("AAA"), s2;
		s2=s1;
		s1="CCC";
		s2= MyString("tmp");
		s1=s1;
	}




	//Задание 6. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	cout<<s<<endl;


	

	//Задание 7. Перегрузите операторы + и += для класса MyString таким образом,
	//чтобы происходила конкатенация строк
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	s4 += s1; 
	stop



	//Задание 8. Перегрузите операторы  постфиксный декремент -- и префиксный инкремент
	//для класса MyString таким образом, при применении декремента производился перевод в нижний регистр всех символов, 
	// являющихся буквами латинского алфавита, а при применении инкремента производился перевод в верхний регистр.
	// при работе можно воспользоваться следующими функциями <ctype.h>:
	//int  isupper( int C);
	//int  islower( int C);
	//int  toupper( int C);
	//int  tolower( int C);
	{ 
	
		MyString str1("Hello World!!!");
		MyString str1_2 = str1--;
	
		MyString str2("Hello World!");
		MyString str2_2 = ++str2;


	}
	//Задание 9. Перегрузите операторы + и +=   для enum WEEKDAY
	{
		enum WD wd1 = SATURDAY;
		wd1 = wd1 + 2;
		WD wd2 = wd1 + 1;
		wd2 += 2;
	}
	
	//Задание 10. Перегрузите оператор << (вывода в поток) для
	//перечисления WD таким образом, чтобы при выводе отображалась строка, 
	// соответствующая именованной константе:
	{
		enum WD wd = SATURDAY;
		std::cout << wd << std::endl;//например, так:saturday
	}

	return 0;
}
