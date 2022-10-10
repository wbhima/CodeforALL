// C++ program to illustrate the
// unordered_map::hash_function()

#include <bits/stdc++.h>
using namespace std;

int main()
{

	// declaration
	unordered_map<string, string> sample;

	// inserts key and elements
	sample.insert({ "Ankit", "MNNIT" });
	sample.insert({ "Ram", "MNNIT" });
	sample.insert({ "Manoj", "Trichy" });
	sample.insert({ "geeks", "geeks" });

	// use of hash_function
	unordered_map<string, string>::hasher fn
		= sample.hash_function();

	cout << fn("geeks") << endl;

	// print the key and elements

	cout << "Key and Elements: ";
	for (auto it = sample.begin(); it != sample.end(); it++) {
		cout << "\n{" << it->first << ":"
			<< it->second << "}, ";
	}
	return 0;
}
