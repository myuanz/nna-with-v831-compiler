cmd_/home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/linux/spi/.install := bash scripts/headers_install.sh /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/linux/spi ./include/uapi/linux/spi spidev.h; bash scripts/headers_install.sh /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/linux/spi ./include/linux/spi ; bash scripts/headers_install.sh /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/linux/spi ./include/generated/uapi/linux/spi ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/linux/spi/$$F; done; touch /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/linux/spi/.install
