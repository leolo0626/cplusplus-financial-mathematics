
This is called overloading function. 
```

    double average(double a, double b) {
        return (a+b)/2;
    }

    double average(double a, double b, double c) {
        return (a+b+c)/2;
    }
``` 

C++ will know which function you're calling if you call the function like this`average(3.0, 2.0, 1.0)` .