#include "List.h"

List::List() : head(nullptr), tail(nullptr), size(0) {} // Конструктор класса List, инициализирующий указатели на начало и конец списка, а также размер списка

void List::addToTail(const Circle& circle) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(circle); // Создание нового узла списка с помощью умного указателя
    if (tail == nullptr) { // Если список пуст
        head = newNode; // Устанавливаем новый узел как начало списка
        tail = newNode; // и как конец списка
    } else { // Если список не пуст
        tail->next = newNode; // Устанавливаем указатель следующего узла текущего последнего узла на новый узел
        newNode->prev = tail; // Устанавливаем указатель предыдущего узла нового узла на текущий последний узел
        tail = newNode; // Устанавливаем новый узел как новый последний узел списка
    }
    size++; // Увеличиваем размер списка
}

void List::addToHead(const Circle& circle) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(circle); // Создание нового узла списка с помощью умного указателя
    if (head == nullptr) { // Если список пуст
        head = newNode; // Устанавливаем новый узел как начало списка
        tail = newNode; // и как конец списка
    } else { // Если список не пуст
        newNode->next = head; // Устанавливаем указатель следующего узла нового узла на текущее начало списка
        head->prev = newNode; // Устанавливаем указатель предыдущего узла текущего начала списка на новый узел
        head = newNode; // Устанавливаем новый узел как новое начало списка
    }
    size++; // Увеличиваем размер списка
}

void List::remove(const Circle& circle) {
    std::shared_ptr<Node> current = head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        if (current->data == circle) { // Если данные текущего узла равны целевому кругу
            if (current == head) { // Если текущий узел - это начало списка
                head = current->next; // Устанавливаем новое начало списка на следующий узел
                if (head != nullptr)
                    head->prev.reset(); // Обнуляем указатель на предыдущий узел нового начала списка
            } else if (current == tail) { // Если текущий узел - это конец списка
                tail = current->prev; // Устанавливаем новый конец списка на предыдущий узел
                if (tail != nullptr)
                    tail->next.reset(); // Обнуляем указатель на следующий узел нового конца списка
            } else { // Если текущий узел находится где-то в середине списка
                current->prev->next = current->next; // Устанавливаем указатель на следующий узел от предыдущего узла текущего узла на следующий узел от текущего узла
                current->next->prev = current->prev; // Устанавливаем указатель на предыдущий узел от следующего узла текущего узла на предыдущий узел от текущего узла
            }
            size--; // Уменьшаем размер списка
            break; // Прерываем цикл
        }
        current = current->next; // Переходим к следующему узлу списка
    }
}

void List::removeAll(const Circle& circle) {
    std::shared_ptr<Node> current = head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        if (current->data == circle) { // Если данные текущего узла равны целевому кругу
            if (current == head) { // Если текущий узел - это начало списка
                head = current->next; // Устанавливаем новое начало списка на следующий узел
                if (head != nullptr)
                    head->prev.reset(); // Обнуляем указатель на предыдущий узел нового начала списка
            } else if (current == tail) { // Если текущий узел - это конец списка
                tail = current->prev; // Устанавливаем новый конец списка на предыдущий узел
                if (tail != nullptr)
                    tail->next.reset(); // Обнуляем указатель на следующий узел нового конца списка
            } else { // Если текущий узел находится где-то в середине списка
                current->prev->next = current->next; // Устанавливаем указатель на следующий узел от предыдущего узла текущего узла на следующий узел от текущего узла
                current->next->prev = current->prev; // Устанавливаем указатель на предыдущий узел от следующего узла текущего узла на предыдущий узел от текущего узла
            }
            size--; // Уменьшаем размер списка
        }
        current = current->next; // Переходим к следующему узлу списка
    }
}

void List::quickSort(std::vector<Circle>& arr, int low, int high) {
    if (low < high) { // Если индекс начала массива меньше индекса конца
        int pi = partition(arr, low, high); // Находим индекс опорного элемента после разбиения массива
        
        quickSort(arr, low, pi - 1); // Рекурсивно сортируем элементы меньше опорного элемента
        quickSort(arr, pi + 1, high); // Рекурсивно сортируем элементы больше опорного элемента
    }
}

