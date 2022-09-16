// Hash Tables in C++

#include <iostream>
#include <list>
#include <cstring>

// HashTable to impliment 987156, vaibhav

class HashTable
{
private:
    static const int HashGroups = 10;
    std::list<std::pair<int, std::string>> table[HashGroups]; // list 1 @ index 0, list 2 @ index 1...

public:
    int key;
    std::string value;
    bool IsEmpty() const;
    int HashFunction(int key);
    void InsertItem(int key, std::string value);
    void RemoveItem(int key);
    std::string SearchTable(int key);
    void PrintTable();
};

bool HashTable::IsEmpty() const
{
    int sum{};
    for (int i = 0; i < HashGroups; i++)
        sum+= table[i].size();
    
    if (!sum)
        return true;
    else
        return false;
}

int HashTable::HashFunction(int key) { return key % HashGroups; } // if key = 905, the return value is 5.

void HashTable::InsertItem(int key, std::string value)
{
    int HashValue = HashFunction(key);
    auto& cell = table[HashValue];
    bool KeyExists = false;
    for (auto kv : cell)
    {
        if (kv.first == key)
        {
            KeyExists = true;
            kv.second = value;
            std::cout << "[WARNING]: Key exists. Value replaced. " << std::endl;
            break;
        }
    }

    if (!KeyExists)
        cell.emplace_back(key, value);
}

void HashTable::RemoveItem(int key)
{
    int HashValue = HashFunction(key);
    auto& cell = table[HashValue];
    auto itr = cell.begin();
    bool KeyExists = false;
    for (; itr != cell.end(); itr++)
    {
        if (itr->first == key)
        {
            KeyExists = true;
            itr = cell.erase(itr);
            std::cout << "[INFO]: Item removed. " << std::endl;
            break;
        }
    }

    if (!KeyExists)
        std::cout << "[WARNING]: Item not found" << std::endl;
}

void HashTable::PrintTable()
{
    for (int i = 0; i < HashGroups; i++)
    {
        if (table[i].size() == 0)
            continue;
        
        for (const auto& kv : table[i])
            std::cout << "[INFO]: Key: " << kv.first << " Value: " << kv.second << std::endl;
    }
}

int main()
{
    HashTable HT;

    if (HT.IsEmpty())
        std::cout << "Correct, the list is empty" << std::endl;
    else    
        std::cout << "Check your code!" << std::endl;

    HT.InsertItem(987, "Vaibhav1");
    HT.InsertItem(678, "Vaibhav2");
    HT.InsertItem(807, "Vaibhav3");
    HT.InsertItem(342, "Vaibhav4");
    HT.InsertItem(786, "Vaibhav5");
    HT.InsertItem(496, "Vaibhav6");
    HT.InsertItem(341, "Vaibhav7");
    HT.InsertItem(431, "Vaibhav8");
    HT.InsertItem(876, "Vaibhav9");


    HT.PrintTable();

    HT.RemoveItem(431156);
    HT.RemoveItem(721231);

    HT.PrintTable();

    if (HT.IsEmpty())
        std::cout << "Check your code!" << std::endl;
    else    
        std::cout << "Correct, the list is not empty" << std::endl;

    std::cin.get();
}