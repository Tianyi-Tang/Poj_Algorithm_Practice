#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define maxStudent 9

int maxValue, minValue,maxIndex,minIndex;
string studentNames[maxStudent];


void intial(){
	maxValue = maxIndex = minIndex = -1;
	minValue = 300;
}

int main()
{
	int studentNum,length,width,heigh,total;
	string name;
	while(cin >> studentNum){
		if(studentNum == -1)
			break;

		intial();
		for(int i =0;i < studentNum;i++){
			cin >> length >> width >> heigh >> name;
			total = length * width * heigh;
			studentNames[i] = name;

			if(total < minValue){
				minIndex = i;
				minValue = total;
			}
			if(total > maxValue){
				maxIndex = i;
				maxValue = total;
			}
		}

		cout << studentNames[maxIndex] << " took clay from " << studentNames[minIndex] << "." << endl;
	}
	return 0;
}