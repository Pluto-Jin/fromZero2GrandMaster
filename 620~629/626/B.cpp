#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se first
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;

const int N=50000;
int a[N],b[N],ar[N],br[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m,k;
	cin>>n>>m>>k;
	for (int i=0;i<n;i++) cin>>ar[i];
	for (int i=0;i<m;i++) cin>>br[i];

	int tmp=0;
	for (int i=0;i<n;i++) {
		if (ar[i]) {tmp++;}
		else {for (int j=1;j<=tmp;j++) a[j]+=tmp-j+1;tmp=0;}
	}
	for (int j=1;j<=tmp;j++) a[j]+=tmp-j+1;

	tmp=0;
	for (int i=0;i<m;i++) {
		if (br[i]) {tmp++;}
		else {for (int j=1;j<=tmp;j++) b[j]+=tmp-j+1;tmp=0;}
    }
	for (int j=1;j<=tmp;j++) b[j]+=tmp-j+1;

	ll ans=0;
	for (int i=1;i<=floor(sqrt(k)+0.5);i++)
		{if (k%i==0) if (k/i>40000) continue; else {if (i!=k/i) ans+=1ll*a[i]*b[k/i]+1ll*a[k/i]*b[i]; else ans+=1ll*a[i]*b[i];}}
	cout<<ans<<endl;

}
