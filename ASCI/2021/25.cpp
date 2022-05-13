// Problem: Find all elements that appear more than n / k times

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> solve(int[], int, int);
void printArray(string, int[], int);
void printArray(string, vector<int>, int);

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);
    cout << "\tn = " << n << endl;
    cout << "\tk = " << k << endl;

    vector<int> ans = solve(arr, n, k);

    cout << "OUTPUT(s):" << endl;
    printArray("ans", ans, ans.size());

    return 0;
}

vector<int> solve(int arr[], int n, int k)
{
    int x = n / k;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] += 1;
    }

    vector<int> v;
    for (auto i = mp.begin(), n = mp.end(); i != n; i++)
    {
        if ((*i).second > x)
        {
            v.push_back((*i).first);
        }
    }

    return v;
}

void printArray(string s, int arr[], int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;
}

void printArray(string s, vector<int> v, int n)
{
    cout << "\t" << s << " = { ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}" << endl;
}
