#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		int ans=0,tmp=-1;
		for (int i=0;i<=s.size();i++) if (!s[i] or s[i]=='R') {ans=max(ans,i-tmp);tmp=i;}	
		cout<<ans<<endl;
	}
}
