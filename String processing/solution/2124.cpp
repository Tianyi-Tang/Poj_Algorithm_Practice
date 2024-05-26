#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

#define characterLen 26
#define differentCha 32

map<char, int> charactMap;


int main()
{
	string input,answer;
	char a;
	bool upperCase;
	int charNum;



	while(getline(cin,input)){

		a = 'a';
		for(int i =0;i < input.length();i++){
			charactMap[a] = input[i];
			a ++;
		}


		getline(cin,input);
		for(int i =0;i < input.length();i++){
			a = input[i];
			if(a >= 65 && a <= 90){
				a += differentCha;
				upperCase = true;
			}
			else
				upperCase = false;

			if(charactMap[a] != 0){
				a = charactMap[a];
				if(upperCase)
					a -= differentCha;
			}
			answer += a;
		}
		cout << answer << endl;

		charactMap.clear();
	}
	return 0;
}