cmd_/home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/xen/.install := bash scripts/headers_install.sh /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/xen ./include/uapi/xen evtchn.h gntalloc.h gntdev.h privcmd.h; bash scripts/headers_install.sh /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/xen ./include/xen ; bash scripts/headers_install.sh /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/xen ./include/generated/uapi/xen ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/xen/$$F; done; touch /home/caiyongheng/tina/out/astar-parrot/compile_dir/toolchain/linux-dev//include/xen/.install
