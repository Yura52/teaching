// Do not compile this, insert this code here: http://quick-bench.com
// (try optim = None and optim = -O3)
#include <algorithm>
#include <vector>

const int kSize = 1000000;

struct Point {
    int x{0};
    int y{0};
};

bool Compare(const Point& first, const Point& second) {
    return
        first.x * first.x + first.y * first.y <
        second.x * second.x + second.y * second.y;
}

static void WithoutLambda(benchmark::State& state) {
  std::vector<Point> v;
  v.reserve(kSize);
  for (int i = 0; i < kSize; ++i) {
      v.push_back({kSize - i, kSize - i});
  }
  for (auto _ : state) {
    auto v1 = v;
    std::sort(v1.begin(), v1.end(), Compare);
  }
}
BENCHMARK(WithoutLambda);

static void WithLambda(benchmark::State& state) {
  std::vector<Point> v;
  v.reserve(kSize);
  for (int i = 0; i < kSize; ++i) {
      v.push_back({kSize - i, kSize - i});
  }
  for (auto _ : state) {
    auto v1 = v;
    std::sort(
      v1.begin(), v1.end(),
      [](auto a, auto b) { return Compare(a, b); }
    );
  }
}
BENCHMARK(WithLambda);
