#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 2

struct Matrix{
	int m[N][N];
};

void initalMaxtrix(Matrix& matrix){
	matrix.m[0][0] =1;
	matrix.m[0][1] =1;
	matrix.m[1][0] =1;
	matrix.m[1][1] = 0;
}

void print(Matrix& max1){
	for(int i =0;i < N;i++)
		cout << max1.m[i][0] << " " << max1.m[i][1] << endl; 
}

void copy(Matrix& max1, Matrix& max2){
	for(int i =0;i < N;i++){
		for(int j =0;j < N;j++)
			max1.m[i][j] = max2.m[i][j];
	}
}

void multiple(Matrix& max1,Matrix& max2){
	Matrix max3;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			max3.m[i][j] = (max1.m[i][0] * max2.m[0][j] + max1.m[i][1] * max2.m[1][j]) % 10000;
		}
	}

	copy(max1,max3);
}

int findFibonacci(int number){
	Matrix ans,max;
	initalMaxtrix(max);
	for(int i = 0;i < N;i++){
		ans.m[i][1-i] = 0;
		ans.m[i][i] = 1;
	}

	while(number != 0){
		if(number & 1)
			multiple(ans,max);
		multiple(max,max);
		number >>= 1;
	}
	return ans.m[0][1];

}


int main()
{
	int number;
	while(cin >> number){
		if(number == -1)
			break;
		cout << findFibonacci(number) << endl;
	}
	
	return 0;
}