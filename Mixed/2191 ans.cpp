#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define C 240
#define TIME 6   
using namespace std;

long long ans[65]; //存2^prime[i]-1非素数的质因子
int prime[65],x[65],m,cnt;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

long long mod_mult(long long a,long long b,long long n) 
{
    long long s=0;
    a=a%n;
    while(b)
    {
        if (b&1) 
		{
            s+=a;
            if(s>=n)
                s-=n;
        }
        a=a<<1;
        if(a>=n)
            a-=n;
        b=b>>1;
    }

    return s;
}

long long mod_exp(long long a, long long b,long long n) 
{
    long long d=1;
    a=a%n;
    while (b>=1)
    {
        if (b&1)
            d=mod_mult(d,a,n);
        a=mod_mult(a,a,n);
        b=b>> 1;
    }
    return d;
}

bool Wintess(long long a,long long n) 
{
    long long m,x,y;
    int i,j=0;
    m=n-1;
    while(m%2==0) 
    {
        m=m>>1;
        j++;
    }
    x=mod_exp(a, m, n);
    for(i=1;i<=j;i++) 
	{
        y=mod_exp(x,2,n);
        if((y==1)&&(x!=1)&&(x!=n-1))   
            return true;  
        x=y;
    }
    if (y!=1)
        return true;
    return false;
}

bool miller_rabin(int times,long long n) 
{
    long long a;
    int i;
    if (n==1)
        return false;
    if (n==2)
        return true;
    if (n%2==0)
        return false;
    srand(time(NULL));  
    for (i =1;i<=times;i++) 
	{
        a=rand()%(n-1)+1;
        if(Wintess(a,n))
            return false;
    }
    return true;
}

long long Pollard(long long n,int c) 
{
    long long i,k,x,y,d;
    srand(time(NULL));
    i=1;
    k=2;
    x=rand()%n;
    y=x;
    while(true) 
	{
        i++;
        x=(mod_mult(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if (d>1&&d<n)
            return d;
        if (y==x)  
            return n;
        if (i==k) 
		{
            y=x;
            k=k<<1;
        }
    }
}

void get_prime(long long n,int c) 
{//二分找出所有素因子 
    long long m;
    if(n==1)
        return;
    if(miller_rabin(TIME,n)) 
    {
        ans[cnt++]=n;
        return;
    }
    m=n;
    while(m>=n) 
        m=Pollard(m,c--);
    get_prime(m,c); 
    get_prime(n/m,c);
}

void init()
{
	int i,tmp;
	memset(x,0,sizeof(x));
	x[0]=x[1]=1;  m=0;
	for(i=2;i<=63;i++)
	{
		if(!x[i])
		{
			prime[++m]=i;
			tmp=i*i;
			while(tmp<=63)
			{
				x[tmp]=1;
				tmp+=i;
			}
		}
	}
}

bool cmp(long long n1,long long n2)
{
	return n1<n2;
}

int main()
{
    init();
    int p,i,j;
    scanf("%d",&p);
    for(i=1;i<=m;i++)
    {
		if(prime[i]<=p)
		{
			long long n=((long long)1<<prime[i])-1;
			if(miller_rabin(TIME,n))//判断是否是素数
				continue;
			memset(ans,0,sizeof(ans));
			cnt=0;
			get_prime(n,C); //分解素因子
			sort(ans,ans+cnt,cmp);
			for(j=0;j<cnt-1;j++)
				printf("%I64d * ",ans[j]);
			printf("%I64d = %I64d = ( 2 ^ %d ) - 1\n",ans[j],n,prime[i]);
		}
		else
			break;
	}
    return 0;
}