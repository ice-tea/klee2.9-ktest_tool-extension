/*
 * First KLEE tutorial: testing two input
 */

#include <klee/klee.h>
typedef struct a{
   int a;
   int b;
}s;

int get_sign(s *arr) {
  if (arr[0].a > arr[1].a){
     if(arr[0].b>arr[1].b)
       return 0;
     else
       return 2;
  }
  
  else{
    if (arr[0].b > arr[1].b)
     return 1;
  else 
     return 2;
  }
}

int main() {
  s a[2];
  klee_make_symbolic(&a, sizeof(a), "a");
  return get_sign(a);
}
