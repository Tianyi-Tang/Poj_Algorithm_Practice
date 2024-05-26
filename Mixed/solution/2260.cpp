#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define maxMatrixLength 99

int matrixSize;
int matrix[maxMatrixLength][maxMatrixLength];


int main()
{
	int oddRow,oddColumn,sum,value;
	bool isCorrupt;

	while(cin >> matrixSize){
		if(matrixSize == 0)
			break;

		isCorrupt = false;
		oddRow = oddColumn = -1;
		for(int i =0;i < matrixSize;i ++){
			sum = 0;
			for(int j =0;j < matrixSize;j++){
				cin >> value;
				matrix[i][j] = value;
				sum += value;
			}
			if(sum % 2 == 1){
				if(oddRow == -1)
					oddRow = i;
				else
					isCorrupt = true;
			}
		}

		if(isCorrupt){
			cout << "Corrupt" << endl;
			continue;
		}

		for(int i =0 ;i < matrixSize;i++){
			sum = 0;
			for(int j =0;j < matrixSize;j++){
				sum += matrix[j][i];
			}
			if(sum % 2 == 1){
				if(oddColumn == -1)
					oddColumn = i;
				else
					isCorrupt = true;
			}
		}

		if(oddColumn == -1 && oddRow == -1)
			cout << "OK" << endl;
		else if(oddColumn != -1 && oddRow != -1 && !isCorrupt)
			cout << "Change bit (" << oddRow +1 << "," << oddColumn +1 << ")" << endl;
		else
			cout << "Corrupt" << endl; 
	}

	return 0;
		
}