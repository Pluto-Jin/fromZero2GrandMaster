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

const int N=1001;
struct node {
	int x,y;
	bool operator<(const node &tmp) const {
		return x*y<tmp.x*tmp.y;
	}
} a[N];

void print(vi &a) {
	if (a.empty()) cout<<0;
	else for (auto i:a) cout<<i;
	cout<<endl;
}
vi operator*(vi &a,int b) {
	vi c; int tmp=0;
	for (int i=(int)a.size()-1;~i;i--) tmp+=a[i]*b,c.pb(tmp%10),tmp/=10;
	while (tmp) c.pb(tmp%10),tmp/=10;
	reverse(c.begin(),c.end());
	return c;
}
vi operator/(vi &a,int b) {
	vi c; int tmp=0,fg=0; 
	for (auto i:a) {
		tmp=tmp*10+i;
		if (tmp>=b or fg) c.pb(tmp/b),tmp%=b,fg=1;
	}
	return c;
}
bool operator<(const vi &a,const vi &b) {
	if (a.size()!=b.size()) return a.size()<b.size();
	for (int i=0;i<a.size();i++) if (a[i]!=b[i]) return a[i]<b[i];
	return 0;	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	vi cur,ans; cur.pb(1);
	for (int i=0;i<=n;i++) {
		chkmax(ans,cur/a[i].y);
		cur=cur*a[i].x;	
	}
	print(ans);
	
	return 0;
}
