#include <vcl.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#pragma hdrstop
#pragma argsused
 
const int dim1=20;
const int dim2=40;
float **a,**a1;
int n;
//vvod matrici
int MatrIn()
{int i,j;
for (i=0;i<n;i++)
for (j=0;j<n;j++)
cin>>a[i][j];
}
//obraschenie matrici
int invMatr(float e)
{
         int i,j,k,n1;
         float f,f1;
         float matr[20][40];
         n1=2*n;
         for (int i=0;i<n;i++)
for (j=0;j<n1;j++)
if (j<n)
matr [i][j]=a[i][j];
else 
if (j==n+1)
matr[i][j]=1;
else
matr [i][j]=0;
         for (int i=0;i<n;i++)
         {k=i;
         f1=matr[i][j];
         while (fabs(f1)<e)
         {if (k<n)
         {
                   k++;
                   f1=matr[k][i];
         }
         else
         {
                   cout<<"matrica virojdena";
                   gatch();
         }
         for (j=i;j<n1;j++)
         {
                   f=matr[k][j];
                   matr[k][j]=matr[i][j];
                   matr[i][j]=f/f1;
         }
         for (k=0;k<n;k++)
                   if (k!=i)
                            for (j=n1-1;j>=i;j--)
                                      matr[k][j]=matr[k][j]-matr[i][j]*matr[k][j];
         }
         for (i=0;i<n;i++)
for (j=0;j<n;j++)
a[i][j]=matr[i][j+n];
         }
}
//vivod obratnoy matrici
int MatrOut()
{
         int i,j;
         for (i=0;i<n;i++)
for (j=0;j<n;j++)
cout<<a1[i][j]<<" ";
}
//glavnaya proga
void main()
{
         float e;
         cout<<"vvedite razm matrici";
         cin>>n;
         cout<<"vvedite cherez probel elementi metrici";
         a=new float*[n];
         MatrIn();
         a1=new float*[n];
         for (int i=0;i<n;i++)
                   a1[i]=new float[n];
         cout<<"vvedite tochnost' vichisleniya";
         cin>>e;
         InvMatr(e);
         cout<<"obratnaya matrica";
         MatrOut();
         getch();
}

