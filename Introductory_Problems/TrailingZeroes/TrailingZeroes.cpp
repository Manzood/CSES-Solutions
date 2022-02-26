#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	scanf("%d",&n);
	int zeroes=5;
	long long ans=0;
	while (zeroes<=n) {
		int temp=zeroes;
		while (zeroes%5==0) {
			ans++;
			zeroes/=5;
		}
		zeroes=temp+5;
	}
	cout<<ans;
}
