#include<iostream>
using namespace std;
void get();
double demandPaging(double a,double b,double c,double d,double e);

double service_page_fault_notModified;
double service_page_fault_modified;
double memory_access_time;
double percentage_page_modified;
double effective_access_time;
double page_fault_rate;

int main()
{
	cout<<"Demand paging "<<"\n";
	get();
}

void get()
{
	cout<<"Enter time(in milliseconds) to service page fault if an empty frame is available or if the replaced page is not modified"<<"\n";
	cin>>service_page_fault_notModified;
	cout<<"Enter time[in millideconds) to modify replaced page: "<<"\n";
	cin>>service_page_fault_modified;
	cout<<"Enter memory access time(in nanoseconds): "<<"\n";
	cin>>memory_access_time;
	cout<<"Percentage of page to be replaced is modified : "<<"\n";
	cin>>percentage_page_modified;
	cout<<"Enter effective access time(in nanoseconds) :"<<"\n";
	cin>>effective_access_time;	
	page_fault_rate=demandPaging(memory_access_time,percentage_page_modified,service_page_fault_modified,service_page_fault_notModified,effective_access_time);
	cout<<"Maximum acceptable page fault rate for an effective access time is: "<<page_fault_rate;
}

double demandPaging(double m_a_t,double p_p_m,double s_p_f_m,double s_p_f_nm,double e_a_t)
{
	double s_p_f_m_ns=s_p_f_m*1000000;
	double s_p_f_nm_ns=s_p_f_nm*1000000;
	
	double percentage_page_modified_per_page=percentage_page_modified/100;
	double up=effective_access_time-memory_access_time;
	double down=(percentage_page_modified_per_page*s_p_f_m_ns)+((1-percentage_page_modified_per_page)*s_p_f_nm_ns)-memory_access_time;
	return(up/down);
}
