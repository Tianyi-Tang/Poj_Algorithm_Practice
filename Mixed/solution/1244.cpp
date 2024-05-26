#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxLetter 26

int  letterSize,accpetSize,line;
int  possibleLetter[maxLetter][3];
char acceptLetter [maxLetter];

struct position{
	int xValue;
	int rootSignThree;
};

void findPosition(position& a,int currentIndex, int totalLetter){
	int numinLine = line;

	a.rootSignThree = 0;
	while(currentIndex < totalLetter - numinLine){
		totalLetter -= numinLine;
		a.rootSignThree ++;
		numinLine --;
	}
	a.xValue = a.rootSignThree + (numinLine-1)*2;

	for(int i = totalLetter;i > currentIndex+1;i--)
		a.xValue -= 2;

}


bool isEquilateralTriangle(position& a,position& b, position& c){
	int d1,d2,d3;
	int temp1,temp2;

	temp1 = abs(a.xValue - b.xValue);
	temp2 = abs(a.rootSignThree - b.rootSignThree);
	d1 = temp1 * temp1 + temp2 * temp2 * 3;

	temp1 = abs(a.xValue - c.xValue);
	temp2 = abs(a.rootSignThree - c.rootSignThree);
	d2 = temp1 * temp1 + temp2 * temp2 * 3;

	temp1 = abs(b.xValue - c.xValue);
	temp2 = abs(b.rootSignThree - c.rootSignThree);
	d3 = temp1 * temp1 + temp2 * temp2 * 3;

	if(d1 == d2 && d1 == d3 && d2 == d3)
		return true;
	else
		return false;
}


int main()
{
	int size,counter;
	char letter;
	position a,b,c;
	string allLetter;

	while(cin >> line){
		if(line ==0)
			break;
		letterSize = accpetSize = 0;
		letter = 'a' - 1;
		cin >> allLetter;
		size = line * (line+1)/2;


		for(int i = 0;i < 26;i++){
			letter ++;
			counter = 0;
			for(int j = 0;j < size;j++){
				if(letter == allLetter[j]){
					possibleLetter[letterSize][counter++] = j;
				}
			}
			if(counter == 3)
				letterSize ++;
		}

		for(int i =0;i < letterSize;i++){
			findPosition(a,possibleLetter[i][0],size);
			findPosition(b,possibleLetter[i][1],size);
			findPosition(c,possibleLetter[i][2],size);
			if(isEquilateralTriangle(a,b,c))
				acceptLetter[accpetSize++] = allLetter[possibleLetter[i][0]];
		}

		if(accpetSize == 0)
			cout << "LOOOOOOOOSER!" << endl;
		else{
			for(int i =0;i < accpetSize;i++)
				cout << acceptLetter[i];
			cout << endl;
		}


	}




	return 0;
}