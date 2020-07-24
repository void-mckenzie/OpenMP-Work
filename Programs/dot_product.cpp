#include<omp.h>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{

long n;
printf("\nEnter the vector length: ");
scanf("%lu",&n);

std::vector<int> v1(n,10);
std::vector<int> v2(n,20);
std::vector<int> v3;
long sum[4]={0,0,0,0};

#pragma omp parallel
{int id=omp_get_thread_num();
for(int i=id;i<n;i=i+4)
{
sum[id]+=(v1[i]*v2[i]);
}
}
printf("Dot product is : %d",(sum[0]+sum[1]+sum[2]+sum[3]));
return 0;
}
