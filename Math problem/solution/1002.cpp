#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

char input[35];
int phoneNum;

int coverntNumber(char a){
	int number = a - 'A';

	if(number > 16)
		number --;
	return number / 3 +2;
}

void coverntInt(int size){
	phoneNum = 0;
	for(int i = 0; i < size;i++){
		if(input[i] >= 65 && input[i] <= 89 && input[i] != 81){
			phoneNum *= 10;
			phoneNum += coverntNumber(input[i]);
		}
		else if(input[i] - '0' >= 0 && input[i] - '0' <=9){
			phoneNum *= 10;
			phoneNum += input[i] - '0';
		}
	}
}

int main()
{
	int t,number,counter;
	scanf("%d",&t);
	int ans[t];
	for(int i = 0;i < t;i++){
		scanf("%s",input);
		coverntInt(strlen(input));
		ans[i] = phoneNum;
	}
	sort(ans,ans+t);
	bool flag,repreat;
	flag = true;
	repreat = false;
	counter = 1;
	for(int i = 0;i < t-1;i++){
		if(!flag)
			flag =true;
	
		if(ans[i] == ans[i+1])
			counter ++;
		else
			flag = false;

		if(flag == false && counter > 1){
			printf("%03d-%04d %d\n",ans[i] / 10000, ans[i]% 10000,counter);
			repreat = true;
			counter = 1;
		}
	}
	if(counter > 1){
		printf("%03d-%04d %d\n",ans[t-1] / 10000, ans[t-1]% 10000,counter);
		repreat = true;
	}
	if(!repreat)
		printf("No duplicates.\n");
	return 0;
}




