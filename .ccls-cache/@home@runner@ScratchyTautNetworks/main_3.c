#include <stdio.h>

int main(void) {
  int start; int stop;
  int N ;
  int find;
  int i;
  printf("Введите начало и конец диапозона : ");
  scanf("%d",&start);
  scanf("%d",&stop);
  
  if (start < stop){
    
  } else {
    printf("Вы ввели некоректные данные диапозона");
    return 1;
  }
  
  printf("Введите сколько чисел вам надо : ");
  scanf("%d",&N);
  
  if (1 <= N && N <= 200000000 ){
    
  } else {
    printf("Вы хотите слишком много/мало чисел");
    return 2;
  }
  
  int arr[N];
    
  int a = 0;
  srand(time(0));
  for (a ; a < N  ;a++){
    int digit;
    digit = (start + rand() % (stop - start + 1));
    arr[a] = digit;
    
  }

  printf("\n");
// Наводим порядок в массиве
  i = 0;
  int j;
  int temper_digit;
  for (i;i < N ; i++){
    j = 0;
    for (j;j < (N - 1); j++){
      if (arr[j+1] < arr[j]){
        temper_digit = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temper_digit;
      }
    }
    
  }

  a = 0;
  for (a;a < N ;a++){
    printf("%d ",arr[a]);   
  }
  printf("\n");

  
// Теперь массив упорядочен

// Определим сколько раз можно разделить массив на 2 части

  printf("\nВведите что вы хотите найти : ");
  scanf("%d",&find);

  int left = 0;
  int right = N ;
  

  while ((left + right) <= 4){
    N = right + left ;
    if (find > arr[N/2]){
      left = N/2 ;
    } else {
      if (find < arr[N/2]){
        right = N/2  ;
      } else {
        if (find == arr[N/2]){
          printf("Да число %d есть в массиве", find);
          return 3;
        }
      }
    } 
    
  }
  for (left ; left <= right; left++){
    if (arr[left] == find){
      printf("Да число %d есть в массиве", find);
      return 3;
    }
  }
  printf("Такого числа нет в массиве");


  printf("тут конец проги , чтобы не вылетала сразу тут будет считывание переменной");
  scanf("%d",&a);
  return 0;
}