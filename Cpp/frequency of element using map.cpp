#include <bits/stdc++.h>

using namespace std;

int main()
{

	// array input
	
	cout << "size of array: ";
	int n; cin >> n;
	int arr[n];
	
	for (int i = 0; i < n; ++i)cin >> arr[i];


	// make map using stl
	map<int, int> m;
	// input array elements in map with increamenting there frequencies
	for (int i = 0; i < n; ++i)
	{
		// if element is not present in map m
		if (m.find(arr[i]) == m.end())m[arr[i]] = 1;
		// if element is present then increament its value
		else m[arr[i]]++;
	}
	// output whole map with there key(aka element) & its value(aka frequency)
 	cout << "Frequencies are-- \n";
	for (auto &it : m)	cout << it.first << "->" << it.second << endl;



	return 0;
}
