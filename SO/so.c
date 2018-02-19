#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>


struct Shared
{
    sem_t isEmpty ;
    sem_t isFull ;
    int count ;
} * g_shm ;

void producer(void) {
    while (1) {     
        sem_wait(&g_shm->isEmpty);
	printf("Wyprodukowalem, aktualna wielkosc magazynu: %d\n", ++g_shm->count);
        sem_post(&g_shm->isFull);
	sleep(1);
    }
}

void consumer(void) {
    while (1) {
        sem_wait(&g_shm->isFull);
	printf("Pobralem, aktualna wielkosc magazynu: %d\n", --g_shm->count);
        sem_post(&g_shm->isEmpty);
	sleep(1);
    }
}

int main()
{
    g_shm = mmap( NULL , sizeof( struct Shared ) , PROT_READ | PROT_WRITE , MAP_SHARED | MAP_ANONYMOUS , -1 , 0 );
    sem_init( & g_shm->isEmpty , 1 , 10 );
    sem_init( & g_shm->isFull , 1 , 0 );
    g_shm->count = 0 ;

    int id = 0;
    id = fork();
 
    if (id < 0){
	perror ("error\n");
	exit(1);
    } 
    else if (id == 0){
	consumer();
 	exit(0);
    }
    
    producer();
    return 1;
}
