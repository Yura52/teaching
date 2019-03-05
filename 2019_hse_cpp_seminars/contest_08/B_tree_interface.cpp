#include <iostream>
#include <map>
#include <string>
#include <vector>

using Path = std::vector<std::string>;

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
public:
    void Insert(const std::vector<std::string>& node) {

    }

    bool Has(const std::vector<std::string>& node) const {
        return true;
    }

private:
    Node root_;
};

int main() {
    Tree tree;
    const std::vector<std::string> v = {"Users", "Petya", "crypto"};
    tree.Insert(v);
    std::cout << tree.Has(v) << '\n';

    return 0;
}
