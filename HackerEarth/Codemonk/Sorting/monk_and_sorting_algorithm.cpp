#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000

void solve();
void mergeSort(int, int);
void merge(int, int, int);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}

vector<ll int> arr;
vector<ll int> res;
vector<ll int> ms1;
vector<ll int> ms2;

void solve()
{
    int N;
    cin >> N;

    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    res.resize(N);
    ms1.resize(N);
    ms2.resize(N);
    ll int mul = 1, mxm = *max_element(arr.begin(), arr.end());
    while (mxm != 0)
    {
        for (int i = 0; i < N; i++)
        {
            res[i] = (arr[i] / mul) % mod;
        }
        mergeSort(0, N - 1);
        for (int i = 0; i < N; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        mul *= mod;
        mxm /= mul;
    }
}

void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m + 1, r);
    }
}

void merge(int l, int m, int r)
{
    int i = l, j = m, k = l;
    while ((i < m) && (j <= r))
    {
        if (res[i] <= res[j])
        {
            ms2[k] = arr[i];
            ms1[k] = res[i];
            i += 1;
        }
        else
        {
            ms2[k] = arr[j];
            ms1[k] = res[j];
            j += 1;
        }
        k += 1;
    }
    while (i < m)
    {
        ms2[k] = arr[i];
        ms1[k] = res[i];
        i += 1;
        k += 1;
    }
    while (j <= r)
    {
        ms2[k] = arr[j];
        ms1[k] = res[j];
        j += 1;
        k += 1;
    }
    for (i = l; i <= r; i++)
    {
        res[i] = ms1[i];
        arr[i] = ms2[i];
    }
}
