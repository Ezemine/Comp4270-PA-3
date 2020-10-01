#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
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
void findFIFOwT(int arr[],int n, int bT[],int wt[],int aT[]){
  wt[0]=0;//first process has 0 wait time
  for(int i =0;i<n;i++){
    wt[i]=bT[i-1]+ wt[i-1];
    wt[i]=wt[i]-aT[i];
    if(wt[i]<0){
      wt[i]=0;
    }
  }

}

void findSJFwT(int arr[],int n,int bT[],int wt[],int aT[])
{
  int rt[n];

  for(int i=0;i<n;i++){
    rt[i] = bT[i];
  }
  int done =0, t=0, minm=INT_MAX;
  int shortest =0, finish;
  bool check = false;//checks if job is the shortest

  while(done !=n){
    for (int j=0;j<n;j++){
      if(aT[j]<=t&&rt[j]<minm&&rt[j]>0){
        minm=rt[j];
        shortest = j;
        check = true;
      }
    }
    if (check==false){
      t++;
      continue;
    }
    rt[shortest]--;

    minm =rt[shortest];
    if (minm ==0){
      minm = INT_MAX;
    }
    if(rt[shortest]==0){
      done++;
      check =false;

      finish= t+1;
      wt[shortest]= finish-bT[shortest]-aT[shortest];

      if(wt[shortest]<0){
        wt[shortest]=0;
      }
      
    }
    t++;
  }


}

//find the average waiting Time using FIFO
void findavgTime(int arr[],int n, int bT[],int aT[]){
    int wt[n],total_wt1=0,total_wt2=0;
    float s,v;

    findFIFOwT(arr,n,bT,wt,aT);
    for (int i =0;i<n;i++){
      total_wt1= total_wt1 + wt[i];
    }
    s = (float)total_wt1 /n;
    s= s*.01;//convert

    findSJFwT(arr,n,bT,wt,aT);
    for (int i =0;i<n;i++){
      total_wt2=total_wt2 + wt[i];
    v = (float)total_wt2 /n;
    v = v*.0001;
    }
    printf("FIFO Waiting Time\tSJF Waiting Time");
    printf("\n%.1f\t\t\t\t%.1f",s,v);

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
  findavgTime(arr,n,bT,aT);
}


int main(void) {
  createpID();
  return 0;
}