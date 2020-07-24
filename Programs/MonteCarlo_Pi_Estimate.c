#include<stdio.h>

#include<omp.h>

#include<stdlib.h>

#include<time.h>

int main()

{
long n,i,sq,circ;

i=sq=circ=0;
        
n=1000;
        
long x,y;

double xx,yy;	
srand(time(NULL));
	
#pragma omp parallel for private(xx,yy) schedule(auto)
 
for(i=1;i<n+1;i++)
        
{

xx = (double)(rand() % (n + 1)) / n; 
yy = (double)(rand() % (n + 1)) / n;           
if(xx*xx+yy*yy<=1)
			
{
			
#pragma omp critical                        
			
circ++;
			
}
        
}
        
printf("%f",(double)(4*circ)/(double)(n));

}
        

