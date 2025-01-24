#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value, Node* next, Node* prev) : data(value), next(next), prev(prev) {}
};

class List {
    Node* head;
    Node* tail;
    int size;
public:
    List()
    {
        head = tail = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr, tail);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty()) {
            throw exception("List is empty"); // ТУТ ВИНЯТОК ДЗ n1
        }

        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforeLast = tail->prev;
        beforeLast->next = nullptr;
        delete tail;
        tail = beforeLast;
    }

    bool IsEmpty()const
    {
        return head == nullptr;
    }
    void Show()const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->data << " ";
        }cout << "\n";
    }
    void Clear() {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    int GetSize()const
    {
        int size = 0;
        for (Node* i = head; i != nullptr; i = i->next)
        {
            size++;
        }
        return size;
    }


    void SetSize(int size, int grow) {
        if (size == GetSize() || size == 0) {
            throw exception("size is the same or 0"); // ТУТ ВИНЯТОК ДЗ n1
        }
        if (size > GetSize()) {
            for (int i = 0; i < size - GetSize() - grow; i++) {
                this->AddToTail(NULL);
            }
        }
        else if (size < GetSize()) {
            for (int i = 0; i < GetSize() - size + grow; i++) {
                this->DeleteFromTail();
            }
        }


        for (int i = 0; i < grow; i++) {
            this->AddToTail(0);
        }
    }
    int GetUpperBound() {
        for (Node* i = head; i != nullptr; i = i->next) {
            int index = 0;
            if (i->data != NULL) {
                continue;
            }
            else if (i->data == NULL) {
                return index;
            }
        }

    }

    void FreeExtra() {
        for (Node* i = head; i != nullptr; i = i->next) {
            if (i->data == NULL) {
                delete i;
            }
        }
    }
    void RemoveAll() {
        for (Node* i = head; i != nullptr; i = i->next) {
            delete i;
        }
    }
    void GetAt(int index) const {
        int count = 0;
        for (Node* i = head; i != nullptr; i = i->next) {
            if (count == index) {
                cout << i->data;
            }
            count++;
        }
    }

    void SetAt(int index, int value) {
        if (index >= GetSize()) {
            throw exception("Index out of range"); // ТУТ ВИНЯТОК ДЗ n1
        }

        int count = 0;
        for (Node* i = head; i != nullptr; i = i->next) {
            if (count == index) {
                i->data = value;
            }
            count++;
        }
    }

    Node* operator[](int index) {
        int count = 0;
        for (Node* i = head; i != nullptr; i = i->next) {
            if (count == index) {
                return i;
            }
            count++;
        }
    }


    void Add(int value) {
        if (GetSize() >= GetUpperBound()) {
            SetSize(GetSize() + 1, 1);
        }
        AddToTail(value);
    }

    void Append(List list) {
        for (Node* i = list.head; i != nullptr; i = i->next) {
            Add(i->data);
        }
    }
    void operator=(List list) {
        Clear();
        for (Node* i = list.head; i != nullptr; i = i->next) {
            Add(i->data);
        }
    }

    int* GetData() {
        if (head == nullptr) {
            return nullptr;
        }
        return &head->data;
    }

    void InsertAt(int index, int value) {


        if (index == 0) {
            AddToHead(value);
        }
        else if (index == GetSize()) {
            AddToTail(value);
        }
        else {
            Node* newNode = new Node(value, nullptr, nullptr);
            Node* prevNode = head;
            for (int i = 0; i < index - 1; i++) {
                prevNode = prevNode->next;
            }
            newNode->next = prevNode->next;
            prevNode->next = newNode;
        }
    }

    void RemoveAt(int index) {

        if (index == 0) {
            DeleteFromHead();
        }
        else if (index == GetSize() - 1) {
            DeleteFromTail();
        }
        else {
            Node* prevNode = head;
            for (int i = 0; i < index - 1; i++) {
                prevNode = prevNode->next;
            }
            Node* removeNode = prevNode->next;
            prevNode->next = removeNode->next;
            delete removeNode;
        }
    }

    void DeleteFromHead() {
        if (IsEmpty()) {
            throw exception("List is empty"); // ТУТ ВИНЯТОК ДЗ n1
        }

        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }



    ~List()
    {
        Clear();
    }
};

//===========================================================

class drib
{
public:
    int znamenik;
    int chiselnik;

public:
    void setZnamenik(int _znamenik)
    {
        if (_znamenik == 0) throw exception("Division by zero"); // ТУТ ВИНЯТОК ДЗ n2
        znamenik = _znamenik;
    }

    void setChiselnik(int _chiselnik)
    {
        chiselnik = _chiselnik;
    }

    drib operator+(const drib other) const
    {
        drib result;
        result.znamenik = this->znamenik * other.znamenik;
        result.chiselnik = this->chiselnik * other.znamenik + other.chiselnik * this->znamenik;
        return result;
    }

    drib operator-(const drib other) const
    {
        drib result;
        result.znamenik = this->znamenik * other.znamenik;
        result.chiselnik = this->chiselnik * other.znamenik - other.chiselnik * this->znamenik;
        return result;
    }

    drib operator*(const drib other) const
    {
        drib result;
        result.znamenik = this->znamenik * other.znamenik;
        result.chiselnik = this->chiselnik * other.chiselnik;
        return result;
    }

    drib operator/(const drib other) const
    {
        if(other.znamenik == 0) throw exception("Division by zero"); // ТУТ ВИНЯТОК ДЗ n2
        if(other.chiselnik == 0) throw exception("Division by zero"); // ТУТ ВИНЯТОК ДЗ n2
        drib result;
        result.znamenik = this->znamenik * other.chiselnik;
        result.chiselnik = this->chiselnik * other.znamenik;
        return result;
    }

};







int main()
{

    // Всі траї і кетчі тут
    cout << "2347";
}