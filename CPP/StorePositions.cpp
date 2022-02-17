#include <bits/stdc++.h>
using namespace std;

int printPositions(int a[], int n, int i, int key, vector<int> &positions)
{
    if (i == n)
    {
        return 0;
    }
    else if (a[i] == key)
    {
        positions.push_back(i);
    }
    printPositions(a, n, i + 1, key, positions);
}

int printPositions2(int a[], int n, int key, vector<int> &positions)
{
    if (n <= 0)
    {
        return -1;
    }
    else if (a[n - 1] == key)
    {
        positions.push_back(n - 1);
    }
    return printPositions2(a, n - 1, key, positions);
}

int main()
{
    cout << "Enter the length of the array: ";
    int n, key;
    cin >> n;
    cout << "Enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    cout << "Enter a key: ";
    cin >> key;
    vector<int> positions;
    printPositions(a, n, i, key, positions);
    // printPositions2(a, n, key);
    for (int i = 0; i < positions.size(); i++)
    {
        cout << positions[i] << " ";
    }
    return 0;
}