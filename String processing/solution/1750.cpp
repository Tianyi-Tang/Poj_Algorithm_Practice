#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define maxLength 10

int wordsNum;
char preWord[maxLength];


int main()
{
	char word[maxLength],currentChar;
	int wordLength,i;
	bool fistInput = true;


	wordsNum = 0;
	while(scanf("%s",word) != EOF){
		wordLength = strlen(word);
		if(fistInput)
			fistInput = false;
		else{
			for(i = 0;i < strlen(preWord) && i <= wordLength;i++){
				if(preWord[i] != word[i])
					break;
			}
			if(i > wordsNum)
				wordsNum ++;
			else
				wordsNum = i;
		}
		printf("%*s\n",wordsNum+wordLength,word);
		strcpy(preWord,word);

	}

	return 0;
}