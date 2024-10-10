#include <iostream>
#include <string>
using namespace std;

/* *********************************** CPUJob Class *********************************** */
class CPUJob {
    public:
        int job_id; // Unique identifier for the job
        int priority; // Priority level of the job (1-10)
        int job_type; // Job type (1-10)
        int cpu_time_consumed; // Total CPU time consumed by the job
        int memory_consumed; // Total memory consumed thus far

        CPUJob();
        CPUJob(int jobId, int prio, int JT, int CPU_TC, int MC);
        CPUJob(CPUJob& otherCPUJob);
        ~CPUJob();

        int getJobId();
        int getPriority();
        int getJobType();
        int getCPU_TC();
        int getMC();

        void setJobId(int jobId);
        void setPriority(int prio);
        void setJobType(int JT);
        void setCPU_TC(int CPU_TC);
        void setMC(int MC);
};

CPUJob::CPUJob(){
    job_id = NULL;
    priority = NULL;
    job_type = NULL;
    cpu_time_consumed = NULL;
    memory_consumed = NULL;
}
CPUJob::CPUJob(int jobId, int prio, int JT, int CPU_TC, int MC){
    job_id = jobId;
    priority = prio;
    job_type = JT;
    cpu_time_consumed = CPU_TC;
    memory_consumed = MC;
}
CPUJob::CPUJob(CPUJob& otherCPUJob){
    job_id = otherCPUJob.job_id;
    priority = otherCPUJob.priority;
    job_type = otherCPUJob.job_type;
    cpu_time_consumed = otherCPUJob.cpu_time_consumed;
    memory_consumed = otherCPUJob.memory_consumed;
}

int CPUJob::getJobId(){ return job_id; }
int CPUJob::getPriority(){ return priority; }
int CPUJob::getJobType(){ return job_type; }
int CPUJob::getCPU_TC() { return cpu_time_consumed; }
int CPUJob::getMC() { return memory_consumed; }

void CPUJob::setJobId(int jobId){ job_id = jobId; }
void CPUJob::setPriority(int prio){ priority = prio; }
void CPUJob::setJobType(int jobType){ job_type = jobType; }
void CPUJob::setCPU_TC(int CPU_TC) { cpu_time_consumed = CPU_TC; }
void CPUJob::setMC(int MC) { memory_consumed = MC; }



/* *********************************** Queue Class *********************************** */
template <class DT>
class Queue {
    public:
        DT* JobPointer; // Pointer to a job (e.g., CPUJob)
        Queue<DT>* next; // Pointer to the next node in the queue
};

/* *********************************** NovelQueue Class *********************************** */
template <class DT>
class NovelQueue {
    public:
        Queue<DT>* front; // Pointer to the front of the queue
        Queue<DT>** NodePtrs; // Array of pointers to Queue nodes
        int size; // Number of elements in the queue

        // Operations of NovelQueue
        void enqueue(int jobId, int prio, int JT, int CPU_TC, int MC); // Adds chips to the end of the queue (linkedlist)
        void enqueue(CPUJob* newCPUJob);
        CPUJob* dequeue(); 
        void modify(int jobId, int new_Prio, int new_JT, int newCPU_TC, int new_MC);
        void change(int jobId, int fieldIndex, int newValue);
        void promote(int jobId, int positions);
        CPUJob* reorder(int attributeIndex);

        int count();
        
        void display() const;
        void listJobs() const;
};

template <class DT>
void NovelQueue<DT>::enqueue(int jobId, int prio, int JT, int CPU_TC, int MC){

}
template <class DT>
void NovelQueue<DT>::enqueue(CPUJob* newCPUJob){

}
template <class DT>
CPUJob* NovelQueue<DT>::dequeue(){

}
template <class DT>
void NovelQueue<DT>::modify(int jobId, int new_Prio, int new_JT, int newCPU_TC, int new_MC){

}
template <class DT>
void NovelQueue<DT>::change(int jobId, int fieldIndex, int newValue){

}
template <class DT>
void NovelQueue<DT>::promote(int jobId, int positions){

}
template <class DT>
CPUJob* NovelQueue<DT>::reorder(int attributeIndex){

}

template <class DT>
int NovelQueue<DT>::count(){

}

template <class DT>
void NovelQueue<DT>::display() const{

}
template <class DT>
void NovelQueue<DT>::listJobs() const{

}

/* *********************************** Main *********************************** */
int main() {
    int n; // Number of commands
    cin >> n; // Read the number of commands
    
    // Instantiate a NovelQueue for CPUJob pointers
    NovelQueue<CPUJob*>* myNovelQueue = new NovelQueue<CPUJob*>();
    
    char command; // Variable to store the command type
    
    // Variables for job attributes
    int job_id, priority, job_type, cpu_time_consumed, memory_consumed;
    
    // Variables for modifying a job
    int new_priority, new_job_type, new_cpu_time_consumed;
    int new_memory_consumed;
    int field_index, new_value;
    // Variable for the number of positions in the 'Promote' command
    int positions;
    int attribute_index; // Variable for the 'Reorder' command

    /************** Read each command Process ***************/

    for (int i = 0; i < n; ++i) {
        cin >> command; // Read the command type
        
        switch (command) {
            case 'A': // Add (Enqueue)
                cin >> job_id >> priority >> job_type;
                cin >> cpu_time_consumed >> memory_consumed;
                CPUJob* newJob = new CPUJob(job_id, priority, job_type,
                cpu_time_consumed, memory_consumed);
                (*myNovelQueue).enqueue(newJob);
                break;
            
            case 'R': // Remove (Dequeue)
                CPUJob* removedJob = (*myNovelQueue).dequeue();
                if (removedJob) {
                    cout << "Dequeued Job: ";
                    (*removedJob).display();
                    delete removedJob; // Clean up memory after use
                }
                break;
            
            case 'M':  // Modify
                cin >> job_id >> new_priority >> new_job_type;
                cin >> new_cpu_time_consumed >> new_memory_consumed;
                (*myNovelQueue).modify(job_id, new_priority, new_job_type,
                new_cpu_time_consumed, new_memory_consumed);
                break;
            
            case 'C': // Change Job Values
                cin >> job_id >> field_index >> new_value;
                (*myNovelQueue).change(job_id, field_index, new_value);
                break;
            
            case 'P': // Promote
                cin >> job_id >> positions;
                (*myNovelQueue).promote(job_id, positions);
                break;
            
            case 'O': // Reorder
                cin >> attribute_index;
                NovelQueue<CPUJob*>* reorderedQueue =
                (*myNovelQueue).reorder(attribute_index);
                cout << "Reordered Queue:" << endl;
                (*reorderedQueue).display();
            break;
            
            case 'D': // Display
                (*myNovelQueue).display();
                break;
            
            case 'N': // Count
                cout << "Number of elements in the queue: " <<
                (*myNovelQueue).count() << endl;
                break;
            
            case 'L': // List Jobs
                (*myNovelQueue).listJobs();
                break;
            
            default:
                cout << "Invalid command!" << endl;
        }
    }

    delete myNovelQueue; // Clean up the NovelQueue after all operations
    return 0;
}
