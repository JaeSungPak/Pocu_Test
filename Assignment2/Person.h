#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		Person(const Person& other);
		virtual ~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;
		
	private:
		std::string mName;
		int mWeight;
		Person* mPointer;
		friend class Vehicle;
		friend class Boatplane;
	};
}