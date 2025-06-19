#include "myClass.h"

int main(){
    Human* someone = new Student("Nguyen Van A",1);
    Human* anotherOne = new Teacher("Nguyen Van Be",1000000);
    Human a;
    someone->mua_quat();
    anotherOne->mua_quat();

    delete someone; someone = nullptr;
    delete anotherOne; anotherOne = nullptr;
    // delete someone;
    // delete anotherOne;
    return 0;
}