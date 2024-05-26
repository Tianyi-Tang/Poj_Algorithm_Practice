#include<stdio.h>

int main()
{
    char c;
    while((c = getchar()) != '#')
    {
        int i = 1;
        long int sum = 0;
        do
        {
            sum += i * (c == ' ' ? 0 : c - 'A' + 1);
            i ++;
        }while((c = getchar()) != 10);
        printf("%ld\n", sum);
    }
    return 0;
}