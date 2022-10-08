#include <iostream>
#include <stack>
using namespace std;

// priority setter
int priority(char r) {
	if (r == '+' || r == '-')return 1;
	else if (r == '*' || r == '/')return 2;
	else if (r == '^')return 3;
	else return 0;
}

// infix to postfix function
string infix_to_postfix(string s)
{
	// using stl stack 
	stack<char>stk; string an;
	for (int i = 0; i < s.size(); ++i)
	{
		// operand condition
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )an += s[i];
		
		// open brackets condition
		else if (s[i] == '(')stk.push(s[i]);

		// close brackets condition
		else if (s[i] == ')') {
			for (; stk.top() != '(' && stk.size() != 0;) {
				an += stk.top(); stk.pop();
			}
			stk.pop();
		}
		
		// operators condition
		else {
		// condition for ^ 
			if (s[i] == '^' && stk.size() != 0 && stk.top() == '^')stk.push(s[i]);
			// condtion for all operators 
			else	{
				for (; stk.size() != 0 && priority(stk.top()) >= priority(s[i])  ;) {an += stk.top(); stk.pop();}
				stk.push(s[i]);
			}
		}
	}
	// poping rest value from stack
	for (; stk.size() > 0;) {an += stk.top(); stk.pop();}
	return an;
}


int main()
{
	
	// user inputs..
	string s,s1; cin >> s;

	s1 = infix_to_postfix(s);
	
	cout << "converted--> " << s1 << endl;


	return 0;
}
