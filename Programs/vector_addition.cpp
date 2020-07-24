#include<omp.h>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
long n=1000000;
std::vector<int> v1(n,10);

std::vector<int> v2(n,20);

std::vector<int> v3(n);
double t1=omp_get_wtime();
#pragma omp parallel for schedule(static,4)
for(int i=0;i<n;i++)
{
v3[i]=v1[i]+v2[i];
}
double t2=omp_get_wtime();

printf("\n%f",t2-t1);
return 1;
}