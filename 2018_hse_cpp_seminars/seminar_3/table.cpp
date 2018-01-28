#include <iostream>
#include <vector>

template<typename T>
class Table {
public:
    using Row = std::vector<T>;

    Table(const size_t row_count, const size_t column_count)
        : data_(row_count, Row(column_count, 0))
        {}

    void resize(size_t row_count, size_t column_count) {
        for (auto& row: data_) {
            row.resize(column_count, T());
        }
        data_.resize(row_count, Row(column_count, T()));
    }

    const Row& operator[](size_t i) const {
        return data_[i];
    }

    Row& operator[](size_t i) {
        return const_cast<Row&>(static_cast<const Table&>(*this)[i]);
    }

private:
    std::vector<Row> data_;
};


int main() {
    Table<int> table(2, 2);
    std::cout << table[0][0] << std::endl;
    table[0][0] = 1;
    std::cout << table[0][0] << std::endl;
    table.resize(1, 1);
    std::cout << table[0][0] << std::endl;

    return 0;
}
