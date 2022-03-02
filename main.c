#include <stdio.h>

#define MAXSIZE 101 

void output (long int a[] ,long int b[] ,int count1 ,int count2){
  int count;
  if (count1 >= count2){
    count = count1;
  } else{
    count = count2;
  }
  printf("\n*********\n");
  for (int i = 0;i <= count;i++){
    if (a[i] != -1 && b[i] != -1)
      printf("* %2d %2d *\n",a[i],b[i]);
    if (a[i] != -1 && b[i] == -1)
      printf("* %2d    *\n",a[i]);
    if (a[i] == -1 && b[i] != -1)
      printf("*    %2d *\n",b[i]);
    if (a[i] == -1 && b[i] == -1){
      printf("*********\n\n");
      break;
    }
  }
}

void del (long int a[] ,long int b[] ,int count1 ,int count2,int c){
  printf("Введите номер элемента \n");
  int n;
  scanf("%d", &n);
  a[n-1] = -1;
  for (int i = 0 ;i <= count1 - 1 ;i++)
    if (a[i] == -1){
      int c = a[i];
      a[i] = a[i+1];
      a[i+1] = c;
    }
  count1--;
  if (c == 4)
    output(a ,b ,count1 ,count2);
  if(c == 5)
      output(b ,a ,count2 ,count1);    
}

void add (long int a[] ,long int b[] ,int count1 ,int count2, int c){
  printf("Введите элемент \n");
  long int b1;
  scanf("%d", &b1);
  count1++;
  a[count1-1] = b1;
  if (c == 2)
    output(a ,b ,count1 ,count2);
  if(c == 3)
      output(b ,a ,count2 ,count1);
}

int main(void){
  int count1 = 0 ,count2 = 0;
  long int a[MAXSIZE] ,b[MAXSIZE];
  for (int i=0;i<= MAXSIZE - 1;i++){
    a[i]=-1;
    b[i]=-1;
  }
  printf("Введите колличество любимых натуральных чисел %d\n ", MAXSIZE);
  scanf("%d", &count1);
  printf("Введите любимые натуральные числа %d \n", MAXSIZE);
  int i = 0;
  while (i <=count1-1){
    int c;
    printf("%d : ", i+1);
    scanf("%d", &c);
    if (c > 0){
      a[i] = c;
      i++;
    } else {
      printf("Вы ввели неподходящее значение\n");
    }  
  }
    printf("Введите любимые четные натуральные числа %d\n", MAXSIZE);
  scanf("%d", &count2);
  printf("Введите ваши любимые натуральные цифры\n");
  i = 0;
 while (i <=count2-1){
    int c;
    printf("%d : ", i+1);
    scanf("%d", &c);
    if (c > 0 && (c % 2 == 0)){
      b[i] = c;
      i++;
    } else {
      printf("Вы ввели неподходящее значение\n");
    }  
  }
  output(a,b,count1,count2);
  int c = 0;
  printf("Введите 1-для вывода 2 множеств,2-для добавления элемента в 1 множество,3-для добавления элемента в 2 множество,4-удаления элемента из 1 множества,5-удаления элемента из 2 множества,6-преращениявыполнения программы\n");
  while (c !=-1){
    scanf("%d",&c);
    if (c == 1){
      output(a,b,count1,count2);
    }
    if (c == 2){
      add(a,b,count1,count2,c);
      count1++;
    }
    if (c == 3){
      add(b,a,count2,count1,c);
      count2++;
    }
    if (c == 4){
      del(a,b,count1,count2,c);
      count1--;
    }
    if (c == 5){
      del(b,a,count2,count1,c);
      count2--;
    }
  }
  
}
