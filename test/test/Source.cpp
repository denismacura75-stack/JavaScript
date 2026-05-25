#include <iostream>
using namespace std;
class baseClass {
public:
	virtual void Show() { cout << "Base class" << endl; }
};
class firstD : public baseClass {
public:
	void Show() { cout << "First Derived Class" << endl; }
};
class secondD : public baseClass {
};

int main()
{
	baseClass ObjB;
	baseClass* bp;
	firstD ObjF;
	secondD ObjS;
	bp = &ObjB;
	bp->Show();
	bp = &ObjF;
	bp->Show();
	bp = &ObjS;
	bp->Show();

	return 0;
}

