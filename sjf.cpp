#include<iostream>
using namespace std;
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
void Arrival(int num, int process[][3]) {
   for(int i=0; i<num; i++) {
      for(int j=0; j<num-i-1; j++) {
         if(process[1][j] > process[1][j+1]) {
            for(int k=0; k<5; k++) {
               swap(process[k][j], process[k][j+1]);
            }
         }
      }
   }
}
void Time(int num, int process[][3]) {
   int temp, val;
   process[3][0] = process[1][0] + process[2][0];
   process[5][0] = process[3][0] - process[1][0];
   process[4][0] = process[5][0] - process[2][0];
    for(int i=1; i<num; i++) {
      temp = process[3][i-1];
      int low = process[2][i];
      for(int j=i; j<num; j++) {
         if(temp >= process[1][j] && low >= process[2][j]) {
            low = process[2][j];
            val = j;
         }
      }
      process[3][val] = temp + process[2][val];
      process[5][val] = process[3][val] - process[1][val];
      process[4][val] = process[5][val] - process[2][val];
      for(int k=0; k<6; k++) {
         swap(process[k][val], process[k][i]);
      }
   }
}
int main() {
   int num = 3, temp;
   int process[6][3] = {2201, 3401, 1103, 1, 2, 3, 3, 2, 1};
   float total_aw = 0;
   float total_tat =0;
   Arrival(num, process);
   Time(num, process);
   cout<<"Course Code\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
   for(int i=0; i<num; i++) {
      cout<<"CSC"<<process[0][i]<<"\t\t"<<process[1][i]<<"\t\t"<<process[2][i]<<"\t\t"<<process[4][i]<<"\t\t"<<process[5][i]<<"\n";
      total_aw = total_aw + process[4][i];
      total_tat = total_tat + process[5][i];
   }
   
    cout<<"Average waiting time is : "; 
    cout<<total_aw/num<<endl; 
    cout<<"average turnaround time : "; 
    cout<<total_tat/num<<endl; 
  
}
