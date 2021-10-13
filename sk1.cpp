#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	cout<<"Date is:";
	time_t now;
	struct tm *current;
	time(&now);
	current=localtime(&now);
	cout<<asctime(current)<<endl;
	return 0;
}
	
