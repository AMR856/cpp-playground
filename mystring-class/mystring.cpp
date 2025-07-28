#include "./mystring.h"
#include "mystring.h"


MyString::MyString(): str{nullptr} {
  this->str = new char[1];
  this->str[0] = '\0';
}

MyString::MyString(const char *s): str{nullptr} {
  if (s == nullptr){
    this->str = new char[1];
    this->str[0] = '\0';
  } else {
    this->str = new char[std::strlen(s) + 1];
    std::strcpy(this->str, s);
  }
} 

MyString::MyString(const MyString &source): str{nullptr} {
  this->str = new char[std::strlen(source.str) + 1];
  std::strcpy(this->str, source.str);
}

MyString::MyString(MyString &&source) : str{nullptr}{
  this->str = source.str;
  source.str = nullptr;
}

MyString::~MyString(){
  delete [] this->str;
}

MyString &MyString::operator=(const MyString &rhs) {
  if (this == &rhs) return *this;
  delete [] this->str;
  this->str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(this->str, rhs.str);
  return *this;
}

MyString &MyString::operator=(MyString &&rhs) {
  if (this == &rhs) return *this;
  delete [] this->str;
  this->str = rhs.str;
  rhs.str = nullptr;
  return *this;
}

bool MyString::operator!() const {
  return (std::strcmp(this->str, "\0") == 0);
}

MyString MyString::operator*(int times) const {
  char *buff = new char[std::strlen(this->str) * times + 1];
  std::strcpy(buff, this->str);
  for (int i = 1; i < times; i++) std::strcat(buff, this->str);
  MyString temp {buff};
  delete [] buff;
  return temp;
}

MyString &MyString::operator*=(int times){
  MyString::operator*(times);
  return *this;
}

MyString &MyString::operator++() {
  // pre-increment
  for (size_t i = 0; i < std::strlen(this->str); i++)
    this->str[i] = std::toupper(this->str[i]);
  return *this;
}

MyString &MyString::operator++(int) {
  // post-increment
  MyString *temp{this};
  MyString::operator++();
  return *temp;
}


MyString MyString::operator-() const {
  char *buff = new char[std::strlen(this->str) + 1];
  std::strcpy(buff, this->str);
  for (size_t i = 0; i < std::strlen(buff); i++)
    buff[i] = std::tolower(buff[i]);
  MyString temp {buff};
  delete [] buff;
  return temp;
}

MyString MyString::operator+(const MyString &rhs) const {
  char *buff = new char[std::strlen(this->str) + std::strlen(rhs.str) + 1];
  std::strcpy(buff, this->str);
  std::strcat(buff, rhs.str);
  MyString temp {buff};
  delete [] buff;
  return temp;
}


MyString &MyString::operator+=(const MyString &rhs) {
  *this = MyString::operator+(rhs);
  return *this;
}

bool MyString::operator==(const MyString &rhs) const {
  return (std::strcmp(this->str, rhs.str) == 0);
}

bool MyString::operator!=(const MyString &rhs) const {
  return (std::strcmp(this->str, rhs.str) != 0);;
}

bool MyString::operator<(const MyString &rhs) const {
  return (std::strcmp(this->str, rhs.str) < 0);;
}

bool MyString::operator>(const MyString &rhs) const {
  return (std::strcmp(this->str, rhs.str) > 0);;
}

bool MyString::operator>=(const MyString &rhs) const {
  return (std::strcmp(this->str, rhs.str) >= 0);;
}

bool MyString::operator<=(const MyString &rhs) const {
  return (std::strcmp(this->str, rhs.str) <= 0);;
}

int MyString::get_length() const {
  return std::strlen(this->str);
}

const char* MyString::get_str() const {
  return this->str;
}

void MyString::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

std::ostream &operator<<(std::ostream &os, const MyString &s) {
  os << s.str << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, MyString &s) {
  delete [] s.str;
  char *buff = new char[MAX_BUFF_SIZE];
  s.str = new char[MAX_BUFF_SIZE];
  is.getline(buff, MAX_BUFF_SIZE);
  strcpy(s.str, buff);
  delete buff;
  return is;
}
