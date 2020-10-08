#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int,string> pis;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	if (k>4*n*m-2*n-2*m) {cout<<"NO"<<endl;return 0;}

	vector<pis> ans;
	if (m-1) ans.pb(mp(min(k,m-1),"R"));
	k-=m-1;
	while (1) {
		if (k<=0) break;
		if (m-1) ans.pb(mp(min(k,m-1),"L"));
		k-=m-1;
		if (k<=0) break;
		for (int i=0;i<n-1;i++) { 
			ans.pb(mp(1,"D"));
			k-=1;
			if (k<=0) break;
			if (m-1) ans.pb(mp(min(k,m-1),"R"));
			k-=m-1;
			if (k<=0) break;
			
			if (k<3*(m-1)) {
				int tmp=k/3;
				if (tmp) ans.pb(mp(tmp,"UDL"));
				k-=3*tmp;
				if (k==1) ans.pb(mp(1,"U"));
				if (k==2) ans.pb(mp(1,"UD"));
				k=0;
				break;
			}
			if (m-1) ans.pb(mp(m-1,"UDL"));
			k-=3*(m-1);
			if (k<=0) break;
		}
		if (k<=0) break;

		if (n-1) ans.pb(mp(min(k,n-1),"U"));
		break;
	}
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	for (auto i:ans) cout<<i.fi<<" "<<i.se<<endl;
}
