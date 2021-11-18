#include <bits/stdc++.h>

#define ll long long
#define INF INT_MAX

using namespace std;

ll SDKedge(ll **Graph, int V, int u, int v, int k)
{
    if (k <= 0)
        return INF;
    else if (k == 0)
    {
        if (u == v)
            return 0;
        else
            return INF;
    }
    else if (k == 1)
    {
        if (u != v)
            return Graph[u][v];
        else
            return INF;
    }

    ll ans = INF;
    for (int i = 0; i < V; ++i)
        if (i != u && i != v && Graph[u][i] != 0)
            ans = min(ans, Graph[u][i] + SDKedge(Graph, V, i, v, k - 1));
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int V;
    cin >> V;
    ll **Graph = (ll **)malloc(V * sizeof(ll *));
    for (int i = 0; i < V; ++i)
        Graph[i] = (ll *)malloc(V * sizeof(ll));
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> Graph[i][j];
    int u, v, k;
    cin >> u >> v >> k;

    ll ans = SDKedge(Graph, V, u - 1, v - 1, k);

    if (ans == INF)
        cout << "No Path of length K is available" << endl;
    else
        cout << "Weight of shortest path from (" << u << "," << v << ") with " << k << " edges : " << ans << endl;

    return 0;
}
