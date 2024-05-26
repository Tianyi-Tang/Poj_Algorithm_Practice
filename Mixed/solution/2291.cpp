#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxRopesNum 1000

int ropes[maxRopesNum];
int ropesNum;


int main()
{
	int n,ropesValue,maxValue,length;
	cin >> n;
	while(n){
		maxValue = 0;
		cin >> ropesNum;
		for(int i =0;i < ropesNum;i++){
			cin >> ropesValue;
			ropes[i] = ropesValue;
		}

		sort(ropes,ropes+ ropesNum);
		length = 1;
		for(int i =ropesNum -1;i >= 0;i--){
			ropesValue = ropes[i] * length;
			length ++;
			if(ropesValue > maxValue)
				maxValue = ropesValue;
		}
		cout << maxValue << endl;
		n--;
	}
	return 0;
}
