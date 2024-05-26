#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 10000

int numSize,startIndex;
int allNum[N];
bool hasVisited[N];


void findRing(int startValue,int targetValue){
	int i;
	for(i = 0;i < numSize;i++){
		if(allNum[i] == targetValue){
			hasVisited[i] = true;
			break;
		}
	}
	
	if(startValue != i +1)
		findRing(startValue,i+1);
}

int hasNext(){
	for(int i =startIndex;i < numSize;i++){
		if(!hasVisited[i]){
			startIndex = i+1;
			hasVisited[i] = true;
			return i;
		}
	}
	return -1;
}



int main()
{
	int inputNum,index,counter,n;

	cin >> n;
	for(int j = 0;j < n;j++){
		
		cin >> numSize;
		for(int i =0;i < numSize;i++){
			cin >> inputNum;
			allNum[i] = inputNum;
			hasVisited[i] = false;
		}

		startIndex = 0;
		counter =0;
		index = hasNext();
		while(index != -1){
			if(allNum[index] != index +1)
				findRing(allNum[index],index+1);
			counter ++;
			index = hasNext();
		}

		cout << numSize - counter << endl;
	}


	return 0;
}