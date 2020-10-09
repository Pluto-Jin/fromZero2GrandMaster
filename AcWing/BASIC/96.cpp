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

int a3[13],a4[13];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=1;i<=12;i++) a3[i]=a3[i-1]*2+1;
	memset(a4,0x3f,sizeof(a4));
	a4[0]=0;
	for (int i=1;i<=12;i++) for (int j=0;j<i;j++) 
		a4[i]=min(a4[i],a4[j]+a3[i-j]+a4[j]);

	for (int i=1;i<=12;i++) cout<<a4[i]<<endl;
}
