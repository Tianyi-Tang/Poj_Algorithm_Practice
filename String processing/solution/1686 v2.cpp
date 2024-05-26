#include<cstring>
#include<iostream>
#include<cstdlib>
#include<stack>
#include<map>
#include<stdio.h>
using namespace std;

stack<char> operStack;
stack<int> reultStack;
map<char, int> variableMap;
string postfix;
int results[2];

void addCharToPostFix(char a){
	postfix += a;
	postfix += ' ';
}

bool isNumber(char a){
	if(a >= '0' && a <='9')
		return true;
	else
		return false;
}

bool isVariable(char c){
	if((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}

int priority(char a){
	if(a  == '*')
		return 2;
	else if(a == '+' || a == '-')
		return 1;
	else
		return -1;
}

int stringToInt(string num){
	int value = 0;
	for(int i =0;i < num.length();i++){
		value *= 10;
		value += num[i] - '0';
	}
	return value;
}

void translateToPostfix(string infix){
	char c;

	postfix = "";
	for(int i =0;i < infix.length();i++){
		c = infix[i];

		if(isVariable(c))
			addCharToPostFix(c);
		else if(isNumber(c)){
			if(i != infix.length() -1 && isNumber(infix[i+1])) // consider number have more than one digital, like 11
				postfix += c;
			else
				addCharToPostFix(c);
		}
		else if(c == '(')// it can be remove, but add it make the algorithm more readable
			operStack.push(c);
		else if(c == ')'){
			while(operStack.top() != '('){
				addCharToPostFix(operStack.top());
				operStack.pop();
			}
			operStack.pop();
		}
		else if(c != ' '){
			while(!operStack.empty() && priority(c) <= priority(operStack.top())){
				addCharToPostFix(operStack.top());
				operStack.pop();
			}
			operStack.push(c);
		}
	}

	while(!operStack.empty()){
		addCharToPostFix(operStack.top());
		operStack.pop();
	}
}

void findResult(int& reuslt){
	int value;
	char c;
	string str = "";

	reuslt = 0;
	for(int i =0;i < postfix.length();i++){
		if(postfix[i] != ' ')
			str += postfix[i];
		else{
			if(str.length() == 1){
				c = str[0];
				if(isVariable(c)){
					if(variableMap[c] == 0)
						variableMap[c] = rand() % 5000 + 1;
					reultStack.push(variableMap[c]);
				}
				else if(isNumber(c))
					reultStack.push(c - '0');
				else{
					value = reultStack.top();
					reultStack.pop();
					if(c == '+')
						value += reultStack.top();
					else if(c == '-'){
						value *= -1;
						value += reultStack.top();
					}
					else
						value *= reultStack.top();
					reultStack.pop();
					reultStack.push(value);
				}
			}
			else{
				value = stringToInt(str);
				reultStack.push(value);
			}
			str = "";
		}
	}
	reuslt = reultStack.top();
	reultStack.pop();
}


int main()
{
	int n;
	string infix;
	cin >> n;
	getchar();
	while(n){
		for(int i = 0;i < 2;i++){
			getline(cin,infix);
			translateToPostfix(infix);
			findResult(results[i]);
		}
		if(results[0] == results[1])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		n --;
	}

	return 0;
}