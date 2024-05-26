#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

bool isMirror(char a){
	if(a == 'A' || a == 'H' || a == 'I' || a == 'M' || a == 'O' || a == 'T' || a == 'U' || a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == '8')
		return true;
	else
		return false;
}

bool isReverse(char a, char b){
	if(a == b)
		return isMirror(a);
	if(a < b)
		swap(a,b);

	if(a == 'E')
		return (b == '3');
	else if(a == 'L')
		return (b == 'J');
	else if(a == 'S')
		return (b == '2');
	else if(a == 'Z')
		return (b == '5');
	else
		return false;
}

void printResult(string str, string result){
	cout << str << " -- is " << result << "." << endl;
}


int main()
{
	string str;
	bool palindrome,mirror,palindromeMirror;
	int stringLength;

	while(cin >> str){
		stringLength = str.length();
		palindrome = true;

		for(int i = 0;i <= stringLength / 2 -1;i++){
			if(str[i] != str[stringLength -1 -i]){
				palindrome = false;
				break;
			}
		}

		if(palindrome){
			palindromeMirror = true;
			for(int i =0;i < stringLength;i++){
				if(!isMirror(str[i])){
					palindromeMirror = false;
					break;
				}
			}
			if(palindromeMirror)
				printResult(str,"a mirrored palindrome");
			else
				printResult(str,"a regular palindrome");
		}
		else{
			mirror = true;
			for(int i = 0;i <= stringLength / 2 -1;i++){
				if(!isReverse(str[i],str[stringLength -1 -i])){
					mirror = false;
					break;
				}
			}

			if(stringLength % 2 == 1 && !isMirror(str[stringLength/2]))
				mirror = false;

			if(mirror)
				printResult(str,"a mirrored string");
			else
				printResult(str,"not a palindrome");
		}
		cout << endl;
	}

	return 0;

}