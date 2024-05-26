#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

string funPattern;
string expersion;

string representNum(long long num,int bits){
    expersion = "";
    string revese;
    bool flag;

    for(int i = 0;i < bits;i++){
        flag = false;
        if(num & 1){
            revese += '1';
            if(funPattern[bits-i -1] == 'n')
                flag = true;
        }
        else
            revese += '0';
        if(flag)
            num ++;
    }

    if(num != 0)
        return "Impossible";


    for(int i = bits -1;i >=0;i--)
        expersion += revese[i];

    return expersion;

}


int main()
{
    long long num;
    int n,k;
    cin >> n;
    for(int i =0;i < n;i++){
        cin >> k;
        cin >> funPattern;
        cin >> num;
        cout << representNum(num,k) << endl;
    }


    return 0;
}