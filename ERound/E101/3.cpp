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

const int N=2e5+5;
int h[N],a[N],b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		for (int i=1;i<=n;i++) cin>>h[i],b[i]=0,a[i]=-1;
		int ok=1;
		a[1]=h[1],a[n]=h[n];
		if (h[1]>h[2]) b[1]=1;
		if (h[n]>=h[n-1]) b[n]=1;
		for (int i=2;i<n;i++) if (h[i]>=h[i-1] and h[i]>h[i+1]) b[i]=1,a[i]=h[i];
		for (int i=2;i<n;i++) if (h[i]<h[i-1] and h[i]<=h[i+1]) a[i]=h[i]+k-1;
		for (int i=1;i<=n;i++) if (b[i]==1) {
			for (int j=i-1;j>1 and a[j]==-1;j--) a[j]=max(a[j+1]+1-k,h[j]);
			for (int j=i+1;j<n and a[j]==-1;j++) a[j]=max(a[j-1]+1-k,h[j]);
		}
		for (int i=2;i<=n;i++) if (abs(a[i]-a[i-1])>k-1 or a[i]-h[i]>k-1) ok=0;
		cout<<(ok?"YES":"NO")<<endl;
	}
	
	return 0;
}
