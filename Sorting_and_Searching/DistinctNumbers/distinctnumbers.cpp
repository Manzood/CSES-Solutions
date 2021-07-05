#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	int ans=0;
	for (int i=0;i<n;i++) {
		if (i==0) ans++;
		if (i!=0 && a[i]!=a[i-1]) {
			ans++;
		}
	}
	cout<<ans;
}
