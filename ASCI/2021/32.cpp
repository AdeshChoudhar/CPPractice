// Problem: Three way partitioning

#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(vector<int> &, int, int);
void printArray(string, vector<int>, int);

int main()
{
    vector<int> v = {1, 2, 3, 3, 4};
    int a = 1, b = 2;

    cout << "INPUT(s):" << endl;
    printArray("arr", v, v.size());
    cout << "\t{a, b} = {" << a << ", " << b << "}" << endl;

    cout << "OUTPUT(s):" << endl;
    printArray("arr", v, v.size());

    return 0;
}

void solve(vector<int> &v, int a, int b)
{
    int low = 0, mid = 0, high = v.size() - 1;
    while (mid < v.size())
    {
        if (v[mid] < a)
        {
            swap(v[mid++], v[low++]);
            mid++;
            low++;
        }
        else if (v[mid] > b)
        {
            swap(v[mid], v[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
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
