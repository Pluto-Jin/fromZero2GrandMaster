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
		int n; cin>>n;
		vi ar(n),br(n),ans; 
		for (int i=0;i<n;i++) cin>>ar[i],br[i]=ar[i];
		sort(br.begin(),br.end());
		reverse(br.begin(),br.end());
		for (int i=0;i<n-2;i++) {
			int pos=0;
			while (ar[pos]!=br[i]) pos++;
			while (pos<n-1-i) {
				int tmp=(pos?pos-1:pos),tmp1=ar[tmp],tmp2=ar[tmp+1],tmp3=ar[tmp+2];
				ans.pb(tmp);
				ar[tmp]=tmp3,ar[tmp+1]=tmp1,ar[tmp+2]=tmp2;
				pos++;
			}
		}
		if (ar[0]>ar[1]) {
			int pos=0;
			if (ar[0]==ar[2]) pos=1;
			else for (int i=2;i<n-1;i++) if (ar[i]==ar[i+1]) {pos=i;break;}
			if (!pos) {cout<<-1<<endl;continue;}
			for (int i=0;i<pos;i++) ans.pb(i),ans.pb(i);
		}
		cout<<ans.size()<<endl;
		for (auto i:ans) cout<<i+1<<' ';
		cout<<endl;
	}
}

