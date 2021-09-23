#include <bits/stdc++.h>

using namespace std;

int linearSearch(int a[], int b, int e, int k)
{
    int no_of_comparison = 0;
    for (int i = b; i <= e; ++i)
    {
        ++no_of_comparison;
        if (a[i] == k)
        {
            cout << "Present " << no_of_comparison << endl;
            return 1;
        }
    }
    cout << "Not Present " << no_of_comparison << endl;
    return 0;
}

int exponentialSearch(int a[], int n, int key)
{
    if (a[0] == key)
    {
        cout << "Present 1" << endl;
        return 1;
    }
    int i = 1;
    while (i < n && a[i] < key)
        i *= 2;
    return linearSearch(a, i / 2, min(n - 1, i), key);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int z = 0; z < n; ++z)
    {
        int l;
        cin >> l;
        int a[l];
        for (int i = 0; i < l; ++i)
            cin >> a[i];
        int key;
        cin >> key;
        exponentialSearch(a, n, key);
    }
    return 0;
}
