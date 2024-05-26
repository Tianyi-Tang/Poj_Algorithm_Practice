#include<cstring>
#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;

map<string, int> mapInventory;
string preValue;

void addCounterToString(int value,string& addStr){
	string str = "";
	while(value != 0){
		str += value % 10 + '0';
		value = value / 10;
	}

	for(int i = str.length()-1;i >= 0;i--)
		addStr += str[i];

}

void findInventory(string orginal,string& result){
	char num = '0';
	int counter,total,stringSize;
	result = "";

	total = 0;
	stringSize = orginal.length();
	for(int i = 0;i <= 9;i++){
		counter = 0;
		for(int j =0;j < stringSize;j++){
			if(orginal[j] == num)
				counter ++;
		}
		if(counter != 0){
			addCounterToString(counter,result);
			result += num;
			total += counter;
		}
		if(total == stringSize)
			break;
		num++;
	}
}

int main()
{
	string input,reArrageNum;
	bool getResult;

	while(cin >> input){
		if(input == "-1")
			break;

		getResult = false;
		findInventory(input,reArrageNum);
		if(input == reArrageNum){
			cout << input << " is self-inventorying" << endl;
			continue;
		}
		mapInventory[reArrageNum] = 1;
		preValue = reArrageNum;
		for(int i =2;i <= 15;i++){
			findInventory(preValue,reArrageNum);
			if(reArrageNum == preValue){
				cout << input << " is self-inventorying after " <<i-1<<" steps" << endl;
				getResult = true;
				break;
			}
			else if(mapInventory[reArrageNum] != 0){
				getResult = true;
				cout << input << " enters an inventory loop of length " <<i - mapInventory[reArrageNum]<< endl;
				break;
			}
			mapInventory[reArrageNum] = i;
			preValue = reArrageNum;
		}

		if(!getResult)
			cout << input << " can not be classified after 15 iterations" << endl;
		mapInventory.clear();
	}



	return 0;
}