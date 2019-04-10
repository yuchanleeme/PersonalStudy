#include <stdio.h>

int main() {
  //https://www.acmicpc.net/problem/1004

  int T;
  int x1,y1,x2,y2;

  int n;
  int cx,cy,r;
  int count;
  int d1,d2;

  scanf("%d",&T);

  for (int i = 0; i < T; i++) {
    count=0;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    scanf("%d",&n);

    for (int j = 0; j <n; j++) {
      scanf("%d %d %d",&cx,&cy,&r);
      d1 = (x1-cx)*(x1-cx) + (y1-cy)*(y1-cy);
      d2 = (x2-cx)*(x2-cx) + (y2-cy)*(y2-cy);
      if(!((d1<r*r) && (d2<r*r) || (d1>r*r) && (d2>r*r))){
        count++;
      }
    }
    printf("%d\n",count);
  }
  return 0;
}
