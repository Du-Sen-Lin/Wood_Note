#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const std::vector<float>& nums = { 1, 3, 5, 6 };

template<typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c, Index i){
    return std::forward<Container>(c)[i];
}



int main() {
    cout<<authAndAccess(nums, 1)<<endl;

    const int theAnswer = 42;

    auto x = theAnswer;
    auto y = &theAnswer;
	std::cout << typeid(x).name() << std::endl;
	std::cout << typeid(y).name() << std::endl;


    return 0;
}
