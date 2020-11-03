#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
	
		unsigned int j = 0;
		unsigned int i = 0;

		for (; i < keys.size(); i++)
		{
			std::pair<std::map<K, V>::iterator, bool> check = m.insert(std::pair<K, V>(keys[i], values[j]));

			if (check.second)
			{
				j++;
			}

			if (j == values.size())
			{
				break;
			}
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		for (auto it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (auto it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		for (int i = v.size() - 1; i >= 0; i--)
		{
			rv.push_back(v[i]);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;

		for (unsigned int i = 0; i < v1.size(); i++)
		{
			bool same = false;

			for (unsigned int j = 0; j < combined.size(); j++)
			{
				if (v1[i] == combined[j])
				{
					same = true;
				}
			}

			if (!same)
			{
				combined.push_back(v1[i]);
			}
		}

		for (unsigned int i = 0; i < v2.size(); i++)
		{
			bool same = false;

			for (unsigned int j = 0; j < combined.size(); j++)
			{
				if (v2[i] == combined[j])
				{
					same = true;
				}
			}

			if (!same)
			{
				combined.push_back(v2[i]);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (auto it = m1.begin(); it != m1.end(); it++)
		{
			combined.insert(*it);
		}

		for (auto it = m2.begin(); it != m2.end(); it++)
		{
			combined.insert(*it);
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (unsigned int i = 0; i < v.size() - 1; i++)
		{
			os << v[i] << ", ";
		}

		os << v[v.size() - 1];

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (auto it = m.begin(); it != m.end(); it++)
		{
			os << "{ " << it->first << ", " << it->second << " }" << std::endl;
		}

		return os;
	}
}