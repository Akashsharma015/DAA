#include <bits/stdc++.h>
#define INF INT_MAX
#define NIL -1
using namespace std;

void printParent(vector<int> &parent, int u)
{
    cout << u + 1 << " ";
    if (parent[u] >= 0)
        printParent(parent, parent[u]);
}

void bellmanFord(int **Graph, int V, int src)
{
    vector<int> weight(V, INF);
    vector<int> parent(V, NIL);
    weight[src] = 0;
    for (int k = 0; k < V - 1; ++k)
    {
        for (int u = 0; u < V; ++u)
        {
            for (int v = 0; v < V; ++v)
            {
                if (Graph[u][v] != 0)
                {
                    if (weight[u] != INF && weight[v] > weight[u] + Graph[u][v])
                    {
                        weight[v] = weight[u] + Graph[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
    }

    for (int i = 0; i < V; ++i)
    {
        printParent(parent, i);
        if (weight[i] == INF)
            cout << ": INF" << endl;
        else
            cout << ": " << weight[i] << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int V;
    cin >> V;
    int **Graph;
    Graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; ++i)
        Graph[i] = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> Graph[i][j];
    int src;
    cin >> src;
    bellmanFord(Graph, V, src - 1);
    return 0;
}
