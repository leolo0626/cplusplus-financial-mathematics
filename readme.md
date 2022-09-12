Command for compiling the C++ code

```
    g++ -std=c++11 -o <name-you-want-to-give> source.pp
    ./<name-you-want-to-give>
```

For chapter 7 's ex, if we need to include the file outside the current directory, 
we need to explicitly `-include`
```
g++ -std=c++11 ex2.cpp -o ex2 -include ../chapter6/FMLib6/FMLib/matlib.cpp
```