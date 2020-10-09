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

const int N=1e5+2;
int ar[N],br[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>ar[i],br[i]=ar[i]-ar[i-1];
	ll a=0,b=0;
	for (int i=2;i<=n;i++) if (br[i]>0) a+=br[i]; else if (br[i]<0) b-=br[i];
	if (a<b) swap(a,b);
	cout<<a<<endl<<a-b+1<<endl;
}
