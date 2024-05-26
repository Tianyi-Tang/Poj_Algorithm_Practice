#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define mapLength 19

int gameMap[mapLength][mapLength];


bool winTheGame(int player,int x,int y){
	int counter,xCurrent,yCurrent;

	counter = 1;
	yCurrent = y+1;
	while(yCurrent < mapLength){
		if(gameMap[yCurrent][x] != player)
			break;
		yCurrent ++;
		counter ++;
	}

	if(counter == 5){
		if(y == 0)
			return true;
		else if(gameMap[y-1][x] != player)
			return true;
	}


	counter = 1;
	xCurrent = x +1;
	while(xCurrent < mapLength){
		if(gameMap[y][xCurrent] != player)
			break;
		xCurrent ++;
		counter ++;
	}

	if(counter == 5){
		if(x == 0)
			return true;
		else if(gameMap[y][x-1] != player)
			return true;
	}


	counter = 1;
	xCurrent = x +1;
	yCurrent = y +1;
	while(xCurrent < mapLength && yCurrent < mapLength){
		if(gameMap[yCurrent][xCurrent] != player )
			break;
		xCurrent ++;
		yCurrent ++;
		counter ++;
	}

	if(counter == 5){
		if(y == 0 || x == 0)
			return true;
		else if(gameMap[y-1][x-1] != player)
			return true;
	}
	
	counter = 1;
	xCurrent = x +1;
	yCurrent = y -1;
	while(xCurrent < mapLength && yCurrent >= 0){
		if(gameMap[yCurrent][xCurrent] != player)
			break;
		xCurrent ++;
		yCurrent --;
		counter ++;
	}


	if(counter == 5){
		if(y == mapLength || x == 0)
			return true;
		else if(gameMap[y+1][x-1] != player)
			return true;
		else
			return false;
	}
	else
		return false;

	
}


int main()
{
	int x,y,n,player,value;
	bool hasWinner;
	cin >> n;
	while(n){
		for(int i =0;i < mapLength;i++){
			for(int j =0;j < mapLength;j++){
				cin >> value;
				gameMap[i][j] = value;
			}	
		}

		hasWinner = false;
		for(y =0;y < mapLength;y++){
			for(x =0;x < mapLength;x++){
				player = gameMap[y][x];
				if(player != 0){
					hasWinner = winTheGame(player,x,y);
					if(hasWinner)
						break;
				}
			}
			if(hasWinner)
				break;
		}

		if(hasWinner){
			cout << player << endl;
			cout << y + 1 << " " << x + 1 << endl;
		}
		else
			cout << 0 << endl;

		n--;
	}

	return 0;
}

