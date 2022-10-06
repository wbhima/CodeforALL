
#include<bits/stdc++.h>
using namespace std;

// Checking balanced parenthesis
bool check_balance_parenthesis(string exp)
{
	stack<char> st;
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
		st.push(exp[i]);
		else
		{
			if(st.empty())
			return false;
			if(exp[i]==')')
			{
				if(st.top()=='(')
				st.pop();
				else
				return false;
			}
			else if(exp[i]==']')
			{
				if(st.top()=='[')
				st.pop();
				else
				return false;
			}
			else if(exp[i]=='}')
			{
				if(st.top()=='{')
				st.pop();
				else
				return false;
			}
		}
	}
	return true;
}


int main() 
{
	//1.) Checing balanced parenthesis
	string exp1 = "[()]{}{[()()]()}", exp2 = "[(])";
	if(check_balance_parenthesis(exp2))
	cout<<"balanced\n\n";
	else
	cout<<"not balanced\n\n";
	
	
	return 0;
}
