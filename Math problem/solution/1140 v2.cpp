#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int twoTime, fiveTime;

int GCD(int a, int b){
	int t;
	while(b){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int maxTwoOrFive(){
	if(twoTime > fiveTime)
		return twoTime;
	else
		return fiveTime;
}

int findTwoAndFiveFactor(int number){
	twoTime = 0;
	fiveTime = 0;
	while(number % 2 ==0){
		number = number / 2;
		twoTime ++;
	}

	while(number % 5 ==0){
		number = number / 5;
		fiveTime ++;
	} 

	return number;
}

int main()
{
	int numerator, denominator,temp,remainFactor,index;
	while(cin>> numerator){
		cin >> denominator;
		if(numerator == 0 && denominator ==0)
			break;
		temp = GCD(denominator,numerator);
		numerator = numerator / temp;
		denominator = denominator / temp;
		remainFactor = findTwoAndFiveFactor(denominator);
		cout << ".";
		if(remainFactor == 1){
			index = maxTwoOrFive();
			for(int i =0;i < index;i++){
				cout << (numerator * 10) / denominator;
				numerator = (numerator * 10) % denominator;
			}
			cout << endl;
			cout << "This expansion terminates." << endl;
		}
		else{
			index = 0;
			temp = 1;
			while(true){
				temp = (temp * 10) % remainFactor;
				index ++;
				if(temp ==1)
					break;
			}
			int maxVlaue = maxTwoOrFive();
			for(int i =0;i < index + maxVlaue;i++){
				cout << (numerator * 10 / denominator);
				numerator = (numerator * 10 )% denominator;
				if((i+2) % 50 == 0 && i != index -1)
					cout << endl;
			}
			cout << endl;
			cout << "The last " << index << " digits repeat forever." <<endl;

		}


	}

	return 0;
}