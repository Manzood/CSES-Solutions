#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x;
#define int long long

int32_t main() {
	int n;
	cin>>n;
	while (1) {
		printf("%lld ",n);
		if (n==1)
			break;
		if (n&1) {
			n*=3;
			n+=1;
		}
		else {
			n/=2;
		}
	}
}