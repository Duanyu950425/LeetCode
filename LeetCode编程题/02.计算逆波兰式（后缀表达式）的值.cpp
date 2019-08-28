#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
	int evalRPN(vector<string> &tokens) 
	{
		if (tokens.size() == 0)
			return 0;
		stack<int> s;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				if (s.size() < 2)
					return 0;
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				if (tokens[i] == "+")
					s.push(num1 + num2);
				else if (tokens[i] == "-")
					s.push(num2 - num1);
				else if (tokens[i] == "*")
					s.push(num1 * num2);
				else
					s.push(num2 / num1);
			}
			else
			{
				s.push(stoi(tokens[i]));
			}
		}
		if (s.size() != 1)
			return 0;
		else
			return s.top();
	}
};

int main02()
{
	vector<string> tokens;
	while (1)
	{
		string input;
		cin >> input;
		tokens.push_back(input);
		char c = getchar();
		if (c == '\n')
			break;
	}
	Solution s;
	cout << s.evalRPN(tokens) << endl;

	return 0;
}