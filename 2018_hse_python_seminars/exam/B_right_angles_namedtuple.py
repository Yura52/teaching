import collections
import itertools
import sys
from typing import List, Tuple


Point = collections.namedtuple('Point', ['index', 'name', 'coordinates'])
# p = Point(3, 'A', [0, 1])
# p.index == p[0] == 3
# p.name == p[1] == 'A'
# p.coordinates == p[2] == [0, 1]


def read_point(line_index: int, line: str) -> Tuple[int, str, List[int]]:
    splitted_line = line.split()
    return Point(
        index=line_index,
        name=splitted_line[0],
        coordinates=[int(x) for x in splitted_line[1:]]
    )


dimenstion_count = int(sys.stdin.readline())
point_count = int(sys.stdin.readline())
points = [
    convert_line_to_point(line_index, line)
    for line_index, line in enumerate(itertools.islice(sys.stdin, point_count))
]


def make_vector(a: Point, b: Point) -> List[int]:
    return [x - y for x, y in zip(b.coordinates, a.coordinates)]


def are_orthogonal_vectors(u: List[int], v: List[int]) -> bool:
    return sum(x * y for x, y in zip(u, v)) == 0


right_triangles = []
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
for triangle in right_triangles:
    point_names = [point.name for point in triangle]
    print(*point_names)
