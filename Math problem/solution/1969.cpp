#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int row,col;


void findNumber(int order){
	row = 1;
	col = 1;
	if(order == 1)
		return;

	int totoalNumber = 1;
	int nexNumber = 2;
	bool movingUp = true;

	while(order > totoalNumber + nexNumber){
		movingUp = !movingUp;
		totoalNumber += nexNumber;
		nexNumber ++;
		row++;
	}

	if(movingUp){
		col = order - totoalNumber;
		row -= order - totoalNumber -2; 
	}
	else{
		col = nexNumber - (order - totoalNumber -1);
		row = order - totoalNumber;
	}
}


int main()
{
	int number;
	while(cin >> number){
		findNumber(number);
		cout << "TERM " << number << " IS ";
		cout << col << "/" << row<< endl; 
	}	
	return 0;
}