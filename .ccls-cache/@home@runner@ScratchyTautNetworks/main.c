#include <stdio.h>

int main() {
  int a;
  
  printf("Введите год\n");
  scanf("%d", &a);
  
  if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
    printf("год %d високосный", a);
  } else {
    printf("год %d не високосный", a);
  }
}