height = int(input())
metre_count_per_day = int(input())
metre_count_per_night = int(input())

last_night_target = height - metre_count_per_day
metre_count_per_turn = metre_count_per_day - metre_count_per_night
extra_day = (
    (last_night_target % metre_count_per_turn + metre_count_per_turn - 1) //
    metre_count_per_turn
)
print(last_night_target // metre_count_per_turn + extra_day + 1)
