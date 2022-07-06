# 调试思路

1、objcopy --only-keep-debug projectD projectsymbol.dbg #生成符号表；
2、gdb -q --symbol=projectsymbol.dbg -exec=projectR #加载符号表；
