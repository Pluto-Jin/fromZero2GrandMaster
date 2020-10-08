#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		int p1=0,p2=s.size()-1;
		while (p1<p2 and s[p1]==s[p2]) p1++,p2--; 
		if (p1>=p2) cout<<s<<endl;
		else {
			string tmp(s,p1,p2-p1+1),rs(tmp.rbegin(),tmp.rend()),a[2];
			a[0]=tmp+'#'+rs,a[1]=rs+'#'+tmp;
			vi lps[2];
			for (int i=0;i<2;i++) {
				lps[i].resize(a[i].size());
				int len=0,p=1;	
				while (p<a[i].size()) {
					if (a[i][p]==a[i][len]) lps[i][p++]=++len;
					else if (!len) lps[i][p++]=0;
					else len=lps[i][len-1];
				}
			}
			int x=lps[0].back(),y=lps[1].back();
			cout<<s.substr(0,p1)+(x>=y?s.substr(p1,x):s.substr(p2-y+1,y))+s.substr(p2+1)<<endl;
		}
	}
}

