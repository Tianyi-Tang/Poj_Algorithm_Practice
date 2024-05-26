#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define diceSide 6
#define maxDiceNum 10000

int diceNum;
int dices[maxDiceNum][diceSide];

int findOpsiteIndex(int order){
	if(order == 0)
		return 5;
	else if(order == 1)
		return 3;
	else if(order == 2)
		return 4;
	else if(order == 3)
		return 1;
	else if(order == 4)
		return 2;
	else 
		return 0;
}

int getMaxValue(int diceNum,int topOrder,int downOrder){
	int maxNum = 0;

	for(int i =0;i < diceSide;i++){
		if(i == topOrder || i == downOrder)
			continue;
		else if(dices[diceNum][i] > maxNum)
			maxNum = dices[diceNum][i];
	}
	return maxNum;
}

int main()
{
	int value,maxSum,sum,down,top,n;
	cin >> n;
	while(n){
		cin >> diceNum;
		for(int i =0;i < diceNum;i++){
			for(int j =0;j < diceSide;j ++){
				cin >> value;
				dices[i][j] = value;
			}
		}

		maxSum = 0;
		for(int i= 0;i < diceSide;i++){
			down = findOpsiteIndex(i);
			sum = getMaxValue(0,i,down);
			for(int j =1;j < diceNum;j++){
				for(top = 0;top < diceSide;top++){
					if(dices[j][top] == dices[j-1][down])
						break;
				}
				down = findOpsiteIndex(top);
				sum += getMaxValue(j,top,down);
			}
			if(maxSum < sum)
				maxSum = sum;
		}

		cout << maxSum << endl;	
		n --;
	}

	
	
	return 0;
}