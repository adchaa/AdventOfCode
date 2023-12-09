#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

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

int isPossible(char * s){
  int red = 0 ,green = 0,blue = 0;
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
        red += n;
        s += 2;
      }else if (findC(s,"blue")){
        blue += n;
        s += 3;
      }else if (findC(s,"green")){
        green += n;
        s += 4;
      }
    }else if ( *s == ';' || *s == '\n' || *s == '\0'){
      if ( red > MAX_RED || blue > MAX_BLUE || green > MAX_GREEN ){
        return 0;
      }
      red = 0;
      blue = 0;
      green = 0;
    }
  }
  return 1;
}

int main(void){
  FILE * f = fopen("2.txt", "r");
  if(f == NULL){
    fprintf(stderr,"error file \n");
    return 1;
  }
  char * s; 
  size_t size = 128;
  s = (char *)malloc(size);
  char * init = s;
  int sum = 0;
  while (getline(&s,&size,f) != -1){
    //skip "GAME "
    s += 5;
    //get id
    char c_id[24];
    size_t c_id_i = 0;
    while (*s != ':'){
      c_id[c_id_i++] = *s++;
    }
    c_id[c_id_i] = '\0';
    int id = atoi(c_id);
    s++;
    if (isPossible(s)){
      sum += id;
    }
    s = init;
  }
  printf("sum is %d \n",sum);
}