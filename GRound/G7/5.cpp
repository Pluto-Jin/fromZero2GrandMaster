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


const int N=3e5+1;
int pos[N];

//a maximum segment tree
#define mid ((l+r)>>1)
#define lch (x<<1)
#define rch (x<<1|1)

int n,ar[N],t[N<<2],mrk[N<<2]; 
void mark(int x,int v) {mrk[x]+=v; t[x]+=v;}
void down(int x) {if (mrk[x]) mark(lch,mrk[x]),mark(rch,mrk[x]),mrk[x]=0;}
void up(int x) {t[x]=max(t[lch],t[rch]);} //

void build(int x=1,int l=1,int r=n) {
	if (l==r) t[x]=ar[l],mrk[x]=0;
	else build(lch,l,mid),build(rch,mid+1,r),up(x);
}

void update(int L,int R,int v,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return mark(x,v);
	down(x);
	if (mid>=L) update(L,R,v,lch,l,mid);
	if (mid+1<=R) update(L,R,v,rch,mid+1,r);
	up(x);
}

int query(int L,int R,int x=1,int l=1,int r=n) {
	if (L<=l and r<=R) return t[x];
	down(x);
	int a=-1e9,b=-1e9; //
	if (mid>=L) a=query(L,R,lch,l,mid);
	if (mid+1<=R) b=query(L,R,rch,mid+1,r);
	return max(a,b); //
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) cin>>ar[i],pos[ar[i]]=i;
	int cur=n;
	update(1,pos[cur],1);
	vi ans;
	for (int i=1;i<=n;i++) {
		while (query(1,n)<=0) update(1,pos[--cur],1);
		ans.pb(cur);
		int tmp; cin>>tmp;
		update(1,tmp,-1);
	}
	for (auto i:ans) cout<<i<<' ';
	cout<<endl;
}

