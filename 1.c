#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  FILE * f = fopen("1.txt", "r");
  if(f == NULL){
    fprintf(stderr,"error file \n");
    return 1;
  }
  char s[128]; 
  int sum = 0;
  while (fscanf(f,"%s",s) != -1){
    char first = 0;
    char last = 0;
    for(int i = 0; s[i] != '\0'; i++){
      if ('0' <= s[i] && '9' >= s[i]){
        if(first == 0){
          first = s[i];
        }else{
          last = s[i];
        }
      }
    }
    char two[3];
    two[0] = first;
    if(last == 0){
      two[1] = first;
    } else {
      two[1] = last;
    }
    int a = atoi(two);
    sum += a;
  }
  printf("%d \n",sum);
  return 0;
}