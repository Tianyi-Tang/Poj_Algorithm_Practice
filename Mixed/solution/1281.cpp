#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define maxNum 10000

int currentMax,displaySize,maxCost,minCost;
int allCost[maxNum];

void initalMaxAndMin(){
	maxCost = -1;
	minCost = maxNum +1;
}

void initalCostArray(){
	for(int i =0;i < currentMax;i++)
		allCost[i] = 0;
}

void findNextMin(){
	while(allCost[minCost-1] == 0 && minCost < maxCost)
		minCost ++;
}

void findNextMax(){
	while(allCost[maxCost-1] == 0 && maxCost > minCost)
		maxCost --;
}


int main()
{
	int displayNum[1000];
	int cost,counter,indexCounter,policies;

	while(cin >> currentMax){
		if(currentMax <= 0)
			break;
		cin >> displaySize;
		int displayNum[1000];
		int cost,counter,indexCounter,policies;
		string operation;

		for(int i =0;i < displaySize;i++){
			cin >> cost;
			displayNum[i] = cost;
		}
		sort(displayNum,displayNum + displaySize);

		initalMaxAndMin();
		initalCostArray();
		counter = indexCounter = 0;
		policies = 1;
		cin >> operation;

		while(operation != "e"){
			if(operation == "a"){
				cin >> cost;
				allCost[cost-1] ++;
				if(maxCost < cost)
					maxCost = cost;
				if(minCost > cost)
					minCost = cost;
			}
			else if(operation == "r"){
				if(maxCost == -1)
					cout << -1 << endl;
				else{
					counter ++;
					if(policies == 1){
						allCost[minCost-1] --;
						if(indexCounter < displaySize && counter == displayNum[indexCounter]){
							cout << minCost << endl;
							indexCounter ++;
						}
						if(allCost[minCost-1] == 0){
							if(minCost == maxCost)
								initalMaxAndMin();
							else
								findNextMin();
						}
					}
					else{
						allCost[maxCost-1] --;
						if(indexCounter < displaySize && counter == displayNum[indexCounter]){
							cout << maxCost << endl;
							indexCounter ++;
						}	
						if(allCost[maxCost-1] ==0){
							if(minCost == maxCost)
								initalMaxAndMin();
							else
								findNextMax();
						}
					}
				}
			}
			else if(operation == "p")
				cin >> policies;
			cin >> operation;
		}
		cout << endl;

	}

	return 0;
}