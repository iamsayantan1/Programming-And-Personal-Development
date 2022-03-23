void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void selectionSort(int arr[], int n)
{
    int temp, loc;
    for (int i = 0; i < n - 1; i++)
    {

        loc = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[loc] > arr[j])
            {
                loc = j;
            }
        }
        if (loc != i)
        {
            swap(arr[i], arr[loc]);
        }
    }
}

int main()
{
    cout << "Enter how many numbers: ";
    int n = 0;
    cin >> n;
    cout << "Enter the numbers: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    cout << "\n"
         << "After sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}