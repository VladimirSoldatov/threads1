#include<iostream>
#include<thread>
#include<chrono>
#include<string>
using namespace std;
void doSomeThing(int &a) 
{
	cout << "================== = run_do_something========================\n";
	for (int i = 0; i < 10; i++) 
	{
		cout << this_thread::get_id() << "\t" << i<<"+" << "\n";
		a *= 2;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
	cout << "================== = end_do_something========================\n";
	
}
int main() 

{
	cout << clock();
	int q = 2;
	thread myThead(doSomeThing,ref(q));
	cout << "=================main====================================\n";
	for (int i = 0; i < 10; i++)
	{
		
		cout << this_thread::get_id() <<" main flow "<<i <<" " << '\n';
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	myThead.join();

	cout << q << endl;
}