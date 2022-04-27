#include "../../lib/include/sysiphos.h"

using namespace sysiphos;

int main()
{
    Car toyota(new KTM());

    toyota.Move();

    Motorcycle honda(new Honda());

    honda.Move();

    return 0;
}
