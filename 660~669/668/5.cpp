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

const int N=3e5+1;
int n,q,ar[N],bs,fen[N],ans[N];
vii qry[N];

void update(int x,int v=-1) {for(;x<=n;x+=x&-x)fen[x]+=v;}
int query(int x) {int res=0;for(;x;x-=x&-x)res+=fen[x];return res;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>ar[i],ar[i]-=i;
	for (int i=1;i<=q;i++) {
		int l,r; cin>>l>>r;
		qry[n-r].pb(mp(i,l+1));
	}
	for (int i=1;i<=n;i++) {
		if (ar[i]<=0 and bs+query(1)>=-ar[i]) {
			int lo=1,hi=i+1;
			while (lo<hi-1) {
				int mid=lo+hi>>1;
				if (bs+query(mid)>=-ar[i]) lo=mid;
				else hi=mid;
			}
			bs++;
			update(hi);
		}
		for (auto [id,l]:qry[i]) ans[id]=bs+query(l);
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
}
