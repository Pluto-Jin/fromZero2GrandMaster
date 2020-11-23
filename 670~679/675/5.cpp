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

const int N=1e5+1;
string res[N];
int ans[N],dif[N],n;

void build(int id,string &s) {
	if (s.size()<=10) for (int i=(int)s.size()-1;~i;i--) res[id]+=s[i];
	else {
		res[id]+=s[0];
		res[id]+=s[1];
		res[id]+="...";
		for (int i=0;i<5;i++) res[id]+=s[i+s.size()-5];
		reverse(res[id].begin(),res[id].end());
	}
	ans[id]=s.size();
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	string a,s; cin>>a;
	n=a.size();
	int x=n-1,y=n-1;
	for (int i=n-1;~i;i--) {
		if (s.empty()) {
			s+=a[i];
			dif[i]=y=x=i;
		} else if (s.back()==a[i]) {
			if (x==i+1 and a[dif[x]]<=a[i]) s.ppb(),x=y;
			else s+=a[i],dif[i]=dif[x],y=x,x=i;
		} else s+=a[i],dif[i]=y=x,x=i;
		build(i,s);
	}
	for (int i=0;i<n;i++) cout<<ans[i]<<' '<<res[i]<<endl;

	return 0;
}
