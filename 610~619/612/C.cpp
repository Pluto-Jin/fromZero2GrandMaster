#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> p;
	p.resize(n);
	for (auto &i:p) cin>>i;

	vector<int> zo[2];
	int prev=-1;
	int zos[2]={0},zoe[2]={0},evod[2]={0};
	int cnt=0,ans=0,tmp=-1;
	for (int i=0;i<n;i++) {
		if (!p[i]) cnt++;
		else {
			tmp=p[i]%2;
			evod[tmp]+=1;
			if (prev==-1) zos[tmp]=cnt;
			else if (prev%2!=tmp) ans+=1;
			else zo[tmp].push_back(cnt); 
			prev=p[i];
			cnt=0;
		}
	}
	if (tmp==-1) {
		if (n==1) cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	if (cnt) zoe[tmp]=cnt;
	int even=n/2-evod[0];
	int odd=n-n/2-evod[1];
	sort(zo[0].begin(),zo[0].end());
	sort(zo[1].begin(),zo[1].end());
	for (int i=0;i<zo[0].size();i++) {
		if (even>=zo[0][i]) even-=zo[0][i];
		else ans+=2;
	}
	for (int i=0;i<zo[1].size();i++) {
		if (odd>=zo[1][i]) odd-=zo[1][i];
		else ans+=2;
	}
	if (zos[0]!=0 and even<zos[0]) ans+=1;
	else even-=zos[0];
	if (zos[1]!=0 and odd<zos[1]) ans+=1;
	else odd-=zos[1];
	if (zoe[0]!=0 and even<zoe[0]) ans+=1;
	if (zoe[1]!=0 and odd<zoe[1]) ans+=1;

	cout<<ans<<endl;
	


}
