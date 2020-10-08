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

const int N=1e5+1;
int n,m;
ll cnt[N];
struct edge{int x,y; ll w;};
vector<edge> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y,w; cin>>x>>y>>w;
		cnt[x]-=w; cnt[y]+=w;
	}
	vi rich,poor;
	for (int i=1;i<=n;i++) {
		if (cnt[i]>0) rich.pb(i); 
		else if (cnt[i]<0) poor.pb(i); 
	}
	int p1=0,p2=0;
	while (p1<rich.size() and p2<poor.size()) {
		int id1=rich[p1],id2=poor[p2];
		ll &a=cnt[id1],&b=cnt[id2];
		if (a==-b) {
			ans.pb({id2,id1,a});
			p1++,p2++;
		} else if (a>-b) {
			ans.pb({id2,id1,-b});
			a+=b; p2++;
		} else {
			ans.pb({id2,id1,a});
			b+=a; p1++;
		}	
	}
	cout<<ans.size()<<endl;
	for (auto i:ans) cout<<i.x<<' '<<i.y<<' '<<i.w<<endl;

}
	/*
	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int x,y; ll w; cin>>x>>y>>w;
		if (!vis[mpp(x,y)]) {
			vis[mpp(x,y)]=1;
			edge[x].pb(y);
			edge[y].pb(x);
		}
		if (x<y) dic[mp(x,y)]+=w;
		else dic[mp(y,x)]-=w;
	}
	for (int i=1;i<=n;i++) {
		vi pos,neg;
		for (auto x:edge[i]) {
			ll tmp=dic[mpp(i,x)];
			if (i<x and tmp>0 or i>x and tmp<0) pos.pb(x);
			else if (i<x and tmp<0 or i>x and tmp>0) neg.pb(x);
		}
		int pp=0,pn=0;
		while (pp<pos.size() and pn<neg.size()) {
			int pid=pos[pp],nid=neg[pn];
			ll &a=dic[mpp(i,nid)],&b=dic[mpp(i,pid)],&c=dic[mpp(nid,pid)];
			ll aa=abs(a),bb=abs(b);
			if (!vis[mpp(nid,pid)]) vis[mpp(nid,pid)]=1,edge[pid].pb(nid),edge[nid].pb(pid); 

			if (aa==bb) {
				if (nid<pid) c+=aa; else c-=aa;
				a=b=0; pp++,pn++;
			} else if (aa>bb) {
				if (nid<pid) c+=bb; else c-=bb;
				if (nid<i) a-=aa-bb; else a+=aa-bb;
				b=0; pp++;
			} else {
				if (nid<pid) c+=aa; else c-=aa;
				if (i<pid) b-=bb-aa; else b+=bb-aa;
				a=0; pn++;
			}
		}
	}
	vii ans;
	for (int i=1;i<=n;i++) for (auto x:edge[i]) 
		if (x>i and dic[mp(i,x)]) ans.pb(mp(i,x));
	cout<<ans.size()<<endl;
	for (auto i:ans) {
		if (dic[i]>0) cout<<i.fi<<' '<<i.se<<' '<<dic[i]<<endl;
		else cout<<i.se<<' '<<i.fi<<' '<<-dic[i]<<endl;
	}
}
*/

