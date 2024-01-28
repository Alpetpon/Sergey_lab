//Задание 6
#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* m_str;

public:
    MyString(const char* str);
    ~MyString();

    const char* GetString() const;
};

#endif 


//Задание 6а/6б

#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
private:
    char* m_str;
    
public:
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();
    const char* GetString() const;
    void SetNewString(const char* newStr);
    MyString& operator=(const MyString& other);
};

#endif 


