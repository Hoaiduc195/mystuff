#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

Node *createNode(int x)
{
    Node *p = new Node;
    p->val = x;
    p->next = nullptr;
    return p;
}

void initList(LinkedList &list)
{
    list.tail = nullptr;
    list.head = nullptr;
}

void addTail(LinkedList &list, int x)
{
    Node *p = createNode(x);
    if (!list.head)
    {
        list.head = p;
        list.tail = p;
    }
    else
    {
        list.tail->next = p;
        list.tail = p;
    }
}

void rmHead(LinkedList &list)
{
    if (list.head)
    {
        if (list.tail == list.head)
        {
            delete list.head;
            list.tail = list.head = nullptr;
        }
        else
        {
            Node *tmp = list.head->next;
            delete list.head;
            list.head = tmp;
        }
    }
}

void rmAll(LinkedList &list)
{
    while (list.head)
    {
        rmHead(list);
    }
}

void rmAfterNode(Node *p)
{
    if (p->next)
    {
        if (p->next->next)
        {
            Node *tmp = p->next->next;
            delete p->next;
            p->next = tmp;
        }
        else
        {
            delete p->next;
            p->next = nullptr;
        }
    }
}

void addHead(LinkedList &list, int x)
{
    Node *p = createNode(x);
    if (!list.head)
    {
        list.head = list.tail = p;
    }
    else
    {
        p->next = list.head;
        list.head = p;
    }
}

void reverseList(LinkedList &list)
{
    LinkedList newList;
    initList(newList);
    Node *cur = list.head;
    while (cur)
    {
        addHead(newList, cur->val);
        cur = cur->next;
    }
    rmAll(list);
    list = newList;
}

void rmDup(LinkedList &list)
{
    if (list.head && list.head != list.tail)
    {
        Node *cur1 = list.head;
        while (cur1->next)
        {
            Node *cur2 = cur1;
            //bool stop = false;
            while (cur2->next)
            {
                if (cur1->val == cur2->next->val)
                {
                    rmAfterNode(cur2);
                    // stop = true;
                    continue;
                }
                cur2 = cur2->next;
                //stop = false;
            }
            cur1 = cur1->next;
        }
    }
}
void rmTail(LinkedList& list)
{
    if(list.head)
    {
        if(list.head == list.tail){
            delete list.head;
            list.head = list.tail = nullptr;
        }else{
            Node* cur = list.head;
            while(cur->next!=list.tail){
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr;
            list.tail = cur;
        }
    }
}

LinkedList mergeSortedList(LinkedList list1, LinkedList list2)
{
    if (!list1.head || !list2.head)
    {
        return (list1.head) ? (list1) : (list2);
    }
    Node *cur1 = list1.head;
    Node *cur2 = list2.head;
    LinkedList newList;
    initList(newList);
    while (cur1 && cur2)
    {
        if (cur1->val <= cur2->val)
        {
            addTail(newList, cur1->val);
            cur1 = cur1->next;
        }
        else
        {
            addTail(newList, cur2->val);
            cur2 = cur2->next;
        }
    }

    if (!cur1 && cur2)
    {
        newList.tail->next = cur2;
        newList.tail = list2.tail;
    }
    else if (cur1 && !cur2)
    {
        newList.tail->next = cur1;
        newList.tail = list1.tail;
    }

    return newList;
}

void readListFromFileText(char path[], LinkedList &list)
{
    if (list.head)
        rmAll(list);
    initList(list);
    ifstream input(path);
    if (!input.is_open())
    {
        cout << "Can not open the file " << path << endl;
        return;
    }

    int inp;
    while (input >> inp)
    {
        addTail(list, inp);
    }
    input.close();
}

void displayList(LinkedList list)
{
    Node *cur = list.head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

void saveListToFileText(char path[], LinkedList list)
{
    ofstream output(path);
    if (!output.is_open())
    {
        cout << "Can not open file " << path << endl;
        return;
    }

    Node *cur = list.head;
    while (cur)
    {
        output << cur->val << " ";
        cur = cur->next;
    }
    cout << "Save successfully to file " << path << endl;
    output.close();
}

void rmAllX(LinkedList& list, int x)
{
    Node* cur = list.head;
    if(cur)
    {
        while(list.head->val == x){
            rmHead(list);
        }
        while(list.tail->val == x){
            rmTail(list);
        }
        while(cur->next)
        {
            if(cur->next->val == x){
                Node* tmp = cur->next->next;
                delete cur->next;
                cur->next = tmp;
            }else{
                cur = cur->next;
            }
        }
    }
}
void rmDupli(LinkedList &list){
    Node* cur = list.head;
    if(cur){
        while(cur){
            bool stop = false;
            Node* move = cur;
            while(move->next){
                if(move->next->val == cur->val){
                    if(move->next == list.tail){
                        rmTail(list);
                    }else{
                        Node* tmp = move->next->next;
                        delete move->next;
                        move->next = tmp;
                    }
                    stop = 1;
                }else{
                    move = move->next;
                }
            }
            if(!stop){
                cur = cur->next;
            }
            
        }
    }
}

void reverse(LinkedList& list){
    LinkedList rev;
    initList(rev);
    Node* cur = list.head;
    while(cur){
        addHead(rev,cur->val);
        cur = cur->next;
    }
    rmAll(list);
    list = rev;
}

int main()
{
    LinkedList list;
    initList(list);
    readListFromFileText("input.txt",list);
    displayList(list);
    // rmAllX(list,12);
    // rmDupli(list);
    reverse(list);
    displayList(list);
    // cout<<list.tail->val<<endl;

    rmAll(list);
    return 0;
}