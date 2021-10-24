#include <pthread.h> 
#include <stdio.h>
#include<stdlib.h>
  
// maximum size of matrix 
#define MAX 4 
  
// maximum number of threads 
#define MAX_THREAD 4 
  
int matA[MAX][MAX]; 
int matB[MAX][MAX]; 
int matC[MAX][MAX]; 
int tmp = 0; 
  
void* multiplication(void* a) 
{ 
    int t = tmp++; 
  
    // Each thread computes 1/4th of matrix multiplication 
    for (int i = t * MAX / 4; i < (t + 1) * MAX / 4; i++)  
        for (int j = 0; j < MAX; j++)  
            for (int k = 0; k < MAX; k++)  
                matC[i][j] += matA[i][k] * matB[k][j]; 
} 
  
// Driver Code 
int main() 
{ 
    // Generating random values in matA and matB 
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++) { 
            matA[i][j] = rand() % 10; 
            matB[i][j] = rand() % 10; 
        } 
    } 
  
    printf("Matrix A\n");
    printf("%d %d %d %d\n", matA[0][0], matA[0][1], matA[0][2], matA[0][3]);
    printf("%d %d %d %d\n", matA[1][0], matA[1][1], matA[1][2], matA[1][3]);
    printf("%d %d %d %d\n", matA[2][0], matA[2][1], matA[2][2], matA[2][3]);
    printf("%d %d %d %d\n", matA[3][0], matA[3][1], matA[3][2], matA[3][3]);
  
    printf("Matrix B\n");
    printf("%d %d %d %d\n", matB[0][0], matB[0][1], matB[0][2], matB[0][3]);
    printf("%d %d %d %d\n", matB[1][0], matB[1][1], matB[1][2], matB[1][3]);
    printf("%d %d %d %d\n", matB[2][0], matB[2][1], matB[2][2], matB[2][3]);
    printf("%d %d %d %d\n", matB[3][0], matB[3][1], matB[3][2], matB[3][3]);
  
    pthread_t threads[MAX_THREAD]; 
  
    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, multiplication, (void*)(p)); 
    } 
  
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);     
  
    printf("A & B urjver\n");
    printf("%d %d %d %d\n", matC[0][0], matC[0][1], matC[0][2], matC[0][3]);
    printf("%d %d %d %d\n", matC[1][0], matC[1][1], matC[1][2], matC[1][3]);
    printf("%d %d %d %d\n", matC[2][0], matC[2][1], matC[2][2], matC[2][3]);
    printf("%d %d %d %d\n", matC[3][0], matC[3][1], matC[3][2], matC[3][3]);
    return 0; 
} 