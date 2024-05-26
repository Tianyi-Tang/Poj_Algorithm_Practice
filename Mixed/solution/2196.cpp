#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void findDenSum(int number,int& decSum){
	decSum = 0;

	while(number >0){
		decSum += number % 10;
		number = number / 10;
	}
}

void findGiveSum(int number,int base,int& reusltSum){
	reusltSum = 0;
	int currentNum = 1;
	int index = 0;

	while(number > currentNum* (base-1)){
		currentNum *= base;
		index ++;
	}

	int digitalNum;
	for(int i = index;i >=0;i--){
		digitalNum = number / currentNum;
		number = number - digitalNum * currentNum;
		reusltSum += digitalNum;
		currentNum = currentNum / base;
	}


}

int main()
{
	int decSum,hexSum,duoSum;

	for(int i =2992;i < 10000;i++){
		findDenSum(i,decSum);
		findGiveSum(i,16,hexSum);
		if(decSum != hexSum)
			continue;
		findGiveSum(i,12,duoSum);
		if(decSum != duoSum)
			continue;
		else
			cout << i << endl;
	}


	return 0;
}