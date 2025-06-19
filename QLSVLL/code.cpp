#include "func.h"

int main()
{
    StudentList list;
    // Student a("123","Duong Hoai Duc",18);
    // Student c("124","Duong Van Anh",25);
    // Student b("125","Nguyen Van Anh",28);
    // initList(list);
    // addTail(list,a);
    // addTail(list,b);
    // addTail(list,c);
    // displayList(list);
    // loadToFileBin("output.bin",list);

    char path[] = "input.txt";
    readFromFileText(path,list);
    rmAll(list);
    return 0;
}


