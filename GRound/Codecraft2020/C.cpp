#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,p;
	cin>>n>>m>>p;
	vector<int> ar,br;
	ar.resize(n);
	br.resize(m);
	for (auto &i:ar) cin>>i;
	for (auto &i:br) cin>>i;
	int i=0,j=0;
	while (ar[i]%p==0) i++;
	while (br[j]%p==0) j++;
	cout<<i+j<<endl;

	
}
