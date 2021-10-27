#include <iostream>
#include <vector>
#include <map>

int fib(const int n){
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    std::vector<int> vect;
    vect.reserve(52);

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);

    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << vect.size() << std::endl;
    std::cout << vect.capacity() << std::endl;

    std::cout << fib(20) << std::endl;

    //std::map<int, int> m;
    //m = {{1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 5}, {6, 8}};
}