#include <bits/stdc++.h>

using namespace std;

int binarySearch(int a[], int l, int k)
{
    int b = 0, e = l - 1, no_of_comparison = 0;
    while (b <= e)
    {
        ++no_of_comparison;
        int mid = (b + e) / 2;
        if (a[mid] == k)
        {
            cout << "Present " << no_of_comparison << endl;
            return 1;
        }
        else if (a[mid] > k)
            e = mid - 1;
        else
            b = mid + 1;
    }
    cout << "Not Present " << no_of_comparison << endl;
    return 0;
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
        binarySearch(a, l, key);
    }
    return 0;
}
