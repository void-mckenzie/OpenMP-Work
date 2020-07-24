#include<omp.h>
#include<stdio.h>
void main()
{
long num_steps =1410065408;
int i;
static double pi,sum=0.0;
double step= 1.0/(double)num_steps;
double t1=omp_get_wtime();


#pragma omp parallel
{
double x;
#pragma omp for schedule(static,4) reduction(+:sum)

for(i=0;i<num_steps;i++)
{
x= (i+0.5)*step;
sum+=(4.0/(1.0+x*x));
}

}

pi=step*sum;
printf("%f",pi);
double t2= omp_get_wtime();
printf("\n%f",t2-t1);
}