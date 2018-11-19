[![Build Status](https://travis-ci.org/uilianries/conan-folly-example.svg?branch=master)](https://travis-ci.org/uilianries/conan-folly-example)
[![MIT](https://img.shields.io/packagist/l/doctrine/orm.svg)](https://img.shields.io/packagist/l/doctrine/orm.svg)

# Conan Folly Example

## Folly example using Conan for blog post

- Conan.io blog: https://blog.conan.io
- Blog post about Folly: https://blog.conan.io/2018/11/19/Using-Facebook-Folly-with-Conan.html

#### How to build
To build this project using cmake:

    git clone https://github.com/uilianries/conan-folly-example.git
    cd conan-folly-example
    mkdir build && cd build
    conan install ..
    cmake ..
    cmake --build .
    bin/folly_example

#### Requirements
- CMake >=3.1.3
- C++ compiler with C++14 support (Folly requirement)
- Conan >=1.9.1

#### License
[MIT](LICENSE)
