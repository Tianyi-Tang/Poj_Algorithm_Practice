#include<iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;



int main()
{
	char c;
	bool replace;

	replace = true;
	c = getchar();
	while(c != EOF){
		if(c == '"'){
			if(replace)
				cout << "``";
			else
				cout << "''";
			replace = !replace;
		}
		else
			cout << c;
		c = getchar();
	}
	
	return 0;
}