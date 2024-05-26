#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

string winnerName;
int maxSolveProblem, minPenaltyPoints;



int main()
{
	int tearmNum,solveProblem,sumbitTime,timeSpend,penaltyPoints;
	string teamName;
	bool changeWinner;

	cin >> tearmNum;
	maxSolveProblem = -1;
	minPenaltyPoints = 0;
	for(int i =0;i < tearmNum;i++){
		cin >> teamName;
		solveProblem = penaltyPoints = 0;
		changeWinner = false;
		for(int j =0;j < 4;j++){
			cin >> sumbitTime >> timeSpend;
			if(sumbitTime > 0 && timeSpend > 0){
				solveProblem ++;
				penaltyPoints += (sumbitTime -1) * 20 + timeSpend;
			}
		}
		if(maxSolveProblem < solveProblem)
			changeWinner = true;
		else if( maxSolveProblem == solveProblem && minPenaltyPoints > penaltyPoints)
			changeWinner = true;

		if(changeWinner){
			winnerName = teamName;
			maxSolveProblem = solveProblem;
			minPenaltyPoints = penaltyPoints;
		}
	}

	cout << winnerName << " " << maxSolveProblem << " " << minPenaltyPoints << endl;

	return 0;
}