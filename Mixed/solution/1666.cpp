#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int studentNum;
int studentCandy[500];

int main()
{
	int candy,carry,temp,finalValue,counter;
	bool same;

	while(cin >> studentNum){

		if(studentNum == 0)
			break;

		same =false;
		counter = 0;
		for(int i =0;i < studentNum;i++){
			cin >> candy;
			studentCandy[i] = candy;
		}

		
		while(!same && studentNum != 1){
			carry = 0;
			same = true;
			for(int j =0;j < studentNum;j++){
				temp = studentCandy[j] / 2;
				if((temp + carry) % 2 != 0 && j != 0)
					carry ++;
				studentCandy[j] = temp + carry;
				carry = temp;

				if(j == 1)
					finalValue = studentCandy[j];
				else if(j > 1 && finalValue != studentCandy[j])
					same = false;

			}
			if((carry+ studentCandy[0])% 2 != 0)
				carry ++;
			studentCandy[0] += carry;
			if(same && finalValue != studentCandy[0])
				same = false;
			counter++;
		}

		cout << counter << " " << studentCandy[0] << endl;

	}
	

	return 0;
}