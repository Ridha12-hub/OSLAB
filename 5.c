#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t room, chop[5];
void * phil(void* num){
    i=*(int*)num;
    sem_wait(&room);
    sem_wait(&chop[i]);
    sem_wait(&chop[(i+1)%5]);
    printf("philosopher %d is eating\n ", i);
    sleep(1);
    sem_post(&chop[(i+1)%5]);
    sem_post(&chop[i]);
    sem_post(&room);
}
int main(){
    pthread_t tid[5];
    int a[5]={0,1,2,3,4};
    sem_init(&room,0,4);
    for(int i=0;i<5;i++) sem_init(&chop[i],0,1);
    for(int i=0;i<5;i++) pthread_create(&tid[i],NULL,philosopher,&a[i]);
    for(int i=0;i<5;i++) pthread_join(tid[i],NULL);
    return 0;
}