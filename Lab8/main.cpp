#include <cassert>
#include <iostream>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;

int main()
{
	FixedVector<int, 5> intVector;
	assert(intVector.GetCapacity() == 5);
	assert(intVector.GetSize() == 0);
	assert(intVector.GetIndex(0) == -1);
	assert(!intVector.Remove(0));
	assert(!intVector[0]);

	for (auto i = 0; i != 5; ++i)
	{
		assert(intVector.Add(i));
		assert(intVector.GetCapacity() == 5);
		assert(intVector.GetSize() == i + 1);
		assert(intVector.Get(i) == i);
	}
	
	
	assert(intVector.Remove(1));
	assert(intVector.Get(4) == NULL);
	
	
	FixedVector<int*, 5> fv;
	fv.Add(new int(3));
	
	
	FixedVector<int*, 5> fv2 = fv;
	assert(*fv2[0] == 3);
	assert(&fv[0] != &fv2[0]);
	
	fv2.Add(new int(5));
	assert(*fv2[1] == 5);
	//assert(*fv[1] == 0);
	assert(fv.GetSize() == 1);

	FixedVector<int*, 5> fv3;
	fv3.Add(new int(1));
	fv3.Add(new int(2));
	fv3.Add(new int(3));
	
	
	FixedVector<int*, 5> fv4;
	fv4 = fv3;
	assert(*fv3[0] == *fv4[0]);
	assert(&fv3[0] != &fv4[0]);



	return 0;
}