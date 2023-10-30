#include<stdio.h>
void main()
{
  int n,a[50],temp;
  printf("enter no. of elements in array= ");
  scanf("%d",&n);

  printf("enter elements of array= ");
  for(int i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }

  //procedure for sorting by bubble sort
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n-1;j++)
      {
          if(a[j]>a[j+1])
          {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
          }
      } 
  }

  //print sorted array
  printf("After sorting \n");
  for(int i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }  
}
