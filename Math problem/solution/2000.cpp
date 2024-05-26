#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int days;

int findTotalCoin(){
	int coins,currentDay,nextCoins;
	coins = 1;
	if(days == 1)
		return coins;

	currentDay = nextCoins = 1;
	
	while(days > currentDay + nextCoins){
		nextCoins++;
		currentDay += nextCoins;
		coins += nextCoins * nextCoins;
	}

	nextCoins ++;
	coins += (days - currentDay) * nextCoins;
	return coins;
}

int main()
{
	while(cin >> days){
		if(days == 0)
			break;
		cout << days << " ";
		cout << findTotalCoin() << endl;
	}
	return 0;
}