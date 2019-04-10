#include<stdio.h>

int main() {
  //https://www.acmicpc.net/problem/1003
  
  int T;
  int num;
  int fibo[41];
  fibo[0] = 0; fibo[1] = 1;

  for (int i = 0; i < 40; i++) {
    fibo[i+2] = fibo[i]+fibo[i+1];
  }
  scanf("%d", &T);

  for (int j = 0; j <T; j++) {
      scanf("%d",&num);
      if(num==0){
        printf("1 0\n");
      }
      else{printf("%d %d\n",fibo[num-1],fibo[num]);}
  }
  return 0;
}
