// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.

#include <iostream>
#include <cstring>

#include <tchar.h>


//Класс для 1 задания
class MyString {
public:
	std::string str;
	
	// Конструктор класса MyString
	MyString(const std::string& s) : str(s) {}
};

//Задание 3
// Перечисление для цветов
enum Color {
	RED,
	GREEN,
	BLUE
};

// Базовый класс Shape
class Shape {
protected:
	Color color;
	
public:
	// Конструктор базового класса с параметром-цветом
	Shape(Color c) : color(c) {
		std::cout << "Shape constructor" << std::endl;
	}
	
	// Виртуальный деструктор для правильного удаления объектов через указатель на базовый класс
	virtual ~Shape() {
		std::cout << "Shape destructor" << std::endl;
	}
	
	// Виртуальная функция для вывода информации о фигуре
	virtual void printInfo() const {
		std::cout << "Shape color: ";
		switch (color) {
			case RED:
				std::cout << "RED";
				break;
			case GREEN:
				std::cout << "GREEN";
				break;
			case BLUE:
				std::cout << "BLUE";
				break;
		}
		std::cout << std::endl;
	}
};

// Производный класс Rect
class Rect : public Shape {
protected:
	// Дополнительные данные для прямоугольника
	
public:
	// Конструктор производного класса Rect
	Rect(Color c) : Shape(c) {
		std::cout << "Rect constructor" << std::endl;
	}
	
	// Деструктор производного класса Rect
	~Rect() override {
		std::cout << "Rect destructor" << std::endl;
	}
	
	// Переопределение виртуальной функции для вывода информации о прямоугольнике
	void printInfo() const override {
		Shape::printInfo();  // Вызов функции базового класса
		std::cout << "Type: Rectangle" << std::endl;
	}
};

// Производный класс Circle
class Circle : public Shape {
protected:
	// Дополнительные данные для круга
	
public:
	// Конструктор производного класса Circle
	Circle(Color c) : Shape(c) {
		std::cout << "Circle constructor" << std::endl;
	}
	
	// Деструктор производного класса Circle
	~Circle() override {
		std::cout << "Circle destructor" << std::endl;
	}
	
	// Переопределение виртуальной функции для вывода информации о круге
	void printInfo() const override {
		Shape::printInfo();  // Вызов функции базового класса
		std::cout << "Type: Circle" << std::endl;
	}
};



//Задание 4
enum Color {
	RED,
	GREEN,
	BLUE
};

class Shape {
protected:
	Color color;
	
public:
	Shape(Color c) : color(c) {}
	
	virtual ~Shape() {}
	
	void WhereAmI() {
		std::cout << "Now I am in class Shape" << std::endl;
	}
	
	virtual void WhereAmIVirtual() {
		std::cout << "Now I am in class Shape (virtual)" << std::endl;
	}
};

class Rect : public Shape {
public:
	Rect(Color c) : Shape(c) {}
	
	void WhereAmI() {
		std::cout << "Now I am in class Rect" << std::endl;
	}
	
	void WhereAmIVirtual() override {
		std::cout << "Now I am in class Rect (virtual)" << std::endl;
	}
};

class Circle : public Shape {
public:
	Circle(Color c) : Shape(c) {}
	
	void WhereAmI() {
		std::cout << "Now I am in class Circle" << std::endl;
	}
	
	void WhereAmIVirtual() override {
		std::cout << "Now I am in class Circle (virtual)" << std::endl;
	}
};


//Задание  5
enum Color {
	RED,
	GREEN,
	BLUE
};

class Shape {
protected:
	Color color;
	
public:
	Shape(Color c) : color(c) {}
	
	~Shape() {
		std::cout << "Now I am in Shape's destructor!" << std::endl;
	}
	
	void WhereAmI() {
		std::cout << "Now I am in class Shape" << std::endl;
	}
	
	virtual void WhereAmIVirtual() {
		std::cout << "Now I am in class Shape (virtual)" << std::endl;
	}
};

class Rect : public Shape {
public:
	Rect(Color c) : Shape(c) {}
	
	~Rect() {
		std::cout << "Now I am in Rect's destructor!" << std::endl;
	}
	
	void WhereAmI() {
		std::cout << "Now I am in class Rect" << std::endl;
	}
	
	void WhereAmIVirtual() override {
		std::cout << "Now I am in class Rect (virtual)" << std::endl;
	}
};

class Circle : public Shape {
public:
	Circle(Color c) : Shape(c) {}
	
	~Circle() {
		std::cout << "Now I am in Circle's destructor!" << std::endl;
	}
	
