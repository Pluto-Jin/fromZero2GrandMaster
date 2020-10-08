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

const int N=-1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		int ans=1e8,last[4]={0,N,N,N};
		for (int i=0;i<s.size();i++) {
			if (s[i]=='1') ans=min(ans,i-min(last[2],last[3])+1);
			if (s[i]=='2') ans=min(ans,i-min(last[1],last[3])+1);
			if (s[i]=='3') ans=min(ans,i-min(last[1],last[2])+1);
			last[s[i]-'0']=i;
		}
		cout<<(ans==1e8?0:ans)<<endl;
	}
}

