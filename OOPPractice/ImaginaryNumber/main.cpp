#include "func.h"

int main()
{

    SoPhuc a(3, 4), b(1, 2);
    SoPhuc c = a.cong(b);
    SoPhuc d = a.tru(b);
    SoPhuc e = a.nhan(b);
    SoPhuc f = a.chia(b);

    c.output();
    d.output();
    e.output();
    f.output();
    return 0;
}