	void WhereAmI() {
		std::cout << "Now I am in class Circle" << std::endl;
	}
	
	void WhereAmIVirtual() override {
		std::cout << "Now I am in class Circle (virtual)" << std::endl;
	}
};

//Задание 7
enum Color {
	RED,
	GREEN,
	BLUE
};

class Shape {
protected:
	Color color;
	
public:
	Shape(Color c) : color(c) {}
	
	virtual ~Shape() {}
	
	void WhereAmIVirtual() {
		std::cout << "Now I am in class Shape (virtual)" << std::endl;
	}
};

class Rect : public Shape {
public:
	Rect(Color c) : Shape(c) {}
	
	~Rect() override {}
	
	void WhereAmIVirtual() {
		std::cout << "Now I am in class Rect (virtual)" << std::endl;
	}
};

//Задание 8
class Shape {
public:
	virtual ~Shape() {}
	
	// Чисто виртуальная функция
	virtual void Inflate(int factor) = 0;
};

class Rect : public Shape {
public:
	// Реализация виртуальной функции для класса Rect
	void Inflate(int factor) override {
		std::cout << "Inflating Rect by factor: " << factor << std::endl;
	}
};

class Circle : public Shape {
public:
	// Реализация виртуальной функции для класса Circle
	void Inflate(int factor) override {
		std::cout << "Inflating Circle by factor: " << factor << std::endl;
		
	}
};

//Задание 9
class MyString {
private:
	char* str;
	
public:
	MyString(const char* s) {
		if (s != nullptr) {
			str = new char[std::strlen(s) + 1];
			std::strcpy(str, s);
		} else {
			str = nullptr;
		}
	}
	
	MyString(const MyString& other) {
		if (other.str != nullptr) {
			str = new char[std::strlen(other.str) + 1];
			std::strcpy(str, other.str);
		} else {
			str = nullptr;
		}
	}
	
	~MyString() {
		delete[] str;
	}
	
	const char* c_str() const {
		return str;
	}
	
	MyString& operator=(const MyString& other) {
		if (this != &other) {
			delete[] str;
			
			if (other.str != nullptr) {
				str = new char[std::strlen(other.str) + 1];
				std::strcpy(str, other.str);
			} else {
				str = nullptr;
			}
		}
		
		return *this;
	}
	
	MyString operator+(const MyString& other) const {
		char* resultStr = new char[std::strlen(str) + std::strlen(other.str) + 1];
		std::strcpy(resultStr, str);
		std::strcat(resultStr, other.str);
		
		MyString result(resultStr);
		delete[] resultStr;
		
		return result;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
		os << myStr.str;
		return os;
	}
};

//Задание 10
// Класс Bin
class Bin {
public:
	unsigned char m_bin0 : 1;
	unsigned char m_bin1 : 1;
	unsigned char m_bin2 : 1;
	unsigned char m_bin3 : 1;
	unsigned char m_bin4 : 1;
	unsigned char m_bin5 : 1;
	unsigned char m_bin6 : 1;
	unsigned char m_bin7 : 1;
	
	void Show() {
		std::cout << static_cast<int>(m_bin7) << m_bin6 << m_bin5 << m_bin4 << " "
		<< m_bin3 << m_bin2 << m_bin1 << m_bin0 << "b";
	}
	
	void ShowPos(int pos) {
		if (pos >= 0 && pos <= 7) {
			std::cout << static_cast<int>((m_bin7 >> pos) & 1);
		} else {
			std::cout << "Invalid position";
		}
	}
	
	void Edit(int pos, int val) {
		if (pos >= 0 && pos <= 7 && (val == 0 || val == 1)) {
			if (val == 1) {
				m_bin7 |= (1 << pos);
			} else {
				m_bin7 &= ~(1 << pos);
			}
		} else {
			std::cout << "Invalid position or value";
		}
	}
	
	friend union Bytes;
};

// Класс Oct
class Oct {
public:
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;
	
	void Show() {
		std::cout << static_cast<int>(m_oct2) << m_oct1 << m_oct0 << "o";
	}
	
	void ShowPos(int pos) {
		if (pos >= 0 && pos <= 5) {
			int shift = 3 * (1 - pos % 2);
			std::cout << static_cast<int>((m_oct2 >> shift) & 7);
		} else {
			std::cout << "Invalid position";
		}
	}
	
