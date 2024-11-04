#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<set>




using namespace std;

void PrintVector(const vector<int>& vec)
{
	cout << "{";
	
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it != vec.begin())
		{
			cout << ", ";
		}
		cout << *it;
	}
	cout << "}" << endl;
}

bool bigger(const int i)
{
	return i > 15;
};

int main()
{
	vector<int> v = { 3,2,4,10,3,3,4,11,250,1,211 };

	//1이 있는지 찾아라. 그리고 index나 iterator를 반환하라.
	cout << "Q1. find number : [1]. and return index or iterator" << endl;

	int index = 0;
	vector<int>::iterator it1_for = v.begin();
	for (it1_for; it1_for != v.end(); it1_for++)
	{
		if (*it1_for == 1)
		{
			break;
		}
		index++;
	}

	//cout << "find" << " : " << *it1_for << ". at : " << index << endl;

	vector<int>::iterator it1_algo = find(v.begin(), v.end(), 1111);
	if (it1_algo != v.end())
	{
		cout << "find" << " : " << *it1_algo << ". at : " << it1_algo - v.begin() << endl;
	}

	//15보다 큰 수가 있는지 찾아라, index 또는 iterator 자리를 찾아라.
	cout << endl << "Q2. find number greater than [15]. and return index or iterator" << endl;

	struct Find_Functor
	{
		bool operator()(const int& element)
		{
			if (checkLess)
			{
				if (element < compareNum)
					return true;
			}
			else
			{
				if (element > compareNum)
					return true;
			}
			return false;
		}
		int compareNum = 0;
		bool checkLess = false;
	};

	//find 
	Find_Functor functor;
	functor.compareNum = 15;
	vector<int>::iterator it2_algo = find_if(v.begin(), v.end(), functor);
	cout << "find" << " : " << *it2_algo << ". at : " << it2_algo - v.begin() << endl;

	// 모든 수가 50보다 작은지 bool으로 알려주세요.
	// use for...
	cout << endl << "Q3. Check all numbers less than [50]. and return index or iterator" << endl;
	vector<int>::iterator it3 = v.begin();
	for (it3; it3 != v.end(); it3++)
	{
		if (*it3 > 50)
		{
			break;
		}
	}
	if (it3 == v.end())
	{
		cout << "All Numbers are less than [50]." << endl;
	}
	else
	{
		cout << "One or more numbers are not less than [50]." << endl;
	}
	//use algorythm...
	Find_Functor functor3;
	functor3.compareNum = 50;
	functor3.checkLess = true;
	if (all_of(v.begin(), v.end(), functor3))
	{
		cout << "All Numbers are less than [50]." << endl;
	}
	else
	{
		cout << "One or more numbers are not less than [50]." << endl;
	}


	// 하나라도 30보다 큰 수가 있는지 bool으로 알려주세요.
	cout << endl << "Q4. Find out if any of the numbers are greater than [30]." << endl;

	// use for...
	vector<int>::iterator it4 = v.begin();
	for (it4; it4 != v.end(); it4++)
	{
		if (*it4 > 30)
			break;
	}
	if (it4 == v.end())
	{
		cout << "No number greater than [30] was found." << endl;
	}
	else
	{
		cout << "One or more numbers are greater than [30]." << endl;
	}

	//use algorythm...
	Find_Functor functor4;
	functor4.compareNum = 30;

	if (any_of(v.begin(), v.end(), functor4))
	{
		cout << "One or more numbers are greater than [30]." << endl;
	}
	else
	{
		cout << "No number greater than [30] was found." << endl;
	}


	// 원소가 3인 원소들의 개수를 알려주세요.

	// use for...
	cout << endl << "Q5. Count the number of elements whose values are [3]." << endl;
	vector<int>::iterator it5 = v.begin();
	int countQ5 = 0;
	for (it5; it5 != v.end(); it5++)
	{
		if (*it5 == 3)
			countQ5++;
	}
	cout << "find " << countQ5 << " numbers." << endl;

	//use algorythm...
	cout << "find " << count(v.begin(), v.end(), 3) << " numbers." << endl;


	// 원소가 5보다 큰 원소들의 개수를 알려주세요.
	cout << endl << "Q6. Count the number of elements whose values are greater than [5]." << endl;
	//use for...
	vector<int>::iterator it6 = v.begin();
	int countQ6 = 0;
	for (it6; it6 != v.end(); it6++)
	{
		if (*it6 > 5)
			countQ6++;
	}
	cout << "find " << countQ6 << " numbers." << endl;

	//use algorythm...
	Find_Functor functor6;
	functor6.compareNum = 5;

	cout << "find " << count_if(v.begin(),v.end(), functor6) << " numbers." << endl;

	// 모든 원소에 3을 곱해주세요.
	//transform

	cout << endl << "Q7. Multiply all numbers by [3]." << endl;
	// use for...
	vector<int> v7;
	vector<int>::iterator it7 = v.begin();
	for (it7; it7 != v.end(); it7++)
	{
		v7.push_back(*it7 * 3);
	}
	PrintVector(v7);

	// use algorythm...

	struct MultipleFunctor
	{
		int operator()(const int& value)
		{
			
			return value * mul;
		}
		int mul;
	};
	
	MultipleFunctor functor7;
	functor7.mul = 3;
	vector<int> v7_algo;
	v7_algo.resize(v.size());
	transform(v.begin(), v.end(), v7_algo.begin(), functor7);
	PrintVector(v7_algo);
	// 중복된 원소들을 '제거'해주세요.
	cout << endl << "Q8. Remove duplicate numbers." << endl;
	// use for...
	vector<int> v8;
	vector<int>::iterator it8 = v.begin();
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (find(v8.begin(), v8.end(), *it) == v8.end())
		{
			v8.push_back(*it);
		}
	}

	PrintVector(v8);

	// use other container
	set<int> st;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		st.insert(*it);
	}

	cout << "{";
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		if (it != st.begin())
		{
			cout << ", ";
		}
		cout << *it;
	}
	cout << "}" << endl;
		
	// use algorythm...
	vector<int> v8_algo = v;
	sort(v8_algo.begin(), v8_algo.end());
	vector<int>::iterator it8_algo = unique(v8_algo.begin(), v8_algo.end());
	v8_algo.resize(distance(v8_algo.begin(), it8_algo));
	PrintVector(v8_algo);


	// 원소가 12인 원소를 지워주세요.
	// remove

	cout << endl << "Q9. Delete elements whose value [12]." << endl;

	vector<int> v9 = v;
	vector<int>::iterator it9_algo = remove(v9.begin(), v9.end(), 12);
	v9.resize(distance(v9.begin(), it9_algo));
	PrintVector(v9);


	// 원소가 10보다 작은 원소들을 지워주세요.

	cout << endl << "Q10. Delete elements whose value are less then [10]." << endl;
	Find_Functor functor10;
	functor10.checkLess = true;
	functor10.compareNum = 10;

	vector<int> v10 = v;
	
	vector<int>::iterator it10_algo = remove_if(v10.begin(), v10.end(), functor10);
	v10.resize(distance(v10.begin(), it10_algo));
	PrintVector(v10);

	
	return 0;
}