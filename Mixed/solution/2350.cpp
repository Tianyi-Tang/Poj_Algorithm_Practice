#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxStduent 1000

int studentNum;
int students[maxStduent];


int main()
{
	int testCase,grade,sum,averageAbove;
	float present,average;

	scanf("%d",&testCase);
	while(testCase){
		sum = 0;
		scanf("%d",&studentNum);
		for(int i =0;i < studentNum;i++){
			scanf("%d",&grade);
			sum += grade;
			students[i] = grade;
		}

		average = sum / (studentNum*1.0);
		averageAbove = 0;
		for(int i =0;i < studentNum;i++){
			if(students[i] > average)
				averageAbove ++;
		}

		present = (averageAbove*100.0) / studentNum;
		printf("%.3f%%\n",present);


		testCase --;
	}

	return 0;
}
