#include "Node.h"

Node::Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {} // Определение конструктора класса Node, инициализирующего данные узла и указатели на следующий и предыдущий узлы списк
