def first_line(x: float) -> float:
    return -x


def second_line(x: float) -> float:
    return 2 * x + 2


# Circle: R ** 2 = (x - XC) ** 2 + (y - YC) ** 2
XC = -1
YC = 1
R = 2


def IsPointInArea(x: float, y: float) -> bool:
    distance_to_circle_center = ((x - XC) ** 2 + (y - YC) ** 2) ** 0.5
    y_first_line = first_line(x)
    y_second_line = second_line(x)

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
