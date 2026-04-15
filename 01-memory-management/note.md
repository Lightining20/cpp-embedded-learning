## int \*value; --> it stores address instead of value

## value = new int(v); --> this do same as above new int(v) find free locattion in memory, stors the vaalue and return ther address like 'a0Xhhh', but remember it work together you casn only store value in pointer variaqble with new int(v)

## you must use ~Sensor if you using pointer beaCUSE you have to destoctor to delete the heap memory

## Pointer file

## You see after assigning the address of var to p, both p and &var point to the same memory location. When we update the value pointed to by p, it changes the value of var because they refer to the same memory. Similarly, when we update var directly, it also changes the value that p points to. This demonstrates how pointers work in C++.
