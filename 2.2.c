#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int findC(char * s ,char * sub){
  while(1){
    if (*sub == 0){
      return 1;
    }
    if (*sub++ != *s++){
      return 0;
    }
  }
}

void getMinRequirementCube(char * s,int a[]){
  int red = 0 ,green = 0,blue = 0;
  int red_max = 0 ,green_max = 0,blue_max = 0;
  for(;*s != 0;s++){
    if('0'<=*s && *s <= '9'){
      char c_n[24];
      size_t c_n_i = 0;
      while ('0'<=*s && *s <= '9'){
        c_n[c_n_i++] = *s++;
      }
      c_n[c_n_i] = '\0';
      int n = atoi(c_n);
      while(!('a' <= *s && 'z' >= *s)){s++;}
      if (findC(s,"red")){
        red = n;
        s += 2;
      }else if (findC(s,"blue")){
        blue = n;
        s += 3;
      }else if (findC(s,"green")){
        green = n;
        s += 4;
      }
    }else if ( *s == ';' || *s == '\n' || *s == '\0'){
      if(red_max < red){
        red_max = red;
      }
      if(blue_max < blue){
        blue_max = blue;
      }
      if(green_max < green){
        green_max = green;
      }
    }
  }
  printf("%d , %d , %d \n",red_max,blue_max,green_max);
  a[0] = red_max;
  a[1] = blue_max;
  a[2] = green_max;
}

int main(void){
  FILE * f = fopen("2.txt", "r");
  if(f == NULL){
    fprintf(stderr,"error file \n");
    return 1;
  }
  char * s; 
  size_t size = 256;
  s = (char *)malloc(size);
  char * init = s;
  unsigned long sum = 0;
  int i = 0;
  while (getline(&s,&size,f) != -1){
    s[size] = '\0';
    i++;
    //skip "GAME "
    s += 5;
    while (*s++ != ':'){}
    s++;
    int a[3] = {0};
    getMinRequirementCube(s,a);
    sum += a[0] * a[1] * a[2];
    printf("%d sum : %lu \n", i,sum);
    s = init;
  }

  printf("sum is %lu \n",sum);
}