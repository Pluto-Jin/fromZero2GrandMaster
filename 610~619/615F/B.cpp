#include "bits/stdc++.h"
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define se second

int comp(pii x,pii y) {
	if (x.fi!=y.fi) return x.fi<y.fi;
	else return x.se<y.se;
}
int main()
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<pii> ar;
		for (int i=0;i<n;i++) {
			int x,y;
			cin>>x>>y;
			ar.push_back(mp(x,y));
		}
		sort(ar.begin(),ar.end(),comp);
		int xx=0,yy=0,flag=0;
		string s="";
		for (auto i:ar) {
			int x=i.fi,y=i.se;
			if (x<xx or y<yy) {flag=1;break;}
			while (x>xx) {xx++;s+="R";}
			while (y>yy) {yy++;s+="U";}
		}
		if (flag) {cout<<"NO"<<endl;continue;}
		else {
			cout<<"YES"<<endl;
			cout<<s<<endl;
		}

	}
}
