#include <bits/stdc++.h>

using namespace std;

int NComparison, NInversion;

void mergeArr(int arr[], int l, int s, int h)
{
    int n = h - l + 1, temp[n], i = l, j = s + 1, k = 0, noi = 0;
    while (i <= s && j <= h)
    {
        NComparison++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            NInversion += s - i + 1;
        }
    }
    for (; i <= s; ++i, ++k)
        temp[k] = arr[i];
    for (; j <= h; ++j, ++k)
        temp[k] = arr[j];

    for (int i = l, j = 0; i <= h; ++i, j++)
        arr[i] = temp[j];
}

void mergeSort(int arr[], int l, int h)
{
    int noc = 0;
    if (l < h)
    {
        int splitInd = (l + h) / 2;
        mergeSort(arr, l, splitInd);
        mergeSort(arr, splitInd + 1, h);
        mergeArr(arr, l, splitInd, h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int no, p = 0;
    cin >> no;
    for (int f = 0; f < no; f++)
    {
        NComparison = NInversion = 0;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\ncomparisons = " << NComparison << endl;
        cout << "inversions = " << NInversion << endl;
    }

    return 0;
}
