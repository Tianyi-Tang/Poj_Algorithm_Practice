#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

void outputResult(int num,int stats){
	if(stats == 0)
		printf("%5d  %s\n",num,"PERFECT");
	else if(stats < 0)
		printf("%5d  %s\n",num,"DEFICIENT");
	else
		printf("%5d  %s\n",num,"ABUNDANT");
}



int main()
{
	int num,copyNum,range,sum;
	printf("%s\n", "PERFECTION OUTPUT");
	while(cin >> num){
		if(num == 0)
			break;


		copyNum = num;
		if(num < 0)
			num = num * -1;

		sum = 1;
		range = num /2;
		for(int i =2;i <= range;i++){
			if(num % i ==0){
				range = num /i -1;
				if(range +1 != i)
					sum += i + range +1;
				else
					sum += i;
			}
		}

		if(sum == 1)
			outputResult(copyNum,-1);
		else
			outputResult(copyNum,sum - abs(copyNum));
	}
	printf("%s\n","END OF OUTPUT");

	return 0;
}