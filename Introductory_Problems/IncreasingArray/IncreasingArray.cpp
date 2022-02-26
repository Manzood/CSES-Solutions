#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	long long ans=0;
	int m=0;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		m=max(a[i],m);
		ans+=(m-a[i]);
	}
	cout<<ans;
}