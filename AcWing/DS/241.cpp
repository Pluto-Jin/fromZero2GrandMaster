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
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

const int N=2e5+1;
int n,a[N],fen[N],ans[N];

void update(int x,int v) {for(;x<=n;x+=x&-x)fen[x]+=v;}
int query(int x) {int y=0;for(;x;x-=x&-x)y+=fen[x];return y;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		update(a[i],1);
		ans[i]=query(a[i]-1);
	}
	memset(fen,0,sizeof fen);
	ll res[2]={0};
	for (int i=n;i;i--) {
		update(a[i],1);
		ll tmp=query(a[i]-1);
		res[1]+=tmp*ans[i];
		res[0]+=1ll*(n-i-tmp)*(i-1-ans[i]);
	}
	cout<<res[0]<<' '<<res[1]<<endl;
	
	return 0;
}
