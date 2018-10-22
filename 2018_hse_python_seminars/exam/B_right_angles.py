import collections
import itertools
import sys
from typing import List, Tuple


def read_point(index: int) -> Tuple[int, str, List[int]]:
    splitted_line = sys.stdin.readline().split()
    # 'A 1 0' -> ['A', '1', '0']
    point_index = index
    point_name = splitted_line[0]
    point_coordinates = [int(x) for x in splitted_line[1:]]
    return point_index, point_name, point_coordinates


dimenstion_count = int(sys.stdin.readline())
point_count = int(sys.stdin.readline())
points = [read_point(index) for index in range(point_count)]
# points = [
# (0, 'A', [0, 1]),
# (1, 'B', [2, 3]),
# ...
# ]


def make_vector(
    a: Tuple[int, str, List[int]],
    b: Tuple[int, str, List[int]]
) -> List[int]:
    return [x - y for x, y in zip(b[2], a[2])]


def are_orthogonal_vectors(u: List[int], v: List[int]) -> bool:
    return sum(x * y for x, y in zip(u, v)) == 0


right_triangles = []
# for i in range(point_count):
#     for j in range(i + 1, point_count):
#         for k in range(j + 1, point_count):
#             a, b, c = points[i], points[j], points[k]
for a, b, c in itertools.combinations(points, 3):
    ab = make_vector(a, b)
    bc = make_vector(b, c)
    ca = make_vector(c, a)
    if are_orthogonal_vectors(ab, bc):
        triangle = a, b, c
    elif are_orthogonal_vectors(bc, ca):
        triangle = a, c, b
    elif are_orthogonal_vectors(ca, ab):
        triangle = b, a, c
    else:
        triangle = None
    if triangle is not None:
        right_triangles.append(triangle)


right_triangles.sort()
# right_triangles = [
#     (
#         (a_index, a_name, a_coords),
#         (b_index, b_name, b_coords)
#         (c_index, c_name, c_coords)
#     ),
#     (
#         (a_index, a_name, a_coords),
#         (b_index, b_name, b_coords)
#         (c_index, c_name, c_coords)
#     ),
#     ...
# ]
for triangle in right_triangles:
    point_names = [point[1] for point in triangle]
    print(*point_names)
