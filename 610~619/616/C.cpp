#include "bits/stdc++.h"
using namespace std;

int t,n,m,k;
int tmp,ttmp,c,nc;
int l,r;
vector<int> ar;


int main()
{
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>k;
		ar.clear();
		ar.resize(n);
		for (auto &i:ar) cin>>i;
		
		c=min(k,m-1);
		nc=max(0,m-1-k);
		ttmp=0;

		for (int i=0;i<=c;i++)
		{
			tmp=1e9;
			for (int j=i;j<=i+nc;j++)
			{
				
				tmp=min(tmp,max(ar[j],ar[j+n-c-nc-1]));
			}
			ttmp=max(ttmp,tmp);
		}
		cout<<ttmp<<endl;
	}
}
