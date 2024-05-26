#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define maxCells 100

int cellSize;
int allCells[maxCells];



void playGame(){
	for(int i =0;i < cellSize;i++){
		if((i+1)%2 !=0)
			allCells[i] = true;
	}

	for(int i = 3;i <= cellSize;i++){
		for(int j = i;j <= cellSize;j+=i){
			allCells[j-1] = !allCells[j-1];
		}
	}
}

int main()
{
	int n,counter;
	cin >> n;
	for(int i =0;i < n;i++){
		counter = 0;
		cin >> cellSize;
		playGame();

		for(int j = 0;j < cellSize;j++){
			if(allCells[j])
				counter++;
		}
		cout << counter << endl;

		for(int j =0;j < cellSize;j++)
			allCells[j] = false;
	}

	return 0;
}