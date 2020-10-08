#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int main()
{
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	vector<ll> ar;
	vector<int> pts;
	ar.resize(n);
	int ans=0;
	for (auto &i:ar) {
		cin>>i;
		if (i<=a or i%(a+b) and i%(a+b)<=a) {
			ans++;
			continue;
		}
		if (!k) continue;
		int tmp;
		if (i%(a+b)==0) tmp=b;
		else tmp=i%(a+b)-a;
		pts.emplace_back(tmp/a+(tmp%a!=0));
	}
	sort(pts.begin(),pts.end());
	for (auto i:pts) {
		if (k<i) break;
		k-=i;
		ans++;
	}
	cout<<ans<<endl;
}

