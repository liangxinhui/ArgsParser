# ArgsParser
A simple c++ parser for (argc, argv)


sample:

```cpp
#include "ArgsParser.h"

int main(int argc, char** argv)
{
    // assume the command is : Demo -A -b somevalue -c othervalue
    ArgsParser arg(argc, argv);
    
    //  input: -A , option without value
    // result: bOptionA == true;
    bool bOptionA = arg.HaveOption('A');
    
    // the sequence of option is not important
    //  input: -c othervalue
    // result: strValueC == "othervalue";
    std::string strValueC = arg.GetOption('C');
    
    //  input: -b somevalue
    // result: strValueB == "somevalue";
    std::string strValueB = arg.GetOption('B');
    
    return 0;
}
```
