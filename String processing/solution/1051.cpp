#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

string morseCode,counterNum;

string charToMorse(char a){
	if(a == 'A')
		return ".-";
	else if(a == 'B')
		return "-...";
	else if(a == 'C')
		return "-.-.";
	else if(a == 'D')
		return "-..";
	else if(a == 'E')
		return ".";
	else if(a == 'F')
		return "..-.";
	else if(a == 'G')
		return "--.";
	else if(a == 'H')
		return "....";
	else if(a == 'I')
		return "..";
	else if(a == 'J')
		return ".---";
	else if(a == 'K')
		return "-.-";
	else if(a == 'L')
		return ".-..";
	else if(a == 'M')
		return "--";
	else if(a == 'N')
		return "-.";
	else if(a == 'O')
		return "---";
	else if(a == 'P')
		return ".--.";
	else if(a == 'Q')
		return "--.-";
	else if(a == 'R')
		return ".-.";
	else if(a == 'S')
		return "...";
	else if(a == 'T')
		return "-";
	else if(a == 'U')
		return "..-";
	else if(a == 'V')
		return "...-";
	else if(a == 'W')
		return ".--";
	else if(a == 'X')
		return "-..-";
	else if(a == 'Y')
		return "-.--";
	else if(a == 'Z')
		return "--..";
	else if(a == '_')
		return "..--";
	else if(a == ',')
		return ".-.-";
	else if(a == '.')
		return "---.";
	else if(a == '?')
		return "----";
	else
		return "";
}

char morseToChar(string a){
	if(a == ".-")
		return 'A';
	else if(a == "-...")
		return 'B';
	else if(a == "-.-.")
		return 'C';
	else if(a == "-..")
		return 'D';
	else if(a == ".")
		return 'E';
	else if(a == "..-.")
		return 'F';
	else if(a == "--.")
		return 'G';
	else if(a == "....")
		return 'H';
	else if(a == "..")
		return 'I';
	else if(a == ".---")
		return 'J';
	else if(a == "-.-")
		return 'K';
	else if(a == ".-..")
		return 'L';
	else if(a == "--")
		return 'M';
	else if(a == "-.")
		return 'N';
	else if(a == "---")
		return 'O';
	else if(a == ".--.")
		return 'P';
	else if(a == "--.-")
		return 'Q';
	else if(a == ".-.")
		return 'R';
	else if(a == "...")
		return 'S';
	else if(a == "-")
		return 'T';
	else if(a == "..-")
		return 'U';
	else if(a == "...-")
		return 'V';
	else if(a == ".--")
		return 'W';
	else if(a == "-..-")
		return 'X';
	else if(a == "-.--")
		return 'Y';
	else if(a == "--..")
		return 'Z';
	else if(a == "..--")
		return '_';
	else if(a == ".-.-")
		return ',';
	else if(a == "---.")
		return '.';
	else if(a == "----")
		return '?';
	else
		return ' ';
}

int main()
{
	string input,morseValue,result;
	int stopPoint,nextStart,startInedex,n;

	cin >> n;
	startInedex = 1;
	while(n){

		cin >> input;
		morseCode = counterNum = "";
		for(int i =0;i < input.length();i++){
			morseValue = charToMorse(input[i]);
			morseCode += morseValue;
			counterNum += morseValue.length() + '0';
		}

		nextStart = 0;
		result = "";
		for(int i = counterNum.length() -1;i >=0;i--){
			stopPoint = counterNum[i] - '0';
			morseValue  = "";
			for(int j =0;j < stopPoint;j++)
				morseValue += morseCode[j+nextStart];
			result += morseToChar(morseValue);
			nextStart += stopPoint;
		}

		cout << startInedex << ": " << result << endl;

		n--;
		startInedex++;
		}

	

	
	
	return 0;
}