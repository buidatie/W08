#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ProgramFrame
{
protected:
	virtual void startMess(ostream&);
	virtual void input(istream&) = 0;
	virtual bool check() = 0;
	virtual void errorMess(ostream&);
	virtual void output(ostream&) = 0;
	virtual void process() = 0;
	virtual bool Continue(istream&, ostream&);
public:
	void run(istream& is, ostream& os);
};

template<class T>
class SortArray {
public:
	virtual void process(vector<T>a);
};

template<class T>
class SATest :public ProgramFrame{
	SortArray* sa;
	vector<T> data;
	int n;
public:
	SATest() {
		SATest = NULL;
		n = 0;
	}
	SATest(SortArray* a)
};



class SelectionS {

};

class InsertionS {

};

class InterchangeS {

};