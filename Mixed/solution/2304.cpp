#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define degreePerNum 9
#define mustTurnDegree 1080


int main()
{
	int initalNum,firtNum,secNum,thirdNum,totalDegree;

	while(cin >> initalNum >> firtNum >> secNum >> thirdNum){

		if(initalNum == 0 && firtNum == 0 && secNum == 0 && thirdNum == 0)
			break;

		totalDegree = 0;
		if(initalNum >= firtNum)
			totalDegree = (initalNum - firtNum) * degreePerNum;
		else
			totalDegree = initalNum * degreePerNum + (40 - firtNum) * degreePerNum;

		if(firtNum <= secNum)
			totalDegree += (secNum - firtNum) * degreePerNum;
		else
			totalDegree += (40 -firtNum) * degreePerNum +secNum * degreePerNum;

		if(secNum >= thirdNum)
			totalDegree += (secNum - thirdNum) * degreePerNum;
		else
			totalDegree += secNum * degreePerNum + (40 - thirdNum) * degreePerNum;

		totalDegree += mustTurnDegree;

		cout << totalDegree << endl;

	}

	return 0;
}