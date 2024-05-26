#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define humbleLength 5842

int factor[4] = {2,3,5,7};
int numberCounter[humbleLength];
int humbleSize;
unsigned int humbles[humbleLength];



void findAllHumble(){
	for(int i = 0;i < humbleLength;i++)
		numberCounter[i] = 0;
	
	humbleSize = 1;
	humbles[0] = 1;
	int start = 0;
	int index;
	unsigned int minValue,temp;
	while(humbleSize < humbleLength){
		minValue = humbles[start] * factor[numberCounter[start]];
		index = start;
		for(int i =start;i<humbleSize-1;i++){
			temp = humbles[i] * factor[numberCounter[i]];
			if(temp < minValue){
				minValue = temp;
				index = i;
			}
		}
		if(humbles[humbleSize-1] != minValue)
			humbles[humbleSize++] = minValue;
		numberCounter[index] ++;
		if(numberCounter[start] ==4)
			start++;
	}
}

void result(int number){
	cout << "The " << number;
	if(number % 10 == 1 && number % 100 != 11)
		cout << "st humble number is ";
	else if(number % 10 == 2 && number % 100 != 12)
		cout << "nd humble number is ";
	else if(number % 10 == 3 && number % 100 != 13)
		cout << "rd humble number is ";
	else
		cout << "th humble number is ";

	cout << humbles[number -1] << "." << endl;
}


int main()
{
	findAllHumble();
	int number;
	while(cin >> number){
		if(number == 0)
			break;
		result(number);
	}
	return 0;
}