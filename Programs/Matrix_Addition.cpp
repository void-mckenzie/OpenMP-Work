#include<omp.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
int m,n,p,i,j;
int d[100][100];
int c[100][100];
printf("Enter the value for M(No of rows)\n");
scanf("%d",&m);
printf("Enter the value for N(No of columns)\n");
scanf("%d",&n);
int a[100][100],b[100][100];
printf("Enter the values of matrix a row wise\n");
p=m*n;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
cin>>a[i][j];
}
printf("Matrix a:\n");

for(i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("Enter the values of matrix b row wise\n");
for(int i=0;i<m;i++)
{
for(j=0;j<n;j++)
cin>>b[i][j];
}
printf("Matrix b:\n");
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",b[i][j]);
}
printf("\n");
}
#pragma omp parallel
{
#pragma omp sections
{
#pragma omp section 
{

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
c[i][j]=a[i][j]+b[i][j];
}

}
#pragma omp section 
{

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
d[i][j]=a[i][j]-b[i][j];
}

}
}
}
printf("Addition:\n");
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",c[i][j]);
}
printf("\n");
}
printf("Subtraction:\n");
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",d[i][j]);
}
printf("\n");
}
return 0;
}