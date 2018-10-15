def combinations(n, k):
    k = min(k, n - k)
    if n < 2 or k == 0:
        return 1
    return combinations(n - 1, k - 1) + combinations(n - 1, k)

n = int(input())
k = int(input())
print(combinations(n, k))
