#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//a list of variables
int arr[1000];//the ProcessID array
int aT[1000];//the arrival time array
int bT[500];//burst time array
int n;


/*
swaps the variables to randomize the processID array*/

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void Shuffle(int arr[], int n){
  srand(time(NULL));
  for(int i=999;i>0;i--)
  {
    int j = rand()%(i+1);
    swap(&arr[i],&arr[j]);
  }

}
void findwT(int arr[],int n, int bT[],int wt[],int aT[]){
  wt[0]=0;//first process has 0 wait time
  for(int i =0;i<n;i++){
    wt[i]=bT[i-1]+ wt[i-1];
    wt[i]=wt[i]-aT[i];
    if(wt[i]<0){
      wt[i]=0;
    }
  }

}

//find the average waiting Time using FIFO
void findavgTime(int arr[],int n, int bT[]){
    int wt[n],total_wt=0;

    findwT(arr,n,bT,wt,aT);
    
    for (int i =0;i<n;i++){
      total_wt= total_wt + wt[i];
    }
    float s = (double)total_wt /n;
    s= s*.01;//convert
    printf("FIFO Waiting Time: \n%.1f",s );

}


/*
creates the ProcessID, Arrival Time, and Burst Time, initial values 
*/


void createpID(){
  srand(time(NULL));
  for(int i=0;i<1000;i++){
    arr[i]= i;
    aT[i]= rand()%999+1;
  }
  for(int i=0;i<500;i++){
    bT[i]= rand()%500+1;
  }

  int n = sizeof(arr)/sizeof(arr[0]);
  Shuffle(arr,n);
  findavgTime(arr,n,bT);
}


int main(void) {
  createpID();
  return 0;
}