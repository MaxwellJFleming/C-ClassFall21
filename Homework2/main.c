#include "logic.h"
#include <stdio.h>

int main(void) {
  //reverse tests
  printf("Now testing integer reverses\n");
  int reverse_int = 123;
  printf("The reverse of %d is %d\n", reverse_int, reverse(reverse_int));

  reverse_int = 56789;
  printf("The reverse of %d is %d\n", reverse_int, reverse(reverse_int));

  reverse_int = 40001;
  printf("The reverse of %d is %d\n", reverse_int, reverse(reverse_int));

  //fib tests
  printf("Now testing fib\n");
  
  int fib = fibbonacci(0);
  printf("This should be 0: %d\n", fib);

  int fibb = fibbonacci(10);
  printf("This should be 55: %d\n", fibb);

  int fibc = fibbonacci(8);
  printf("This should be 21: %d\n", fibc);

  int fibd = fibbonacci(5);
  printf("This should be 5: %d\n", fibd);

  //pythagorean triplet test
  printf("Now testing pythagorean\n");
  
  Result *test = pythagorean_triples(50);
  printf("This should be 3, 4, 5: %d, %d, %d\n", test->a, test->b, test->c);
  free(test);
}
