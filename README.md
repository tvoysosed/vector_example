[![Build Status](https://travis-ci.org/tvoysosed/vector_example.svg?branch=master)](https://travis-ci.org/tvoysosed/vector_example)

```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
