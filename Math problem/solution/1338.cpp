#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define uglyLength 1500

int facotrs[3] = {2,3,5};
int uglySize;
long uglys[uglyLength];
int counter[uglyLength];

void findUlgy(){
	for(int i =0;i < uglyLength;i++)
		counter[i] = 0;

	uglySize = 0;
	uglys[uglySize ++] = 1;
	int start = 0;
	long minVlaue,temp;
	int minIndex;
	while(uglySize < uglyLength){
		minVlaue = uglys[start] * facotrs[counter[start]];
		minIndex = start;
		for(int i =start;i < uglySize;i++){
			temp = uglys[i] * facotrs[counter[i]];
			if(temp < minVlaue){
				minVlaue = temp;
				minIndex = i;
			}
		}
		if(minVlaue != uglys[uglySize-1]){
			uglys[uglySize++] = minVlaue;
		}
		counter[minIndex] ++;
		if(counter[start] == 3)
			start ++;
	}
}

int main()
{
	findUlgy();
	int number;
	while(cin >> number){
		if(number == 0)
			break;
		cout << uglys[number-1] << endl;
	}
 	
	return 0;
}