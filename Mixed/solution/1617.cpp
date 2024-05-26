#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define keywordLength 10

int keywordSize;
int orderList[keywordLength];



int main()
{
	int order,encryptionSize,addIndex,rowNum;
	char ch;
	string keyword,encryption,result;

	while(cin >> keyword){
		if(keyword == "THEEND")
			break;

		ch = 'A' -1;
		order = 0;
		result = "";

		cin >> encryption;
		keywordSize = keyword.length();
		encryptionSize = encryption.length();
		rowNum = encryptionSize / keywordSize;

		for(int i =0;i < 26;i++){
			ch += 1;
			for(int j =0;j < keywordSize;j++){
				if(keyword[j] == ch)
					orderList[j] = order ++;
			}
		}

		for(int i =0;i < rowNum;i++){
			for(int j = 0;j < keywordSize;j++){
				addIndex = orderList[j];
				result += encryption[addIndex * rowNum + i];
			}
		}
		cout << result << endl;
	}


	

	


	return 0;
}