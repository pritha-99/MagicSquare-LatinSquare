#include"square.h"
#include<iostream>
using namespace std;
bool checkMagicsqr(int n,int** arr)
{
int mcons=n*(n*n+1)/2;
int d1=0,d2=0;
int sum;
for(int i=0;i<n;i++)
{
 d1+=arr[i][i];
 d2+=arr[i][n-1-i];
}
if(d1!=mcons||d2!=mcons)
return 0;
for(int i=0;i<n;i++)
{
sum=0;
for(int j=0;j<n;j++)
{
 sum+=arr[i][j];
}
if(sum!=mcons)
return 0;
}

for(int j=0;j<n;j++)
{
sum=0;
for(int i=0;i<n;i++)
{
 sum+=arr[i][j];
}
if(sum!=mcons)
return 0;
}
return 1;
}

void createOddMagicsqr(int n)
{
int **a;
a=new int*[n];
for(int k=0;k<n;k++)
a[k]=new int[n];
for(int x=0;x<n;x++)
{
for(int y=0;y<n;y++)
{
a[x][y]=0;
}
}
int i=n/2,j=n-1;
for(int e=1;e<=n*n;)
{
 if(i==-1 && j==n)
 {j=n-2;
 i=0;
 }
 else
 {
 if(j==n)
 j=0;
 if(i==-1)
 i=n-1;
 }
 
 if(a[i][j])
 {i++;
 j=j-2;
 continue;
 }
 
 else
 
 a[i][j]=e++;
 i--;
 j++;
 
}
displayMagicSquare(a,n);
if(checkMagicsqr(n,a))
cout<<"It is a Magic square"<<endl;
else
cout<<"It is NOT a Magic square"<<endl;

}

void fillQuarter(int** mSquare, int firstRow, int lastRow, int firstCol, int lastCol, int num, int lastNum) {
    int i = firstRow;
    int j = (lastCol + firstCol) / 2;

    while (num <= lastNum) {
        if (i < firstRow && j >= lastCol) {
            i += 2;
            j -= 1;
        }
        if (j >= lastCol) {
            j = firstCol;
        }
        if (i < firstRow) {
            i = lastRow - 1;
        }
        if (mSquare[i][j] != 0) {
            i += 2;
            j -= 1;
            continue;
        } else {
            mSquare[i][j] = num++;
        }
        i -= 1;
        j += 1;
    }
}

void exchangeCell(int i, int j, int** magicSquare, int n) {
    int r = (n / 2) + i;
    int temp=magicSquare[i][j];
    magicSquare[i][j]=magicSquare[r][j];
    magicSquare[r][j]=temp;
}


void createSinglyEvenMsqr(int n) {
    int **mSquare;
    mSquare=new int*[n];
     for(int k=0;k<n;k++)
     mSquare[k]=new int[n];
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    mSquare[i][j]=0;
    }
    }
    fillQuarter(mSquare, 0, n / 2, 0, n / 2, 1, (n / 2) * (n / 2));
    fillQuarter(mSquare, n / 2, n, n / 2, n, ((n / 2) * (n / 2)) + 1, (n * n) / 2);
    fillQuarter(mSquare, 0, n / 2, n / 2, n, ((n * n) / 2 )+ 1, 3 * (n / 2) * (n / 2));
    fillQuarter(mSquare, n / 2, n, 0, n / 2, (3 * (n / 2) * (n / 2)) + 1, n * n);

    int shift = ((n / 2) - 1) / 2;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < shift; j++) {
            if (i == n / 4) {
                exchangeCell(i, j + shift, mSquare, n);
            } else {
                exchangeCell(i, j, mSquare, n);
            }
        }
    }
    if(n>6)
    {
    for (int i = 0; i < n / 2; i++) {
        for (int j = n-1;j>n-shift; j--) {
            exchangeCell(i, j, mSquare, n);
        }
    }
    }
    displayMagicSquare(mSquare,n);
    if(checkMagicsqr(n,mSquare))
    cout<<"It is a Magic square"<<endl;
else
cout<<"It is NOT a Magic square"<<endl;
}
void displayMagicSquare(int **mSquare, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mSquare[i][j] << "\t";
        }
        cout << endl;
    }
}

void createDoublyEvenMsqr(int n) {
    int** mSquare;
    mSquare=new int*[n];
    for(int k=0;k<n;k++)
     mSquare[k]=new int[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mSquare[i][j] = (n * i) + j + 1;
        }
    }

    for (int i = 0; i < n / 4; i++) {
        for (int j = 0; j < n / 4; j++) {
            mSquare[i][j] = (n * n + 1) - mSquare[i][j];
        }
    }

    for (int i = 0; i < n / 4; i++) {
        for (int j = 3 * (n / 4); j < n; j++) {
            mSquare[i][j] = (n * n + 1) - mSquare[i][j];
        }
    }

    for (int i = 3 * (n / 4); i < n; i++) {
        for (int j = 0; j < n / 4; j++) {
            mSquare[i][j] = (n * n + 1) - mSquare[i][j];
        }
    }

    for (int i = 3 * (n / 4); i < n; i++) {
        for (int j = 3 * (n / 4); j < n; j++) {
            mSquare[i][j] = (n * n + 1) - mSquare[i][j];
        }
    }

    for (int i = n / 4; i < 3 * (n / 4); i++) {
        for (int j = n / 4; j < 3 * (n / 4); j++) {
            mSquare[i][j] = (n * n + 1) - mSquare[i][j];
        }
    }
    displayMagicSquare(mSquare,n);
    if(checkMagicsqr(n,mSquare))
    cout<<"It is a Magic square"<<endl;
else
cout<<"It is NOT a Magic square"<<endl;
}



void createLatinsqr(int n)
{

int** arr;
arr=new int*[n];
for(int k=0;k<n;k++)
arr[k]=new int[n];
for(int i=0;i<n;i++)
{
int k=i+1;
for(int j=0;j<n;j++)
{
arr[i][j]=k++;
if(arr[i][j]==n){
k=1;}
} 
}
displayMagicSquare(arr,n);

}

