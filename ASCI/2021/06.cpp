// Problem: Union and intersection of two arrays

#include <bits/stdc++.h>

using namespace std;

int solve(int[], int[], int, int);
void uniosizeofArrays(int[], int[], int, int);
void intersectiosizeofArrays(int[], int[], int, int);
void printArray(string, int[], int);
void printSet(string, set<int>);

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3, 4, 5};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << "INPUT(s):" << endl;
    printArray("A", a, n);
    printArray("B", b, m);

    int ans = solve(a, b, n, m);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << ans << endl;

    // uniosizeofArrays(a, b, n, m);
    // intersectiosizeofArrays(a, b, n, m);

    return 0;
}

int solve(int a[], int b[], int n, int m)
{
    vector<int> v;

    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;

    if (a[i] < b[j])
    {
        v.push_back(a[i++]);
    }
    else if (b[j] < a[i])
    {
        v.push_back(b[j++]);
    }
    else
    {
        v.push_back(a[i++]);
        j++;
    }

    while (i < n || j < m)
    {
        if (i == n && j < m)
        {
            if (b[j] != *(v.end() - 1))
            {
                v.push_back(b[j]);
            }
            j++;
        }
        else if (i < n && j == m)
        {
            if (a[i] != *(v.end() - 1))
            {
                v.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (a[i] < b[j])
            {
                if (a[i] != *(v.end() - 1))
                {
                    v.push_back(a[i]);
                }
                i++;
            }
            else if (b[j] < a[i])
            {
                if (b[j] != *(v.end() - 1))
                {
                    v.push_back(b[j]);
                }
                j++;
            }
            else
            {
                if (a[i] != *(v.end() - 1))
                {
                    v.push_back(a[i]);
                    j++;
                }
                i++;
            }
        }
    }

    return v.size();
}

void uniosizeofArrays(int a[], int b[], int n, int m)
{
    set<int> s = {};

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }

    printSet("Union", s);
}

void intersectiosizeofArrays(int a[], int b[], int n, int m)
{
    set<int> s = {};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; b[j] <= a[i]; j++)
        {
            if (b[j] == a[i])
            {
                s.insert(b[j]);
            }
        }
    }

    printSet("Intersection", s);
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

void printSet(string s, set<int> st)
{
    cout << "\t" << s << " = { ";
    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << "}" << endl;
}
