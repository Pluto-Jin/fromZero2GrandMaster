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

	int n,m,ma=0; cin>>n>>m;
	ll sum=0;
	vi ar(m),ans(m);
	for (int i=0;i<m;i++) {
		cin>>ar[i];
		ma=max(ma,ar[i]+i);
		sum+=1ll*ar[i];
	}
	if (ma>n or sum<n) cout<<-1<<endl;
	else {
		sum=sum-n;
		ans[0]=1;
		for (int tail=1+ar[0],i=1;i<m;i++) {
			int fw=min(1ll*tail-ans[i-1]-1,sum);
			sum-=fw;
			ans[i]=tail-fw;
			tail=ans[i]+ar[i];
		}
		for (auto i:ans) cout<<i<<' ';
		cout<<endl;
	}
	//why it is a judgement failed????
}

