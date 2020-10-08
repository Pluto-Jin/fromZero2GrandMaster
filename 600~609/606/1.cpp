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
		vector<bool> ans(s.size());
		for (int i=0;i<(int)s.size()-2;i++) {
			string tmp=s.substr(i,3);
			if (i<(int)s.size()-4 and s.substr(i,5)=="twone") ans[i+2]=1,i+=4;
			else if (tmp=="one" or tmp=="two") ans[i+1]=1;
		}
		int cnt=0;
		for (auto i:ans) if (i) cnt++;
		cout<<cnt<<endl;
		for (int i=0;i<s.size();i++) if (ans[i]) cout<<i+1<<' ';
		cout<<endl;
	}
}

