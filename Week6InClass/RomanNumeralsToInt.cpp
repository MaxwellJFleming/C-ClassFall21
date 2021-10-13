#include <iostream>
#include <string>

int RomanNumeralsToInt(std::string& input)
{
  int out = 0;
  char prev;
  
  for(int i = 0; i < input.length(); i++)
  {
    char n = input[i];
    
    if (prev == 'I' && n == 'V') {
      out += 3;
    } else if (prev == 'I' && n == 'X') {
      out += 8;
    } else if (prev == 'X' && n == 'C') {
      out += 80;
    } else if (prev == 'C' && n == 'M') {
      out += 800;
    } else if (prev == 'C' && n == 'D') {
      out += 300;
    } else if (n == 'M') {
      out += 1000;
    } else if (n == 'D') {
      out += 500;
    } else if (n == 'C') {
      out += 100;
    } else if (n == 'L') {
      out += 50;
    } else if (n == 'X') {
      out += 10;
    } else if (n == 'V') {
      out += 5;
    } else if (n == 'I') {
      out += 1;
    }
    
    prev = n;
  }
  
  return out;
}

int main()
{
  std::string test = "XVII";
  std::cout << RomanNumeralsToInt(test) << std::endl;

  std::string test1 = "XIV";
  std::cout << RomanNumeralsToInt(test1) << std::endl;

  std::string test2 = "IX";
  std::cout << RomanNumeralsToInt(test2) << std::endl;

  std::string test3 = "IV";
  std::cout << RomanNumeralsToInt(test3) << std::endl;

  std::string test4 = "MMMMCMXCIX";
  std::cout << RomanNumeralsToInt(test4) << std::endl;
}