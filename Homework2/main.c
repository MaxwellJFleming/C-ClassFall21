#include "logic.h"
#include <stdio.h>

int main(void) {
  int fib = fibbonacci(5);
  printf("This should be 5: %d\n", fib);

  int fibb = fibbonacci(10);
  printf("This should be 55: %d\n", fibb);

  int fibc = fibbonacci(8);
  printf("This should be 21: %d\n", fibc);
}
