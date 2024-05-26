#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int numberTwo = 0;
int numberFive = 0;

int otherNumber[3];

void factorization(int number){
	while(number % 2 ==0){
		number = number /2;
		numberTwo ++;
	}

	while(number % 5 ==0){
		number = number / 5;
		numberFive ++;
	}

	number = number % 10;
	if(number == 3)
		otherNumber[0] ++;
	else if(number == 7)
		otherNumber[1] ++;
	else if (number == 9)
		otherNumber[2] ++;
}

int lastDigitalTwo(){
	if(numberTwo == 0)
		return 1;
	else{
		int number = numberTwo % 4;
		if(number == 0)
			return 6;
		else if(number == 1)
			return 2;
		else if(number == 2)
			return 4;
		else
			return 8;
	}
}

int lastDigitalThree(){
	if(otherNumber[0] == 0)
		return 1;
	else{
		int number = otherNumber[0] % 4;
		if(number == 0)
			return 1;
		else if(number == 1)
			return 3;
		else if(number == 2)
			return 9;
		else
			return 7;
	}
}

int lastDigitalSeven(){
	if(otherNumber[1] == 0)
		return 1;
	else{
		int number = otherNumber[1] % 4;
		if(number == 0)
			return 1;
		else if(number == 1)
			return 7;
		else if(number == 2)
			return 9;
		else
			return 3;
	}
}

int lastDigitalNine(){
	if(otherNumber[2] == 0)
		return 1;
	else{
		int number = otherNumber[2] % 2;
		if(number == 0)
			return 1;
		else
			return 9;
	}
}

int lastDigital(){
	numberTwo -= numberFive;
	int number = lastDigitalTwo() * lastDigitalThree() * lastDigitalSeven() * lastDigitalNine();
	return number % 10;
}

void empty(){

	for(int i=0;i < 3;i++)
		otherNumber[i] = 0;

	numberTwo = 0;
	numberFive = 0;
}

void print(int lastNumber, int inputNumber){
	printf("%5d", inputNumber);
	printf(" -> %d\n",lastNumber);

}

int main()
{
	int number;
	while(cin  >> number){
		empty();
		for(int i =1;i < number + 1;i++){
			factorization(i);
		}
		print(lastDigital(),number);
	}

}