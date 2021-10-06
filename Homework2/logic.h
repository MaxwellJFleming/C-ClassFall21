#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int a, b, c;
} Result;

int reverse(const int n);

int fibbonacci(const int n);

Result *pythagorean_triples(const int n);

#endif
