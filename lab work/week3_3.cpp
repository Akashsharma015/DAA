#include<iostream>
using namespace std;
void qsort(int ar[],int low,int high)
{
    if(low<high)
    {
   int pivot=ar[high];
   int i=low-1;
   int temp;
   for(int j=low;j<high;j++)
   {
       if(ar[j]<pivot)
       {
            i++;
           temp=ar[i];
           ar[i]=ar[j];
           ar[j]=temp;

       }
   }
     temp=ar[i+1];
           ar[i+1]=ar[high];
           ar[high]=temp;
   qsort(ar,low,i);
   qsort(ar,i+2,high);
    }
}
int main()
{
    int ar[10000];
    int t,co,com;
    cin>>t;
    for(int i=0;i<t;i++)
    {

        cin>>co;
        for(int j=0;j<co;j++)
        {
            cin>>ar[j];
        }
        qsort(ar,0,co-1);
        cout<<endl;

        com=0;
        for(int j=0;j<co-1;j++)
        {
            if(ar[j]==ar[j+1])
            {
                cout<<"YES"<<endl;
                com=1;
                break;
        }
        }
        if(com==0)
        cout<<"NO"<<endl;
    }
}
