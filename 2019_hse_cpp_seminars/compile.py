#!/usr/bin/env python3
import argparse
import os
import subprocess


def compile_one(absolute_path):
    executable_absolute_path = absolute_path.rsplit('.', 1)[0]
    print(f'>>> compiling {format(os.path.basename(absolute_path))}')
    subprocess.run([
        'clang++', '-std=c++17', absolute_path,
        '-o', executable_absolute_path, '-O0'
    ])
    print('')


def compile_all(directory):
    for path in os.listdir(directory):
        if path.endswith('.cpp'):
            compile_one(os.path.join(directory, path))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('path', default='.')
    args = parser.parse_args()
    if args.path.endswith('.cpp'):
        compile_one(args.path)
    else:
        compile_all(args.path)


if __name__ == '__main__':
    main()
