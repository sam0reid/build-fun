# Combining dependencies with CMAKE
This project aims to demonstrate the issue documented [here](https://gitlab.kitware.com/cmake/cmake/-/issues/19611).

Three projects are compiled separately and made to depend on eachother.

1. `special_math` 
2. `calculator`
3. `client`

`calculator` links PRIVATELY to `special_math` and makes use of a function in one of its source files. `client` makes use of `calculator` to perform a calculation. In the configuration provided, running `task build` should yield the following output once the client program has been executed.

```
computing...
Invoked calculator add
Invoked special_add
1 + 2 = 3
```

### Problem

If `calculator` is built as a static library the following error will appear when building `client`

```
  The link interface of target "calculator::calculator" contains:

    special_math::special_math
```

This is because linking in static libraries is deferred until its linked with either a shared library or executable.

Some possible ways to resolve this include:

1. Add a `find_package` call to the private dependency in the client CMakeLists.txt file.
2. Absorb the private dependency by combining static libraries when building the secondary project. `calculator` in this case.
3. Build the secondary project as a shared library.
