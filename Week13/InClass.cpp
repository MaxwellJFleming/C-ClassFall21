#include <iostream>
#include <string>
#include <vector>

void autoStuff()
{
    // // auto is cool and fun and never will fail you trust me
    // auto i = 10;    //bad. hard to tell what it's gonna do
    // auto vect = new std::vector<int>(); //better use
    
    // // how to iterate thru a vector
    // for (std::vector<int>::iterator it = vect->begin(); it != vect->end(); it++)
    // {

    // }

    // // make it easier with auto!
    // for (auto it = vect->begin(); it != vect->end(); it++)
    // {

    // }

    // // range-based for loop
    // for (int i : *vect)
    // {

    // }
}

struct MyType
{
    MyType()
    {
        std::cout << "Yay I'm alive!" << std::endl;
    }

    MyType(const MyType &src)
    {
        std::cout << "I'm a copy!" << std::endl;
    }

    MyType(const MyType &&src)
    {
        std::cout << "I've been moved" << std::endl;
    }

    ~MyType()
    {
        std::cout << "bye" << std::endl;
    }
};

int getSomething(MyType t)
{
    std::cout << "Hit" << std::endl;
    return 0;
}

int foo(MyType &&t)
{
    std::cout << "Moved" << std::endl;
    return 0;
}

MyType &&bat()
{
    MyType t = MyType();
    return std::move(t);
}

// there are different types of errors that need to be handled differently
template <class T> class Result
{
    bool success;
    std::string error;
    T data;

public:
    Result(std::string error){
        this->success = false;
        this->error = error;
    }
    Result(T data){
        this->success = true;
        this->data = data;
    }

    bool IsSuccess()
    {
        return success;
    }
    std::string GetError()
    {
        if (!this->success){
            return this->error;
        }
        throw "Cannot Get Error From Successful Result";
    }

    T getData() {
        if (this->success){
            return this->data;
        }
        throw "Cannot Return Data From Failed Result";
    }

    static Result<T> * Ok(T data){
        return new Result(data);
    }

    static Result<T> *Failure(std::string error){
        return new Result(error);
    }
};

class Atm
{
    int amount = 10000;
public:
    Result<int> *withdraw(int x)
    {
        if(this->amount < x){
            return Result<int>::Failure("Not Enough Funds");
        }
        int result = amount;
        this->amount -= x;

        return Result<int>::Ok(result);
    }
};

template <class T> bool isGreaterThan(T a, T b)
{
    return a > b;
}

struct CoolStruct
{
public:
    int val;
    
    CoolStruct(int i){
        this->val = i;
    }

    bool operator > (CoolStruct &rhs)
    {
        return this->val > rhs.val;
    }
};

int main()
{
    MyType t = MyType();

    // getSomething makes a copy of t which only lives for as long as getSomething is running.
    // AVOID COPYING because it's expensive. *unless* it's something really small like an int. This is what pointers are for; to avoid this situation.
    getSomething(t);

    //alternatively, you could use...

    // r-value reference. Use && and std::move(). Only in c++11 and newer.
    // allows you to pass things by value by moving the object rather than creating a whole new copy.
    foo(std::move(t));

    bat();

    // makes vectors nicer to use too! (Harder to type tho)
    auto vect = std::vector<MyType>();
    vect.push_back(std::move(t));
    vect.push_back(std::move(t));
    vect.push_back(std::move(t));
    vect.push_back(std::move(t));

    Atm a = Atm();

    Result<int> *result = a.withdraw(20000);

    if(result->IsSuccess()){
        std::cout << "Okay" << std::endl;
    }
    else {
        std::cout << result->GetError() << std::endl;
    }

    std::cout << isGreaterThan(4, 3) << std::endl;

    auto t1 = CoolStruct(4);
    auto t2 = CoolStruct(3);
    std::cout << isGreaterThan(t1, t2) << std::endl;

    return 0;
}