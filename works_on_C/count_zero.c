#include <stdio.h>

int count_zero(int *arr, int len){
  int c = 0;
  for (int i=0; i<len; i++){
    if (arr[i]==0)
      c++;
  }
  return c;
}

int main(){
  int arr[]={2, 0, 6, 0, 0, 0, -3, 4};
  int len = sizeof(arr)/sizeof(*arr);
  printf("%d\n", count_zero(arr, len));
  return 0;
}
