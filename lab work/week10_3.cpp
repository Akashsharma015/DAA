#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> s;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }
    sort(s.begin(), s.end());
    int s1 = s[0], s2 = 0;
    for (int i = 1; i < n; ++i)
    {
        s1 += s[i];
        s2 += s1;
    }
    cout << s2 << endl;
    return 0;
}
