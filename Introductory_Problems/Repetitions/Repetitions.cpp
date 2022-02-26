#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	string dna;
	cin>>dna;
	int curr=0;
	int m=0;
	char prev;
	for (int i=0;i<dna.size();i++) {
		if (i==0) { 
			prev=dna[i];
			curr++;
		}
		else {
			if (dna[i]==prev)
				curr++;
			else {
				curr=1;
			}
			prev=dna[i];
		}
		m=max(curr,m);
	}
	cout<<m;
}