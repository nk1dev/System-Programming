#include <iostream>
using namespace std;
template<typename T>
class List
{
private:
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        Node* pPrev;
        T data;

        Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };
    int SizeList;
    Node<T>* First;
    Node<T>* Last;
public:
    List()
    {
        SizeList = 0;
        First = Last = nullptr;
    }
    ~List()
    {
        Clear();
    }
    int Count() { return SizeList; }
    void Insert(T data, int index)
    {
        if (index <= 0) InsertFront(data);
        else
        {
            if (index >= SizeList) InsertBack(data);
            else
            {
                Node<T>* temp = First;
                int count = 0;
                while (temp != nullptr)
                {
                    if (count == index - 1)
                    {
                        Node<T>* element = new Node<T>(data);
                        element->pNext = temp->pNext;
                        element->pPrev = temp;
                        temp->pNext = element;
                        element->pNext->pPrev = element;
                        SizeList++;
                        break;
                    }
                    count++;
                    temp = temp->pNext;
                }
            }
        }




    }
    void InsertFront(T data)
    {
        if (First == nullptr)
        {
            First = Last = new Node<T>(data);
        }
        else
        {
            Node<T>* element = new Node<T>(data);
            element->pNext = First;
            First->pPrev = element;
            First = element;
        }
        SizeList++;
    }
    void InsertBack(T data)
    {
        if (First == nullptr)
        {
            First = Last = new Node<T>(data);
        }
        else
        {
            Node<T>* element = new Node<T>(data);
            Last->pNext = element;
            element->pPrev = Last;
            Last = element;
        }
        SizeList++;
    }
    void Delete(int index)
    {
        if (index <= 0) DeleteFront();
        else
        {
            if (index > SizeList || index == SizeList - 1) DeleteBack();
            else
            {
                Node<T>* temp = First;
                int count = 0;
                while (temp != nullptr)
                {
                    if (count == index - 1)
                    {
                        Node<T>* toDelete = temp->pNext;
                        temp->pNext = toDelete->pNext;
                        temp->pNext->pPrev = temp;
                        delete toDelete;
                        SizeList--;
                        break;

                    }
                    count++;
                    temp = temp->pNext;
                }

            }
        }
    }
    void DeleteFront()
    {
        if (First != nullptr)
        {
            Node<T>* temp = First;
            First = First->pNext;
            if (SizeList > 1)
                First->pPrev = nullptr;
            SizeList--;
            delete temp;
        }
    }
    void DeleteBack()
    {
        if (First != nullptr)
        {
            Node<T>* temp = Last;
            Last = Last->pPrev;
            Last->pNext = nullptr;
            SizeList--;
            delete temp;
        }
    }
    T& operator[](const int index)
    {
        int count = 0;

        Node<T>* temp = First;

        while (temp != nullptr)
        {
            if (count == index)
            {
                return temp->data;
            }
            temp = temp->pNext;
            count++;
        }
    }
    void Clear()
    {
        while (SizeList) DeleteFront();
    }

};
int main()
{
    setlocale(LC_ALL, "ru");
    List<int> list;
    list.InsertBack(5);
    list.InsertFront(1);
    list.InsertFront(6666);
    list.Insert(666, 1);
    list[2] = 5;
    for (int i = 0; i < list.Count(); i++)
    {
        cout << list[i] << endl;
    }
    cout << "" << endl;
    cout << "Удаление элемента " << endl;
    list.Delete(2);
    for (int i = 0; i < list.Count(); i++)
    {
        cout << list[i] << endl;
    }
    cout << "" << endl;
    List<string>lst;
    lst.InsertBack("Элент №2");
    lst.InsertFront("Элент №344");
    lst.InsertFront("Элент №244");
    for (int i = 0; i < lst.Count(); i++)
    {
        cout << lst[i] << endl;
    }
    cout << "" << endl;
    cout << "Удаление элемента" << endl;
    lst.DeleteFront();
    for (int i = 0; i < lst.Count(); i++)
    {
        cout << lst[i] << endl;
    }
    return 0;
}