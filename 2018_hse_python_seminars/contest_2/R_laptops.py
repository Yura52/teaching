stock_length = int(input())
stock_height = int(input())
stock_width = int(input())
box_length = int(input())
box_height = int(input())
box_width = int(input())

max_box_count = (
    (stock_length // box_length) *
    (stock_height // box_height) *
    (stock_width // box_width)
)

new_box_count = (
    (stock_length // box_length) *
    (stock_height // box_width) *
    (stock_width // box_height)
)
if new_box_count > max_box_count:
    max_box_count = new_box_count

new_box_count = (
    (stock_length // box_width) *
    (stock_height // box_length) *
    (stock_width // box_height)
)
if new_box_count > max_box_count:
    max_box_count = new_box_count

new_box_count = (
    (stock_length // box_width) *
    (stock_height // box_height) *
    (stock_width // box_length)
)
if new_box_count > max_box_count:
    max_box_count = new_box_count

new_box_count = (
    (stock_length // box_height) *
    (stock_height // box_length) *
    (stock_width // box_width)
)
if new_box_count > max_box_count:
    max_box_count = new_box_count

new_box_count = (
    (stock_length // box_height) *
    (stock_height // box_width) *
    (stock_width // box_length)
)
if new_box_count > max_box_count:
    max_box_count = new_box_count

print(max_box_count)
