#include<bits/stdc++.h>
using namespace std;
void mark(int **G, int n, int k)
{
    for (int i = 0; i < n; ++i)
        if (G[i][k] == 1)
            G[i][k] = 2;
}

bool bipar(int **ar,int n)
{
    queue<int> q;
    q.push(0);
    int color[n]={1};
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(ar[u][u]==1)
        return false;
        int curcol=color[u]*-1;
        for(int i=0;i<n;i++)
        {
            if(ar[u][i]!=0)
            {
                if(color[i]==0)
                color[i]=curcol;
            else if (color[i] !=curcol)
            return false;
            if(ar[u][i]==1)
            {
                q.push(i);
                mark(ar,n,i);
            }
            }
        }
    }
    return true;
}
int main()
{
    int n,s,d;
    cin>>n;
    int **arr;
    arr=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    arr[i]=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    if(bipar(arr,n))
    cout<<"Bipartite";
    else
    cout<<"Not Bipartite";
}
