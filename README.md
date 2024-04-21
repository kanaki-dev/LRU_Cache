# LRU Cache Implementation in C++

This is a simple C++ implementation of an LRU (Least Recently Used) cache, which is a data structure used for storing a fixed number of items and evicting the least recently used item when the cache is full.

## Features

- Supports `getValue(key)` and `insertKeyValue(key, value)` operations.
- Time complexity of both `get` and `put` operations is O(1).

## How to Use

1. Include the `iostream`, `unordered_map` and `list` file in your C++ project.
2. Create an instance of `LRUCache` by specifying the maximum capacity.
3. Use the `getValue(key)` method to retrieve the value associated with a key.
4. Use the `insertKeyValue(key, value)` method to insert or update a key-value pair.

```cpp
#include "LRUCache.cpp"

int main()
{

    LRUCache lru(3);

    lru.insertKeyValue("🥭", 10);
    lru.insertKeyValue("🍎", 20);
    lru.insertKeyValue("🍇", 30);

    std::cout << "Most Recently Used: " << lru.mostRecentKey() << std::endl;

    lru.insertKeyValue("🥭", 40);
    std::cout << "Most Recently Used: " << lru.mostRecentKey() << std::endl;

    lru.insertKeyValue("🍌", 20);

    if (lru.getValue("🍎") == NULL)
    {
        std::cout << "Apple doesn't exists" << std::endl;
    }

    if (lru.getValue("🥭") == NULL)
    {
        std::cout << "Mango doesn't exists" << std::endl;
    }

    if (lru.getValue("🍇") == NULL)
    {
        std::cout << "Grages doesn't exists" << std::endl;
    }

    if (lru.getValue("🍌") == NULL)
    {
        std::cout << "Banana doesn't exists" << std::endl;
    }

    return 0;
}
```
