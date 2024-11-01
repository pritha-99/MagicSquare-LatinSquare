#include<iostream>
#include"square.h"
using namespace std;
int main()
{
int n,ch;
int** a;
cout<<"Enter\n 1 for Generating Magic square\n 2 for Checking Magic square\n 3 for Generating Latin square\n Any other number to quit\n"<<endl;
cout<<"Enter your choice:";
cin>>ch;
cout<<"Enter the size:";
cin>>n;
switch(ch)
{
case 1:
if(n%2!=0)
createOddMagicsqr(n);
else
{
if(n%4!=0)
createSinglyEvenMsqr(n);
else
createDoublyEvenMsqr(n);
}
break;
case 2:
a=new int*[n];
for(int k=0;k<n;k++)
a[k]=new int[n];
cout<<"Enter only unique elements!!!\n\n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<"Enter the element("<<i<<","<<j<<"):";
cin>>a[i][j];
}
}
if(checkMagicsqr(n,a))
cout<<"Magic square"<<endl;
else
cout<<"Not a Magic square"<<endl;
break;
case 3:
createLatinsqr(n);
break;
default:cout<<"Invalid choice!!!!"<<endl;
break;
}
return 0;
}