	void Edit(int pos, int val) {
		if (pos >= 0 && pos <= 5 && val >= 0 && val <= 7) {
			int shift = 3 * (1 - pos % 2);
			m_oct2 &= ~(7 << shift);
			m_oct2 |= (val << shift);
		} else {
			std::cout << "Invalid position or value";
		}
	}
	
	friend union Bytes;
};

// Класс Hex
class Hex {
public:
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;
	
	void Show() {
		std::cout << std::hex << static_cast<int>(m_hex1) << m_hex0 << "h" << std::dec;
	}
	
	void ShowPos(int pos) {
		if (pos >= 0 && pos <= 3) {
			int shift = 4 * (1 - pos % 2);
			std::cout << std::hex << static_cast<int>((m_hex1 >> shift) & 0xF) << std::dec;
		} else {
			std::cout << "Invalid position";
		}
	}
	
	void Edit(int pos, int val) {
		if (pos >= 0 && pos <= 3 && val >= 0 && val <= 15) {
			int shift = 4 * (1 - pos % 2);
			m_hex1 &= ~(0xF << shift);
			m_hex1 |= (val << shift);
		} else {
			std::cout << "Invalid position or value";
		}
	}
	
	friend union Bytes;
};

// Объединение Bytes
union Bytes {
public:
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;
	
	Bytes(unsigned char byte) : m_dec(byte) {}
	
	void ShowBin() { m_bin.Show(); }
	
	void ShowOct() { m_oct.Show(); }
	
	void ShowHex() { m_hex.Show(); }
	
	void ShowDec() { std::cout << static_cast<int>(m_dec) << "d"; }
	
	void ShowChar() {
		if (m_dec >= 32 && m_dec <= 126) {
			std::cout << static_cast<char>(m_dec);
		} else {
			std::cout << "Not printable";
		}
	}
	
	void ShowBinPos(int pos) { m_bin.ShowPos(pos); }
	
	void ShowOctPos(int pos) { m_oct.ShowPos(pos); }
	
	void ShowHexPos(int pos) { m_hex.ShowPos(pos); }
	
	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	
	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
};

