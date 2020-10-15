#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int index = v.size();
		int sum = 0;

		for (int i = 0; i < index; i++)
		{
			sum += v[i];
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int min = INT_MAX;
		int index = v.size();

		for (int i = 0; i < index; i++)
		{
			min = v[i] > min ? min : v[i];
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int max = INT_MIN;
		int index = v.size();

		for (int i = 0; i < index; i++)
		{
			max = v[i] < max ? max : v[i];
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		int sum = Sum(v);

		return static_cast<float>(sum) / v.size();
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		int index = v.size();

		std::vector<int> element(v.size());
		std::vector<int> count(v.size());

		//v의 요소 개수 선별

		for (int i = 0; i < index; i++)
		{
			bool same = false;
			for (unsigned int j = 0; j < element.size(); j++)
			{
				if (v[i] == element[j])
				{
					count[j] += 1;
					same = true;
					break;
				}
			}
			if (!same)
			{
				element.push_back(v[i]);
				count.push_back(0);
			}
		}

		//가장 많은 수 선택

		int max = 0;

		for (unsigned int i = 0; i < count.size(); i++)
		{
			max = count[i] > count[max] ? i : max;
		}

		return element[max];
	}

	void SortDescending(std::vector<int>& v)
	{
		int index = v.size();

		for (int i = index - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (v[j] < v[j + 1])
				{
					int temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
				}
			}
		}
	}

}