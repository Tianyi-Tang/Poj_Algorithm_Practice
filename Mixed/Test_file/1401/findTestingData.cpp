#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
	// int counter1, counter2;
	// string line;
	// counter1 = counter2 = 0;
	// ifstream outputfile("output.txt");
	// while(getline(outputfile,line)){
	// 	counter1 ++;
	// 	if(line == "658")
	// 		break;
	// }
	// outputfile.close();
	// counter1 --;
	// ifstream inputfile("input.txt");
	// for(int i =0;i < counter1;i++){
	// 	getline(inputfile,line);
	// }
	// cout << line << endl;
	// inputfile.close();


	string line1, line2;
	bool flag = true;
	int counter = 0;
	ifstream outputfile("output.txt");
	ifstream resultfile("result.txt");

	while(getline(outputfile,line1)){
		counter++;
		getline(resultfile,line2);
		if(line1 != line2){
			cout << "result:" << line2 << " output:" << line1 << " index:" << counter << endl;
			flag = false;
			break;
		}
	}

	outputfile.close();
	resultfile.close();


	ifstream inputfile("input.txt");
	for(int i =0;i < counter;i++)
		getline(inputfile,line1);
	if(!flag)
		cout << line1 << endl;


	
	return 0;
}