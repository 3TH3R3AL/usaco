## NV Chad notes
- Toggle FE = Ctrl N
- a to create new file while in nvtree
- Enter to open file while in nvtree
- Ctrl w to change windows
- Tab to change files/tab things (but not actually tabs)


## GDB Notes
- Run with `gdb binary`
- set breakpoint with `b [Line Number]`, so `b 49`
- start program with `run`
- Have to compile like `g++ -g input.cpp -o output` in order to use gdb
- step with `step` or shortened, `s`
- step over function with `next` or `n`

## C++ Notes:
- You can do something similiar to pythons `for item in list` via `for (std:string& str : strList)` where std:string is the type, & means to use a reference, str is the temporary variable, and strList is the iterable. 
- std:vector from <vector> are like pseudo-dynamic arrays that are handled automatically.
- need to use long long, because long is weird. 
- `push_back` to append to end of vector
