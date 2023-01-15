Command for compiling the C++ code

```
    Ch1 - 
    # compile the c++ program
    g++ -std=c++11 -o <name-you-want-to-give> source.pp
    # it will produce a executable file.
    #  run the program
    ./<name-you-want-to-give>
```

For chapter 7 's ex, if we need to include the file outside the current directory, 
we need to explicitly `-include`

```
g++ -std=c++11 ex2.cpp -o ex2 -include ../chapter6/FMLib6/FMLib/matlib.cpp
```