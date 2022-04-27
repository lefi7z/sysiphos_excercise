#include "../../lib/include/sysiphos.h"

using namespace sysiphos;

int main()
{
    Car toyota(new KTM());

    toyota.Move();

    return 0;
}
