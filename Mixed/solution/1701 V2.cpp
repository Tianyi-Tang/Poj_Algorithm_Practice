#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define maxFloor 10000

int floorNum,siutablFloor;
int tenantsFloor[maxFloor];
long long sum[maxFloor],mSeries[maxFloor],sSeries[maxFloor];
long long tValue, hValue,minDissatisfied,preDissatisfied;

void setInitalValue(int a, int b){
	int tenants;

	minDissatisfied = 0;
	for(int i = 1;i <= floorNum;i++){
		cin >> tenants;
		tenantsFloor[i-1] = tenants;
		if(i == 1)
			sum[0] = tenants;
		else{
			sum[i-1] = tenants + sum[i-2];
			minDissatisfied += a * (i-1) * tenants + tenants * 0.5 * (i-1) * (i-2);
		}	
	}

	mSeries[floorNum-1] = sSeries[floorNum-1] = 0;
	for(int i = floorNum -2;i >= 0;i--){
		sSeries[i] = sSeries[i+1] + (sum[floorNum-1] - sum[i]);
		mSeries[i] = mSeries[i+1] + (1 - a) * tenantsFloor[i+1];
	}

	tValue = b * tenantsFloor[0];
	hValue = 0;
	preDissatisfied = minDissatisfied;
	siutablFloor = 1;
}

void findNextDissatisfied(int a, int b,int currentFloor){
	long long currentDissatisfied = preDissatisfied + tValue + hValue + mSeries[currentFloor -2] - sSeries[currentFloor -2];


	if(currentDissatisfied < minDissatisfied){
		siutablFloor = currentFloor;
		minDissatisfied = currentDissatisfied;
	}
	preDissatisfied = currentDissatisfied;

	if(currentFloor < floorNum){
		tValue = tValue + b * tenantsFloor[currentFloor-1];
		hValue = hValue + sum[currentFloor -2];
	}
}

int main(int argc, char const *argv[])
{
	int n,a,b;
	cin >> n;
	for(int i =0;i < n;i++){
		cin >> floorNum >> a >> b;
		setInitalValue(a,b);
		for(int j = 2;j <= floorNum;j++)
			findNextDissatisfied(a,b,j);
		cout << siutablFloor << endl;
	}
	return 0;
}

