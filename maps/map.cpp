#include <iostream>
#include <vector>

template <typename KeyType, typename ValueType>
class Map
{
private:
    std::vector<std::pair<KeyType, ValueType>> data;

public:
    void insert(const KeyType &key, const ValueType &value)
    {
        for (auto &pair : data)
        {
            if (pair.first == key)
            {
                pair.second = value; // Key already exists, update the value
                return;
            }
        }
        data.push_back(std::make_pair(key, value)); // Key doesn't exist, add a new key-value pair
    }

    ValueType &operator[](const KeyType &key)
    {
        for (auto &pair : data)
        {
            if (pair.first == key)
            {
                return pair.second; // Return the value if the key exists
            }
        }
        ValueType defaultValue{};                          // Default value for new keys
        data.push_back(std::make_pair(key, defaultValue)); // Add a new key-value pair with default value
        return data.back().second;
    }

    bool contains(const KeyType &key) const
    {
        for (const auto &pair : data)
        {
            if (pair.first == key)
            {
                return true; // Key exists
            }
        }
        return false; // Key doesn't exist
    }

    void erase(const KeyType &key)
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (it->first == key)
            {
                data.erase(it); // Erase the key-value pair if the key exists
                return;
            }
        }
    }

    void clear()
    {
        data.clear(); // Clear all key-value pairs
    }

    void print() const
    {
        for (const auto &pair : data)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }
};

int main()
{
    Map<int, std::string> myMap;

    myMap.insert(1, "John");
    myMap.insert(2, "Emily");
    myMap.insert(3, "Michael");

    myMap.print();

    std::cout << "Value at key 2: " << myMap[2] << std::endl;

    std::cout << "Key 3 exists: " << (myMap.contains(3) ? "true" : "false") << std::endl;

    myMap.erase(1);

    myMap.clear();

    return 0;
}
