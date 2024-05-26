#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int columnNum,rowNum;
	string input,answer;
	bool leftToRight;

	while(cin >> columnNum){
		if(columnNum == 0)
			break;

		cin >> input;
		rowNum = input.length() / columnNum;
		answer  = "";

		for(int i = 0;i < columnNum;i++){
			leftToRight = true;
			for(int j =0;j < rowNum;j++){
				if(leftToRight)
					answer += input[j*columnNum+i];
				else
					answer += input[j*columnNum+columnNum-1-i];
				leftToRight = !leftToRight;
			}
		}

		cout << answer << endl;

	}

	return 0;
}