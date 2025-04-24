#ifndef HASHMAP_H
#define HASHMAP_H
#include <vector>
#include <utility>
#include <functional>

template <typename K, typename V>
class HashMap {
    private:
        struct Entry {
            K key;
            V value;
        };
        std::vector<std::vector<Entry>> buckets;
        size_t size_;
        size_t capacity_;
        double max_load_factor = 0.75;

    public:
        HashMap(int capacity = 1000) : buckets(capacity), size_(0), capacity_(capacity) {}

        void insert(const K& key, const V& value) {            
            V* existingValue = get(key);
            if (existingValue != nullptr) {
                *existingValue = value;
                return;
            }

            if (size_ / buckets.size() > max_load_factor) {
                rehash();
            }

            size_t index = hash(key, capacity_);
            buckets[index].push_back({key, value});
            size_++;
            return;
        }

        size_t hash(const K& key, size_t capacity) const {
            return std::hash<K>{}(key) % capacity;
        }

        const V* get(const K& key) const {
            size_t index = hash(key, capacity_);
            for (const auto& entry : buckets[index]) {
                if (entry.key == key) {
                    return &entry.value;
                }
            }
            return nullptr;
        }

        V* get(const K& key) {
            size_t index = hash(key, capacity_);
            for (auto& entry : buckets[index]) {
                if (entry.key == key) {
                    return &entry.value;
                }
            }
            return nullptr;
        }

        void rehash() {
            size_t new_capacity = buckets.size() * 2;
            std::vector<std::vector<Entry>> new_buckets(new_capacity);
            for (const auto& bucket : buckets) {
                for (const auto& entry : bucket) {
                    size_t new_index = hash(entry.key, new_capacity);
                    new_buckets[new_index].push_back(entry);
                }
            }
            buckets = std::move(new_buckets);
            capacity_ = new_capacity;
            return;
        }

        bool remove(const K& key) {
            size_t index = hash(key, capacity_);
            auto& bucket = buckets[index];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (it->key == key) {
                    bucket.erase(it);
                    size_--;
                    return true;
                }
            }
            return false;
        }

        size_t size() const {
            return size_;
        }

        size_t capacity() const {
            return capacity_;
        }

        bool empty() const {
            return size_ == 0;
        }

        void clear() {
            for (auto& bucket : buckets) {
                bucket.clear();
            }
            size_ = 0;
            return;
        }

        V& operator[](const K key) {
            V* value = get(key);
            if (value == nullptr) {
                insert(key, V());
                value = get(key);
            }
            return *value;
        }
};

#endif