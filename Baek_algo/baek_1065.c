#include <stdio.h>
// https://www.acmicpc.net/problem/1065
int main(int argc, char const *argv[]) {

  int number,count = 0;
  int a,b,c;

  scanf("%d", &number);

  for(int i = 1 ; i<=number ; i++){

    if(i > 0 && i < 100){count++;}
    else{
      a = i/100;
      b = (i/10) % 10;
      c= i % 10;
      if((b-a) == (c-b)){count++;}
    }
  }
  printf("%d",count);

  return 0;
}
