#include<iostream>
using namespace std;
int main()
{
    int ar[10000];
    int mini,t,co,r,key,com,swa,temp;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        com=swa=0;
        cin>>co;
        for(int j=0;j<co;j++)
        {
            cin>>ar[j];
        }
        for(int k=0;k<co-1;k++)
        {
            mini=k;
            for(int h=k+1;h<co;h++)
            {
                com++;
                if(ar[h]<ar[mini])
                mini=h;
            }
            temp=ar[mini];
            ar[mini]=ar[k];
            ar[k]=temp;
            swa++;
        }
        for(int z=0;z<co;z++)
        cout<<ar[z]<<" ";
        cout<<endl;
        cout<<"comparisions  "<<com<<endl;
        cout<<"swaps  "<<swa<<endl;
}
}
