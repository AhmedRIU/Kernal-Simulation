#include <iostream>
#include <algorithm>
#include<stdlib.h>
#include<iomanip> //SJF Exclusive
#include<climits> //SJF Exclusive

using namespace std;
int total=0;
struct Process
{
  int p_ID,AT,BT,CT,WT,TAT,RT,start_time;  

  string Name;
  string status;
  string priority;   
}PS[100];


bool comparatorAT(struct Process a,struct Process b)
{
   int x =a.AT;
   int y =b.AT;
   return x < y;
}  

bool comparatorPID(struct Process a,struct Process b)
{
   int x =a.p_ID;
   int y =b.p_ID;
   return x < y;
}
void getdata(int num){
	int i=total;
	num+=total;

			    for( i;i<num;i++)
			    {
			    PS[i].priority="high";
    	        PS[i].p_ID=i;
    	        cout<<"\n***************************************"<<endl;
    			cout<<"Process ID:"<<PS[i].p_ID<<endl;
    			PS[i].status="ready";
				cout<<"Process Status: "<<PS[i].status<<endl;
			    cout<<"***************************************"<<endl;
			    cout<<"_______________________________________"<<endl;
			    cout<<"\nEnter Process NO " <<i<< "| Process Name : ";
			    cin >>PS[i].Name; 
			    cout<<"\nEnter Process NO " <<i<< "| Arrival Time : ";
			    cin >> PS[i].AT;
			    cout<<"\nEnter Process NO " <<i<< "| Burst Time : ";
			    cin >> PS[i].BT;
			    cout<<"\n_______________________________________"<<endl;
			    total++;
			    }				    
			    
}
void showprocess(int num){
cout<<"\nProcess-No.\tName\tAT\tBT"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<i<<"\t\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<"\t"<<endl;

	}
}
void destroyprocess(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].p_ID >= 0){
			list++;
		}
	}
	if(list > 0){
		showprocess(total);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Delete: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	            for(int j=i; j<(total-1); j++)
	                PS[j] = PS[j+1];
	            found++;
	            i--;
	            total--;
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Deleted Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Available Processes."<<endl;
	}
}
void suspendprocess(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].p_ID >= 0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(total);
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Suspend: ";
	    cin>>name;
	    
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	            PS[i].status = "suspend";
	            PS[i].priority = "medium";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Suspended Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Available Process."<<endl;
	}		
}
void resumeprocess(int num){
	string name;
	int found=0;
	int list=0;
	for(int i=0;i<num;i++)
	{
		if(PS[i].status=="suspend"){
			list++;
		}
	}
	if(list > 0){
	    cout<<"\nP-No.\tName\tAT\tBT\n";
				for(int i=0;i<num;i++)
		{
			if(PS[i].status=="suspend"){
			cout<<PS[i].p_ID<<"\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<endl;	
			}
		}
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		
		cout<<"\nEnter Process Name to Resume: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	            PS[i].status = "ready";
	            PS[i].priority = "high";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Resumed Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Suspended Processes."<<endl;
	}
}
void blockprocess(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].p_ID>=0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(total);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Block: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	           PS[i].status = "block";
	            PS[i].priority = "low";
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Blocked Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Available Process."<<endl;
	}
}
void wakeupprocess(int num){
	string name;
	int found=0;
	int list=0;
	for(int i=0;i<num;i++)
	{
		if(PS[i].status=="block"){
			list++;
		}
	}
	if(list > 0){
		cout<<"Process Number\tArrival Time\tBurst Time\n";
		for(int i=0;i<num;i++)
		{
			if(PS[i].status=="block"){
				cout<<PS[i].p_ID<<"\t\t"<<PS[i].AT<<"\t\t"<<PS[i].BT<<endl;		
			}
		}
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

		cout<<"\nEnter Process Name to Resume: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].status=="block"){
	        	if(PS[i].Name==name)
		        {
		        	found++;
		            PS[i].status = "ready";
		            PS[i].priority = "high";
		        }
			}
			else{
				goto found0;
			}
	    }
	    if(found==0)
	    found0:
	        cout<<"\nElement doesn't found in the Array!";
	    else
	        cout<<"\nElement Resumed Successfully!";
	    cout<<endl;
	}
	else{
		cout<<"No Blocked Processes."<<endl;
	}
}

