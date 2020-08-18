// C++ program for implementation of FCFS scheduling 
#include<iostream> 
using namespace std; 
  
// Function to find the waiting time for all processes 
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) 
{ 
    int waittime[n]; 
    waittime[0] = 0; 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int i = 1; i < n ; i++) 
    { 
        // Add burst time of previous processes 
        waittime[i] = waittime[i-1] + bt[i-1]; 
  
        // Find waiting time for current process
        wt[i] = waittime[i] - at[i]; 
        if (wt[i] < 0) 
            wt[i] = 0; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) 
{ 
    // Calculating turnaround time by adding bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
// Function to calculate average waiting and turn-around times. 
void findavgTime(int processes[], int n, int bt[], int at[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0;; 
  
    // Function to find waiting time
    findWaitingTime(processes, n, bt, wt, at); 
  
    // Function to find turn around time
    findTurnAroundTime(processes, n, bt, wt, tat); 
  
    // Display processes along with all details 
    cout << "Course code " << " Period  " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time " << endl; 
     
    for (int i = 0 ; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
         
        cout << " " << "CSC "<< processes[i] << "\t" << bt[i] << "\t\t"
             << at[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i]  <<  "\t\t " << endl; 
    } 
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main() 
{ 
    // Process id's 
    int processes[] = {2201,3401,1103}; 
    int n = sizeof processes / sizeof processes[0]; 
  
    // Burst time of all processes 
    int burst_time[] = {3, 2, 1}; 
  
    // Arrival time of all processes 
    int arrival_time[] = {1, 2, 3}; 
  
    findavgTime(processes, n, burst_time, arrival_time); 
  
    return 0; 
} 
