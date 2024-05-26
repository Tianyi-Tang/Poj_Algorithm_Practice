#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
	int maxWidth,lineWidth,lineHeigth,widthCurrent,heighCurrent;
	int rectWidth,rectHeight;

	while(cin >> maxWidth){
		if(maxWidth == 0)
			break;

		lineWidth = heighCurrent = lineHeigth = widthCurrent = 0;
		while(cin >> rectWidth >> rectHeight){
			if(rectWidth == -1 && rectHeight == -1)
				break;

			if(lineWidth + rectWidth > maxWidth){
				lineWidth = rectWidth;
				lineHeigth = rectHeight;
				heighCurrent += rectHeight;
			}
			else{
				lineWidth += rectWidth;
				if(lineWidth > widthCurrent)
					widthCurrent = lineWidth;
			}

			if(lineHeigth < rectHeight){
				heighCurrent += (rectHeight- lineHeigth);
				lineHeigth = rectHeight;
			}
		}
		cout << widthCurrent << " x " << heighCurrent << endl;
	}

	return 0;
}