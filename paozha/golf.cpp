#include"golf.h"
using namespace std;
Bank::Bank()
{
	na="NULL";
	zh="NULL";
	mon=0.0;
}

Bank::Bank(const std::string & dna,const std::string &dzh,double money)
{
	na=dna;
	zh=dzh;
	mon=money;
}

Bank::~Bank()
{
}
void Bank::show()
{
	cout<<"name= "<<na<<" count= "<<zh<<" money= "<<mon<<endl;
}

void Bank::input(double mo)
{
	mon+=mo;
	cout<<"Now money="<<mon<<endl;
}

void Bank::output(double mo)
{
	if(mon-mo<0)
	{
		cout<<"This count have not enough money!"<<endl;
		return;
	}
	mon-=mo;
	cout<<"Now count have money:"<<mon<<endl;
}