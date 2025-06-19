#include "func.h"

Student inputData()
{
    Student tmp;
    cin >> tmp.ID;
    cin.ignore();
    cin.getline(tmp.name, 100);
    cin >> tmp.age;
    return tmp;
}

Node *createNode(Student q)
{
    Node *p = new Node;
    p->data = q;
    p->next = nullptr;
    return p;
}

void initList(StudentList &list)
{
    list.head = nullptr;
    list.tail = nullptr;
}

void addTail(StudentList &list, Student p)
{
    Node *tmp = createNode(p);
    if (!list.head)
    {
        list.head = tmp;
        list.tail = tmp;
    }
    else
    {
        list.tail->next = tmp;
        list.tail = tmp;
    }
}

void rmHead(StudentList &list)
{
    if (list.head)
    {
        if (list.head == list.tail)
        {
            delete list.head;
            list.head = nullptr;
            list.tail = nullptr;
        }
        else
        {
            Node *nextHead = list.head->next;
            delete list.head;
            list.head = nextHead;
        }
    }
}
void rmAll(StudentList &list)
{
    while (list.head)
    {
        rmHead(list);
    }
}

void displayStudent(Student p)
{
    cout << setw(12) << p.ID << " | " << setw(20) << p.name << " | " << setw(3) << p.age << endl;
}

void displayList(StudentList list)
{
    Node *cur = list.head;
    while (cur)
    {
        displayStudent(cur->data);
        cur = cur->next;
    }
    cout << endl;
}

void loadToFileBin(char fileName[], StudentList list)
{
    fstream output(fileName, ios::binary | ios::out);
    if (!output.is_open())
    {
        cout << "Can not open file " << fileName << endl;
        return;
    }

    Node *cur = list.head;
    while (cur)
    {
        output.write((char *)(&cur->data), sizeof(Student));
        cur = cur->next;
    }
    cout << "Save successfully!" << endl;
    output.close();
}

void readFromFileBin(char path[], StudentList &list)
{
    if (list.head)
        rmAll(list);
    initList(list);

    fstream input(path, ios::binary | ios::in);
    if (!input.is_open())
    {
        cout << "Can not open file " << path << endl;
        return;
    }
    Student tmp;
    while (input.read((char *)(&tmp), sizeof(Student)))
    {
        addTail(list, tmp);
    }
    cout << "Successfully read from file: " << endl;
    displayList(list);
    input.close();
}

void readFromFileText(char path[], StudentList list)
{
    if(list.head) rmAll(list);
    initList(list);
    fstream input(path, ios::in);

    char buffer[1000];
    while(input.getline(buffer, 1000))
    {
        Student bufferStudent;
        char* token = strtok(buffer,"|");
        strcpy(bufferStudent.ID,token);
        token = strtok(NULL, "|"); 
        strcpy(bufferStudent.name,token);
        token = strtok(NULL,"|");
        bufferStudent.age = atoi(token);
        addTail(list,bufferStudent);
    }
    cout<<"Read successfully from file!"<<endl;
    input.close();
}

void loadToFileText(char path[], StudentList list)
{
    ofstream output(path, ios::out);
    if(!output.is_open())
    {
        cout<<"Can not open file "<<path<<endl;
        return;
    }

    //Format 
    Node* cur = list.head;
    while(cur)
    {
        output<<cur->data.ID<<"|"<<cur->data.name<<"|"<<cur->data.age<<endl;
        cur = cur->next;
    }

    cout<<"Save successfully to file "<<path<<endl;

    output.close();
}