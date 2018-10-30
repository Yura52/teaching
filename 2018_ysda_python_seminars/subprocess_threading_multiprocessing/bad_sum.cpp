int Sum(int first, int second) {
    return first + second;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    std::cout << Sum(a, b) << '\n';
}
