#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;


int findScore(double r){
	if(r <= 3)
		return 100;
	else if(r <= 6)
		return 80;
	else if(r <= 9)
		return 60;
	else if(r <= 12)
		return 40;
	else if(r <= 15)
		return 20;
	else
		return 0;
}

int main(int argc, char const *argv[])
{
	int aScore,bscore;
	double xPosition,yPosition,r;

	while(cin >> xPosition >> yPosition){
		if(xPosition == -100)
			break;

		aScore = bscore = 0;
		r = sqrt(pow(xPosition,2)  + pow(yPosition,2));
		aScore += findScore(r);

		for(int i =0 ;i < 2;i++){
			cin >> xPosition >> yPosition;
			r = sqrt(xPosition * xPosition + yPosition * yPosition);
			aScore += findScore(r);
		}

		for(int i =0 ;i < 3;i++){
			cin >> xPosition >> yPosition;
			r = sqrt(xPosition * xPosition + yPosition * yPosition);
			bscore += findScore(r);
		}

		if(aScore > bscore)
			cout << "SCORE: " << aScore << " to " << bscore << ", PLAYER 1 WINS." << endl;
		else if (bscore > aScore)
			cout << "SCORE: " << aScore << " to " << bscore << ", PLAYER 2 WINS." << endl;
		else
			cout << "SCORE: " << aScore << " to " << bscore << ", TIE." << endl;
	}

	return 0;
}