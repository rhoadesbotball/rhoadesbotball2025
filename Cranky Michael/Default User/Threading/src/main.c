#include <kipr/wombat.h>

void printthread();

int main()
{
    thread thread1 = thread_create(printthread);
    //thread_start(thread1);
    printf("Thread Main\n");
    motor(0, -100);
    motor(2, -100);
    msleep(10000);
    //thread_destroy(thread1);
    return 0;
}

void printthread(){
    printf("Thread Secondary\n");
    motor(2, -100);
    msleep(10000);
}