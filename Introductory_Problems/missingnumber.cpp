#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	long long n;
	cin>>n;
	long long sum=0;
	long long check=(n*(n+1))/2;
	// debug(check);
	for (int i=0;i<n-1;i++) {
		int temp;
		scanf("%d",&temp);
		sum+=temp;
	}
	printf("%lld",check-sum);
}