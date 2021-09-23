#include "logic.h"
#include <stdio.h>

bool is_palindrome(char *input, size_t length) {
    size_t a = 0;
    size_t b = length-1;
    while (true) {
      if (input[a] != input[b]){
        return false;
      } else if (a == b) {
        return true;
      } else if (a+1 == b) {
        return true;
      }
      a++;
      b--;
    }
  return false;
}
