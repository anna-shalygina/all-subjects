#include <iostream>      
#include <string>        
#include <algorithm>     
using namespace std;    

struct stack 
{
	char inf;           
	stack* next;        
};

void push(stack*& h, char x)
{
	stack* r = new stack;   
	r->inf = x;             
	r->next = h;            
	h = r;                  
}

char pop(stack*& h) 
{
	if (!h)
	{
		return '\0';
	}
	char i = h->inf;        
	stack* r = h;           
	h = h->next;            
	delete r;               
	return i;               
}


bool empty(stack* h) 
{
	return h == nullptr;    
}

char top(stack* h) 
{
	return h ? h->inf : '\0';   
}


int priority(char op) 
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
	return 0;
}

bool operators(char c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


bool operand(char c) 
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}


string prefix(const string& expression)
{
	string expr;
	for (char c : expression)
	{
		if (c != ' ')
		{
			expr += c;
		}
	}

	string revers = expr;
	reverse(revers.begin(), revers.end());

	for (char& c : revers)
	{
		if (c == '(')
		{
			c = ')';
		}
		else if (c == ')')
		{
			c = '(';
		}
	}

	stack* st = nullptr;
	string postfix = "";

	for (char c : revers)
	{
		if (operand(c))
		{
			postfix += c;
		}
		else if (c == '(')
		{
			push(st, c);
		}
		else if (c == ')')
		{
			while (!empty(st) && top(st) != '(')
			{
				postfix += pop(st);
			}
			if (!empty(st) && top(st) == '(')
			{
				pop(st);
			}
		}
		else if (operators(c))
		{
			while (!empty(st) && top(st) != '(' && priority(top(st)) > priority(c))
			{
				postfix += pop(st);
			}
			push(st, c);
		}
	}

	while (!empty(st))
	{
		postfix += pop(st);
	}

	string prefix = postfix;
	reverse(prefix.begin(), prefix.end());

	return prefix;
}
int main()
{
	string input;

	cout << "Input expression: ";
	getline(cin, input);

	cout << "Prefix form: " << prefix(input) << endl;

}