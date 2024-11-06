#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = { 4,5,2,1,12,313,22,50 };

    // 150보다 큰수를 찾고 싶다.
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

    // 람다함수 
    // => 무명함수
    // 람다식
    // [캡쳐](매개변수) -> 반환식 { 함수식 }
    // - 캡쳐부분에 원본을 전달할 수 있다. ref
    // - 캡쳐부분에 위에있는 지역변수를 모두 전달할 수 있다. =

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

    // v 정렬 

    return 0;
}