void changepriority(int num){
	int list=0;
	for(int i=0;i<num;i++){
		if(PS[i].p_ID>=0){
			list++;
		}
	}
	
	if(list > 0){
		showprocess(total);
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		string name;
		int found=0;
		cout<<"\nEnter Process Name to Change Priority: ";
	    cin>>name;
	    for(int i=0; i<total; i++)
	    {
	        if(PS[i].Name==name)
	        {
	        	found++;
	        	string temp;
	        	cout<<"Enter Process Priority: ";
	            cin>>temp;
	            if(temp=="high"){
	            	PS[i].status="ready";
	            	PS[i].priority="high";
				}
				else if(temp=="medium"){
					PS[i].status="suspend";
	            	PS[i].priority="medium";
				}
				else if(temp=="low"){
					PS[i].status="block";
	            	PS[i].priority="low";
				}
				else{
					cout<<"Invalid"<<endl;
				}
	        }
	    }
	    if(found==0)
	        cout<<"\nElement doesn't found in the Array!";
	    else{
	    	cout<<"\nPriority Changed Successfully!"<<endl;
		}
	        
	}
	else{
		cout<<"No Available Process."<<endl;
	}
}
void fcfs(int num){
	
	 float sum_TAT=0,sum_WT=0,sum_RT=0;
			    int length_cycle,total_idle_time=0;
			    sort(PS,PS+num, comparatorAT);
			
			    for(int i=0;i<num;i++)
			    {
			      PS[i].start_time = (i==0) ? PS[i].AT : max(PS[i].AT, PS[i-1].CT);  
			      PS[i].CT =  PS[i].start_time + PS[i].BT;
			      PS[i].TAT = PS[i].CT-PS[i].AT;       
			      PS[i].WT = PS[i].TAT-PS[i].BT;
			      PS[i].RT=PS[i].WT;
			       
			      sum_TAT += PS[i].TAT;
			      sum_WT += PS[i].WT;
			      sum_RT += PS[i].RT;
			      total_idle_time += (i==0) ? 0 : (PS[i].start_time -  PS[i-1].CT);
			    }
			    length_cycle = PS[num-1].CT - PS[0].start_time;
			    sort(PS,PS+num, comparatorPID);
			    
			    cout<<"__________________________________________________"<<endl;
			    cout<<"\nP-No.\tName\tAT\tBT\tCT\tTAT\tWT\tRT\n";
			    cout<<"__________________________________________________"<<endl;
			    for(int i=0;i<num;i++)
			     cout<<i<<"\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<"\t"<<PS[i].CT<<"\t"<<PS[i].TAT<<"\t"<<PS[i].WT<<"\t"<<PS[i].RT<<endl;
			    cout<<"__________________________________________________"<<endl;
			    cout<<endl;
			   
			    
	
}
void sjf(int num){
	
	bool is_completed[100]={false},is_first_process=true;
    int current_time = 0;
    int completed = 0;
    int sum_tat=0,sum_wt=0,sum_rt=0,total_idle_time=0,prev=0,length_cycle;
    float cpu_utilization;
    int max_completion_time,min_arrival_time;
    
    
    while(completed!=num)
    {
        //find process with min. burst time in ready queue at current time
        int min_index = -1;
        int minimum = INT_MAX;
        for(int i = 0; i < num; i++) {
            if(PS[i].AT <= current_time && is_completed[i] == false) {
                if(PS[i].BT < minimum) {
                    minimum = PS[i].BT;
                    min_index = i;
                }
                if(PS[i].BT== minimum) {
                    if(PS[i].AT < PS[min_index].AT) {
                        minimum= PS[i].BT;
                        min_index = i;
                    }
                }
            }
        }

        if(min_index==-1)
        {
            current_time++;
        }
        else            
        {
        PS[min_index].start_time = current_time;
        PS[min_index].CT = PS[min_index].start_time + PS[min_index].BT;
        PS[min_index].TAT = PS[min_index].CT - PS[min_index].AT;
        PS[min_index].WT = PS[min_index].TAT - PS[min_index].BT;
        PS[min_index].RT = PS[min_index].WT;
        // ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;
                
        sum_tat +=PS[min_index].TAT;
        sum_wt += PS[min_index].WT;
        sum_rt += PS[min_index].RT;
        total_idle_time += (is_first_process==true) ? 0 : (PS[min_index].start_time -  prev);
        
        completed++;
        is_completed[min_index]=true;
        current_time = PS[min_index].CT;
        prev= current_time;
        is_first_process = false;  
        }
    }
    
    //Calculate Length of Process completion cycle
    max_completion_time = INT_MIN;
    min_arrival_time = INT_MAX;
    for(int i=0;i<num;i++)
    {
        max_completion_time = max(max_completion_time,PS[i].CT); 
        min_arrival_time = min(min_arrival_time,PS[i].AT);
    }
    length_cycle = max_completion_time - min_arrival_time;
    cout<<"\nP-No.\tName\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for(int i=0;i<num;i++){
    cout<<i<<"\t"<<PS[i].Name<<"\t"<<PS[i].AT<<"\t"<<PS[i].BT<<"\t"<<PS[i].CT<<"\t"<<PS[i].TAT<<"\t"<<PS[i].WT<<"\t"<<PS[i].RT<<endl;

	
 }
}

