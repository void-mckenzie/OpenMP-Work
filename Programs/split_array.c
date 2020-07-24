#include<omp.h>
#include<stdio.h>

long func(double x,double step)
{	
	int i;
	double sum=0.0,bub;
	int end=(x+1)*(1410065408/6);
	for(i=x*(1410065408/6);i<end;i++)
	{
		bub=(i+0.5)*step;
		sum=sum+(4.0/(1.0+bub*bub));
	}
	printf("%d %f ",i,sum);
	return(sum);
}

void main()
{ 

	int i;
	long num_steps=1410065408;
	double x,pi;
	double step = 1.0/(double)num_steps;
	omp_set_num_threads(6);
	printf("HELLO");
	double ans[6][8];
	double t1=omp_get_wtime();
	#pragma omp parallel
	{
	ans[omp_get_thread_num()][0]=func(omp_get_thread_num(),step);
	}
	pi=step*(ans[0][0]+ans[1][0]+ans[2][0]+ans[3][0]+ans[4][0]+ans[5][0]);
	printf("%f\n",step);
	printf("%f",pi);
	double t2= omp_get_wtime();
	printf("\n%f",t2-t1);
}