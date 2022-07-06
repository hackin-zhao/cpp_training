#include <iostream>

int main()
{
    int *b;
    b[5] = 1;
    return 0;
}

// 1、objcopy --only-keep-debug projectD projectsymbol.dbg #生成符号表；
// 2、gdb -q --symbol=projectsymbol.dbg -exec=projectR #加载符号表；
