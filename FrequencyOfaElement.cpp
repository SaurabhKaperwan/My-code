#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,8,3,2,2,2,5,1};
	int length=sizeof(a)/sizeof(a[0]);

	int temp[length];
	int visit=-1;

	for(int i=0;i<length;i++)
	{
		int count=1;
		for(int j=i+1;j<length;j++)
		{
			if(a[i]==a[j])
			{
				count++;
				temp[j]=visit;
			}
		}
		if(temp[i]!=visit)
			temp[i]=count;
	}
	for(int i=0;i<length;i++)
	{
		if(temp[i] != visit)
		{
			cout<<a[i]<<" "<<temp[i]<<"\n";
		}
	}
}