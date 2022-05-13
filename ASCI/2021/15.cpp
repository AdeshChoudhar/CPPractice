// Problem: Next permutation

#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &);
void printArray(string, vector<int>, int);

int main()
{
    vector<int> v = {1, 2, 3};

    cout << "INPUT(s):" << endl;
    printArray("arr", v, v.size());

    solve(v);

    cout << "OUTPUT(s):" << endl;
    printArray("arr", v, v.size());

    return 0;
}

void solve(vector<int> &v)
{
    int i, length = v.size();
    for (i = length - 2; i >= 0 && v[i] >= v[i + 1]; i--)
    {
        // NOTHING
    }

    if (i < 0)
    {
        sort(v.begin(), v.end());
    }
    else
    {
        int index = -1, l = i + 1, r = length - 1, key = v[i];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (v[mid] <= key)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
                if (index == -1 || v[index] >= v[mid])
                {
                    index = mid;
                }
            }
        }

        int tmp = v[i];
        v[i] = v[index];
        v[index] = tmp;

        for (int l = i + 1, r = length - 1; l < r; l++, r--)
        {
            tmp = v[l];
            v[l] = v[r];
            v[r] = tmp;
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
