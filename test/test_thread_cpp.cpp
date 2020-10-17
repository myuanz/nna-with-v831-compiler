#include <thread>
#include <cstdio>

void hello() {
    printf("hello");
}

int main(){
    std::thread t1(hello);
    t1.detach();
    printf("main");
    getchar();
    return 0;
}