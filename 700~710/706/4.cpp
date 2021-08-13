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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
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

const int N=1e5+5;
int a[N];
map<int,pii> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) if (a[i]>a[i-1] and a[i]>a[i+1]) s[i]={0,0};
	int ma=0;
	for (auto [x,o]:s) {
		int cnt=0;
		for (int i=x-1;i>0;i--,cnt++) if (a[i]>a[i+1]) break;
		s[x].fi=cnt; chkmax(ma,cnt); cnt=0;
		for (int i=x+1;i<=n;i++,cnt++) if (a[i]>a[i-1]) break;
		s[x].se=cnt; chkmax(ma,cnt);
	}
	int cnt=0,ok=0;
	for (auto [i,j]:s) {
		auto [x,y]=j;
		if (x==ma) cnt++;
		if (y==ma) cnt++;
		if (x==y and x==ma) ok=1,cnt--;
	}
	if (cnt>1 or !ok) cout<<0<<endl;
	else cout<<(ma%2==0)<<endl;
	
	return 0;
}
