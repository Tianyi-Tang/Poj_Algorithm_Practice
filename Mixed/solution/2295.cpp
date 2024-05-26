#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int leftXValue,leftIntValue,rigthXValue,rightIntValue;

void coverntStringToInt(string number,int end,int & addingValue){
	int start,value;
	bool postive = true;

	value = start = 0;

	if(number[0] == '-' || number[0] == '+'){
		start = 1;
		if(number[0] == '-')
			postive = false;
	}

	for(int i = start;i <= end;i++){
		value *= 10;
		value += number[i] - '0';
	}

	if(end == -1 || start > end)
		value = 1;

	if(!postive)
		value *= -1;
	
	addingValue += value;
}

void addValue(string number, bool left){

	if(number[number.length()-1] == 'x'){
		if(left)
			coverntStringToInt(number,number.length()-2,leftXValue);
		else
			coverntStringToInt(number,number.length()-2,rigthXValue);
	}
	else{
		if(left)
			coverntStringToInt(number,number.length()-1,leftIntValue);
		else
			coverntStringToInt(number,number.length()-1,rightIntValue);
	}
}

int main()
{
	string number;
	char equation[1000];
	int xInetValue,n,equationSize;
	double xReuslt;

	scanf("%d",&n);
	while(n){
		scanf("%s",equation);
		equationSize = strlen(equation);

		leftXValue = rigthXValue = rightIntValue = leftIntValue = 0;

		number = "";
		int i;
		for( i =0;i < equationSize;i++){
			if((equation[i] == '-' || equation[i] == '+')&& number.length() != 0){
				addValue(number,true);
				number = equation[i];
			}
			else if(equation[i] == '='){
				addValue(number,true);
				break;
			}
			else
				number += equation[i];
		}

		number = "";
		for(int j = i +1;j < equationSize;j++){
			if((equation[j] == '-' || equation[j] == '+')&& number.length() != 0){
				addValue(number,false);
				number = equation[j];
			}
			else
				number += equation[j];
		}
		addValue(number,false);

		leftXValue -= rigthXValue;
		rightIntValue -= leftIntValue;

		if(leftXValue == 0 && rightIntValue == 0)
			printf("IDENTITY\n");
		else if(leftXValue == 0)
			printf("IMPOSSIBLE\n");
		else{
			xReuslt = rightIntValue / (leftXValue*1.0);
			xInetValue = xReuslt;
			if(xReuslt <0 && xReuslt - xInetValue != 0)
				xInetValue --;
			printf("%d\n",xInetValue);
		}

		n--;
	}
	

	return 0;
}