#include <iostream>
#include <fstream>

void SerializeArray(
    const size_t size,
    int* data,
    std::ostream& os)
{
    // T name_of_my_array [123];
    // type(name_of_my_array) == T*;

    for (int i = 0; i < size; ++i) {
        data[i] = i;
    }

    // os.write(char* data, size_t size);
    os.write(reinterpret_cast<const char *>(&size), sizeof(size));
    os.write(reinterpret_cast<const char *>(data), size * sizeof(int));
}

int main() {
    const size_t size = 100;
    int data[size] = {}; // set all elements to 0
    SerializeArray(size, data, std::cout);
    std::ofstream file("file.txt");
    SerializeArray(size, data, file);

    return 0;
}

