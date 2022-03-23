#include <bits/stdc++.h>
using namespace std;

int SumOfTheArray(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n < 0)
    {
        cout << "Invalid";
    }
    return (SumOfTheArray(a, n - 1) + a[n - 1]);
}

int SumOfTheArray2(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n < 0)
    {
        cout << "Invalid";
    }
    return (SumOfTheArray2(a + 1, n - 1) + a[0]);
}

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;
    cout << "Enter the array: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Sum of the array(through 1st method) is : " << SumOfTheArray(a, n) << endl;
    cout << "Sum of the array(through 2nd method) is : " << SumOfTheArray2(a, n) << endl;
    return 0;
}