#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
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

const int N=2501;
pii a[N];
int cnt[N],vis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int c,l; cin>>c>>l;
	for (int i=0;i<c;i++) cin>>a[i].fi>>a[i].se;
	for (int i=0;i<l;i++) {
		int x,y; cin>>x>>y;
		cnt[x]+=y;
	}
	sort(a,a+c,[](pii x,pii y){
			if (x.se!=y.se) return x.se<y.se; return x.fi<y.fi;	});
	int ans=0;
	for (int i=1;i<=1000;i++) {
		for (int j=0;cnt[i] and j<c;j++) if (!vis[j]) 
			if (i<=a[j].se and i>=a[j].fi) cnt[i]--,vis[j]=1,ans++;
	}
	cout<<ans<<endl;
}
