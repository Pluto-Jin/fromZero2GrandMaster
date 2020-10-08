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
		int n,m; cin>>n>>m;
		vector<string> ar(n);
		for(auto &i:ar) cin>>i;
		int pos=-1;
		for (int i=0;i<m;i++) {
			for (auto s:ar) if (s[i]!=ar[0][i]) {pos=i;break;}
			if (pos!=-1) break;
		}	
		if (pos==-1) {cout<<ar[0]<<endl; continue;}
		if (m==1) {cout<<'a'<<endl; continue;}
		vi tmp[26];
		set<int> let; 
		for (int i=0;i<n;i++) let.insert(ar[i][pos]-'a'),tmp[ar[i][pos]-'a'].pb(i);
		int ok=0;
		for (auto c:let) {
			string s;
			vector<string> q;
			for (int i=0;i<26;i++) {
				if (i!=c) {
					for (auto j:tmp[i]) {
						string x=ar[j].substr(0,pos)+ar[j].substr(pos+1,m-pos-1);
						if (!s.size()) s=x;
						if (s!=x) {s="";break;}
					}
					if (tmp[i].size() and !s.size()) break;
				}
				else for (auto j:tmp[i]) q.pb(ar[j].substr(0,pos)+ar[j].substr(pos+1,m-pos-1));  
			}
			if (s.size()) {
				int cnt=0;
				for (auto i:q) {
					for (int j=0;j<m-1;j++) if (s[j]!=i[j]) cnt++;
					if (cnt>1) break;
					else cnt=0;
				} 
				if (!cnt) {
					for (int i=0;i<pos;i++) cout<<s[i]; cout<<char('a'+c);
					for (int i=pos;i<m-1;i++) cout<<s[i]; cout<<endl;		
					ok=1; break;
				}
			}
		}
		if (!ok) cout<<-1<<endl;
	}
}


