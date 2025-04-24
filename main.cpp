#include <iostream>
#include "HashMap.h"

int main() {
    HashMap<std::string, int> map;

    // Test insertion
    map.insert("apple", 1);
    map.insert("banana", 2);
    map.insert("orange", 3);

    std::cout << "Initial insertions:" << std::endl;
    std::cout << "apple: " << *map.get("apple") << std::endl;
    std::cout << "banana: " << *map.get("banana") << std::endl;
    std::cout << "orange: " << *map.get("orange") << std::endl;

    // Test update
    map.insert("banana", 5);
    std::cout << "\nAfter updating banana:" << std::endl;
    std::cout << "banana: " << *map.get("banana") << std::endl;

    // Test missing key
    if (map.get("pear") == nullptr) {
        std::cout << "\npear not found (correct behavior)" << std::endl;
    }

    // Test deletion
    std::cout << "\nRemoving orange..." << std::endl;
    bool removed = map.remove("orange");
    std::cout << "Removed: " << std::boolalpha << removed << std::endl;

    if (map.get("orange") == nullptr) {
        std::cout << "orange correctly removed" << std::endl;
    }

    // Check size and empty
    std::cout << "\nSize: " << map.size() << std::endl;
    std::cout << "Is empty? " << std::boolalpha << map.empty() << std::endl;

    // Stress test for rehashing
    std::cout << "\nInserting 2000 items to trigger rehash..." << std::endl;
    for (int i = 0; i < 2000; ++i) {
        map.insert("key" + std::to_string(i), i);
    }

    std::cout << "New size after rehash: " << map.size() << std::endl;
    std::cout << "New capacity after rehash: " << map.capacity() << std::endl;

    // Validate a few keys after rehash
    std::cout << "key1999: " << *map.get("key1999") << std::endl;
    std::cout << "key0: " << *map.get("key0") << std::endl;

    // Clear the map
    std::cout << "\nClearing map..." << std::endl;
    map.clear();
    std::cout << "Size after clear: " << map.size() << std::endl;
    std::cout << "Is empty? " << std::boolalpha << map.empty() << std::endl;

    // Test operator[]
    map["apple"] = 10;
    map["banana"] = 20;
    map["orange"] = 30;
    map["orange"] += 10;

    std::cout << "\nTesting operator[]:" << std::endl;
    std::cout << "apple: " << map["apple"] << std::endl;
    std::cout << "banana: " << map["banana"] << std::endl;
    std::cout << "orange: " << map["orange"] << std::endl;

    return 0;
}