//Floyd Warshall Undirected Graph

#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

#define ll long long

ll **floydWarshall(ll **Graph, ll V)
{
    ll **result = (ll **)malloc(V * sizeof(ll *));
    for (ll i = 0; i < V; ++i)
        result[i] = (ll *)malloc(V * sizeof(ll));

    for (ll i = 0; i < V; ++i)
        for (ll j = 0; j < V; ++j)
            result[i][j] = Graph[i][j];

    for (ll i = 0; i < V; ++i)
        for (ll j = 0; j < V; ++j)
            for (ll k = 0; k < V; ++k)
                if (result[i][k] != INF && result[k][j] && result[i][j] > result[i][k] + result[k][j])
                    result[i][j] = result[i][k] + result[k][j];

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll V;
    cin >> V;

    ll **Graph = (ll **)malloc(V * sizeof(ll *));
    for (ll i = 0; i < V; ++i)
        Graph[i] = (ll *)malloc(V * sizeof(ll));

    for (ll i = 0; i < V; ++i)
        for (ll j = 0; j < V; ++j)
            if (i != j)
                Graph[i][j] = INF;
            else
                Graph[i][j] = 0;

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            ll x;
            cin >> x;
            if (i != j && x != 0)
                Graph[i][j] = x;
        }
    }

    ll **result = floydWarshall(Graph, V);

    cout << "Shortest Distance Matrix:" << endl;
    for (ll i = 0; i < V; ++i)
    {
        for (ll j = 0; j < V; ++j)
            if (result[i][j] != INF)
                cout << result[i][j] << "\t";
            else
                cout << "INF"
                     << "\t";
        cout << endl;
    }

    return 0;
}
