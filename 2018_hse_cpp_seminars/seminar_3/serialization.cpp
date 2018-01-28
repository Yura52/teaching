#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

// for POD (plain old data) types
template<class T>
void Serialize(const T value, std::ostream& os) {
    os.write(reinterpret_cast<const char*>(&value), sizeof(value));
}

void Serialize(const std::string& str, std::ostream& os) {
    const auto size = str.size();
    Serialize(size, os);
    os.write(str.data(), size);
}

template<typename T>
void Serialize(const std::vector<T>& vec, std::ostream& os) {
    Serialize(vec.size(), os);
    for (const auto& item: vec) {
        Serialize(item, os);
    }
}

template<typename K, typename V>
void Serialize(const std::map<K, V>& mapping, std::ostream& os) {
    const auto size = mapping.size();
    Serialize(size, os);
    for (const auto& item: mapping) {
        Serialize(item.first, os);
        Serialize(item.second, os);
    }
}

// for POD (plain old data) types
template<typename T>
void Deserialize(std::istream& is, T* const buffer) {
    is.read(reinterpret_cast<char*>(buffer), sizeof(T));
}

void Deserialize(std::istream& is, std::string* const buffer) {
    size_t size = 0;
    Deserialize(is, &size);
    buffer->resize(size);
    // in C++17 const_cast is not needed
    is.read(const_cast<char*>(buffer->data()), size);
}

template<typename T>
void Deserialize(std::istream& is, std::vector<T>* const buffer) {
    size_t size = 0;
    Deserialize(is, &size);
    buffer->resize(size);
    for (size_t i = 0; i < size; ++i) {
        Deserialize(is, buffer->data() + i);
    }
}

template<typename K, typename V>
void Deserialize(std::istream& is, std::map<K, V>* const buffer) {
    size_t size = 0;
    Deserialize(is, &size);
    for (size_t i = 0; i < size; ++i) {
        K key;
        Deserialize(is, &key);
        V value;
        Deserialize(is, &value);
        buffer->insert({key, value});
    }
}

int main() {
    std::ofstream number_out_file("number.bin", std::ios::binary);
    std::ofstream matrix_out_file("matrix.bin", std::ios::binary);
    std::ofstream mapping_out_file("mapping.bin", std::ios::binary);

    const int8_t number = 0;
    const std::vector<std::vector<char>> matrix = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    const std::map<std::string, std::vector<size_t>> mapping = {
        {"A", {1, 1, 1}},
        {"B", {2, 2, 2}},
        {"C", {3, 3, 3}}
    };

    Serialize(number, number_out_file);
    Serialize(matrix, matrix_out_file);
    Serialize(mapping, mapping_out_file);

    number_out_file.close();
    matrix_out_file.close();
    mapping_out_file.close();

    std::ifstream number_in_file("number.bin", std::ios::binary);
    std::ifstream matrix_in_file("matrix.bin", std::ios::binary);
    std::ifstream mapping_in_file("mapping.bin", std::ios::binary);

    int8_t new_number = 0;
    std::vector<std::vector<char>> new_matrix;
    std::map<std::string, std::vector<size_t>> new_mapping;

    Deserialize(number_in_file, &new_number);
    Deserialize(matrix_in_file, &new_matrix);
    Deserialize(mapping_in_file, &new_mapping);

    return 0;
}