int List::partition(std::vector<Circle>& arr, int low, int high) {
    Circle pivot = arr[high]; // Выбираем последний элемент массива как опорный элемент
    int i = low - 1; // Инициализируем индекс наименьшего элемента
    
    for (int j = low; j < high; j++) { // Проходим по всем элементам массива, кроме последнего (опорного элемента)
        if (arr[j].getRadius() <= pivot.getRadius()) { // Если текущий элемент меньше или равен опорному
            i++; // Увеличиваем индекс наименьшего элемента
            std::swap(arr[i], arr[j]); // Меняем местами текущий элемент и элемент с индексом наименьшего элемента
        }
    }
    std::swap(arr[i + 1], arr[high]); // Меняем местами опорный элемент и элемент, стоящий после наименьшего элемента
    return i + 1; // Возвращаем индекс опорного элемента
}

void List::sortList() {
    if (size <= 1) return; // Если размер списка меньше или равен 1, нет необходимости в сортировке
    std::vector<Circle> circles; // Создаем вектор для хранения элементов списка
    std::shared_ptr<Node> current = head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        circles.push_back(current->data); // Добавляем данные текущего узла в вектор
        current = current->next; // Переходим к следующему узлу списка
    }
    
    quickSort(circles, 0, circles.size() - 1); // Вызываем функцию быстрой сортировки для вектора
    
    current = head; // Устанавливаем указатель на текущий узел в начало списка
    for (const auto& circle : circles) { // Перебираем отсортированный вектор
        current->data = circle; // Заменяем данные текущего узла на данные из вектора
        current = current->next; // Переходим к следующему узлу списка
    }
}

List::List(const List& other) {
    std::shared_ptr<Node> current = other.head; // Устанавливаем указатель на текущий узел в начало списка other
    while (current != nullptr) { // Пока не достигнут конец списка
        addToTail(current->data); // Добавляем данные текущего узла в конец списка
        current = current->next; // Переходим к следующему узлу списка other
    }
}

List& List::operator=(const List& other) {
    if (this != &other) { // Проверка на самоприсваивание
        head.reset(); // Освобождаем память, занимаемую текущим списком
        tail.reset();
        size = 0;

        std::shared_ptr<Node> current = other.head; // Устанавливаем указатель на текущий узел в начало списка other
        while (current != nullptr) { // Пока не достигнут конец списка
            addToTail(current->data); // Добавляем данные текущего узла в конец списка
            current = current->next; // Переходим к следующему узлу списка other
        }
    }
    return *this; // Возвращаем ссылку на текущий объект класса List
}

List::List(List&& other) noexcept {
    head = std::move(other.head); // Перемещаем указатель на начало списка из other в текущий объект
    tail = std::move(other.tail); // Перемещаем указатель на конец списка из other в текущий объект
    size = other.size; // Копируем размер списка из other в текущий объект

    other.head.reset(); // Обнуляем указатель на начало списка в other
    other.tail.reset(); // Обнуляем указатель на конец списка в other
    other.size = 0; // Обнуляем размер списка в other
}

List& List::operator=(List&& other) noexcept {
    if (this != &other) { // Проверка на самоприсваивание
        head = std::move(other.head); // Перемещаем указатель на начало списка из other в текущий объект
        tail = std::move(other.tail); // Перемещаем указатель на конец списка из other в текущий объект
        size = other.size; // Копируем размер списка из other в текущий объект

        other.head.reset(); // Обнуляем указатель на начало списка в other
        other.tail.reset(); // Обнуляем указатель на конец списка в other
        other.size = 0; // Обнуляем размер списка в other
    }
    return *this; // Возвращаем ссылку на текущий объект класса List
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    std::shared_ptr<Node> current = list.head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        os << current->data << " "; // Выводим данные текущего узла в поток
        current = current->next; // Переходим к следующему узлу списка
    }
    os << std::endl; // Выводим символ новой строки в поток
    return os; // Возвращаем поток вывода
}

std::istream& operator>>(std::istream& is, List& list) {
    Circle circle(Point(0, 0), 0); // Создаем круг с нулевыми координатами и радиусом
    while (is >> circle) { // Пока можно считать данные для круга из потока
        list.addToTail(circle); // Добавляем считанный круг в конец списка
    }
    return is; // Возвращаем поток ввода
}
