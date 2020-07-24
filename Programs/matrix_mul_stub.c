int alg_matmul2D(int m, int n, int p, float** a, float** b, float** c)
{
   int i,j,k;
#pragma omp parallel shared(a,b,c) private(i,j,k) 
   {
#pragma omp for  schedule(static)
   for (i=0; i<m; i=i+1){
      for (j=0; j<n; j=j+1){
         a[i][j]=0.;
         for (k=0; k<p; k=k+1){
            a[i][j]=(a[i][j])+((b[i][k])*(c[k][j]));
         }
      }
   }
   }
   return 0;
}