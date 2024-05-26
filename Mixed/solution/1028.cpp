#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

stack<string> backwardStack;
stack<string> forwardStack;

int main()
{
	string operation, webURL;
	backwardStack.push("http://www.acm.org/");
	while(cin >> operation){
		if(operation == "QUIT")
			break;
		else if(operation == "VISIT"){
			cin >> webURL;
			backwardStack.push(webURL);
			
			while(!forwardStack.empty())
				forwardStack.pop();
			cout << webURL << endl;
		}
		else if(operation == "BACK"){
			if(backwardStack.size() == 1)
				cout << "Ignored" << endl;
			else{
				forwardStack.push(backwardStack.top());
				backwardStack.pop();
				cout << backwardStack.top() << endl;
			}
		}
		else if(operation == "FORWARD"){
			if(forwardStack.empty())
				cout << "Ignored" << endl;
			else{
				backwardStack.push(forwardStack.top());
				forwardStack.pop();
				cout << backwardStack.top() << endl;
			}
		}

	}
	return 0;
}