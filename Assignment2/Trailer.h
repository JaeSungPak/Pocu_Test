#pragma once



namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);
		Trailer(const Trailer& other);
		virtual ~Trailer();

		unsigned int GetWeight() const;

	private:
		int mWeight;
		Trailer* mPointer;
		friend class Sedan;
	};
}