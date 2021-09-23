#include "logic.h"
#include <stdio.h>

int main(void) {

  // setup your test cases here
  if (!is_palindrome("test", 4)) {
    printf("test is not a palindrome\n");
  } else {
    printf("test IS a palindrome\n");
  }
  if (!is_palindrome("abba", 4)) {
    printf("abba is not a palindrome\n");
  } else {
    printf("abba IS a palindrome\n");
  }
  if (!is_palindrome("girafarig", 9)) {
    printf("girafarig is not a palindrome\n");
  } else {
    printf("girafarig IS a palindrome\n");
  }
  if (!is_palindrome("gamermoment", 11)) {
    printf("gamermoment is not a palindrome\n");
  } else {
    printf("gamermoment IS a palindrome\n");
  }
}
