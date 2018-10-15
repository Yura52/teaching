NOT_FOUND_INDEX = -1
SYMBOL_TO_REPLACE = 'h'
NEW_SYMBOL = 'H'

str_ = str(input())
left_index = str_.find(SYMBOL_TO_REPLACE)
if left_index == NOT_FOUND_INDEX:
    new_str = str_
else:
    right_index = str_.rfind(SYMBOL_TO_REPLACE)
    new_str = (
        str_[:left_index + 1] +
        str_[left_index + 1:right_index].replace(
            SYMBOL_TO_REPLACE, NEW_SYMBOL
        ) +
        str_[right_index:]
    )
print(new_str)
