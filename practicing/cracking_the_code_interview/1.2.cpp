#include<stdio.h>
#include<string.h>


void reverse_cstyle_1(char * str){
  char tmp;
  int len = strlen(str);
  for(int i = 0; i < len / 2; i++){
    tmp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = tmp;
  }
}

void reverse_cstyle_2(char * str){
  char * end = str;
  char tmp;
  if(str){
    while(*end){
      end++;
    }
    end--;
    while(str < end){
      tmp = *str;
      *str++ = *end;
      *end-- = tmp;
    }
  }
}


int main(){
  char str1[] = "abcd";
  printf("%s\n", str1);
  reverse_cstyle_1(str1);
  printf("%s\n", str1);

  printf("------ \n");

  char str2[] = "abcd";
  printf("%s\n", str2);
  reverse_cstyle_2(str2);
  printf("%s\n", str2);

  return 0;
}
