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