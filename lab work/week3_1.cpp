#include<iostream>
using namespace std;
int main()
{
    int ar[10000];
    int t,co,r,key,com,shif;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        com=shif=0;
        cin>>co;
        for(int j=0;j<co;j++)
        {
            cin>>ar[j];
        }
        for(int k=1;k<co;k++)
        {
            key=ar[k];
            r=k-1;
            while(r>=0 &&ar[r]>key)
            {
                com++;
                shif++;
                ar[r+1]=ar[r];
                r--;
            }
            shif++;
            ar[r+1]=key;
        }
        for(int z=0;z<co;z++)
        cout<<ar[z]<<" ";
        cout<<endl;
        cout<<"comparisions  "<<com<<endl;
        cout<<"shifts  "<<shif<<endl;
    }
}

