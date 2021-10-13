#include <iostream>
#include <string>

void foo();

void bar(std::string &s)
{
  std::cout << s << std::endl;
}

void foo()
{
  int i = 1;
  float f = 0.1;
  double d = 0.000001;
  std::string s = "hello world";
}

void func(){}

void func(int i){}

void func(int i = 10, float f = 0.1){}

enum EColor : uint8_t { Blue = 255, Black = 1, Green = 3, Red = 4 };

int main()
{
  std::string s = "bar";
  std::cout << "hello world" << std::endl;
  std::cerr << "hello world, but this time an error" << std::endl;
  bar(s);
}