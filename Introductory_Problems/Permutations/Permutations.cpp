#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin>>n;
	vector <int> ans;
	if (n%2==0) {
		for (int i=2;i<=n;i+=2) {
			ans.push_back(i);
		}
		for (int i=1;i<=n;i+=2) {
			ans.push_back(i);
		}
	}	
	else {
		for (int i=1;i<=n;i+=2) {
			ans.push_back(i);
		}
		for (int i=2;i<=n;i+=2) {
			ans.push_back(i);
		}
	}
	bool possible=true;
	for (int i=0;i<n-1;i++) {
		if (abs(ans[i]-ans[i+1])==1) 
			possible=false;
	}
	if (possible) {
		for (int i=0;i<n;i++) {
			printf("%d ",ans[i]);
		}
	}
	else {
		printf("NO SOLUTION");
	}
}