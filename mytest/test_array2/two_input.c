/*
 * First KLEE tutorial: testing two input
 */

#include <klee/klee.h>

int get_sign(int *arr) {
  if (arr[0] > arr[1]){
     if(arr[0]>arr[2])
       return 0;
     else
       return 2;
  }
  
  else{
    if (arr[1] > arr[2])
     return 1;
  else 
     return 2;
  }
}

int main() {
  int a[3];/*
  klee_make_symbolic(&a[0], sizeof(a[0]), "a[0]");
  klee_make_symbolic(&a[1], sizeof(a[1]), "a[1]");
  klee_make_symbolic(&a[2], sizeof(a[2]), "a[2]");*/
  a[0] = klee_int("a0");
  a[1] = klee_int("a1");
  a[2] = klee_int("a2");
  return get_sign(a);
}
