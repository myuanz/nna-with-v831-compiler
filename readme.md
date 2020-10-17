## 配置环境 / Configure the environment
### Windows
用 wsl 转 Linux / Use wsl and see Linux
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

## 编译nna / Compile nna
```bash
cd nna/eyesee-mpp/middleware/v459/sample/sample_nna
make -f tina.mk
```