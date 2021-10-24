#include <stdio.h>
#include <pthread.h>

void * thread_sum(void *);
int TotalSum=0;
int main()
{
    int iNumber,iCount;
    iNumber=100;   
    for(iCount=1;iCount<=iNumber;iCount++)
    {	
        pthread_t tid;
    	pthread_create(&tid,NULL,thread_sum,(void *)&iCount);
        pthread_join(tid,NULL);
    } 
}
void *thread_sum(void *no)
{
    int *iNumber,i,n;
    iNumber=(int*)no;
    n = *iNumber;
    
    for(i=2;i<n;i++){
		if(0==n%i){
			printf("%d anhnii too bish\n",n);
			break;	
		}	
	}
	if(i==n)
	printf("%d anhnii too\n",n);
    pthread_exit(NULL);    
}
