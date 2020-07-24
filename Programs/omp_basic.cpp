#include<stdio.h>
#include<vector>
#include<omp.h>
using namespace std;
int main()
{

omp_set_num_threads(4);
printf("\n4 threads are made to run.");
#pragma omp parallel
{
int id=omp_get_thread_num();
if(id==0)
printf("\nThis is thread %d. The master thread.",id);
else
printf("\nThis is thread %d. Not the master thread.",id);
}
printf("\nProgram is serialized again. Threads join together.");
return 0;
}