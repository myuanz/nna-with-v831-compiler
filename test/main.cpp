#include <stdio.h>
#include <string>
#include <unistd.h>


using namespace std;

auto func(int i) {
    return i;
}
template<typename T> auto func2(T t) { return t; }


template <typename ... Ts>
auto sum(Ts ... ts) {
    return (ts + ...);
}

// template <int N, int... Ns>
// auto sum_int()
// {
//     if constexpr (0 == sizeof...(Ns))
//         return N;
//     else
//         return N + sum_int<Ns...>();
// }

int main(){
    printf("%d\n", func(123));
    printf("%d\n", func2(123));

    int a {sum(1, 2, 3, 4, 5)};
    std::string b{"hello "};
    std::string c{"world"};
    printf("%s\n", sum(b, c).c_str());
    printf("%s\n", (b + c).c_str());
    printf("%d\n", sum(1, 2, 3, 4, func(5)));

    // printf("%d\n", sum_int<1, 2, 3>()); // error

    auto pid = getpid();
    printf("%ud\n", pid);

}
