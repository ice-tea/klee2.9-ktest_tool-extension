/*
 * First KLEE tutorial: testing two input
 */

#include <klee/klee.h>


typedef struct first{
	int a;
	int b;
	struct {int a; int b;} c;
} f;

int get_sign(f s) {
  if (s.a > s.b)
     return 0;
  
  if (s.a < s.b)
     return -1;
  if (s.c.a < s.c.b) 
     return 1;
  else
     return 2;
} 

int main() {
  f mystruct;
  klee_make_symbolic(&mystruct, sizeof(mystruct), "mystruct");
  //klee_make_symbolic(&(mystruct.a), sizeof(mystruct.a), "mystruct.a");
  //klee_make_symbolic(&(mystruct.b), sizeof(mystruct.b), "mystruct.b");
  //mystruct.a = klee_int("mystruct.a");
  //mystruct.b = klee_int("mystruct.b");
  return get_sign(mystruct);
}
