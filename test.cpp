#include <iostream>
using namespace std;

struct Foo
{
    void bah(Foo& f) const {cout << "v";}
}foo;

const Foo foo2;
int main()
{
    foo2.bah(foo);
}