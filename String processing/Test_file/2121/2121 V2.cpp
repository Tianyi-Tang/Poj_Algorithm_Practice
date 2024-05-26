#include <cstring>
#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

string result;
stack<string> opStack;

string stringToNum(string str){
	if(str == "negative")
		return "-";
	else if (str == "zero")
		return "0";
	else if (str == "one")
		return "1";
	else if (str == "two")
		return "2";
	else if (str == "three")
		return "3";
	else if (str == "four")
		return "4";
	else if (str == "five")
		return "5";
	else if (str == "six")
		return "6";
	else if (str == "seven")
		return "7";
	else if (str == "eight")
		return "8";
	else if (str == "nine")
		return "9";
	else if (str == "ten")
		return "01";
	else if (str == "eleven")
		return "11";
	else if (str == "twelve")
		return "21";
	else if (str == "thirteen")
		return "31";
	else if (str == "fourteen")
		return "41";
	else if (str == "fifteen")
		return "51";
	else if (str == "sixteen")
		return "61";
	else if (str == "seventeen")
		return "71";
	else if (str == "eighteen")
		return "81";
	else if (str == "nineteen")
		return "91";
	else if (str == "twenty")
		return "02";
	else if (str == "thirty")
		return "03";
	else if (str == "forty")
		return "04";
	else if (str == "fifty")
		return "05";
	else if (str == "sixty")
		return "06";
	else if (str == "seventy")
		return "07";
	else if (str == "eighty")
		return "08";
	else if (str == "ninety")
		return "09";
	else
		return "";
}

int main()
{
	string input,subStr,revResult;
	bool appearNum;
	int endIndex;

	while(getline(cin,input)){
		if(input == "")
			break;

		subStr = revResult = result = "";
		for(int i =0;i < input.length();i++){
			if(input[i] == ' '){
				opStack.push(subStr);
				subStr = "";
			}
			else
				subStr += input[i];

			if(i == input.length()-1)
				opStack.push(subStr);
		}

		appearNum = false;
		while(!opStack.empty()){
			subStr = opStack.top();
			if(subStr == "hundred" || subStr == "thousand" || subStr =="million"){

				if(subStr == "hundred"){
					if(result.length() < 3)
						endIndex = 2;
					else if(result.length() < 6)
						endIndex = 5;
					else
						endIndex = 8;
				}
				else if(subStr == "thousand")
					endIndex = 3;
				else if(subStr == "million")
					endIndex = 6;

				for(int i = result.length();i < endIndex;i++)
					result += '0';

				appearNum = false;
			}
			else{
				subStr = stringToNum(subStr);
				if(appearNum && subStr.length() == 2 && subStr[0] == '0')
					result += subStr[1];
				else{
					result += subStr;
				}
				appearNum = true;
			}

			opStack.pop();
		}

		for(int i = result.length() -1;i >=0;i--)
			revResult += result[i];

		cout << revResult << endl;

	}
	return 0;
}

