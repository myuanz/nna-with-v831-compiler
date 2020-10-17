#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <syscall.h>


#define NUM_THREADS 5

void *say_hello(void *args)
{
    printf("%u, Hello\n", pthread_self());
    printf("%ld, Hello\n", syscall(SYS_gettid));

}

int main()
{
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0) {
            printf("pthread_create error: error_code = %d\n", ret);
        }
    }
    pthread_exit(NULL);
    return 0;
}
