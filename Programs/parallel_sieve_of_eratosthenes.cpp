#include<omp.h>
#include<stdio.h>
#include"iostream"
using namespace std;
int main()
{
int i,j;
unsigned long n;
cin>>n;
n=n+1;
int *arr = new int[n];
#pragma omp parallel for schedule(auto) lastprivate(i)
for(i=0;i<n+1;i++)
arr[i]=0;
printf("Created %d space",i-1);
long double t1=omp_get_wtime();
int x=2;
arr[0]=-1;
arr[1]=-1;
while(x*x<n)
{
	if(arr[x]!=-1)
	{
	int t=(n)/x;
	#pragma omp parallel for schedule(auto) firstprivate(t)
	for(i=x;i<=t;i=i+1)
	{arr[i*x]=-1;
	}
	}	
	x++;
}
long double t2=omp_get_wtime();
for(i=0;i<n;i++)
{if(arr[i]!=-1)
;//cout<<"\n"<<i;
}
cout<<"\n"<<t2-t1;
}

/*
while(x*x<n)
{
	if(arr[x]!=-1)
	{
	i=j=x;
	#pragma omp parallel firstprivate(j)
	while(i*(j+omp_get_thread_num()+1)<n)
	{
		arr[i*(j+omp_get_thread_num()+1)]=-1;
		j=j+1;
	}
	
	}
	
	x++;
}
*/