#include <iostream>
#include <string>
using namespace std;
struct PeoplDt
{
    string Name;
    string Surname;
    int Age;
    PeoplDt()
    {
        Name = "";
        Surname = "";
        Age = 0;
    };
    PeoplDt(string Name, string Surname, int Age)
    {
        this->Name = Name;
        this->Surname = Surname;
        this->Age = Age;
    }
    void Print()
    {
        cout << "\n";
        cout << " " << Name << " " << Surname << " " << Age << endl;
        cout << "\n";
    }
};
struct Element
{
    PeoplDt PData;
    Element* next;
    Element* pre;
    Element() { pre = next = nullptr; };

    Element(PeoplDt peopleData)
    {
        this->PData = peopleData;
        pre = next = nullptr;
    }
};
struct ListPeoples
{

    ListPeoples() { First = Last = nullptr; SizeList = 0; }
    ~ListPeoples() { Clear(); }

    void Print()
    {
        Element* temp = First;
        while (temp != nullptr)
        {
            temp->PData.Print();
            temp = temp->next;
        }
    }
    int Count() { return SizeList; }

    void Insert(PeoplDt peopleData, int index)
    {
        if (index < 0 || index == 0) InsertFront(peopleData);
        else
        {
            if (index > SizeList || index == SizeList) InsertBack(peopleData);
            else
            {
                Element* temp = First;
                int count = 0;
                while (temp != nullptr)
                {
                    if (count == index - 1)
                    {
                        Element* people = new Element(peopleData);
                        people->next = temp->next;
                        people->pre = temp;
                        temp->next = people;
                        people->next->pre = people;
                        SizeList++;
                        break;
                    }
                    count++;
                    temp = temp->next;
                }
            }
        }
    }
    void Delete(int index)
    {
        if (index < 0 || index == 0) DeleteFront();
        else
        {
            if (index > SizeList || index == SizeList - 1) DeleteBack();
            else
            {
                Element* temp = First;
                int count = 0;
                while (temp != nullptr)
                {
                    if (count == index - 1)
                    {
                        Element* toDelete = temp->next;
                        temp->next = toDelete->next;
                        temp->next->pre = temp;
                        delete toDelete;
                        SizeList--;
                        break;

                    }
                    count++;
                    temp = temp->next;
                }

            }
        }
    }
    Element Get(int index)
    {
        if (index == SizeList - 1) { return Last->PData; }
        else
        {
            if (index == 0) return First->PData;
            else
            {
                Element* temp = First;
                int count = 0;
                while (temp != nullptr)
                {
                    if (count == index) { return temp->PData; }
                    count++;
                    temp = temp->next;
                }
            }
        }
    }
    bool Set(string Name, string Surname, int Age, int index)
    {
        if (index == SizeList - 1)
        {
            Last->PData.Name = Name;
            Last->PData.Surname = Surname;
            Last->PData.Age = Age;
            return true;
        }
        else
        {
            if (index == 0)
            {
                First->PData.Name = Name;
                First->PData.Surname = Surname;
                First->PData.Age = Age;
                return true;
            }
            else
            {
                Element* temp = First;
                int count = 0;
                while (temp != nullptr)
                {
                    if (count == index)
                    {
                        temp->PData.Name = Name;
                        temp->PData.Surname = Surname;
                        temp->PData.Age = Age;
                        return true;
                    }
                    count++;
                    temp = temp->next;
                }
            }
        }
        return false;
    }
    void Clear()
    {
        while (SizeList) DeleteFront();
    }

private:
    Element* First;
    Element* Last;
    int SizeList;
    void InsertFront(PeoplDt peopleData)
    {
        if (First == nullptr)
        {
            First = Last = new Element(peopleData);
        }
        else
        {
            Element* people = new Element(peopleData);
            people->next = First;
            First->pre = people;
            First = people;
        }
        SizeList++;
    }
    void InsertBack(PeoplDt peopleData)
    {
        if (First == nullptr)
        {
            First = Last = new Element(peopleData);
        }
        else
        {
            Element* people = new Element(peopleData);
            Last->next = people;
            people->pre = Last;
            Last = people;
        }
        SizeList++;
    }
    void DeleteFront()
    {
        Element* temp = First;
        First = First->next;
        if (SizeList > 1)
            First->pre = nullptr;
        SizeList--;
        delete temp;
    }
    void DeleteBack()
    {
        if (First != nullptr)
        {
            Element* temp = Last;
            Last = Last->pre;
            Last->next = nullptr;
            SizeList--;
            delete temp;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    ListPeoples ppl;
    ppl.Insert(PeoplDt("Никита", "Ковалев ", 18), 0);
    ppl.Insert(PeoplDt("Адольф", "Ефимович ", 15), 1);
    ppl.Insert(PeoplDt("Стёпан", "Мышьев ", 18), 2);
    ppl.Insert(PeoplDt("Иван", "Пушкин ", 33), 3);
    bool b = ppl.Set("Дмитрий", "Александров", 23, 3);
    cout << "\nЗамена данных: " << b << endl;
    Element people;
    people = ppl.Get(2);
    cout << "\nЗначение элемента:\n ";
    people.PData.Print();
    cout << "\nУдаление элемента:\n";
    ppl.Delete(2);
    ppl.Print();
    cout << "\nКоличество элементов: " << ppl.Count() << endl;
    ppl.Clear();
    cout << "\nКоличество элементов: " << ppl.Count() << endl;
    return 0;
}