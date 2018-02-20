#include<stdio.h>
#include<string.h>


void replace(char * str){
  int len = strlen(str), space_counter = 0;
  for(int i = 0; i < len; i++){
    if(str[i] == ' '){
      space_counter++;
    }
  }
  int new_length = len + 2 * space_counter;
  str[new_length--] = '\0';
  for(int i = len - 1; i >= 0; i--){
    if(str[i] == ' '){
      str[new_length--] = '0';
      str[new_length--] = '2';
      str[new_length--] = '%';
    } else {
      str[new_length--] = str[i];
    }
  }
}


int main(){
  char str[] = " Igor Bragaia Yo";
  printf("%s\n", str);
  replace(str);
  printf("%s\n", str);
  return 0;
}
