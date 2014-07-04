#include "SmartPointer.h"
#include <iostream>
using namespace std;
class SimpleTest{
public:
	SimpleTest(int i) :t(i){};
	int t;
};
void test(){
	SmartPointer<SimpleTest> sp1(new SimpleTest(1));
	SmartPointer<int> sp2(new int(2));
	cout << "sp1->t:" << sp1->t << endl;
	cout << "sp1.get:" << sp1.get()->t << endl;
	cout << "*sp2:" << *sp2 << endl;
	sp2.reset();
	SmartPointer<SimpleTest> sp3(new SimpleTest(2));
	sp1 = sp3;
	cout << "sp1 count" << sp1.use_count() << endl;
	SmartPointer<SimpleTest> sp4(sp1);
	cout << "sp3 count" << sp3.use_count() << endl;
}
int main()
{
	test();
	system("pause");
}