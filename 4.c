#include <stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t rw_mu, mu;
int read_count=0;

void* reader(void* rno){
    sem_wait(&mu);
    read_count++;
    if(read_count==1) sem_wait(&rw_mu);
    sem_post(mu);
    printf("Reader is reading\n", *((int*)rno));
    sem_wait(&mu);
    read_count--;
    if(read_count==0) sem_post(&rw_mu);
    sem_post(&mu);
}
void* writer(void* no){
    sem_wait(&mu);
    printf("writer is writing\n",*((int*)no));
    sem_post(&mu);
}
int main(){
    pthread_t r[3],w[2];
    sem_init(&mu,0,1);
    sem_init(&rw_mu,0,1);
    
}