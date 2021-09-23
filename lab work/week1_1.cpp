#include <bits/stdc++.h>

using namespace std;

int linearSearch(int a[], int l, int k)
{
    int no_of_comparison = 0;
    for (int i = 0; i < l; ++i)
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
        int arr[l];
        for (int i = 0; i < l; ++i)
            cin >> arr[i];
        int key;
        cin >> key;
        linearSearch(arr, l, key);
    }
    return 0;
}
