#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool vowelAppear,accpect;
int counterVowel, counterConsonants;
char preLetter;

bool isVowel(char letter){
	if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
		return true;
	else
		return false;
}

int main()
{
	string password,result;
	while(cin >> password){
		if(password == "end")
			break;
		vowelAppear = false;
		accpect = true;
		counterConsonants = counterVowel = 0;
		preLetter = ' ';
		for(int i = password.length()-1;i >=0;i--){
			if(isVowel(password[i])){
				if(!vowelAppear)
					vowelAppear = true;
				counterConsonants = 0;
				counterVowel ++;
			}
			else{
				counterVowel = 0;
				counterConsonants ++;
			}

			if(counterConsonants == 3 || counterVowel == 3){
				accpect =false;
				break;
			}
			if(preLetter == password[i]){
				if(preLetter != 'e' && preLetter != 'o'){
					accpect = false;
					break;
				}
				
			}
			preLetter = password[i];
		}
		if(!vowelAppear)
			accpect = false;

		if(accpect)
			result = "acceptable.";
		else
			result = "not acceptable.";

		cout << "<" << password << "> is " << result << endl;

	}
	return 0;
}
