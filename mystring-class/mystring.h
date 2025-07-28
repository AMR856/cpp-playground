#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

#define MAX_BUFF_SIZE 1024

class MyString
{
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    friend std::istream& operator>>(std::istream& is, MyString& s);
private:
    char *str;
public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();

    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);

    MyString operator-() const;
    bool operator!() const;
    MyString operator*(int times) const;
    MyString &operator*=(int times);

    MyString operator+(const MyString &rhs) const;
    MyString& operator+=(const MyString& rhs);
    MyString& operator++();
    MyString& operator++(int);
    bool operator==(const MyString &rhs) const;
    bool operator!=(const MyString& rhs) const;
    bool operator<(const MyString& rhs) const;
    bool operator>(const MyString& rhs) const;
    bool operator<=(const MyString& rhs) const;
    bool operator>=(const MyString& rhs) const;

    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif // _MYSTRING_H_
