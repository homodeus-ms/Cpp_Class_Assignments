#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		typename vector<K>::const_iterator k_Iter = keys.begin();
		typename vector<V>::const_iterator v_Iter = values.begin();

		while (k_Iter != keys.end() && v_Iter != values.end())
		{
			if (m.find(*k_Iter) == m.end())
			{
				pair<K, V> p(*k_Iter++, *v_Iter++);
				m.insert(p);
			}
			else
			{
				k_Iter++;
			}
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());

		typename map<K, V>::const_iterator iter;

		for (iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(m.size());

		typename map<K, V>::const_iterator iter;
		for (iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(v.size());

		typename vector<T>::const_reverse_iterator riter;
		for (riter = v.rbegin(); riter != v.rend(); ++riter)
		{
			rv.push_back(*riter);
		}

		return rv;
	}

	template <typename T>
	inline void InsertVectorToSet(set<T>& tempSet, const vector<T>& v)
	{
		typename vector<T>::const_iterator iter;
		for (iter = v.begin(); iter != v.end(); ++iter)
		{
			tempSet.insert(*iter);
		}
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		combined.reserve(v1.size() + v2.size());
		set<T> tempSet;

		InsertVectorToSet(tempSet, v1);
		InsertVectorToSet(tempSet, v2);

		for (typename set<T>::iterator iter = tempSet.begin(); iter != tempSet.end(); ++iter)
		{
			combined.push_back(*iter);
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		typename map<K, V>::const_iterator iter;

		for (iter = m1.begin(); iter != m1.end(); ++iter)
		{
			combined.insert(*iter);
		}

		for (iter = m2.begin(); iter != m2.end(); ++iter)
		{
			combined.insert(*iter);
		}


		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		typename vector<T>::const_iterator iter;
		for (iter = v.begin(); iter + 1 != v.end(); ++iter)
		{
			os << *iter << ", ";
		}
		os << *iter;

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			os << "{ " << it->first << ", " << it->second << " }" << endl;
		}

		return os;
	}
}