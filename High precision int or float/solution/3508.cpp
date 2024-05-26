#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define N 1000009

char input[N];
char ans[N];

char error[] = "IMPOSSIBLE";
int counter;

void findNumber(){
	int n = strlen(input);
	ans[n-1] = input[n-1];

	int carry = 0;

	for(int i = n - 2; i >=0;i--){
		ans[i] = (input[i] - ans[i+1] - carry + 10) % 10 + '0';
		carry = (ans[i] -'0' + ans[i+1] - '0' + carry) / 10;
	}

	ans[n] = 0;
	if(ans[0]!= '0')
		printf("%d. %s\n",counter,ans);
	else
		printf("%d. %s\n",counter,error);
}

int main()
{
	counter = 1;
	while(scanf("%s",input)){
		if(strcmp(input,"0") ==0)
			break;
		findNumber();
		counter++;
	}


	return 0;
}