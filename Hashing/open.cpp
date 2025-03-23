#include <iostream>
using namespace std;

class Hash
{
private:
    int *array;
    int size;

public:
    Hash(int size)
    {
        this->size = size;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = -1; // -1 means empty
        }
    }

    int Hashfunc(int data)
    {
        return data % size;
    }

    void Insert(int data)
    {
        int index = Hashfunc(data);
        int i = 1;

        while (array[index] != -1)
        {
            index = (index + i * i) % size;
            i++;

            if (i == size)
            {
                cout << "Hash table is full. Cannot insert " << data << endl;
                return;
            }
        }

        array[index] = data;
        cout << "Inserted " << data << " at index " << index << endl;
    }

    void display()
    {
        cout << "\nHash Table (Quadratic Probing):\n";
        for (int i = 0; i < size; i++)
        {
            if (array[i] == -1)
                cout << "[" << i << "] : Empty" << endl;
            else
                cout << "[" << i << "] : " << array[i] << endl;
        }
    }

    ~Hash()
    {
        delete[] array;
    }
};

int main()
{
    cout << "Starting...\n";
    Hash H1(5);

    H1.Insert(12); // index 2
    H1.Insert(62); // collision at 2, quadratic probe
    H1.Insert(52);
    H1.Insert(42);
    H1.Insert(32); // fills the table
    H1.Insert(99); // table is full

    H1.display();

    return 0;
}



// linear probing

#include <iostream>
using namespace std;

class Hash
{
private:
    int *array;
    int size;

public:
    Hash(int size)
    {
        this->size = size;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = -1; // -1 means empty
        }
    }

    int Hashfunc(int data)
    {
        return data % size;
    }

    void Insert(int data)
    {
        int index = Hashfunc(data);
        int i = 0;

        while (array[(index + i) % size] != -1 && array[(index + i) % size] != -2) // Check for empty or deleted slot
        {
            i++;
            if (i == size)
            {
                cout << "Hash table is full. Cannot insert " << data << endl;
                return;
            }
        }

        index = (index + i) % size;
        array[index] = data;
        cout << "Inserted " << data << " at index " << index << endl;
    }

    void Delete(int data)
    {
        int index = Hashfunc(data);
        int i = 0;

        while (array[(index + i) % size] != -1) // Search until an empty slot is found
        {
            if (array[(index + i) % size] == data)
            {
                array[(index + i) % size] = -2; // Mark as deleted
                cout << "Deleted " << data << " from index " << (index + i) % size << endl;
                return;
            }
            i++;
            if (i == size)
            {
                cout << "Element " << data << " not found in the hash table.\n";
                return;
            }
        }

        cout << "Element " << data << " not found in the hash table.\n";
    }

    void display()
    {
        cout << "\nHash Table (Linear Probing):\n";
        for (int i = 0; i < size; i++)
        {
            if (array[i] == -1)
                cout << "[" << i << "] : Empty" << endl;
            else if (array[i] == -2)
                cout << "[" << i << "] : Deleted" << endl;
            else
                cout << "[" << i << "] : " << array[i] << endl;
        }
    }

    ~Hash()
    {
        delete[] array;
    }
};

int main()
{
    cout << "Starting...\n";
    Hash H1(5);

    H1.Insert(12);
    H1.Insert(62);
    H1.Insert(52);
    H1.Insert(42);
    H1.Insert(32);
    H1.Insert(99); // Table is full

    H1.display();

    cout << "\nDeleting elements...\n";
    H1.Delete(62);
    H1.Delete(42);
    H1.Delete(99); // Not in the table

    H1.display();

    return 0;
}