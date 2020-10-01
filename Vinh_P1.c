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

/*prints out the ProcessID, Arrival Time, and Burst Time
*/

void printArr(int arr[],int n, int aT[],int bT[]){
       printf("ProcessID\tArrival Time\tBurst Time");
      for (int i = 0; i < n; i++) 
        printf
        ("\n%d\t\t\t%d\t\t\t\t%d ", arr[i],
        aT[i],bT[i]); //prints out the "table" that shows processID, Arrival Time, and Burst Time
}
//does exactly what name says, shuffles the pID array to randomize the processor
void Shuffle(int arr[], int n){
  srand(time(NULL));
  for(int i=999;i>0;i--)
  {
    int j = rand()%(i+1);
    swap(&arr[i],&arr[j]);
  }

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
  printArr(arr,n,aT,bT);
}


int main(void) {
  createpID();//calls function to create table of process ID with arrival time and burst time
  return 0;
}