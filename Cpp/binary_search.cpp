#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int> arr, int x) {
  int low = 0;
  int high = arr.size() - 1;
  while (high >= low) {
    int mid = (low + high - 1) / 2;

    // if the targeted value is matched
    if (arr[mid] == x) return mid;

    // if the targetd value is less than arr[mid]
    if (arr[mid] > x) high = mid - 1;

    // if the targetd value is less than arr[mid]
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  int n;
  cout << "enter the size\n";
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int z;
    cin >> z;
    arr.push_back(z);
  }
  int x;
  cout << "Enter the search value in the array\n";
  cin >> x;
  int ans = binary_search(arr, x);
  cout << "Element " << x << "is found at index " << (ans + 1);
  return 0;
}
