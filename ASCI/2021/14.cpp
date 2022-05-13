// Problem: Merge intervals

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(vector<vector<int>>);
void printArray(string, vector<int>, int);

int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    cout << "INPUT(s):" << endl;
    cout << "\tintervals = { ";
    for (auto i = v.begin(); i < v.end(); i++)
    {
        printArray("", *i, i->size());
        cout << ", ";
    }
    cout << "}" << endl;

    vector<vector<int>> ans = solve(v);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = { ";
    for (auto i = ans.begin(); i < ans.end(); i++)
    {
        printArray("", *i, i->size());
        cout << ", ";
    }
    cout << "}" << endl;

    return 0;
}

struct cmp
{
    bool operator()(vector<int> a, vector<int> b) const
    {
        return a.at(0) < b.at(0);
    }
};

vector<vector<int>> solve(vector<vector<int>> v)
{
    sort(v.begin(), v.end(), cmp());

    vector<vector<int>> V;

    int start1, end1, start2, end2;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        start1 = (*i).at(0);
        end1 = (*i).at(1);

        for (auto j = i + 1; i != v.end() && j != v.end(); j++)
        {
            start2 = (*j).at(0);
            end2 = (*j).at(1);

            if (start2 > end1)
            {
                break;
            }
            else
            {
                end1 = max(end1, end2);
                i++;
            }
        }
        V.push_back({start1, end1});
    }

    return V;
}

void printArray(string s, vector<int> v, int n)
{
    cout << s << "{ ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ", ";
    }
    cout << "}";
}
