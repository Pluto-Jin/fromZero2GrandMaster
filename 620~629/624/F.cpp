#include "bits/stdc++.h"
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define mp make_pair
#define pb push_back
const int N=2e5+5;
int x[N],v[N];
int main()
{
	int n;
	vector<pii> ar,br,cr;
	ll as,bs,cs;
	for (int i=0;i<n;i++) cin>>x[i];
	for (int i=0;i<n;i++) cin>>v[i];

	for (int i=0;i<n;i++) {
		if (v[i]<0) {ar.pb(mp(v[i],x[i]));as+=x[i];}
		if (v[i]>0) {br.pb(mp(v[i],x[i]));bs+=x[i];}
		if (v[i]==0) {cr.pb(mp(v[i],x[i]));cs+=x[i];}
	}
	sort(ar.begin(),ar.end());
	sort(br.begin(),br.end());
	sort(cr.begin(),cr.end());

	ll ans=0;
	int a=ar.size(),b=br.size(),c=cr.size();
	for (int i=0;i<ar.size();i++) {
		
	}

}
