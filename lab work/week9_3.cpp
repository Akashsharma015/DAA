#include <bits/stdc++.h>

#define ll long long
#define INF INT_MAX

using namespace std;

int prims(int **arr, int n)
{
    vector<bool> visited(n, false);
    vector<int> weight(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    int src = 0;
    weight[src] = 0;
    min_heap.push(make_pair(weight[src], src));
    while (!min_heap.empty())
    {
        int u = min_heap.top().second;
        min_heap.pop();
        if (!visited[u])
        {
            visited[u] = true;
            for (int v = 0; v < n; ++v)
            {
                if (!visited[v] && arr[u][v] != 0 && arr[u][v] < weight[v])
                {
                    weight[v] = arr[u][v];
                    min_heap.push(make_pair(weight[v], v));
                }
            }
        }
    }

    int sum = 0;
    for (auto i : weight)
        sum += i;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int **arr;
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
        arr[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    cout << "Minimum spanning weight : " << prims(arr, n);
    return 0;
}
