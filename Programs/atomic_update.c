#include<omp.h>
#include<stdio.h>

long func(int x,long double step)
{	
	int i;
	double sum=0.0,bub;
	int end=(x+1)*(1410065408/6);
	for(i=x*(1410065408/6);i<end;i++)
	{
		bub=(i+0.5)*step;
		sum=sum+(4.0/(1.0+bub*bub));
	}
	printf("\n%d %f ",i,sum);
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
	double ans;
	double t1=omp_get_wtime();
	#pragma omp parallel
	{	
		int t;
		t=func(omp_get_thread_num(),step)*step;
		#pragma omp atomic
		pi+=t;
	}
	printf("%f\n",step);
	printf("%f",pi);
	double t2= omp_get_wtime();
	printf("\n%f",t2-t1);
}