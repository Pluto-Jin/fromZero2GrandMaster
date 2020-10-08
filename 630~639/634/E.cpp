#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,ma0=0,cnt0[201]={0}; cin>>n;
		vi ar(n); 
		for (auto &i:ar) {
			cin>>i;
			cnt0[i]++;
			ma0=max(ma0,cnt0[i]);
		}
		int ans=ma0;
		for (int a=1;a<=200;a++) {
			int na=cnt0[a]/2,odd=cnt0[a]%2;
			if (!na) continue;
			int p1=0,p2,cnt[201]={0},ma=0;
			for (int i=0;i<na;p1++) if (ar[p1]==a) i++;	
			p1--;
			for (p2=p1+1;ar[p2]!=a or odd--;p2++) cnt[ar[p2]]++,ma=max(ma,cnt[ar[p2]]);
			int cur=na*2+ma;
			while (--na) {
				while (ar[--p1]!=a) cnt[ar[p1]]++,ma=max(ma,cnt[ar[p1]]); 
				while (ar[++p2]!=a) cnt[ar[p2]]++,ma=max(ma,cnt[ar[p2]]); 
				cur=max(cur,na*2+ma);
			}
			ans=max(ans,cur);
		}
		cout<<ans<<endl;
	}
}

