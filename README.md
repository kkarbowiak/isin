# is in #

Ever wrote a lengthy `if` statement comparing a variable with some values?

```c++
if ((event == ERROR_1) ||
    (event == ERROR_2) ||
    (event == ERROR_3) ||
    ...
{
    // process
}
```

Ever missed the elegant Pythonic idiom in C++ code?

```python
if event is in [ERROR_1, ERROR_2, ERROR_3, ...]:
    # process
```

Miss no longer as this little library makes it possible to transform the first `if` statement to python-like below code:

```c++
if (event is_in(ERROR_1, ERROR_2, ERROR_3, ...))  // notice just a whitespace separating event and is_in
{
    // process
}
```

Below is a short example. Compile it and try running with several command-line arguments.

```c++
#include "isin.h"
#include <iostream>

int main(int argc, char * /*argv*/[])
{
    if (argc is_in(2, 3, 4, 5))
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }
}
```

## License ##

This project is released under **MIT/X11** license, so feel free to do anything you like with it.

