#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;
using namespace std;

int main()
{
	cout << "- PolyLine::AddPoint() -" << endl;
	PolyLine pl;

	assert(pl.AddPoint(1.0f, 2.0f) == true);
	assert(pl.AddPoint(new Point(2.0f, 3.0f)) == true);
	assert(pl.AddPoint(2.2f, 1.9f) == true);  // pl�� [1.0f, 2.0f], [2.0f, 3.0f], [2.2f, 1.9f]
	assert(pl.AddPoint(5.2f, 8.9f) == true);
	assert(pl.AddPoint(2.2f, 1.4f) == true);
	assert(pl.AddPoint(10.1f, 11.9f) == true);
	assert(pl.AddPoint(7.5f, 1.9f) == true);
	assert(pl.AddPoint(6.6f, 4.5f) == true);
	assert(pl.AddPoint(3.1f, 0.9f) == true);
	assert(pl.AddPoint(0.1f, 0.1f) == true);  // 10��° ��. �̶����� AddPoint()�� true�� ��ȯ.

	assert(pl.AddPoint(2.2f, 1.9f) == false);  // 11��° �� �߰� �õ�. AddPoint()�� false�� ��ȯ�ϰ� �� ���� PolyLine ��ü�� �߰����� �ʾƾ� ��.

	/*
	AddPoint �Ű������� �Էµ� Point ��ü�� �ٸ� PolyLine ��ü�� �����ϰų�
	���� �޸𸮿� �Ҵ��� �ϸ�, �Ҹ��� ������ �߻��Ѵ�.
	*/
	PolyLine pl2;
	Point* p1 = new Point(2.2f, 3.3f);
	assert(pl2.AddPoint(1.1f, 2.2f) == true);
	assert(pl2.AddPoint(p1) == true);
	assert(p1->GetX() == 2.2f && p1->GetY() == 3.3f);

	PolyLine pl3(pl2);
	Point* p2 = new Point(22.22f, 33.33f);
	assert(pl3.AddPoint(11.11f, 22.22f) == true);
	assert(pl3.AddPoint(p2) == true);
	assert(p2->GetX() == 22.22f && p2->GetY() == 33.33f);
	
	PolyLine* pl4 = new PolyLine(pl3);
	Point* p3 = new Point(222.22f, 333.33f);
	assert(pl4->AddPoint(11.11f, 22.22f) == true);
	assert(pl4->AddPoint(p3) == true);
	
	PolyLine* pl5 = pl4;
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == true);
	assert(pl5->AddPoint(11.11f, 22.22f) == false);
	assert(pl5->AddPoint(11.11f, 22.22f) == false);
	
	delete pl4;
	
	PolyLine pl6 = pl3;
	assert(pl6.AddPoint(11.11f, 22.22f) == true);
	assert(pl6.AddPoint(11.11f, 22.22f) == true);
	assert(pl6.AddPoint(new Point(55.5f, 66.6f)) == true);

	cout << "- PolyLine::AddPoint() - END -" << endl;
	

	return 0;
}