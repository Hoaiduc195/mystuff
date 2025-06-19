#include "fraction.h"

int main()
{

    Fraction a(4, 7);
    Fraction b(3, 2);
    Fraction c;
    c = b+a;
    c.display();
    c = b-a;
    c.display();
    c = b*a;
    c.display();
    c = b/a;
    c.display();
    return 0;   
}