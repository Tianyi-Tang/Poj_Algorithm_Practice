#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define characetLen 26

int characeterNum[2][characetLen];

void charCounter(string input,int arrIndex){
	for(int i =0;i < input.length();i++)
		characeterNum[arrIndex][input[i] - 'A'] ++;
}

int main()
{

	string input;
	bool flage;
	while(cin >> input){
		if(input == "")
			break;

		memset(characeterNum[0],0,sizeof(characeterNum[0]));
		memset(characeterNum[1],0,sizeof(characeterNum[1]));

		charCounter(input,0);

		cin >> input;
		charCounter(input,1);

		sort(characeterNum[0],characeterNum[0]+characetLen);
		sort(characeterNum[1],characeterNum[1]+characetLen);

		flage = true;
		for(int i =0;i < characetLen;i++){
			if(characeterNum[0][i] != characeterNum[1][i]){
				flage = false;
				break;
			}
		}
		if(flage)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}