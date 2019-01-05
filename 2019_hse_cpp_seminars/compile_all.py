#!/usr/bin/env python3
import argparse
import os
import subprocess


def compile_one(absolute_path):
    executable_absolute_path = absolute_path.rsplit('.', 1)[0]
    print(f'>>> compiling {format(os.path.basename(absolute_path))}')
    subprocess.run([
        'clang++', '-std=c++14', absolute_path,
        '-o', executable_absolute_path
    ])
    print('')


def compile_all(directory):
    for path in os.listdir(directory):
        if path.endswith('.cpp'):
            compile_one(os.path.join(directory, path))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', '--dir', default='.')
    args = parser.parse_args()
    directory = args.dir

    compile_all(directory)


if __name__ == '__main__':
    main()
