#include <stdio.h>

int find_quotient(int a, int b){
	int r = a;
    if (b == 0) 
      r = -1; // Деление на ноль
      
    int b_abs = (b < 0) ? -b : b;

    if (a >= 0) {
        while (r >= b_abs) {
            r -= b_abs;
        }
    } 
    
    else {
        while (r < 0) {
            r += b_abs;
        }
    }

    return r;
}

int main(){
  printf("%d\n", find_quotient(7, 4)); // 7=4*1+3
  printf("%d\n", find_quotient(7, -4)); // 7=-4*(-1)+3
  printf("%d\n", find_quotient(-7, 4)); // -7=4*(-2)+1
  printf("%d\n", find_quotient(-7, -4)); // -7=-4*2+1
  printf("%d\n", find_quotient(7, 0)); // -1, делить на 0 нельзя
  printf("%d\n", find_quotient(0, 4)); // 0=4*0+0
}
