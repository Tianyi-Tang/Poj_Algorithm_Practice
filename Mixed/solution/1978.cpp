#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxCardNum 50

int cardNum,topCardNum;
int cardOrder[maxCardNum],topCard[maxCardNum-1];


int main()
{
	int operation,cardValue,c;

	while(cin >> cardNum >> operation){

		if(cardNum == 0 && operation == 0)
			break;

		for(int i =0;i < cardNum;i++)
			cardOrder[i] = cardNum - i;
		
		for(int i =0;i < operation;i++){
			cin >> topCardNum >> c;
			topCardNum --;

			for(int j =0;j < topCardNum;j++)
				 topCard[j] = cardOrder[j];
			for(int j = 0;j < c;j++)
				cardOrder[j] = cardOrder[j+topCardNum];
			for(int j = 0;j < topCardNum;j++)
				cardOrder[c+j] = topCard[j];
		}

		cout << cardOrder[0] << endl;
	}

	
	return 0;
}