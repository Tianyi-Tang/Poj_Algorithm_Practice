#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;

#define maxRefNum 1000

int appearToCorrt[maxRefNum] = {0}, orderRef[maxRefNum] = {0};
int referNum = 1;
string allReference[maxRefNum][4];

bool isBlank(string input){
	for(int i =0;i < input.length();i++){
		if(input[i] != ' ')
			return false;
	}
	return true;
}

int main()
{
	string input;
	int num,n;
	bool referAppear = false;

	while(getline(cin,input)){
		if(isBlank(input))
			continue;
		else if(input[0] == '['){
			num = input[1] - '0';
			n = 0;
			for(int i = 2;i < input.length();i++){
				if(input[i] != ']')
					num = num * 10 + input[i] - '0';
				else
					break;
			}
			
			while(true){
				allReference[num][n++] = input;
				getline(cin,input);
				if(isBlank(input))
					break;
			}
		}
		else{
			while(true){
				for(int i =0;i < input.length();i++){
					if(referAppear && input[i] == ']'){
						referAppear = false;
						if(appearToCorrt[num] == 0){
							cout << referNum;
							appearToCorrt[num] = referNum;
							orderRef[referNum++] = num; 
						}
						else
							cout << appearToCorrt[num];
					}
					else if(referAppear){
						num = num * 10 + input[i] - '0';
						continue;
					}
					else if(input[i] == '['){
						referAppear = true;
						num = 0;
					}
					cout << input[i];
				}
				getline(cin,input);
				if(isBlank(input))
					break;
			}
		}
	}

	int strlen;
	for(int i =1;i < maxRefNum;i++){
		num = orderRef[i];
		if(num !=0){
			strlen = allReference[num][0].length();
			n = allReference[num][0].find(']');
			cout << '[' << i;
			cout << allReference[num][0].substr(n,strlen);
			for(int i =1;i < 4;i++){
				if(allReference[num][0] != ""){
					cout << endl;
					cout << allReference[num][0];
				}
			}
			cout << endl;
		}
	}

	return 0;
}

