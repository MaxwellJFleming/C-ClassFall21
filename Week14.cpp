#include <iostream>
#include <string>
#include <vector>
#include <memory> // for smart pointers

// Lambda functions
template <class T> bool greater_than(T lhs, T rhs, std::function<T()>)
{
  
}
// idk bro this shits wack

// Smart pointers
// Introducted in std11 (so objectively better in all regards)
// Three types of smart pointers: Unique, shared, weak (don't worry about weak)
// Unique can only be owned by one process. Gets passed around rather than referenced. Deleted when process falls out of scope.
// g++ doesn't seem to like unique pointers?
// Shared can share references out. Only when all references fall out of scope will the pointer be deleted.
struct Foo
{
public:
  ~Foo ()
  {
    std::cout << "Foo out!" << std::endl;
  }
};

struct Buzz
{
private:
  std::shared_ptr<Foo> m_s;

public:
  Buzz (std::shared_ptr<Foo> s)
  {
    m_s = s;
  }

  ~Buzz ()
  {
    std::cout << "Buzz out!" << std::endl;
  }
};

int main()
{
  std::shared_ptr<Foo> gamer = std::make_shared<Foo>();

  Buzz *b = new Buzz(gamer);
  delete b;

  Buzz *b2 = new Buzz(gamer);
  delete b2;

  Buzz *b3 = new Buzz(gamer);
  delete b3;

  return 0;
}