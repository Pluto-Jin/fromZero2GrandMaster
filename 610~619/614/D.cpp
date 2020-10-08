#include "bits/stdc++.h"
using namespace std;

long long int x,y,bx,by;
int ax,ay;
long long int x0,y0,t;
int i,j,ans=0,stop;
long long int pre,tmp,step;
long long int xi,yi,xc,yc;

long long int dis(long long int x0,long long int y0, long long int x1, long long int y1)
{
	return abs(x0-x1)+abs(y0-y1);
}

int main()
{
	cin>>x>>y>>ax>>ay>>bx>>by;
	cin>>x0>>y0>>t;
	//cout<<"g";
	xi=x;
	yi=y;

	step=dis(x0,y0,x,y);
	pre=step;
	ans=0;
	stop=0;
	while (not stop)
	{
		ans++;
		x=ax*x+bx;
		y=ay*y+by;
		tmp=dis(x0,y0,x,y);
		//cout<<pre<<" "<<tmp<<" "<<x<<" "<<y<<endl;
		if (tmp>=pre)
		{
			x=(x-bx)/ax;
			y=(y-by)/ay;
			stop=1;
		}
		pre=tmp;
	}
	//cout<<tmp<<" "<<x<<" "<<y<<" "<<ans<<endl;
	//cout<<x0<<" "<<y0<<endl;
	xc=x;
	yc=y;
	
	if (dis(x0,y0,xc,yc)+dis(xc,yc,xi,yi)>t)
	{
		ans=0;
		step=dis(x0,y0,x,y);
		while (step<=t)
		{
			ans++;
			x=(x-bx)/ax;
			y=(y-by)/ay;
			if (x<xi and y<yi)
				break;
			step+=dis(ax*x+bx,ay*y+by,x,y);
		}
		if (step>t and not xc<=x0 and yc<=y0)
		{
			x=(x-bx)/ax;
			y=(y-by)/ay;

		}
	}
	else
	{
		ans--;
		while (step<=t)
		{
			ans++;
			x=ax*x+bx;
			y=ay*y+by;
			step=min(dis(xi,yi,x0,y0),dis(x,y,x0,y0))+dis(xi,yi,x,y);
		}
	}
	cout<<ans<<endl;
}
