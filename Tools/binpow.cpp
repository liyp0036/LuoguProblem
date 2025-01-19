#include<bits/stdc++.h>
#define int long long
using namespace std;
int p;
long long binpow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a;
		res%=p;
		a = a * a;
		a=a%p;
		b >>= 1;
		// b%=p;
 	}
	return res;
}
signed main()
{
	int a,b;
	cin>>a>>b>>p;
	cout<<a<<"^"<<b<<" mod "<<p<<"=";
	cout<<binpow(a,b);
}
