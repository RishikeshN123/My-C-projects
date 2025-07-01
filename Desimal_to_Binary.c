#include <stdio.h>
int main()
{
  int n;
  printf("Enter the number:");
  scanf("%d",&n);
  int q,r,i;
  int a[1024];
  q=n;
  i=0;
  while(q>0)
  {
   r=q%2;
   q=q/2;
   a[i]=r;
   i++;
  }
   printf("Binary Number:");
   for(int j=i-1;j>=0;j--)
     {
      printf("%d",a[j]);
     }
     printf("\n");
  return 0;
}