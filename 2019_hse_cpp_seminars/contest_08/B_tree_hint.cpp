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
        auto* subtree = &root_;
        for (const auto& x : node) {
            subtree = &subtree->children[x];
        }
    }

    bool Has(const std::vector<std::string>& node) const {
        const auto* subtree = &root_;
        for (const auto& x : node) {
            const auto it = subtree->children.find(x);
            if (it == subtree->children.end()) {
                return false;
            }
            subtree = &it->second;
        }
        return true;
    }

private:
    Node root_;
};

using u64 = uint64_t;
void SaveVarint(const std::map<u64, u64>& m, std::ostream& out) {

}

int main() {
    Tree tree;
    const std::vector<std::string> v = {"Users", "Petya", "crypto"};
    tree.Insert(v);
    std::cout << tree.Has(v) << '\n';

    return 0;
}
