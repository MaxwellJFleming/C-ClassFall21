#include "logic.h"
#include <stdio.h>

// Each method is worth 5 points

//1

//int reverse(const int n) {
  // Your job is to reverse an integer
  // sample input 123
  // sample output 321
  //return 0;
//}

//2
int i;

int fib(int a, int b, int target){
  int next = a + b;
  printf("%d\n", next);
  if (i == target){
    return next;
  } else {
    i++;
    fib(b, next, target);
  }
  return i;
}

int fibbonacci(const int n) {
  i = 2;
  return fib(1, 1, n);
}

//3

//Result *pythagorean_triples(const int n) {
  // calculate 3 integers a, b, c
  // such that a ^ 2 + b ^ 2 + c^ 2 = n
  // return the results as the provided struct
  // or NULL if there is no set
  //return NULL;
//}
