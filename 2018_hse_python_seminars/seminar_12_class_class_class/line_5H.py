# try to run this script


class Line:
    def __init__(self, k: float, b: float) -> None:
        self._k = k
        self._b = b

    def __call__(self, x: float) -> float:
        return self._k * x + self._b


################################################################################
# Next, the solution of the problem 5H is coming
################################################################################
FIRST_LINE = Line(-1, 0)
SECOND_LINE = Line(2, 2)


# Circle: R ** 2 = (x - XC) ** 2 + (y - YC) ** 2
XC = -1
YC = 1
R = 2


def IsPointInArea(x: float, y: float) -> bool:
    distance_to_circle_center = ((x - XC) ** 2 + (y - YC) ** 2) ** 0.5
    y_first_line = FIRST_LINE(x)
    y_second_line = SECOND_LINE(x)

    is_in_upper_part = (
        y >= y_first_line and
        y >= y_second_line and
        distance_to_circle_center <= R
    )
    if is_in_upper_part:
        return True

    is_in_lower_part = (
        y <= y_first_line and
        y <= y_second_line and
        distance_to_circle_center >= R
    )
    return is_in_lower_part


x = float(input())
y = float(input())
message = 'YES' if IsPointInArea(x, y) else 'NO'
print(message)
