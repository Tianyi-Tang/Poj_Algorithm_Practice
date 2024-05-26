#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const string hexadecimal32 = "00100000";

string aEncryption, bEncryption,key;
char twoChar[2];

int covenrtCharToInt(char a){
	if(a >= '0' && a <= '9')
		return a - '0';
	else
		return a - 'A' + 10;
}

char covenrtIntToChar(int a){
	if(a <= 9)
		return a + '0';
	else
		return a - 10 + 'A';
}

void getPartKey(string partKey){
	int number,charValue,halfStringSize;
	string bi = partKey;
	halfStringSize = partKey.length() /2;

	for(int i =0;i < 2;i++){
		number = 1;
		charValue = 0;
		for(int j = halfStringSize -1;j >= 0;j--){
			if(bi[j+i*4] == '1')
				charValue += number;
			number *= 2;
		}
		key += covenrtIntToChar(charValue);
	}
}

void translateHexToBi(string& result){
	int value,start;
	result = "";

	for(int i = 0;i < 2;i++){
		start = 8;
		value = covenrtCharToInt(twoChar[i]);
		for(int j = 0;j < 4;j++){
			if(value >= start){
				value -= start;
				result += '1';
			}
			else
				result += '0';
			start >>= 1;
		}
	}
}

void findAnotherString(const string& a,const string &b, string& c){
	c = "";
	for(int i =0;i < a.length();i++){
		if(a[i] == b[i])
			c += '0';
		else
			c += '1'; 
	}
}



int main()
{
	int aIndex, bIndex;
	string partKey,encrypBinary,organlBinary;

	// cin >> aEncryption >> bEncryption;
	// aIndex = bIndex = 0;
	// key = "";

	// for(int i =0;i < 2;i++)
	// 	twoChar[i] = bEncryption[bIndex++];
	// translateHexToBi(encrypBinary);
	// findAnotherString(encrypBinary,hexadecimal32,partKey);
	// getPartKey(partKey);

	// cout << key << endl;


	while(cin >> aEncryption >> bEncryption){
		aIndex = bIndex = 0;
		key = "";
		for(int i =0;i < 2;i++)
			twoChar[i] = bEncryption[bIndex++];
		translateHexToBi(encrypBinary);
		findAnotherString(encrypBinary,hexadecimal32,partKey);
		getPartKey(partKey);

		while(bIndex < bEncryption.length()){
			for(int i =0;i < 2;i++)
				twoChar[i] = aEncryption[aIndex++];
			translateHexToBi(encrypBinary);
			findAnotherString(encrypBinary,partKey,organlBinary);

			for(int i =0;i < 2;i++)
				twoChar[i] = bEncryption[bIndex++];
			translateHexToBi(encrypBinary);
			findAnotherString(encrypBinary,organlBinary,partKey);
			getPartKey(partKey);
		}
		cout << key << endl;
	}
	return 0;
}