#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

//algorithm: figure out the binary search once and for all, then use it to find the last element greater than or equal to the given number.
// I'm too tired to do this at the moment, but I will eventually return to this.

set <int> used;
int search (vector <int> a, int val) {
	int low=0, high=a.size()-1;
	int mid=(low+high)/2;
	while (low<=high) {

	}
	return mid;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector <int> a(n);
	vector <int> cust(m);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for (int i=0;i<m;i++) {
		scanf("%d",&cust[i]);
	}
	sort(a.begin(),a.end());

}