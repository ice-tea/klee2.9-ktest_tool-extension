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
  int a[3];
  klee_make_symbolic(&a, sizeof(a), "a");
  return get_sign(a);
}
