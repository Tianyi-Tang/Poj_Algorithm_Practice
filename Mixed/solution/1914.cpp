#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

long long determinantValue[3];


struct Matrice3{
	long long array[3][3];
};

struct Matrice1{
	long long array[3];
};

void formNewMatrice(Matrice3& a, Matrice1& b, int index,Matrice3& c){
	for(int i =0;i < 3;i++){
		for(int j =0;j < 3;j++){
			if(i == index)
				c.array[j][i] = b.array[j];
			else
				c.array[j][i] = a.array[j][i];
		}
	}
}

long long findDeterminant(Matrice3& a){
	return a.array[0][0] *(a.array[1][1] * a.array[2][2] - a.array[1][2]*a.array[2][1]) - a.array[0][1] *(a.array[1][0] * a.array[2][2] - a.array[1][2]*a.array[2][0]) + a.array[0][2] *(a.array[1][0] * a.array[2][1] - a.array[1][1]*a.array[2][0]);
}

int main()
{
	double value;
	int n;
	long long determinant,num;
	Matrice3 a,c;
	Matrice1 b;

	scanf("%d",&n);
	for(int z = 0;z < n;z++){
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				scanf("%lld",&num);
				a.array[i][j] = num;
			}
			scanf("%lld",&num);
			b.array[i] = num;
		}

		for(int i =0;i < 3;i++){
			formNewMatrice(a,b,i,c);
			determinant = findDeterminant(c);
			determinantValue[i] = determinant;
		}
		determinant = findDeterminant(a);
		printf("%lld %lld %lld %lld\n",determinantValue[0],determinantValue[1],determinantValue[2],determinant);

		if(determinant == 0)
			printf("No unique solution\n\n");
		else{
			printf("Unique solution:");
			for(int i =0;i < 3;i++){
				value =  determinantValue[i] / (determinant*1.0);
				if(-0.0005 < value && value < 0.0005){
					value = 0;
				}
				printf(" %.3lf",value);
			}
			printf("\n\n");
		}
	}

	
	return 0;
}

