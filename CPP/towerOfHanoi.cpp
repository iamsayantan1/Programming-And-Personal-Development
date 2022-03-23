<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n < 1)
    {
        return 0;
    }
    return towerOfHanoi(n - 1) * 2 + 1;
}

void printSteps(int n, char s, char d, char h)
{
    if (n == 1)
    {
        cout << "Moving disk " << n << " from " << s << " to " << d << " ." << endl;
        return;
    }
    else if (n == 0)
    {
        return;
    }
    printSteps(n - 1, s, h, d);
    cout << "Moving disk " << n << " from " << s << " to " << d << " ." << endl;
    printSteps(n - 1, h, d, s);
}

int main()
{
    cout << "Tower of Hanoi problem" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter the number of disk: ";
    int n;
    cin >> n;
    cout << "Number of steps is: " << towerOfHanoi(n) << endl;
    printSteps(n, 'A', 'C', 'B');
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n < 1)
    {
        return 0;
    }
    return towerOfHanoi(n - 1) * 2 + 1;
}

void printSteps(int n, char s, char d, char h)
{
    if (n == 1)
    {
        cout << "Moving disk " << n << " from " << s << " to " << d << " ." << endl;
        return;
    }
    else if (n == 0)
    {
        return;
    }
    printSteps(n - 1, s, h, d);
    cout << "Moving disk " << n << " from " << s << " to " << d << " ." << endl;
    printSteps(n - 1, h, d, s);
}

int main()
{
    cout << "Tower of Hanoi problem" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter the number of disk: ";
    int n;
    cin >> n;
    cout << "Number of steps is: " << towerOfHanoi(n) << endl;
    printSteps(n, 'A', 'C', 'B');
    return 0;
>>>>>>> d430e7484d1a6fea6c0fcdb61b54cae3c9cd8776
}