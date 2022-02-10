#include "cgads/algorithm.h"

#include <stdio.h>

// int的字长
int world_length() {
  int i;
  unsigned int v = ~0;
  for (i = 1; (v = v >> 1) > 0; ++i)
    ;
  return i;
}

//#define N 100

// 2015北航,七题
void test7() {
  char s[100], *p = s, max;
  while (scanf("%c", p++) != EOF)
    ;
  max = *s;
  p = s;
  while (*p++ != '\0') {
    if (*p > max) max = *p;
  }
  printf("%d", max);
}
