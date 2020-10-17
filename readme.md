## 配置环境 / Configure the environment
### Windows
`?`
### Linux
```bash
git clone https://github.com/myuanz/nna-with-v831-compiler
```

## 编译测试 / Compile test
```bash
mkdir build
cd build 
cmake -DCMAKE_TOOLCHAIN_FILE=../test/cross_compile.cmake ../test/
make -j4
```
