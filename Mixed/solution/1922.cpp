#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;




int main()
{

	int n,minArriveTime,speed,startTime,currentValue;

	while(cin >> n){
		if(n ==0)
			break;

		minArriveTime = -1;
		for(int i =0;i < n;i++){
			cin >> speed >> startTime;
			if(startTime >= 0){
				currentValue = startTime + 16200 / speed;
				if(16200 % speed != 0)
					currentValue += 1;
				if(currentValue < minArriveTime || minArriveTime == -1)
					minArriveTime = currentValue;
			}
		}
		cout << minArriveTime << endl;
	}

	return 0;
}