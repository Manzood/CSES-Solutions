#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector <int> desired(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&desired[i]);
	}
	vector <int> apt(m);
	for (int i=0;i<m;i++) {
		scanf("%d",&apt[i]);
	}
	sort(desired.begin(),desired.end());
	sort(apt.begin(),apt.end());
	// for (int i=0;i<n;i++) {
	// 	debug(desired[i]);
	// }
	int startptr=0;
	int ans=0;
	for (int i=0;i<n && startptr<m;i++) {
		while (desired[i]>apt[startptr]+k) {
			startptr++;
			if (startptr==m) {
				break;
			}
		}
		if (startptr!=m && desired[i]>=(apt[startptr]-k)) {
			ans++;
			startptr++;
		}
	}
	printf("%d",ans);
}
