#ifndef COUNTER_H
#define COUNTER_H

#include <cstring>

// Класс Counter представляет собой умный указатель с подсчетом ссылок для строковых данных.
class Counter {
private:
    char* m_pStr;            // Указатель на строку данных
    int m_nOwners;           // Количество владельцев данного экземпляра
    Counter* pNext;          // Указатель на следующий экземпляр Counter в списке
    int* m_pRefCount;        // Указатель на счетчик ссылок для данной строки

    static Counter* m_pHead;             // Голова списка экземпляров Counter
    static unsigned int m_curCounters;   // Общее количество счетчиков

public:
    // Конструктор, создающий экземпляр Counter для переданной строки данных.
    Counter(const char* str);

    // Деструктор, освобождающий ресурсы, связанные с экземпляром Counter.
    ~Counter();

    // Увеличивает количество владельцев данного экземпляра Counter.
    void AddUser();

    // Уменьшает количество владельцев данного экземпляра Counter.
    void RemoveUser();

    // Статический метод для поиска экземпляра Counter по строке данных.
    static Counter* Find(const char* str);

    // Получает указатель на голову списка экземпляров Counter.
    static Counter* GetHead() { return m_pHead; }

    // Получает указатель на следующий экземпляр Counter в списке.
    Counter* GetNext() const { return pNext; }

    // Получает текущее количество активных счетчиков.
    static unsigned int GetCurCounters() { return m_curCounters; }

    // Получает строку данных, связанную с данным экземпляром Counter.
    char* GetString() const { return m_pStr; }

    // Получает количество владельцев данного экземпляра Counter.
    int GetOwners() const { return m_nOwners; }

    // Увеличивает количество владельцев данного экземпляра Counter на единицу.
    void IncrementOwners() { ++m_nOwners; }

    // Уменьшает количество владельцев данного экземпляра Counter на единицу.
    void DecrementOwners() { --m_nOwners; }
};

#endif
