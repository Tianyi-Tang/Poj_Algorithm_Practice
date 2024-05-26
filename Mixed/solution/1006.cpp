#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define phsyCycle 5544
#define emotCycle 14421
#define intellCycle 1288
#define maxCycle 21252

int peakDay;
int counter;

void result(){
	cout << "Case " << counter << ": the next triple peak occurs in ";
	cout << peakDay << " days." << endl;
}

int main()
{
	int p,e,i,d;
	counter = 1;
	while(cin >> p){
		cin >> e;
		cin >> i;
		cin >> d;
		if(p == -1 && e == -1 && i == -1 && d == -1)
			break;
		peakDay = (p * phsyCycle) % maxCycle;
		peakDay = (peakDay + e * emotCycle) % maxCycle;
		peakDay = (peakDay + i * intellCycle) % maxCycle;
		peakDay -= d;
		if(peakDay <= 0)
			peakDay += maxCycle;
		
		result();
		counter ++;
	}
	return 0;
}