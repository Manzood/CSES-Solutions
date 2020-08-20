#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> tickets(n);
	vector <int> customers(m);
	for (int i=0; i<n; i++) {
		scanf("%d", &tickets[i]);
	}
	for (int i=0; i<m; i++) {
		scanf("%d", &customers[i]);
	}
	sort(tickets.begin(), tickets.end());
	vector <int> ans;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (j > 0 && tickets[j] <= customers[i]) {
				ans.push_back(tickets[j-1]);
				tickets[j-1] = -1;
				// debug(j);
				break;
			}
			else if (j == 0 && tickets[j] > customers[i]) {
				ans.push_back(-1);
				break;
			}
		}
	}
	for (int x: ans) printf("%d\n", x);
}