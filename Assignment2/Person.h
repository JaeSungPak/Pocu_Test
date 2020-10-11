#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;
		Person* mPointer;
	private:
		std::string mName;
		int mWeight;
		
		friend class Vehicle;
	};
}