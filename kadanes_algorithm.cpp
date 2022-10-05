//Kadane's Algorithm to find maximum Sub-Array sum

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, sum = 0, maxSum = 0;
	cin >> n;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	for(int i=0; i<n; i++){
		sum += a[i];
		if(sum < 0)
			sum = 0;
		maxSum = max(sum, maxSum);
	}

	cout << maxSum << endl;

	return 0;
}