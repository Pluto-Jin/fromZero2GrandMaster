#include "bits/stdc++.h"
using namespace std;

int prl(array<int,2> a,array<int,2> b)
{
	if (a[0]*(-1)!=b[0] or a[1]*(-1)!=b[1]) return 0;
	else return 1;
}
int main()
{
	int n;
	cin>>n;
	vector<array<int,2>> ar;
	vector<array<int,2>> br;
	ar.resize(n);
	br.resize(n);
	for (auto &i:ar) cin>>i[0]>>i[1];
	for (int i=0;i<n;i++)
	{
		br[i][0]=ar[i][0];
		br[i][1]=ar[i][1];
	}
	if (n%2) {
		cout<<"NO"<<endl;
		return 0;
	}
	for (int i=0;i<n;i++) {
		ar[i][0]-=br[(i+1)%n][0];
		ar[i][1]-=br[(i+1)%n][1];
	}
	for (int i=0;i<n/2;i++) {
		if (!prl(ar[i],ar[i+(n/2)])) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;

}