int _tmain(int argc, _TCHAR* argv[])
{
	//Задание 1.Массив объектов класса.
	{
	//Объявите и проинициализируйте массив ar из объектов
	// типа MyString. 
		//const int N=3;
		//MyString str1[N] = {...};
  
	//Проверка - печать строк-членов класса
	
	//Замените размер const int N=5; , не изменяя список инициализаторов.
	
		
		// Исходный размер массива
		const int N = 3;
		
		// Инициализация массива объектов MyString
		MyString str1[N] = {MyString("String1"), MyString("String2"), MyString("String3")};
		
		// Печать строк-членов класса
		for (int i = 0; i < N; ++i) {
			std::cout << "str1[" << i << "]: " << str1[i].str << std::endl;
		}
		
		// Новый размер массива 
		const int M = 5;
		
		// Замените размер массива, не изменяя список инициализаторов
		const int NewN = M;
		
		// Создание нового массива с новым размером
		MyString str2[NewN] = {MyString("String4"), MyString("String5"), MyString("String6"), MyString("String7"), MyString("String8")};
		
		// Печать строк-членов нового массива
		for (int i = 0; i < NewN; ++i) {
			std::cout << "str2[" << i << "]: " << str2[i].str << std::endl;
		}
		

	}



	//Задание 2.Массив указателей на объекты класса.
	{
	//Объявите и проинициализируйте массив arPtr из N
	//указателей на объекты типа MyString (сами объекты 
	//создаются динамически!).
	//const int N=3;
	
	//Печать строк-членов класса

   	//Замените размер const int N=5; , не изменяя список инициализаторов.
		
	
		// Исходный размер массива указателей
		const int N = 3;
		
		// Инициализация массива указателей на объекты MyString (создание объектов динамически)
		MyString* arPtr[N];
		arPtr[0] = new MyString("String1");
		arPtr[1] = new MyString("String2");
		arPtr[2] = new MyString("String3");
		
		// Печать строк-членов класса через указатели
		for (int i = 0; i < N; ++i) {
			std::cout << "arPtr[" << i << "]: " << arPtr[i]->str << std::endl;
		}
		
		// Новый размер массива (может быть любым)
		const int M = 5;
		
		// Замените размер массива указателей, не изменяя список инициализаторов
		// (просто укажите новый размер)
		const int NewN = M;
		
		// Создание нового массива указателей с новым размером
		MyString* arPtrNew[NewN];
		arPtrNew[0] = new MyString("String4");
		arPtrNew[1] = new MyString("String5");
		arPtrNew[2] = new MyString("String6");
		arPtrNew[3] = new MyString("String7");
		arPtrNew[4] = new MyString("String8");
		
		// Печать строк-членов нового массива указателей
		for (int i = 0; i < NewN; ++i) {
			std::cout << "arPtrNew[" << i << "]: " << arPtrNew[i]->str << std::endl;
		}
		
		// Освобождение памяти для каждого созданного объекта
		for (int i = 0; i < N; ++i) {
			delete arPtr[i];
		}
		
		// Освобождение памяти для каждого созданного объекта нового массива
		for (int i = 0; i < NewN; ++i) {
			delete arPtrNew[i];
		}

	
	}



	//Задание 3.Простое наследование.Аргументы конструктора,
	// передаваемые в базовый класс.

	//Создайте иерархию классов:
	//базовый класс Shape (который описывает любую фигуру)
	//и два производных класса Rect и Circle.
	//Подумайте: какие данные и методы нужно ввести в базовый
	//и производные классы (например, любую фигуру можно сделать
	//цветной => в базовом классе можно ввести переменную, которая
	//будет определять цвет фигуры.
	//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);
	

	
	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов
	
	// Создание объектов иерархии
	Rect rect(RED);
	Circle circle(GREEN);
	
	// Вывод информации о фигурах
	rect.printInfo();
	std::cout << std::endl;
	circle.printInfo();
	




//////////////////////////////////////////////////////////////////////

	//Задание 4.Виртуальные функции.
	//4а) Модифицируйте классы Shape,Rect и Circle:
	//добавьте в каждый класс public метод void WhereAmI().
	//Реализация каждой функции должна выводить сообщение 
	//следующего вида "Now I am in class Shape(Rect или Circle)".
	//Выполните приведенный фрагмент, объясните результат.


	{
		
	Shape s(RED);
	Rect r(GREEN);
	Circle c(BLUE);
	
	s.WhereAmI();  // Now I am in class Shape
	r.WhereAmI();  // Now I am in class Rect
	c.WhereAmI();  // Now I am in class Circle
	
	Shape* pShape = &s;
	Shape* pRect = &r;
	Shape* pCircle = &c;
	pShape->WhereAmI();  // Now I am in class Shape
	pRect->WhereAmI();   // Now I am in class Shape
	pCircle->WhereAmI(); // Now I am in class Shape
	
	Shape& rShape = s;
	Shape& rRect = r;
	Shape& rCircle = c;
	rShape.WhereAmI();  // Now I am in class Shape
	rRect.WhereAmI();   // Now I am in class Shape
	rCircle.WhereAmI(); // Now I am in class Shape

	}

	//4б) Добавьте в базовый и производные классы виртуальный
	// метод WhereAmIVirtual(). По аналогии с 4а вызовите
	// виртуальный метод посредством объектов, указателей и
	// ссылок, определенных в предыдущем фрагменте.
	//Выполните новый фрагмент, объясните разницу.
	
	s.WhereAmIVirtual();   // Now I am in class Shape (virtual)
	r.WhereAmIVirtual();   // Now I am in class Rect (virtual)
	c.WhereAmIVirtual();   // Now I am in class Circle (virtual)
	
	pShape->WhereAmIVirtual();  // Now I am in class Shape (virtual)
	pRect->WhereAmIVirtual();   // Now I am in class Rect (virtual)
	pCircle->WhereAmIVirtual(); // Now I am in class Circle (virtual)
	
	rShape.WhereAmIVirtual();  // Now I am in class Shape (virtual)
	rRect.WhereAmIVirtual();   // Now I am in class Rect (virtual)
	rCircle.WhereAmIVirtual(); // Now I am in class Circle (virtual)


//////////////////////////////////////////////////////////////////////

	//Задание 5.Виртуальные деструкторы.
	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.

	// b) Добавьте в объявление деструкторов ключевое слово virtual 
	//Выполните фрагмент.Объясните разницу.
	Shape s(RED);
	Rect r(GREEN);
	Circle c(BLUE);
	
	/*При выполнении кода будет вызван деструктор для каждого объекта, когда он выходит из области видимости. Однако, поскольку деструкторы не виртуальные, при удалении объектов через указатель на базовый класс (который может указывать на объект производного класса), вызывается только деструктор базового класса. В данном случае, деструкторы производных классов (Rect и Circle) не будут вызваны.
	
	Теперь, если мы добавим ключевое слово virtual к деструкторам базового класса и запустим фрагмент, то деструкторы производных классов будут вызваны правильно при удалении объектов через указатель на базовый класс.*/
	
	//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте

		Rect r(<параметры>);
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//Вызовите для каждого элемента массива метод WhereAmIVirtual()
		for (int i = 0; i < 4; ++i) {
			ar[i]->WhereAmIVirtual();
		}
		/*Вызывается конструктор Rect с параметрами <параметры>.
		
		Вызываются конструкторы для каждого элемента массива ar:
		
		new Shape(r) вызывает конструктор Shape с параметром r.
		new Rect(r) вызывает конструктор Rect с параметром r.
		new Circle(r) вызывает конструктор Circle с параметром r.
		new Circle() вызывает конструктор Circle без параметров.*/
		




	//Задание 6*. В чем заключается отличие 1) и 2)
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)
		/*
		В данном коде отличие между 1) и 2) связано с типами указателей и их влиянием на механизм вызова виртуальных функций и работу с массивами объектов.
		
		Shape* pShapes = new Rect[10]; - создает массив указателей на объекты типа Shape, но фактически указывает на первый элемент массива объектов типа Rect. Такое приведение типа называется "срезкой" (slicing). Это означает, что массив, созданный таким образом, содержит объекты типа Rect, но каждый из них рассматривается как Shape. Это может привести к проблемам при вызове виртуальных функций, так как вызывается метод из класса Shape, а не из производного класса Rect.
		
		Rect* pRects = new Rect[10]; - создает массив указателей на объекты типа Rect. В этом случае указатели указывают на объекты того же типа, что и указатель (Rect). Поэтому при вызове виртуальной функции метода WhereAmIVirtual() будет правильно вызываться соответствующий метод класса Rect.
		*/
		//Попробуйте вызвать метод WhereAmIVirtual() для каждого элемента обоих массивов -
		//в чем заключается проблема???
		/*Проблема возникает, когда вы пытаетесь вызвать виртуальную функцию для каждого элемента массива с использованием указателя типа Shape. Поскольку этот указатель видит только объекты типа Shape, он будет вызывать метод из Shape, даже если они фактически являются объектами типа Rect.
		
		Для правильного вызова виртуальных функций для объектов массива, созданного вариантом 1), вам нужно использовать указатель типа Rect или привести его к нужному типу перед вызовом виртуальной функции:*/
		
		for (int i = 0; i < 10; ++i) {
			dynamic_cast<Rect*>(pShapes[i])->WhereAmIVirtual();
		}



		//Освободите динамически захваченную память
		
		delete[] pShapes;
		delete[] pRects;

	}



