import functools
import sys

print(
    *functools.reduce(
        lambda u, v: map(
            lambda x: int(x[0]) ^ int(x[1]),
            zip(u, v)
        ),
        map(
            lambda x: x.split(),
            map(
                lambda _: input(),
                range(int(sys.stdin.readline()))
            )
        ),
    )
)
