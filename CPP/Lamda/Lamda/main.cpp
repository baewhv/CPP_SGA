#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = { 4,5,2,1,12,313,22,50 };

    // 150���� ū���� ã�� �ʹ�.
    struct Finder
    {
        Finder() = default;

        bool operator()(const int& element)
        {
            if (element > compareNum)
                return true;
            return false;
        }

        int compareNum = 150;
    };

    // �����Լ� 
    // => �����Լ�
    // ���ٽ�
    // [ĸ��](�Ű�����) -> ��ȯ�� { �Լ��� }
    // - ĸ�ĺκп� ������ ������ �� �ִ�. ref
    // - ĸ�ĺκп� �����ִ� ���������� ��� ������ �� �ִ�. =

    int compareNum = 150;
    int temp = 1;

    auto iter = std::find_if(v.begin(), v.end(), [=](const int& element) -> bool
        {
            if (element > compareNum)
            {
                return true;
            }
            return false;
        });

    cout << *iter << endl;


    std::sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
        {
            if (a < b)
                return true;
            return false;
        });

    // v ���� 

    return 0;
}