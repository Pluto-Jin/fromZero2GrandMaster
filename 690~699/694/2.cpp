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

const int N=3e5+1;
int n,ps[1001],a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=1;i<=1000;i++) ps[i]=i*i;
	int t; cin>>t;
	while (t--) {
		cin>>n;
		map<int,int> cnt;
		int ma=0,mm=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];	
			int cur;
			for (int j=1;j<=1000 and ps[j]<=a[i];j++) if (a[i]%ps[j]==0) cur=j;	
			cnt[a[i]/ps[cur]]++;
		}
		for (auto [x,y]:cnt) {
			chkmax(ma,y);
			if (x==1 or y%2==0) mm+=y;
		}
		int q; cin>>q;
		while (q--) {
			ll w; cin>>w;
			if (!w) cout<<ma<<endl;
			else cout<<max(mm,ma)<<endl;
		}
	}
	
	return 0;
}
