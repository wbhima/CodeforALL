#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[10] = {5, -1, 6, 23, 789, 98, -9, -98, 89, 10};
    cout << "Enter any key value: " << endl;
    int key;
    cin >> key;

    bool found = linearSearch(arr, 10, key);

    if (found)
    {
        cout << "Key is Present" << endl;
    }
    else
    {
        cout << "Key is absent" << endl;
    }

    return 0;
}