#include <stdio.h>
// https://www.acmicpc.net/problem/1924
int main(int argc, char const *argv[]) {

  int NumberOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  char DayOfWeek[7][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
  int month, day;

  scanf("%d %d",&month , &day);

  for(int i =0 ; i < month-1 ; i++){
    day += NumberOfMonth[i];
  }

  printf("%s", DayOfWeek[day%7]);

  return 0;
}
