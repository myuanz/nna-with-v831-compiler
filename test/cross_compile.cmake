set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../toolchain-sunxi-musl/toolchain")
set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/bin/arm-openwrt-linux-muslgnueabi-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PATH}/bin/arm-openwrt-linux-muslgnueabi-g++")

add_definitions(-DV831)