void Avergecalculator(int num){

	     fcfs(num);
	   	    float sum_TAT=0,sum_WT=0,sum_RT=0;
	   	        cout<<"\nAVERAGE TURN-AROUND-TIME : "<< sum_TAT/num;
                cout<<"\nAVERAGE WAITING TIME :"<<sum_WT/num;
                cout<<"\nAVEARGE RESPONSE TIME : "<<sum_RT/num/num;
                cout<<endl;

}
int main()
{
	menu:
	int n;
    cout<<"_______________________________________"<<endl;
	cout<<"|                                     |"<<endl;
	cout<<"|     SSNN-Command Line Interface     |"<<endl;
	cout<<"|_____________________________________|"<<endl;
	cout<<"|                                     |"<<endl;
	cout<<"|     [1] Process Management          |"<<endl;
	cout<<"|     [2] Memory Management           |"<<endl;
	cout<<"|     [3] Other Operations            |"<<endl;
	cout<<"|     [4] Process Control Block       |"<<endl;
	cout<<"|_____________________________________|"<<endl;
    cout<<"|                                     |"<<endl;
	cout<<"|           [0] Shut Down             |"<<endl;
    cout<<"|_____________________________________|"<<endl;
	cout<<"|                                     |"<<endl;
	cout<<"|   NOTE: Write Index No to Command   |"<<endl;	
	cout<<"|_____________________________________|"<<endl;
	cin>>n;
	
	switch(n){
		case 1:
			cout<<"_______________________________________"<<endl;
			cout<<"|                                     |"<<endl;
			cout<<"|          PROCESS MANAGEMENT         |"<<endl;
			cout<<"|_____________________________________|"<<endl;
			cout<<"|                                     |"<<endl;
			cout<<"|      [1] Create a Process           |"<<endl;
			cout<<"|      [2] Destory a Process          |"<<endl;
			cout<<"|      [3] Suspend a Process          |"<<endl;
			cout<<"|      [4] Resume a Process           |"<<endl;
			cout<<"|      [5] Block a Process            |"<<endl;
			cout<<"|      [6] Wakeup a Process           |"<<endl;
			cout<<"|      [7] Dispatch a Process         |"<<endl;
			cout<<"|      [8] Change Process Priority    |"<<endl;
			cout<<"|      [9] Process Communication      |"<<endl;
			cout<<"|      [0] Back                       |"<<endl;
			cout<<"|_____________________________________|"<<endl;
		    cout<<"|                                     |"<<endl;
	        cout<<"|   NOTE: Write Index No to Command   |"<<endl;	
	        cout<<"|_____________________________________|"<<endl;

			cin>>n;
			switch(n){
			case 1:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|          Create a Process :-        |"<<endl;
			        cout<<"|_____________________________________|"<<endl;	
					int num;
					cout<<endl;
				    cout << "Enter Total Number of Processes: ";
				    cin >> num;
				    cout<<endl;
					getdata(num);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;				
					cin>>n;
					switch(n){
						case 0:
						goto menu;
						break;
					}
			break;
			case 2:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|          Destroy a Process :-       |"<<endl;
			        cout<<"|_____________________________________|"<<endl;
					destroyprocess(total);	
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;                    
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
				break;
			
			case 3:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|          Suspend a Process :-       |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					suspendprocess(total);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
			break;
		}
		break;
			case 4:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|          Resume a Process :-        |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					resumeprocess(total);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
			break;
			case 5:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|          Block a Process :-         |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					blockprocess(total);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
					break;
			break;
			case 6:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|          Wakeup a Process :-        |"<<endl;
			        cout<<"|_____________________________________|"<<endl;			
					wakeupprocess(total);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
					break;
			case 7:
					cout<<"______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|         Dispatch a Process :-       |"<<endl;
			        cout<<"|_____________________________________|"<<endl;
								
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
					goto menu;
						break;
					}
			break;
			case 8:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|       Change Process Priority :-    |"<<endl;
			        cout<<"|_____________________________________|"<<endl;				
					changepriority(total);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
			break;
			case 9:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|        Process Communication:-      |"<<endl;
			        cout<<"|_____________________________________|"<<endl;			
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>num;
					
					switch(num){
						case 0:
						goto menu;
						break;
					}
			break;
			case 0:
			goto menu;
			break;
			
			}
			break;
		case 2:
			cout<<"_______________________________________"<<endl;
			cout<<"|                                     |"<<endl;
			cout<<"|           MEMORY MANAGEMENT         |"<<endl;
			cout<<"|_____________________________________|"<<endl;
			cout<<"|                                     |"<<endl;			
			cout<<"|             [1] Paging              |"<<endl;
			cout<<"|             [2] LRU                 |"<<endl;
			cout<<"|             [0] Back                |"<<endl;
			cout<<"|_____________________________________|"<<endl;
		    cout<<"|                                     |"<<endl;
	        cout<<"|   NOTE: Write Index No to Command   |"<<endl;	
	        cout<<"|_____________________________________|"<<endl;
								
			cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
						case 1:
						goto menu;
						break;
			case 2:
			int nopages, nofaults, page[20],i ,count=0;
			cout<<"_______________________________________"<<endl;
		    cout<<"|                                     |"<<endl;
	        cout<<"|         Least Recently Used :-      |"<<endl;	
	        cout<<"|_____________________________________|"<<endl;
            cout<<"\n Enter the No of Pages :"; 
            cin>> nopages;  //it will store the number of Pages
            cout<<"\n Enter the Reference String :";
            for(i=0;i< nopages;i++)
            {
            cout<<"\t"; 
            cin>>page[i];
            }   
            
            cout<<"\n Enter the Number of Frames :"; 
            cin>> nofaults;
            int frame[nofaults],fcount[nofaults];
            for(i=0;i< nofaults;i++)
            {
            frame[i]=-1;
            fcount[i]=0; //it will keep the track of when the page was last used
            }
            i=0;
            while(i< nopages)
            {
                int j=0,flag=0;
                while(j< nofaults)
                {
                if(page[i]==frame[j]){  //it will check whether the page already exist in frames or not
                flag=1;
                fcount[j]=i+1;
                }
                j++;
                }   
                j=0;  
                cout<<"\n\t-----------------------------------------------------------------------------------------------------\n";
                cout<<"\t"<<page[i]<<"~";   
                if(flag==0)
                {
                int min=0,k=0;
                while(k<nofaults-1) 
                { 
                    if(fcount[min]>fcount[k+1]) //It will calculate the page which is least recently used
                    min=k+1;
                    k++;
                    }
                frame[min]=page[i]; 
                fcount[min]=i+1;  //Increasing the time
                count++;           //it will count the total Page Fault
                while(j< nofaults)
                {
                cout<<"\t|"<<frame[j]<<"|";
                j++;
                }
                }
            i++; 
            }
            cout<<"\n\t------------------------------------------------------------------------------------------------------------\n";
            cout<<"\n Page Fault :"<<count<<endl;
               goto menu;
            break;
        }
		break;
        
		case 3:
		    cout<<"_______________________________________"<<endl;
			cout<<"|                                     |"<<endl;
			cout<<"|           OTHER OPERATIONS          |"<<endl;
			cout<<"|_____________________________________|"<<endl;
			cout<<"|                                     |"<<endl;			
			cout<<"|             [1] FCFS                |"<<endl;
			cout<<"|             [2] SJF                 |"<<endl;
			cout<<"|             [0] Back                |"<<endl;
			cout<<"|_____________________________________|"<<endl;
		    cout<<"|                                     |"<<endl;
	        cout<<"|   NOTE: Write Index No to Command   |"<<endl;	
	        cout<<"|_____________________________________|"<<endl;
			cin>>n;
			switch(n){ 
		
			case 1:
		
				    cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|        FIRST COME FIRST SERVE       |"<<endl;
			        cout<<"|_____________________________________|"<<endl;
			        
		                fcfs(total);
		    

				cout<<"_______________________________________"<<endl;		    
	            cout<<"|                                     |"<<endl;
	            cout<<"|          AVERAGE CALCULATOR         |"<<endl;		    
	            cout<<"|_____________________________________|"<<endl;
	            cout<<"|                                     |"<<endl;
	            cout<<"|       [1] Average TAT, WT, RT       |"<<endl;
	            cout<<"|       [0] Back                      |"<<endl;
	            cout<<"|_____________________________________|"<<endl;
	            cout<<"|                                     |"<<endl;
	            cout<<"|   NOTE: Write Index No to Command   |"<<endl;	
                cout<<"|_____________________________________|"<<endl;
	            cin>>n;
			    
			    switch(n) {	
			     case 1:
			    Avergecalculator(total);
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
		
				break;
				case 0:
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
					break;
				}
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;					
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
		
		          break;
		 	
		 case 2:
				    cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|        Shortest Job First (SJF)     |"<<endl;
			        cout<<"|_____________________________________|"<<endl;
		 	sjf(total);
		 	
					cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|               [0] Back              |"<<endl;
			        cout<<"|_____________________________________|"<<endl;
					cin>>n;
					
					switch(n){
						case 0:
						goto menu;
						break;
					}
			break;
			
		case 3:
			goto menu;
			break;
		} 
		break;
	
			case 5:
				    cout<<"_______________________________________"<<endl;
					cout<<"|                                     |"<<endl;
			        cout<<"|        Process Control Block        |"<<endl;
			        cout<<"|_____________________________________|"<<endl;
			        
			for(int i=0; i<total; i++)
		    {
		    	cout<<"_____________________________________"<<endl;
		        cout<<"ID: "<<PS[i].p_ID<<endl;
		        cout<<"_____________________________________"<<endl;
		        cout<<"Name: "<<PS[i].Name<<endl;
		        cout<<"_____________________________________"<<endl;
		        cout<<"Status: "<<PS[i].status<<endl;
		        cout<<"_____________________________________"<<endl;
		        cout<<"Priority: "<<PS[i].priority<<endl;
		        cout<<"_____________________________________"<<endl;
		        cout<<"Parent Process: N/A"<<endl;
		        cout<<"_____________________________________"<<endl;
				cout<<"Child Processes: N/A"<<endl;
				cout<<"_____________________________________"<<endl;
		        cout<<"Memory Requirements: N/A"<<endl;
		        cout<<"_____________________________________"<<endl;
		        cout<<"***************************************************"<<endl;
			}
				cout<<"_______________________________________"<<endl;
				cout<<"|                                     |"<<endl;
			    cout<<"|               [0] Back              |"<<endl;
			    cout<<"|_____________________________________|"<<endl;
			    cin>>n;
		
			switch(n){
				case 0:
				system("CLS");
				goto menu;
				break;
			}
			break;
				
           		case 6:
           			cout<<"Shutting Down";
           			break;
           		}
			    return 0;
			}

