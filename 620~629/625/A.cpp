#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> ar,br;
	ar.resize(n);
	br.resize(n);
	for (auto &i:ar) cin>>i;
	for (auto &i:br) cin>>i;
	int tmp=0,cnt=0;
	for (int i=0;i<n;i++) {
		if (ar[i]==br[i]) continue;
		if (br[i]) tmp++;
		else cnt++;
	}
	if (cnt==0) cout<<-1<<endl;
	else cout<<tmp/cnt+1<<endl;
}
