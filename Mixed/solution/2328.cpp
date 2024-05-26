#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

const string higher = "too high";
const string lower =  "too low";


int main()
{
	int biggerValue, smallerValue,input;
	string respones;
	char c;

	biggerValue = 11;
	smallerValue = 0;
	while(true){
		cin >> input;
		if(input == 0)
			break;

		cin >> respones;
		while((c = getchar())!= '\n'){
			respones += c;
		}
		

		if(respones == higher && input < biggerValue)
			biggerValue = input;
		else if(respones == lower && input > smallerValue)
			smallerValue = input;
		else if (respones == "right on"){
			if(input < biggerValue && input > smallerValue)
				cout << "Stan may be honest" << endl;
			else
				cout << "Stan is dishonest" << endl;
			biggerValue = 11;
			smallerValue = 0;
		}

	}

	return 0;
}