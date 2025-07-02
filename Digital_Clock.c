#include <stdio.h>
#include <stdlib.h>
//for linex os
#include <unistd.h>
//for windows os use Sleep(1000) instead
//of sleep(1)
#include <windows.h>
#include <time.h>
//for boolien variables
#include <stdbool.h>
#include <stdio.h>
int main()
{
  bool Clock=true;
  time_t rawtime=0;
  struct tm *pT=NULL;
  while(Clock)
  {
    time(&rawtime);
    pT=localtime(&rawtime);
    system("clear");
    printf("\t Digital clock:\n");
    printf("\t %02d:%02d:%02d \n",pT->tm_hour,pT->tm_min,pT->tm_sec);
    sleep(1);
  }
  return 0;
}