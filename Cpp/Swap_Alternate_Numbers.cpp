#include <iostream>
using namespace std;

void alternate(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            // With Swap Function
            // swap(arr[i], arr[i+1]);

            // Without Swap Function
            int temp;
            temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
}

int printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int brr[5] = {11, 12, 13, 14, 15};

    alternate(arr, 6);
    alternate(brr, 5);

    printArray(arr, 6);
    printArray(brr, 5);

    return 0;
}