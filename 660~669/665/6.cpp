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

const int N=(1<<18)+1;
int n;
ll fen[N];
void update(int x,int v) {for(;x<=1<<n;x+=x&-x)fen[x]+=v;} 
ll query(int x) {ll res=0;for(;x;x-=x&-x)res+=fen[x];return res;}
ll query(int l,int r) {return query(r)-query(l-1);}

int hbit(int x) {
	x|=x>>1; x|=x>>2; x|=x>>4; x|=x>>8; x|=x>>16;
	return x^x>>1;
}
ll get(int l,int r,int x) {
	ll res=0;
	int len=r-l+1,t=min(l&-l,hbit(len));
	if (!t) t=hbit(len);
	while (len) {
		int tmp=(l^x)&~(t-1);
		res+=query(tmp+1,tmp+t);
		len-=t,l+=t,t=min(l&-l,hbit(len));
		if (!t) t=hbit(len);
	}
	return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int q; cin>>n>>q;
	for (int i=0;i<1<<n;i++) {
		int x; cin>>x;
		update(i+1,x);
	}
	int cur=0;
	for (int i=0;i<q;i++) {
		int t; cin>>t;
		if (t==1) {
			int x,k; cin>>x>>k;
			x=(x-1^cur)+1;
			update(x,k-query(x,x));
		} else if (t==2) {
			int k; cin>>k;
			cur^=(1<<k)-1;
		} else if (t==3) {
			int k; cin>>k;
			cur^=1<<k;
		} else if (t==4) {
			int l,r; cin>>l>>r;
			cout<<get(l-1,r-1,cur)<<endl;
		}
	}
}

