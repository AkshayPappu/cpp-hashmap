# C++ HashMap Implementation

A custom implementation of a HashMap data structure in C++ using template classes. This implementation provides a flexible and efficient key-value storage solution with features similar to `std::unordered_map`.

## Features

- Template-based implementation supporting any key and value types
- Dynamic resizing with load factor management
- Efficient hash-based lookups
- Basic operations: insert, get, remove, clear
- Operator overloading for intuitive usage

## Implementation Details

The HashMap is implemented using a vector of vectors (buckets) to handle collisions through chaining. Key features include:

- **Collision Resolution**: Uses separate chaining with linked lists
- **Load Factor**: Automatically resizes when load factor exceeds 0.75
- **Hash Function**: Uses std::hash for key hashing
- **Memory Management**: Efficient memory usage with vector-based storage

## Usage Example

```cpp
#include "HashMap.h"
#include <string>
#include <iostream>

int main() {
    // Create a HashMap with string keys and integer values
    HashMap<std::string, int> map;
    
    // Insert key-value pairs
    map.insert("apple", 1);
    map.insert("banana", 2);
    map.insert("orange", 3);
    
    // Access values using operator[]
    std::cout << map["apple"] << std::endl;  // Outputs: 1
    
    // Check if key exists
    if (map.get("banana") != nullptr) {
        std::cout << "banana exists!" << std::endl;
    }
    
    // Remove a key-value pair
    map.remove("orange");
    
    // Get size
    std::cout << "Size: " << map.size() << std::endl;
    
    return 0;
}
```

## Performance Characteristics

- **Average Case**:
  - Insert: O(1)
  - Lookup: O(1)
  - Delete: O(1)
- **Worst Case**:
  - All operations: O(n) when all keys hash to the same bucket

## Requirements

- C++11 or later
- Standard Template Library (STL)

## Future Improvements

Potential areas for enhancement:
- Iterator support
- Custom hash function support
- Reserve capacity method
- Exception safety improvements
- Move semantics optimization

## License

This project is open source and available under the MIT License.