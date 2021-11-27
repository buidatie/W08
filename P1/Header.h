#ifndef Header_h
#define Header_h
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

class ArraySort
{
public:
	virtual void process(vector <float>& a) = 0;
};

class SelectionS : public ArraySort
{
public:
	void process(vector <float>& a)
	{
		int temp;
		for (int j = 0; j < a.size() - 1; ++j) {
			int min = a.at(j);
			temp = j;
			for (int i = j + 1; i < a.size(); ++i) {
				if (min > a.at(i)) {
					min = a.at(i);
					temp = i;
				}
			}
			swap(a.at(j), a.at(temp));
		}
	}
};

class InsertionS : public ArraySort
{
public:
	void process(vector < float>& a)
	{
		int temp, j;
		for (int i = 1; i < a.size(); i++)
		{
			temp = a.at(i);
			j = i - 1;
			while (j >= 0 && a.at(j) > temp)
			{
				a.at(j + 1) = a.at(j);
				j = j - 1;
			}
			a.at(j + 1) = temp;
		}
	}
};

class Interchange : public ArraySort
{
public:
	void process(vector <float >& a)
	{
		for (int i = 0; i < a.size() - 1; i++)
			for (int j = i + 1; j < a.size(); j++)
				if (a.at(i) > a.at(j))
					swap(a.at(i), a.at(j));
	}
};

class SATest : public ProgramFrame
{
	ArraySort* alg;
	vector <float> Data;
	int n;
public:
	SATest() { alg = NULL; }
	SATest(ArraySort* arrS) {
		//*alg = new SATest;
		alg = arrS;
	}

	void input(istream& is) {
		is >> n;
		if (n <= 0)
		{
			return;
		}
		Data.resize(n);
		for (int i = 0; i < Data.size(); i++)
			is >> Data[i];
	}

	bool check() {
		return Data.size() > 0;
	}
	void output(ostream& os)
	{
		for (int i = 0; i < Data.size(); i++)
			os << Data[i] << "\t";
	}
	void startMess(ostream& os)
	{
		os << "Nhap n, arr[0],...,arr[n-1]: ";
	}
	void process() {
		if (alg != NULL)
			alg->process(Data);
	}
};

/*class sortArray
{
protected:
	int *arr;
	int size;
public:
	int getSize()
	{
		return this->size;
	}
	int* getArr()
	{
		return this->arr;
	}
	void setArr(int i, int n)
	{
		this->arr[i] = arr[n];
	}

	sortArray()
	{
		this->size = 1;
		this->arr = new int[this->size]();
	}
	sortArray(const sortArray& temp)
	{
		this->size = temp.size;
		delete[] this->arr;
		this->arr = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = temp.arr[i];
		}
	}

	friend istream& operator>> (istream& is, sortArray& ps);
	friend ostream& operator<< (ostream& os,const sortArray& ps);

	sortArray& operator=(const sortArray& ps)
	{
		if (this == &ps)
			return *this;

		delete[] arr;
		this->size = ps.size;
		this->arr = new int[this->size];

		for (int i = 0; i < ps.size; i++)
		{
			this->arr[i] = ps.arr[i];
		}
		return *this;
	}

	~sortArray()
	{
		delete[] arr;
	}
};

class SelectionS : public sortArray
{
public:
	SelectionS() : sortArray() {};
	void selection();
};

class InsertionS : public sortArray
{
public:
	InsertionS() : sortArray() {};
	void insertion();
};

class InterchangeS : public sortArray
{
public:
	InterchangeS() : sortArray() {};
	void interchange();
};*/

#endif