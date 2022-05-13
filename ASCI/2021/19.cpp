// Problem: Common elements

#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> solve(int[], int[], int[], int, int, int);
void printArray(string, int[], int);
void printArray(string, vector<int>, int);

int main()
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    cout << "INPUT(s):" << endl;
    printArray("A", A, n1);
    printArray("B", B, n2);
    printArray("C", C, n3);

    vector<int> ans = solve(A, B, C, n1, n2, n3);

    cout << "OUTPUT(s):" << endl;
    printArray("ans", ans, ans.size());

    return 0;
}

vector<int> solve(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> v(max(n1, max(n2, n3)));
    set<int> a(A, A + n1), b(B, B + n2), c(C, C + n3);

    auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
    v.resize(it - v.begin());

    set<int> tmp(v.begin(), v.end());
    it = set_intersection(tmp.begin(), tmp.end(), c.begin(), c.end(), v.begin());
    v.resize(it - v.begin());

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
