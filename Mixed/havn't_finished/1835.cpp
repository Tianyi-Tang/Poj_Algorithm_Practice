#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int currentDirection,x,y,z;

void changeDirection (string operation){
	if(operation == "left"){
		if(currentDirection == 0 || currentDirection ==3)
			currentDirection = (currentDirection + 4) % 6;
		else if(currentDirection == 1 || currentDirection ==4)
			currentDirection = (currentDirection + 5) % 6;
		else
			currentDirection = 4;

	}
	else if(operation == "right"){
		if(currentDirection == 0 || currentDirection ==3)
			currentDirection = (currentDirection + 1) % 6;
		else if(currentDirection == 1 || currentDirection ==4)
			currentDirection = (currentDirection + 2) % 6;
		else
			currentDirection = 1;
	}
	else if(operation == "up"){
		if(currentDirection == 2 || currentDirection ==5)
			currentDirection = (currentDirection + 1) % 6;
		else
			currentDirection = 2;
	}
	else if(operation == "down"){
		if(currentDirection == 2 || currentDirection ==5)
			currentDirection = (currentDirection + 4) % 6;
		else
			currentDirection = 5;

	}
	else if(operation == "back"){
		currentDirection = (currentDirection + 3) % 6;
	}
}

void changePostion(int value){
	if(currentDirection == 0 || currentDirection ==3){
		if(currentDirection == 3)
			value *= -1;
		x += value;
	}
	else if(currentDirection == 1 || currentDirection ==4){
		if(currentDirection == 4)
			value *= -1;
		y += value;
	}
	else{
		if(currentDirection == 5)
			value *= -1;
		z += value;
	}
}


int main()
{
	int n,operationTime,moveValue;
	string operation;

	cin >> n;
	for(int i =0;i < n;i++){
		cin >> operationTime;
		currentDirection = 0;
		x = y = z= 0;
		for(int j = 0;j < operationTime;j++){
			cin >> operation >> moveValue;
			changeDirection(operation);
			changePostion(moveValue);
		}
		cout << x << " " << y << " " << z << " " << currentDirection << endl;
	}

	return 0;
}
