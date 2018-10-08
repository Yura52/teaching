import itertools
import sys


country_count = int(sys.stdin.readline())

# it's like [:country_count], but in a form of generator
city_to_country = {}
for line in itertools.islice(sys.stdin, country_count):
    name_iterator = iter(line.split())
    country = next(name_iterator)
    for city in name_iterator:
        city_to_country[city] = country

city_count = int(sys.stdin.readline())
for city in itertools.islice(sys.stdin, city_count):
    print(city_to_country[city.strip()])
