#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char num[10];
char dam[10];
int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	char ch='-',ab;
	int sum=0;
	int ans=0,ans1=0;
	int k=0,k1=0,k2=0;
	while(scanf("%s",dam)==1){
			ab=getchar();
			if(!strcmp(dam,"negative")) putchar(ch);
			if(!strcmp(dam,"one")) sum+=1;
			else if(!strcmp(dam,"two")) sum+=2;
			else if(!strcmp(dam,"three")) sum+=3;
			else if(!strcmp(dam,"four")) sum+=4;
			else if(!strcmp(dam,"five")) sum+=5;
			else if(!strcmp(dam,"six")) sum+=6;
			else if(!strcmp(dam,"seven")) sum+=7;
			else if(!strcmp(dam,"eight")) sum+=8;
			else if(!strcmp(dam,"nine")) sum+=9;
			else if(!strcmp(dam,"ten")) sum+=10;
			else if(!strcmp(dam,"eleven")) sum+=11;
			else if(!strcmp(dam,"twelve")) sum+=12;
			else if(!strcmp(dam,"thirteen")) sum+=13;
			else if(!strcmp(dam,"fourteen")) sum+=14;
			else if(!strcmp(dam,"fifteen")) sum+=15;
			else if(!strcmp(dam,"sixteen")) sum+=16;
			else if(!strcmp(dam,"seventeen")) sum+=17;
			else if(!strcmp(dam,"eighteen")) sum+=18;
			else if(!strcmp(dam,"nineteen")) sum+=19;
			else if(!strcmp(dam,"twenty")) sum+=20;
			else if(!strcmp(dam,"thirty")) sum+=30;
			else if(!strcmp(dam,"forty")) sum+=40;
			else if(!strcmp(dam,"fifty")) sum+=50;
			else if(!strcmp(dam,"sixty")) sum+=60;
			else if(!strcmp(dam,"seventy")) sum+=70;
			else if(!strcmp(dam,"eighty")) sum+=80;
			else if(!strcmp(dam,"ninety")) sum+=90;
			else if(!strcmp(dam,"hundred")) {if(k1) {sum*=100;ans1+=sum;k=1;} else{sum*=100;ans+=sum;k=1;}sum=0;}
			else if(!strcmp(dam,"thousand")) 
			{
				if(k1)
				{
					if(!k)
					{sum*=1000;ans1+=sum;}
					else
					{ans1=(ans1+sum)*1000;}
					//printf("lll%d\n",ans1);
				}
				else if(k) {ans=(ans+sum)*1000;}
			    else {sum*=1000;ans+=sum;}
				sum=0;
				//printf("%d\n",ans);
			}
			else if(!strcmp(dam,"million")) {ans=(ans+sum)*1000000;sum=0;k1=1;k=0;}
			if(ab=='\n') {printf("%d\n",ans+ans1+sum);sum=0;ans=0;ans1=0;k=0;k1=0;}
	}
}