//////////////////////////////////////////////////////////////////////

	//Задание 7.Виртуальные функции и оператор разрешения области видимости. 

	{
		Rect r(GREEN);
		Shape* p = &r;
		
		p->WhereAmIVirtual(); // Now I am in class Shape (virtual)
	
	
		
		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmIVirtual()класса Shape
		// Оператор разрешения области видимости для вызова WhereAmIVirtual() из класса Shape
		r.Shape::WhereAmIVirtual(); // Now I am in class Shape (virtual)
		
		
	}


//////////////////////////////////////////////////////////////////////

	//Задание 8.Чисто виртуальные функции. 
	//Введите в базовый класс метод void Inflate(int); Подумайте:
	//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
	//Реализуйте этот метод для производных классов.
	{
		Rect r;
		Shape* p = &r;
		p->Inflate(5);
		
		Circle c;
		p = &c;
		p->Inflate(5);
	}



//////////////////////////////////////////////////////////////////////
	//Задание 9. Создайте глобальную функцию, которая будет принимать любое
	//количество указателей на строки, а возвращать объект MyString,
	//в котором строка будет конкатенацией параметров
	
	const char* str1 = "Hello, ";
	const char* str2 = "world!";
	const char* str3 = " How are you?";
	
	MyString result = MyString(str1) + MyString(str2) + MyString(str3);
	
	std::cout << result << std::endl;
	
////////////////////////////////////////////////////////////////////////

	//Задание 10.Объединения (union) C++. Битовые поля.
	//1.
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;

	Bytes byte(0x1F);
	byte.ShowHex();
	std::cout << std::endl;
	byte.ShowBin();
	std::cout << std::endl;
	byte.ShowDec();
	std::cout << std::endl;
	byte.ShowChar();
	std::cout << std::endl;
	
	byte.ShowHexPos(0);
	std::cout << std::endl;
	byte.ShowBinPos(2);
	std::cout << std::endl;
	
	byte.EditHex(1, 8);
	byte.ShowHex(); 
	std::cout << std::endl;




	return 0;
}//endmain
