#include <bits/stdc++.h>
using namespace std;

int ways(int n, int way[], int m, int &output)
{
    if (n == 0)
    {
        output += 1;
        return output;
    }
    else if (n < 0)
    {
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        ways(n - way[i], way, m, output);
    }
}

int countWays(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main()
{
    cout << "Enter the number where do you want to reach: ";
    int n;
    cin >> n;
    cout << "How many ways you can take a jump: ";
    int m;
    cin >> m;
    int way[m];
    cout << "Enter those ways: ";
    int output = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> way[i];
    }
    ways(n, way, m, output);
    cout << "There are " << output << " number of ways to solve the problem." << endl;
    cout << "There are " << countWays(n) << " number of ways to solve the problem.";
    return 0;
}