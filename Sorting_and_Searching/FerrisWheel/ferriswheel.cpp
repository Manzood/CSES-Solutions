#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n, x;
	cin>>n>>x;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	// for (int i=0;i<n;i++) {
		// printf("%d ",a[i]);
	// }
	int ans=0;
	int i=0;
	//two pointer technique (i think)
	int end=n-1;
	set <int> used;
	for (int i=0;i<n;i++) {
		if (i<end) {
			while (a[i]+a[end]>x && end>i) { 
				end--;
			}
			if (a[i]+a[end]<=x) {
				used.insert(end);
				end--;
			}
		}
		if (used.count(i)==0)
			ans++;
	}	
	cout<<ans;
}	