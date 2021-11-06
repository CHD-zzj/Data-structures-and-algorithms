#include <stdio.h>
//常用的矩阵乘法 O（N三次方）
void matrixmultiply(matrix a,matrix b,matrix c,int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(j=0;j<n;j++)
            {
                c[i][j]=0.0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
    }
}
//一种低效的斐波那契数列算法
int Fib(int N)
{
  if(N<=1)
    return 1;
  else
    return Fib(N-1)+Fib(N-2);
}
//线性算法
int FIB(int N)
{
  int i,last,Nexttolast,answer;
  if(N<=1)
    return 1;
  last=Nexttolast=1;
  for(i=2;i<=N;i++)
  {
    answer=last+Nexttolast;
    Nexttolast=last;
    last=answer;
  }
  return answer;
}
