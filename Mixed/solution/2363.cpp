#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
	int blocksNum,heightNum,area,minSum,testCase;
	double result;

	cin >> testCase;
	while(testCase){
		cin >> blocksNum;

		minSum = -1;
		for(int i = 1;i <= blocksNum;i++){
			for(int j = 1;j <= blocksNum/i;j++){
				result = blocksNum / (i*j*1.0);
				heightNum = result;
				if(heightNum - result == 0)
					area = (i * j + i * heightNum+ j * heightNum) * 2;
				if(minSum == -1 || minSum > area)
					minSum = area;
			}
		}

		if(blocksNum == 0)
			minSum = 6;
		
		cout << minSum << endl;

		testCase --;
	}


	

	return 0;
}