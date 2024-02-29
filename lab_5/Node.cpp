#include "Node.h"

Node::Node() : pPrev(nullptr), pNext(nullptr) {}

Node::Node(const Circle& circle, Node* prevNode, Node* nextNode)
    : m_Data(circle), pPrev(prevNode), pNext(nextNode) {}

Node::~Node() {}
