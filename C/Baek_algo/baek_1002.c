#include <stdio.h>

int main() {
  int num;
  int x1,y1,r1,x2,y2,r2;
  int d;

  scanf("%d",&num);

  for(int i =0; i<num;i++){
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);

    d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

    if(d==0){   // 원의 중심 같을 때
      if(r1==r2){
        printf("-1\n");
      } // 반지름 길이 같을 때
      else{printf("0\n");}  // 반지름 길이 다를 때
    }
    else{       // 원의 중심 다를 때
      if(d>(r1+r2)*(r1+r2)){printf("0\n");} // 밖에서 안 만날 때
      else if(d==(r1+r2)*(r1+r2)){printf("1\n");} // 외접 할 때
      else if(d<(r1+r2)*(r1+r2) && d>(r1-r2)*(r1-r2)){printf("2\n");} // 두 점에서 만날 때
      else if(d==(r1-r2)*(r1-r2)){printf("1\n");} //내접 할 때
      else if(d<(r1-r2)*(r1-r2)){printf("0\n");} // 안에서 안 만 날때
    }

  }
  return 0;
}
