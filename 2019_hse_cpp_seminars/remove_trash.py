#!/usr/bin/env python3
import argparse
import os


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', '--dir', default='.')
    args = parser.parse_args()

    for path in os.listdir(args.dir):
        if not path.endswith('.cpp') and not path.endswith('.py'):
            os.remove(os.path.join(args.dir, path))


if __name__ == '__main__':
    main()
