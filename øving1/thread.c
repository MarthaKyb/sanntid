#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    for (j = 1; i <= 1000000; j++) 
    { 
        i += 1;     
    } 
    return NULL;
}

void* decrementingThreadFunction(){
    for (j = 1; i <= 1000000; j++) 
    { 
        i -= 1;     
    }        
    return NULL;
}


int main(){
    // TODO: declare incrementingThread and decrementingThread (hint: google pthread_create)
    pthread_t incrementingThread;
    pthread_t decrementingThread;


    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_join(incrementingThread, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
    pthread_join(decrementingThread, NULL);

    sleep(5);
    printf("The magic number is: %d\n", i);
    return 0;
}