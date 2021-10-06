#include<iostream>
using namespace std;
int main()
{
	int count=0;
	string s;
	cout<<"Enter string:";
	getline(cin,s);
	std::string::iterator i;
	std::string::reverse_iterator j;
	j=s.rbegin();
	for(i=s.begin();i!=s.end();i++)
	{
		if(*i!=*j)
		{
			count++;
		}
		j++;
	}
	if(count>0)
	{
		cout<<"Not palindrome";
	}
	else
	{
		cout<<"Palindrome";
	}
}
	
