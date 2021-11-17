#include <iostream>

struct ChildTest
{
    ChildTest()
    { 
        std::cout << "ChildTest Initialized" << std::endl;
    }

    ~ChildTest()
    {
        std::cout << "ChildTest DeInitialized" << std::endl;
    }
};

struct Test
{
    private:
        ChildTest *m_child_test;
    
    public:
        Test()
        { 
            m_child_test = new ChildTest();
            std::cout << "Test Initialized" << std::endl;
        }

        ~Test()
        { 
            delete m_child_test;
            std::cout << "Test DeInitialized" << std::endl;
        }
};

Test *create_test()
{
    return new Test();
}

int main()
{
    Test t = Test();
    Test *PointerTest = create_test();
    delete PointerTest;
    return 0;
}