#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s);
int main()
{
	string s;
	cin>>s;
	bool d = isValid(s);
	cout << d;
}

bool isValid(string s) {
	
	int n = s.length();
	if (n % 2 != 0)
	{
		return false;
	}
	stack<char> st;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(s[i]);
		}
		else
		{
			char d = st.top();
			if (st.empty())
			{
				return false;
			}
			if (s[i] == ')' && st.top() != '(')
			{
				return false;
			}
			if (s[i] == '}' && st.top() != '{')
			{
				return false;
			}
			if (s[i] == ']' && st.top() != '[')
			{
				return false;
			}
			st.pop();
		}
	}
	return st.empty();
}

