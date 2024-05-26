#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

map<int, int> numberIndex;

int newSixDigitalNumber(int inputNum){
	int newNum,sixDigNum,oneDigNum;

	sixDigNum = inputNum / 100000;
	oneDigNum = inputNum % 10;
	newNum = (inputNum - sixDigNum * 100000 - oneDigNum)/10;
	newNum = (newNum * newNum) % 1000000;

	return newNum;
}

int main()
{
	int inputNum,newNum,index,result;

	while(cin >> inputNum){
		numberIndex.clear();
		newNum = newSixDigitalNumber(inputNum);
		index = 1;
		result = 0;
		while(newNum != inputNum && result == 0){
			numberIndex[newNum] = index ++;
			newNum = newSixDigitalNumber(newNum);
			result = numberIndex[newNum];
		}
		cout << newNum << " " << index - result << " " << index << endl;
	}



	return 0;
}