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

char findIfCar(char ** s){
  if(findC(*s,"one") == 1){
    *s += 3;
    return '1';
  }else if (findC(*s,"two") == 1){
    *s += 3;
    return '2';
  }else if (findC(*s,"three") == 1){
    *s += 5;
    return '3';
  }
  else if (findC(*s,"four") == 1){
    *s += 4;
    return '4';
  }
  else if (findC(*s,"five") == 1){
    *s += 4;
    return '5';
  }
  else if (findC(*s,"six") == 1){
    *s += 3;
    return '6';
  }
  else if (findC(*s,"seven") == 1){
    *s += 5;
    return '7';
  }
  else if (findC(*s,"eight") == 1){
    *s += 5;
    return '8';
  }
  else if (findC(*s,"nine") == 1){
    *s += 4;
    return '9';
  }
}

int main(void){
  FILE * f = fopen("1.txt", "r");
  if(f == NULL){
    fprintf(stderr,"error file \n");
    return 1;
  }
  char s[128]; 
  int sum = 0;
  char a;
  while (fscanf(f,"%s",s) != -1){
    char first = 0;
    char last = 0;
    for(int i = 0; s[i] != '\0'; i++){
      char *cc = s + i;
      if ('0' <= s[i] && '9' >= s[i]){
        if(first == 0){
          first = s[i];
        }else{
          last = s[i];
        }
      } else if ( a = findIfCar(&cc)) {
        if(first == 0){
          first = a;
        }else{
          last = a;
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