#include "logic.h"
#include <stdio.h>

// Each method is worth 5 points

//1

int reverse(const int n) {
  // Your job is to reverse an integer
  // sample input 123
  // sample output 321
  int original_num = n;
  int reverse_num = 0;

  while (original_num > 0){
    reverse_num = (reverse_num * 10) + (original_num % 10);
    original_num = original_num / 10;
  }
  return reverse_num;
}

//2
int fib(int a, int b, int target, int i){
  int next = a + b;
  //printf("%d\n", next);
  if (i == target){
    return a;
  }
  i++;
  fib(b, next, target, i);
}

int fibbonacci(const int n) {
  return fib(0, 1, n, 0);
}

//3

Result *pythagorean_triples(const int n) {
  Result *r;
  r = malloc(sizeof(Result));
  r->a = 1;
  r->b = 1;
  r->c = 1;
  
  while (r->a < r->b)
  {
    while (r->b < r->c)
    {
      while (r->c < n)
      {
        if ((r->a ^ 2) + (r->b ^ 2) + (r->c ^ 2) == n && (r->a ^ 2) + (r->b ^ 2) == (r->c ^ 2))
        {
          return r;
        }
        r->c++;
      }
      r->b++;
    }
    r->a++;
  }
  return NULL;
}
