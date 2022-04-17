#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,7,1,2,2,2,1,1};
	int length=sizeof(a)/sizeof(a[0]);
	int visit=-1;

	for(int i=0;i<length;i++)
	{
		for(int j=i+1;j<length && a[i]!=visit;j++)
		{
			if(a[i]==a[j])
			{
				a[j]=visit;
			}
		}
	}
	for(int i=0;i<length;i++)
	{
		if(a[i] != visit)
		{
			cout<<a[i]<<"\n";
		}
	}
}