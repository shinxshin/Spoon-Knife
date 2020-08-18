#include <bits/stdc++.h> 
  
using namespace std; 
  
#define totalproc 3 
  
// input process  
struct process { 
	int at,duration,pr,course; 
}; 
  
process proc[50]; 
bool comp(process a,process b) 
	{ 
	if(a.at == b.at) { 
	return a.pr<b.pr; 
	} 
	else{ 
    return a.at<b.at; 
	}	 
} 
  
// find Waiting time
void getwt(int wt[]) { 
	// array size
	int Asize[50]; 
	Asize[0] = proc[0].at; 
	wt[0]=0; 
	for(int i=1;i<totalproc;i++)
	 { 
		Asize[i]=proc[i-1].duration+Asize[i-1]; 
		wt[i]=Asize[i]-proc[i].at;
		if(wt[i]<0) 
   		{ 
   		wt[i]=0; 
   		} 
	} 
} 
//find turnaround time
void gettat(int tat[],int wt[]) {
	for(int i=0;i<totalproc;i++) 
	{ 
 	   tat[i]=proc[i].duration+wt[i]; 
	}     
} 
  
void findtime() {	 
	//Declare waiting time and turnaround time array 
	int wt[50],tat[50]; 
	float wtavg=0,tatavg=0; 
	//Function call to find waiting time and turnaround time 
	getwt(wt);
	gettat(tat,wt); 
      
	int starttime[50],endtime[50];
	starttime[0] = proc[0].at; 
	endtime[0]   = starttime[0]+tat[0]; 
	for(int i=1;i<totalproc;i++) 
    { 
        starttime[i] = endtime[i-1]; 
        endtime[i]   = starttime[i]+tat[i]-wt[i]; 
    }  
	cout<<"Process_no\tStart_time\tEnd_time\tTurn_Around_Time\tWaiting_Time"<<endl; 
    // display
	for(int i=0;i<totalproc;i++) 
    { 
        wtavg += wt[i]; 
        tatavg += tat[i]; 
          
        cout<<proc[i].course<<"\t\t"<< 
            starttime[i]<<"\t\t"<<endtime[i]<<"\t\t"<< 
            tat[i]<<"\t\t\t"<<wt[i]<<endl; 
    } 
    // display the average waiting time and average turn around time   
    cout<<"Average waiting time is : "; 
    cout<<wtavg/totalproc<<endl; 
    cout<<"average turnaround time : "; 
    cout<<tatavg/totalproc<<endl; 
  
} 
  
int main() 
{ 
	int arrivaltime[] = { 1, 2, 3}; 
	int durationtime[] = { 3, 2, 1}; 
	int priority[] = { 2, 3, 1}; 
	int course_code[] = {2201, 3401, 1103}; 
   
	for(int i=0;i<totalproc;i++) 
	{	 
    	proc[i].at= arrivaltime[i]; 
    	proc[i].duration= durationtime[i]; 
    	proc[i].pr= priority[i]; 
    	proc[i].course = course_code[i]; 
    } 
    sort(proc,proc+totalproc,comp); 
    findtime();  
  
    return 0; 
} 
