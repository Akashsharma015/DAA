#include <bits/stdc++.h>

using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.second * 1.0 / a.first.first > b.first.second * 1.0 / b.first.first;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int V[n], W[n];
    for (int i = 0; i < n; ++i)
        cin >> W[i];
    for (int i = 0; i < n; ++i)
        cin >> V[i];
    vector<pair<pair<int, int>, int>> items;
    for (int i = 0; i < n; ++i)
        items.push_back(make_pair(make_pair(W[i], V[i]), i + 1));
    int k;
    cin >> k;
    sort(items.begin(), items.end(), compare);
    float max_profit = 0;
    vector<pair<int, int>> sack;
    for (int i = 0; i < n && k > 0; ++i)
    {
        int w = items[i].first.first, v = items[i].first.second, ind = items[i].second;
        if (w <= k)
        {
            k -= w;
            max_profit += v;
            sack.push_back(make_pair(ind, w));
        }
        else
        {
            max_profit += k * v * 1.0 / w;
            sack.push_back(make_pair(ind, k));
            k = 0;
        }
    }
    cout << "Maximum Value : " << max_profit << endl;
    cout << "item-weight" << endl;
    for (auto i : sack)
        cout << i.first << " " << i.second << endl;
}
