// Problem: Maximum and minimum of an array

#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int mini;
    int maxi;
} Pair;

Pair solve(int[], int);
void printArray(string, int[], int);

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "INPUT(s):" << endl;
    printArray("arr", arr, n);

    Pair mm = solve(arr, n);

    cout << "OUTPUT(s):" << endl;
    cout << "\tans = " << mm.mini << ", " << mm.maxi << endl;

    return 0;
}

Pair solve(int arr[], int n)
{
    Pair mm;
    int i;

    if (n % 2)
    {
        mm.mini = arr[0];
        mm.maxi = arr[0];
        i = 1;
    }
    else
    {
        mm.mini = arr[0] < arr[1] ? arr[0] : arr[1];
        mm.maxi = arr[0] > arr[1] ? arr[0] : arr[1];
        i = 2;
    }

    for (; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            mm.mini = arr[i] < mm.mini ? arr[i] : mm.mini;
            mm.maxi = arr[i + 1] > mm.maxi ? arr[i + 1] : mm.maxi;
        }
        else
        {
            mm.mini = arr[i + 1] < mm.mini ? arr[i + 1] : mm.mini;
            mm.maxi = arr[i] > mm.maxi ? arr[i] : mm.maxi;
        }
    }

    return mm;
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
