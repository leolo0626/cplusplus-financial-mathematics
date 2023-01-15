5.5.3

If you mark the function `normcdf` as `static` in the header file,  what are the consequence ? in the cpp file ? in both ? 
WHat if you don't mark horner Function as `static` ?

1. function 'normcdf' has internal linkage but is not defined. `static` make the function can only be used in source file. (Cannot export);
2. static declaration of 'normcdf' follows non-static declaration. It is because the header file is not static
3. Same as 1
4. Yes , the horner function can be done with or without `static`. Since it is used in the matlib.cpp file only.

```
g++ main.cpp -o main -include ./matlib.cpp
```