# naive-hash-table
C naive hash table

- OS: Windows 10 64bit
- IDE: CodeBlock
- MingW32

## Compile

ignored.

```shell
-------------- Build: Release in hash (compiler: GNU GCC Compiler)---------------

mingw32-gcc.exe -Wall -O2  -c F:\Codeblock\hash\hash\hash.c -o obj\Release\hash.o
mingw32-g++.exe  -o bin\Release\hash.exe obj\Release\hash.o  -s  
Output file is bin\Release\hash.exe with size 21.00 KB
Process terminated with status 0 (0 minute(s), 0 second(s))
0 error(s), 0 warning(s) (0 minute(s), 0 second(s))
```

## Execution

```shell
[INFO] create hash table successfully
[INFO] ---- print hash table ----
[INFO] t->length:15
[INFO] t->used_length:0
addr value
   0    0
   1    0
   2    0
   3    0
   4    0
   5    0
   6    0
   7    0
   8    0
   9    0
  10    0
  11    0
  12    0
  13    0
  14    0

[INFO] ---- print hash table ----
[INFO] t->length:15
[INFO] t->used_length:3
addr value
   0    0
   1    0
   2    0
   3   93
   4    0
   5   95
   6    0
   7    0
   8    0
   9    0
  10    0
  11    0
  12   12
  13    0
  14    0

[WARN] 30 not found in hash table
[INFO] 12 found in hash table address: 12
[INFO] destroy hash table successfully
```
