/*
 * First KLEE tutorial: testing two input
 */

#include <klee/klee.h>


typedef struct first{
	int a;
	int b;
        struct first* c;
} f;

typedef struct complex{
	int a;
	f b;
	f* c;
struct complex* d;
} ff;
int get_sign(ff s) {
  if (s.a > s.b.a)
     return 0;
  
  if (s.a < s.b.a)
     return -1;
  else 
     return 1;
} 

int main() {
  ff mystruct;
  klee_make_symbolic(&mystruct, sizeof(mystruct), "mystruct");
  f mm;
   klee_make_symbolic(&mm, sizeof(mm), "mm");
  return get_sign(mystruct);
} 
