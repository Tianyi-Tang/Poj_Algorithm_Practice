#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cstdio>
using namespace std;

#define maxTeamNum 20
#define maxProblemNum 9

int teamNum,problemNum;
map<string,int> teamIndex;
string allTeamName[maxTeamNum];

bool problemCorrect[maxTeamNum][maxProblemNum];
int solveAndTime[maxTeamNum][2],wrongSumbit[maxTeamNum][maxProblemNum];

void inital(){
	for(int i =0;i < teamNum;i++){
		for(int j =0; j < problemNum;j++){
			problemCorrect[i][j] = false;
			wrongSumbit[i][j] = 0;
		}
		solveAndTime[i][0] = 0;
		solveAndTime[i][1] = 0;
	}
}


void sumbitResult(int problem, int timeSpeend, string solved,string teamName){
	int index = teamIndex[teamName];

	if(problemCorrect[index][problem-1])
		return;

	if(solved == "Yes"){
		problemCorrect[index][problem-1] = true;
		solveAndTime[index][0] += 1;
		solveAndTime[index][1] += timeSpeend + wrongSumbit[index][problem-1] * 20;
	}
	else if(solved == "No"){
		wrongSumbit[index][problem-1] += 1;
	}
}



int main()
{
	string solved,teamName;
	int sumbitTime,problem,timeSpeend,sizeTeamName,n;
	int currentMaxProblem,currentMinTime,preMaxProblem,preMinTime,order,printTeam;

	cin >> n;
	while(n){
		cin >> teamNum;

		for(int i =0;i < teamNum;i ++){
			cin >>teamName;
			allTeamName[i] = teamName;
			teamIndex[teamName] = i;
			
		}

		cin >> problemNum >> sumbitTime;
		inital();
		for(int i =0;i < sumbitTime;i++){
			cin >> problem >> timeSpeend >> solved >> teamName;
			sumbitResult(problem,timeSpeend,solved,teamName);
		}


		preMaxProblem = -1;
		currentMinTime = preMinTime = 301;
		for(int i =0;i < teamNum;i++){
			currentMaxProblem = solveAndTime[0][0];
			currentMinTime = solveAndTime[0][1];
			printTeam = 0;
			for(int j =1;j < teamNum;j++){
				if(solveAndTime[j][0] > currentMaxProblem || (currentMaxProblem == solveAndTime[j][0] && currentMinTime > solveAndTime[j][1])){
					currentMaxProblem = solveAndTime[j][0];
					currentMinTime = solveAndTime[j][1];
					printTeam = j;
				}
			}
			teamName = allTeamName[printTeam];
			solveAndTime[printTeam][0] = -1;

			for(int j = teamName.length();j < 8;j++)
				teamName += ' ';

			if(currentMinTime != preMinTime || currentMaxProblem != preMaxProblem)
				order = i + 1;

			printf("%2d. ",order);
			cout << teamName << " ";
			printf("%d %4d\n",currentMaxProblem,currentMinTime);
			preMaxProblem = currentMaxProblem;
			preMinTime = currentMinTime;
		}
		cout << endl;

		n --;
	}

	return 0;
}