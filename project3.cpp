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

        // Default constructor: Initializes all data members to 0
        CPUJob(); 

        // Parameterized constructor: Initializes data members with the given values
        CPUJob(int jobId, int prio, int JT, int CPU_TC, int MC);
        
        // Copy constructor: Creates a new CPUJob object as a copy of an existing one
        CPUJob(CPUJob& otherCPUJob);

        // Destructor: Automatically called when an object of this class is destroyed
        // Since no dynamic memory allocation is done, no need for manual cleanup
        ~CPUJob();

        // Getter methods: Return the value of respective data members
        int getJobId() const; // Returns job_id
        int getPriority() const; // Returns priority
        int getJobType() const; // Returns job_type
        int getCPU_TC() const; // Returns cpu_time_consumed
        int getMC() const; // Returns memory_consumed

        // Setter methods: Modify the value of respective data members
        void setJobId(int jobId); // Sets job_id
        void setPriority(int prio); // Sets priority
        void setJobType(int JT); // Sets job_type
        void setCPU_TC(int CPU_TC); // Sets cpu_time_consumed
        void setMC(int MC); // Sets memory_consumed

        // Displays the job's information in a formatted manner
        void display() const;
};

// Constructors
// Default constructor: Initializes all fields to 0
CPUJob::CPUJob(): 
    job_id(0), priority(0), job_type(0), cpu_time_consumed(0), memory_consumed(0) {}

// Parameterized constructor: Assigns values to the data members based on the arguments passed
CPUJob::CPUJob(int jobId, int prio, int JT, int CPU_TC, int MC): 
    job_id(jobId), priority(prio), job_type(JT), cpu_time_consumed(CPU_TC), memory_consumed(MC) {}

// Copy constructor: Copies the attributes from another CPUJob object
CPUJob::CPUJob(CPUJob& otherCPUJob): 
    job_id(otherCPUJob.job_id), priority(otherCPUJob.priority), job_type(otherCPUJob.job_type), 
    cpu_time_consumed(otherCPUJob.cpu_time_consumed), memory_consumed(otherCPUJob.memory_consumed) {}

// Get/Set methods
// These methods allow controlled access and modification of the job's attributes
// Returns the job ID
int CPUJob::getJobId() const { return job_id; }

// Returns the job's priority
int CPUJob::getPriority() const { return priority; }

// Returns the job type
int CPUJob::getJobType() const { return job_type; }

// Returns the total CPU time consumed
int CPUJob::getCPU_TC() const { return cpu_time_consumed; }

// Returns the total memory consumed
int CPUJob::getMC() const { return memory_consumed; }

// Sets the job ID to the specified value
void CPUJob::setJobId(int jobId){ job_id = jobId; }

// Sets the priority to the specified value
void CPUJob::setPriority(int prio){ priority = prio; }

// Sets the job type to the specified value
void CPUJob::setJobType(int jobType){ job_type = jobType; }

// Sets the CPU time consumed to the specified value
void CPUJob::setCPU_TC(int CPU_TC) { cpu_time_consumed = CPU_TC; }

// Sets the memory consumed to the specified value
void CPUJob::setMC(int MC) { memory_consumed = MC; }

// Displays the job's details in a user-friendly format
void CPUJob::display() const {
    cout << "Job ID: " << job_id << ", Priority: " << priority << ", Job Type: " << job_type << 
    ", CPU Time Consumed: " << cpu_time_consumed << ", Memory Consumed: " << memory_consumed << endl;
}

// Destructor: No dynamic memory allocation, so nothing to explicitly delete
CPUJob::~CPUJob(){}

/* *********************************** Queue Class *********************************** */
template <class DT>
class Queue {
    public:
        DT* JobPointer; // Pointer to a job (e.g., a CPUJob object)
        Queue<DT>* next; // Pointer to the next node in the queue

        // Default constructor: Initializes JobPointer and next to nullptr
        Queue();

        // Parameterized constructor: Initializes JobPointer and next with given values
        Queue(DT* JobPtr, Queue<DT>* nextJob);

        // Parameterized constructor: Initializes JobPointer and sets next to nullptr
        Queue(DT* JobPtr);

        // Copy constructor: Creates a new Queue node as a copy of an existing node
        Queue(Queue& otherQueue);

        // Destructor: Handles clean-up when a Queue object is destroyed
        ~Queue();

        // Getter methods: Provide access to JobPointer and next node
        DT* getJobPointer() const; // Returns JobPointer (pointer to the job)
        Queue<DT>* getNext() const; // Returns the next node in the queue

        // Setter methods: Modify JobPointer and the next node
        void setJobPointer(DT* jobPtr); // Sets the JobPointer to the given job
        void setNext(Queue<DT>* nextJob); // Sets the next node in the queue

        // Returns the size of the queue (number of nodes after the current node)
        int size();
};

// Constructors
// Default constructor: Initializes the JobPointer and next pointers to nullptr
template <class DT>
Queue<DT>::Queue(): JobPointer(nullptr), next(nullptr) {}

// Parameterized constructor: Initializes JobPointer with a job pointer and next with the next node pointer
template <class DT>
Queue<DT>::Queue(DT* JobPtr, Queue<DT>* nextJob): JobPointer(JobPtr), next(nextJob) {}

// Parameterized constructor: Initializes JobPointer with a job pointer, sets next to nullptr (no next node)
template <class DT>
Queue<DT>::Queue(DT* JobPtr): JobPointer(JobPtr), next(nullptr) {}

// Copy constructor: Copies the JobPointer and next node from another Queue object
template <class DT>
Queue<DT>::Queue(Queue& otherQueue): JobPointer(otherQueue.JobPointer), next(otherQueue.next) {}


// Get/Set methods
// Returns the pointer to the job (JobPointer)
template <class DT>
DT* Queue<DT>::getJobPointer() const { return JobPointer; }

// Returns the pointer to the next node in the queue
template <class DT>
Queue<DT>* Queue<DT>::getNext() const { return next; }

// Sets the JobPointer to the specified job pointer
template <class DT>
void Queue<DT>::setJobPointer(DT* jobPtr){ JobPointer = jobPtr; }

// Sets the next pointer to the specified next node
template <class DT>
void Queue<DT>::setNext(Queue<DT>* nextJob){ next = nextJob; }

// Size method
// Computes the size of the queue by traversing the list and counting the nodes
template <class DT>
int Queue<DT>::size(){

    Queue<DT>* current = next; // Start from the next node (skip the current one)
    int count = 0;

    // Traverse the linked list and count each node
    while (current != nullptr){
        current = current->next;
        count++;
    }
    
    return count; // Return the total number of nodes after the current one
}

// Destructor
// Destructor: Deletes the JobPointer (since it's dynamically allocated), sets pointers to nullptr
template <class DT>
Queue<DT>::~Queue(){

    delete JobPointer; // Free the dynamically allocated job
    JobPointer = nullptr; // Set the pointer to nullptr to avoid dangling pointers
    next = nullptr; // Set the next pointer to nullptr as well
}

/* *********************************** NovelQueue Class *********************************** */
template <class DT>
class NovelQueue {
    public:
        Queue<DT>* front; // Pointer to the front of the queue
        Queue<DT>** NodePtrs; // Array of pointers to Queue nodes for binary search and direct access
        int size; // Number of elements in the queue
        int capacity; // Current capacity of NodePtrs array, dynamically adjusted as needed

        NovelQueue(); // Default constructor
        NovelQueue(Queue<DT>* frontPtr, Queue<DT>** nodePtrs, int numElements); // Constructor with front pointer, NodePtrs array, and size
        NovelQueue(Queue<DT>* frontPtr); // Constructor with front pointer only
        NovelQueue(NovelQueue& otherNovelQueue); // Copy constructor

        ~NovelQueue(); // Destructor

        // Queue operations
        bool enqueue(DT& newCPUJob); // Adds a new job to the queue
        void resize(); // Resizes the NodePtrs array if it runs out of capacity
        CPUJob* dequeue(); // Removes the front job from the queue
        void modify(int jobId, int new_Prio, int new_JT, int newCPU_TC, int new_MC); // Modifies job attributes based on jobId
        bool change(int jobId, int fieldIndex, int newValue); // Modifies a specific field of a job
        void promote(int jobId, int positions); // Promotes a job up by a given number of positions in the queue
        NovelQueue<DT>* reorder(int attributeIndex); // Reorders the queue based on an attribute (e.g., JobId, priority)

        int binarySearch(int keyValue, int left, int right); // Binary search for jobId

        int count(); // Returns the number of elements in the queue
        
        void display() const; // Displays the jobs in queue order
        void listJobs() const; // Displays jobs based on NodePtrs order (sorted by jobId for binary search)
};

// Default constructor initializes an empty queue with an initial capacity of 10 for NodePtrs
template <class DT>
NovelQueue<DT>::NovelQueue(): front(nullptr), size(0), capacity(10) {
    NodePtrs = new Queue<DT>*[capacity]; // Allocate NodePtrs array with initial capacity of 10
}

// Constructor with front pointer, NodePtrs array, and size
template <class DT>
NovelQueue<DT>::NovelQueue(Queue<DT>* frontPtr, Queue<DT>** nodePtrs, int numElements): front(frontPtr), 
    NodePtrs(nodePtrs), size(numElements) {}

// Constructor with just front pointer
template <class DT>
NovelQueue<DT>::NovelQueue(Queue<DT>* frontPtr): front(frontPtr), NodePtrs(nullptr), size(1) {}

// Copy constructor creates a shallow copy of another NovelQueue
// NodePtrs and front are shared between the queues (be cautious about memory management here)
template <class DT>
NovelQueue<DT>::NovelQueue(NovelQueue& otherNovelQueue): front(otherNovelQueue.front), NodePtrs(otherNovelQueue.NodePtrs), size(otherNovelQueue.size) {}

// Enqueue operation - adds a new job to the queue
// Checks if the queue needs resizing and handles duplicates based on JobId
template <class DT>
bool NovelQueue<DT>::enqueue(DT& newCPUJob){

    if (size >= capacity){
        resize(); // If the queue is full, resize the NodePtrs array
    }
    
    DT* newJob = new DT(newCPUJob); // Create a new job dynamically
    Queue<DT>* newQueue = new Queue<DT>(newJob); // Create a new queue node for the job

    Queue<DT>* current = front;
    while (current != nullptr) { // Check for duplicate job IDs
        if ((*newJob)->getJobId() == (*current->JobPointer)->getJobId()){
            cout << "Job ID " << (*current->JobPointer)->getJobId() << " already exists!" << endl;
            return false;
        }
        current = current->next;
    }

    // Handle adding the first element or appending at the end
    if (size == 0){ // If the queue is empty, set the front
        front = newQueue;
        NodePtrs[0] = newQueue;
    }
    else { // Otherwise, find the end of the queue and add the new job
        Queue<DT>* current = front;
        for (int i = 0; i < size; i++){
            if (current->next != nullptr){
                current = current->next;
            }
        }
        current->setNext(newQueue); // Append new job at the end of the queue
        NodePtrs[size] = newQueue; // Store the new job in NodePtrs for fast access
    }

    NodePtrs[size]->setNext(nullptr); // Mark the new job as the end of the queue
    size++; // Increase the size of the queue

    return true;
}

/* LLM: The resize function was suggested to help increase the capacity of the queue when the queue had reached its 
        maximum size after encountering troubles with the initialization of the NovelQueue. 
*/
// Resizes the NodePtrs array when it reaches capacity
template <class DT>
void NovelQueue<DT>::resize(){

    int newCapacity = capacity * 2; // Double the capacity
    Queue<DT>** newNodePtr = new Queue<DT>*[newCapacity]; // Create a new, larger array

    // Copy the existing elements to the new array
    for (int i = 0; i < size; i++){
        newNodePtr[i] = NodePtrs[i];
    }

    // Delete the old array and assign the new one
    delete[] NodePtrs;
    NodePtrs = newNodePtr;
    capacity = newCapacity; // Update the capacity to the new size
}

// Dequeues the front job from the queue
template <class DT>
CPUJob* NovelQueue<DT>::dequeue(){

    // Copy the front job for return
    CPUJob* result = new CPUJob((**front->getJobPointer())); 
    
    Queue<DT>* temp = front; // Store the current front node
    front = front->getNext(); // Move the front pointer to the next job
    temp->setNext(nullptr); // Detach the dequeued node

    // Remove the job from NodePtrs (shift elements left)
    for (int i = 0; i < size - 1; i++){
        if ((*NodePtrs[i]->JobPointer)->getJobId() == result->getJobId()){
            for (int k = i; k < size; k++){
                NodePtrs[k] = NodePtrs[k + 1];
            }
            break;
        }
    }

    delete temp; // Deallocate the dequeued node
    size--; // Decrease the size
    return result; // Return the dequeued job
}

/* LLM: 
*/
// Modifies a job's attributes based on its jobId
template <class DT>
void NovelQueue<DT>::modify(int jobId, int new_Prio, int new_JT, int newCPU_TC, int new_MC){
    
    // Find the job using binary search
    int index = binarySearch(jobId, 0, size - 1); 
    
    // If Job is not found in the Queue
    if (index == -1){
        cout << "Modified Job with ID " << jobId << " not found in the queue." << endl;
        return;
    }

    // Update the job's attributes
    (*NodePtrs[index]->JobPointer)->setPriority(new_Prio);
    (*NodePtrs[index]->JobPointer)->setJobType(new_JT);
    (*NodePtrs[index]->JobPointer)->setCPU_TC(newCPU_TC);
    (*NodePtrs[index]->JobPointer)->setMC(new_MC);

    cout << "Modified Job ID " << jobId << ":" << endl;
    (*NodePtrs[index]->JobPointer)->display(); // Display the updated job
}

// Changes a specific field of a job by jobId
template <class DT>
bool NovelQueue<DT>::change(int jobId, int fieldIndex, int newValue){
    
    // Find the job using binary search
    int index = binarySearch(jobId, 0, size - 1); 
    
    // If Job is not in the Queue
    if (index == -1){
        cout << "Job with ID " << jobId << " not found in the queue. " << endl;
        return false;
    }  

    // Modify the specific field based on the fieldIndex provided
    switch (fieldIndex)
    {
        case 1:
            (*NodePtrs[index]->JobPointer)->setPriority(newValue);
            break;
        case 2:
            (*NodePtrs[index]->JobPointer)->setJobType(newValue);
            break;
        case 3:
            (*NodePtrs[index]->JobPointer)->setCPU_TC(newValue);
            break;
        case 4:
            (*NodePtrs[index]->JobPointer)->setMC(newValue);
            break;
        default:
            cout << "Invalid number: " << fieldIndex << endl;
            break;
    }

    cout << "Changed Job ID " << jobId << " field " << fieldIndex << " to " << newValue << ": " << endl;
    (*NodePtrs[index]->JobPointer)->display(); // Display the updated job

    return true;
}

/* LLM: When I asked Chat to help me with the promote function, many issues began to arise with it. Initially, 
        I thought that this was going to be simple. Boy was I wrong. Chat and I had thought that using NodePtr 
        (our array of queues) would be sufficient enough. I would find my promoting job using binary search and 
        assumed that the indeces before and after the index of the promoting job would be the job directly 
        before and after. I did not realize what the problem was until after using a mass amount of debugging 
        lines. Then and only then did I understand what I was doing. Jobs in NodePtr may be sorted by job ID, but 
        not completely correct in terms of the queue. Essentially job 101, 102, 103, and 104 could be sorted in 
        terms of NodePtr, but could be in a completely different order in terms of the queue due to position 
        changing jobs such as promote and reorder. I resolve this issue by iterating through the queue itself and 
        not through NodePtr. This resolve the issue of finding the promoting job as well as the jobs that appear 
        before and after it. 

        With the correct way to find the promoting job and jobs around it arose another problem. Edge cases where 
        the promoting job may not have a job that comes directly before or after it. The fix was simple, yet took 
        too long to discover. I did not understand why the promoting job was stopping my outputs until, again, the 
        use of a mass amount of debugging lines to help dig up the problem. The fix was to simply check if the jobs 
        before and after the promoting job were nullptrs, as well as checking if the jobs of where the new position 
        of the promoting job were nullptrs too (in the case of sending the job to the front of the queue, where there 
        are no jobs that come before that position). 
*/
// Promotes a job by a given number of positions within the queue
template <class DT>
void NovelQueue<DT>::promote(int jobId, int positions){

    // Find the current position of the job
    int currPosition = 0;
    Queue<DT>* current = front;
    while (current != nullptr){
        if ((*current->JobPointer)->getJobId() == jobId){
            break;
        }
        current = current->next;
        currPosition++;
    }

    // If the jobId isn't found in the queue, print an error message and exit the function
    if (currPosition == size){
        cout << "Job Id not found in promote: " << jobId << endl;
        return;
    }

    // Calculate the new position after promotion (subtracting positions)
    int newPosition = currPosition - positions;

    // Ensure the new position is not less than 0 (if so, set it to 0)
    if (newPosition <= 0){
        newPosition = 0;   
    }

    // If the job is already in the desired position or no promotion is requested, exit the function
    if ((currPosition == newPosition) || (positions == 0)){
        cout << "Job is already in the promoted position" << endl;
        return;
    }

    // Store the pointer to the job being promoted
    Queue<DT>* promotedJob = NodePtrs[currPosition];

    // Identify the job before and after the current job in the queue (if they exist)
    // Used to be identified this way, but soon came to realize that this became a problem since next job can be different than the order in NodePtrs
    Queue<DT>* jobBefore;
    Queue<DT>* jobAfter;

    int count = 0;

    if (currPosition == 0){
        // Indicates if job is at the front of the Queue
        jobBefore = nullptr;
        jobAfter = front->next;
    }
    else if (currPosition == size - 1){
        // Indicates if job is at the back of the Queue
        current = front;
        
        // Searches through the Queue starting from the front
        while (count < currPosition - 1){
            current = current->next;
            count++;
        }

        jobBefore = current;
        jobAfter = nullptr;
    }
    else{
        // Indicates if current position is neither at the back or front of the Queue
        current = front;

        while (count < size){
            if (count == currPosition - 1){
                jobBefore = current;
            }
            else if (count == currPosition){
                jobAfter = current->next;
                break;
            }

            current = current->next;
            count++;
        }
    }

    // Update the links between the jobs before and after the promoted job
    if (jobBefore != nullptr && jobAfter != nullptr) {
        // Link the job before to the job after (removing the promoted job from its current position)
        jobBefore->setNext(jobAfter);
    } 
    else if ((currPosition == size - 1) && (jobBefore != nullptr) && (jobAfter == nullptr)) {
        // If the promoted job is at the end, set the jobBefore's next to nullptr (making jobBefore the new end)
        jobBefore->setNext(nullptr);
    } 

    // If the new position is the front (0), update the front pointer to the promoted job
    if (newPosition == 0){ 
        promotedJob->setNext(front);
        front = promotedJob;
    }
    else{
        // Find the job before and after the new position of the promoted job
        // Promotion lands somewhere in the Queue
        
        Queue<DT>* beforePromotedJob;
        Queue<DT>* afterPromotedJob;

        count = 0;
        current = front;

        // Searches thorugh the Queue for the jobs before and after the new promotion position
        while (count < size){
            if (count == newPosition - 1){
                beforePromotedJob = current;
            }
            else if (count == newPosition){
                afterPromotedJob = current;
                break;
            }

            current = current->next;
            count++;
        }

        // Temporarily set the next pointers of the surrounding jobs to nullptr
        beforePromotedJob->setNext(nullptr);
        promotedJob->setNext(nullptr);

        // Insert the promoted job between beforePromotedJob and afterPromotedJob
        beforePromotedJob->setNext(promotedJob);
        promotedJob->setNext(afterPromotedJob);
    }

    // Output the details of the promoted job.
    cout << "Promoted Job ID " << jobId << " by " << positions << " Position(s): " << endl;
    (*promotedJob->JobPointer)->display();
}

/* LLM: When I first asked Chat to help me with the reorder function, chat had generated something similar
        to what was shown here. Chat had suggested to create not only a resulting NovelQueue, but a temparary 
        queue to house the elements and put them in a sorted order. This had me tremendously confused as Chat 
        kept generating code while I was stuck trying to understand what it was trying to do. Soon, I came to 
        realize that what Chat was doing was to allow us to sort a completely separate queue so that we could 
        enqueue the sorted queue into the resulting NovelQueue, returning the sorted NovelQueue as requested, 
        in respect to the attribute index. 

        There, however, was a problem. After returning the resulting NovelQueue, when the display function was 
        called, there was an ordering mistake that I did not catch until further inspection. The reason why the 
        reorder function was not completely finished was because when multiple jobs have equality between 
        attributes, the sorting algorithm would place the job who was closest to the front as the first job. The 
        problem that arises with this is that given job 108 with priority 4 and job 103 with priority 4 was well, 
        if job 108 came first in the queue, the sorting algorithm would place job 108 in the sorted queue first 
        and then place job 103 after. However, the auto grader had further sorted the output and had job 103 come 
        before job 108. The fix was simply checking if the jobs had the same value in the respected attribute and 
        then comparing their job ID. This resolved the reorder functions sorting issues.  
*/
// Reorders the queue based on a specific attribute (e.g., JobId, priority)
template <class DT>
NovelQueue<DT>* NovelQueue<DT>::reorder(int attributeIndex){

    // Create a new NovelQueue to store the reordered results
    NovelQueue<DT>* result = new NovelQueue<DT>();

    // Create a temporary array to hold pointers to the jobs in NodePtrs for sorting
    Queue<DT>** tempArray = new Queue<DT>*[size];
    for (int i = 0; i < size; i++) {
        // Copy each element from NodePtrs into the tempArray
        tempArray[i] = new Queue<DT>((*NodePtrs[i]));
    }

    // Perform selection sort based on the specified attribute
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; // Assume the current index is the minimum

        // Iterate through the unsorted portion of the array to find the smallest element
        for (int j = i + 1; j < size; j++) {
            bool condition = false; // This will determine if the current element is smaller

            // Check which attribute to sort by, and compare accordingly
            switch (attributeIndex) {
                case 1: 
                    // Sort by JobId
                    condition = (*tempArray[j]->JobPointer)->getJobId() < (*tempArray[minIndex]->JobPointer)->getJobId();
                    break;
                
                case 2: 
                    // Sort by Priority
                    condition = (*tempArray[j]->JobPointer)->getPriority() < (*tempArray[minIndex]->JobPointer)->getPriority();
                    
                    // If Priority is the same, compare Job IDs
                    if ((*tempArray[j]->JobPointer)->getPriority() == (*tempArray[minIndex]->JobPointer)->getPriority()){
                        condition = (*tempArray[j]->JobPointer)->getJobId() < (*tempArray[minIndex]->JobPointer)->getJobId();   
                    }
                    break;
                
                case 3: 
                    // Sort by Job Type
                    condition = (*tempArray[j]->JobPointer)->getJobType() < (*tempArray[minIndex]->JobPointer)->getJobType();

                    // If JobType is the same, compare Job IDs
                    if ((*tempArray[j]->JobPointer)->getJobType() == (*tempArray[minIndex]->JobPointer)->getJobType()){
                        condition = (*tempArray[j]->JobPointer)->getJobId() < (*tempArray[minIndex]->JobPointer)->getJobId();   
                    }
                    break;
                
                case 4: 
                    // Sort by CPU Time Consumed
                    condition = (*tempArray[j]->JobPointer)->getCPU_TC() < (*tempArray[minIndex]->JobPointer)->getCPU_TC();

                    // If CPU Time Consumed is the same, compare Job IDs
                    if ((*tempArray[j]->JobPointer)->getCPU_TC() == (*tempArray[minIndex]->JobPointer)->getCPU_TC()){
                        condition = (*tempArray[j]->JobPointer)->getJobId() < (*tempArray[minIndex]->JobPointer)->getJobId();   
                    }
                    break;
                
                case 5: 
                    // Sort by Memory Consumed
                    condition = (*tempArray[j]->JobPointer)->getMC() < (*tempArray[minIndex]->JobPointer)->getMC();

                    // If Memory Consumed is the same, compare Job IDs
                    if ((*tempArray[j]->JobPointer)->getMC() == (*tempArray[minIndex]->JobPointer)->getMC()){
                        condition = (*tempArray[j]->JobPointer)->getJobId() < (*tempArray[minIndex]->JobPointer)->getJobId();   
                    }
                    break;
                
                default:
                    // If an invalid attributeIndex is provided, display an error and clean up
                    cout << "Invalid Attribute" << endl;
                    delete[] tempArray; // Free the temporary array.
                    return nullptr; // Return null due to the invalid input
            }

            // If the condition is true, update minIndex to the new smaller element
            if (condition) {
                minIndex = j;
            }
        }

        // If the minimum element is not already at the current index, swap the two
        if (i != minIndex) {
            Queue<DT>* temp = tempArray[i];
            tempArray[i] = tempArray[minIndex];
            tempArray[minIndex] = temp;
        }
    }

    // After sorting, enqueue the jobs into the result queue in sorted order
    for (int i = 0; i < size; i++) {
        result->enqueue((*tempArray[i]->JobPointer)); // Enqueue each job
    }

    delete[] tempArray;  // Free the array itself

    // Update the front of the current queue to point to the front of the reordered result
    front = result->front;

    // Return the newly sorted queue
    return result;
}

// Binary search for finding a job by its jobId
template <class DT>
int NovelQueue<DT>::binarySearch(int keyValue, int left, int right) {

    if (right < left) {
        // Job not found
        return -1;
    }

    int mid = left + (right - left) / 2; // Calculate the middle index

    int jobIdAtMid = (*NodePtrs[mid]->JobPointer)->getJobId(); // Get the jobId at the middle index

    if (jobIdAtMid == keyValue) {
        return mid; // Job found at the mid index
    }
    if (jobIdAtMid > keyValue) {
        // If the middle jobId is greater than the key, search the left half
        return binarySearch(keyValue, left, mid - 1);
    } else {
        // If the middle jobId is less than the key, search the right half
        return binarySearch(keyValue, mid + 1, right);
    }
}

// Returns the number of elements in the queue
template <class DT>
int NovelQueue<DT>::count() { return size; } // Simply return the size of the queue

// Displays the jobs in queue order
template <class DT>
void NovelQueue<DT>::display() const {

    Queue<DT>* current = front; // Start at the front of the queue

    // Traverse through the queue and display each job
    while (current != nullptr) {
        (*current->JobPointer)->display(); // Display the job
        current = current->getNext(); // Move to the next job
    }
}

// Lists the jobs based on the NodePtrs array (sorted by JobId)
template <class DT>
void NovelQueue<DT>::listJobs() const {

    cout << "List of jobs sorted by job IDs:" << endl;

    // Traverse the NodePtrs array and display each job (sorted by JobId)
    for (int i = 0; i < size; i++) {
        (*NodePtrs[i]->JobPointer)->display(); // Display the job
    }
}
// Destructor for NovelQueue
template <class DT>
NovelQueue<DT>::~NovelQueue(){

    // Delete jobs
    for (int i = 0; i < size; i++){
        delete NodePtrs[i];
    }

    // Set pointers to nullptr for safety
    front = nullptr;
    NodePtrs = nullptr;
    size = 0; // Reset size to 0
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
            case 'A': { // Add (Enqueue)
                cin >> job_id >> priority >> job_type >> cpu_time_consumed >> memory_consumed;
                CPUJob* newJob = new CPUJob(job_id, priority, job_type, cpu_time_consumed, memory_consumed);

                bool result = (*myNovelQueue).enqueue(newJob);

                if (result){
                    cout << "Enqueued Job: " << endl;
                    newJob->display();

                    cout << "Jobs after enqueue:" << endl;
                    (*myNovelQueue).display();
                }

                break;
            }
            
            case 'R': { // Remove (Dequeue)
                CPUJob* removedJob = (*myNovelQueue).dequeue();
                if (removedJob) {
                    cout << "Dequeued Job: " << endl;
                    (*removedJob).display();
                    delete removedJob; // Clean up memory after use
                                    
                    cout << "Jobs after dequeue: " << endl;
                    (*myNovelQueue).display();
                }
                break;
            }
            
            case 'M': { // Modify
                cin >> job_id >> new_priority >> new_job_type;
                cin >> new_cpu_time_consumed >> new_memory_consumed;
                (*myNovelQueue).modify(job_id, new_priority, new_job_type, new_cpu_time_consumed, new_memory_consumed);
                            
                cout << "Jobs after modification: " << endl;
                (*myNovelQueue).display();

                break;
            }
            
            case 'C': { // Change Job Values
                cin >> job_id >> field_index >> new_value;
                bool result = (*myNovelQueue).change(job_id, field_index, new_value);

                if (result){
                    cout << "Jobs after changing field: " << endl;
                    (*myNovelQueue).display();
                }

                break;
            }
            
            case 'P': { // Promote
                cin >> job_id >> positions;
                (*myNovelQueue).promote(job_id, positions);
                            
                cout << "Jobs after promotion: " << endl;
                (*myNovelQueue).display();

                break;
            }
            
            case 'O': { // Reorder
                cin >> attribute_index;
                NovelQueue<CPUJob*>* reorderedQueue = (*myNovelQueue).reorder(attribute_index);

                cout << "Reordered Queue by attribute " << attribute_index << ": " << endl;
                (*reorderedQueue).display();

                break;
            }
            
            case 'D': { // Display
                cout << "Displaying all jobs in the queue: " << endl;
                (*myNovelQueue).display();

                break;
            }
            
            case 'N': { // Count
                cout << "Number of elements in the queue: " <<
                (*myNovelQueue).count() << endl;

                break;
            }
            
            case 'L': { // List Jobs
                (*myNovelQueue).listJobs();

                break;
            }
            
            default:{
                cout << "Invalid command!" << endl;
            }
        }
    }

    delete myNovelQueue; // Clean up the NovelQueue after all operations
    return 0;
}

/*
    LLM Usage: 
        This project proved its dire need of the usage of a large language model, such as ChatGPT. This project 
        not only had many ways of doing it, but each way proved to have a vast amount of various ways to get stuck 
        too. In this project, Chat had helped suggest and implement functions, such as the resize function, and help 
        improve (and mess up) other functions such as the reorder and promote. 

    LLM Documentation:
        Prompt: What would be the best approach to implementing the reorder function to return a queue sorted by 
        a specific attribute like JobId or Priority.
            I had asked Chat many questions that revolved around the reorder function. With each question, Chat 
            had suggested many different solutions, many which proved useful, and many which had confictions with 
            the code. I chose these prompts that revolved around this centeral prompt of improving the reorder function 
            because with each of the prompts, it incrementally improved the succession rate of the reorder function, even 
            if I did not see it at first. One suggestion helped me to realize that creating a temperary queue for sorting 
            would prove beneficial. Without the use of a temperary queue, the the sorting part of the reorder function would 
            be harder to implement since we would have no reference to the orginal queue to do comparisions with. Something 
            that Chat could not help me with was trying to debug the reorder function. The reorder function was very picky 
            with which job came before the other when sorting by a certain attribute other than job IDs. For instance, if the 
            order of the queue was 101, 102, 108, 103, 104, with each job having a priority of 8, 2, 4, 4, 1, respectively, 
            then the order of the resulting NovelQueue I had would be 104, 102, 108, 103, 101. The resulting NovelQueue had 
            placed job 108 before job 103 because it had came before job 103 in the queue. However, the autograder had placed 
            job 108 after job 103 in its desired output and this became a struggle for me to find what was wrong and when I 
            noticed that it had sorted the queue by job ID if the attribute value were equal was astounding. This was the last 
            function that I needed to finished before declaring this project done and with the completion of this function, the 
            incremental incentive was through the roof. 
        
        Prompt: Why is the promote function not working correctly?
            I asked Chat to help me dubug the promote function. My main worry with the promotion function was that I 
            was not setting the order of jobs correctly after moving the job to its new position. I found out that I 
            had set some of the jobs pointers to nullptr and this cause conflictions with the display function to show 
            outputs and debugging. This solved essentially the biggest problem of the promote function and boosted the 
            progression of the project. With the promotion function working, the rest of the functions would work based 
            on the new queue.The reason I chose this prompt was becuase this is a part of every question that was related 
            to the promote function I had asked Chat. "Why is (certian part of promote) not working correctly?", " Why is 
            jobBefore and jobAfter not working correctly?", "Why is (many questions related to NodePtr) not working?". These 
            are only some of the questions that I constantly asked Chat. Each time I had implemented one of Chats suggestions, 
            it would either be of great help to me or backfire and completely break my code. The incremental develpment was 
            shaky, but in the end, it had paid off and with the fixed promotion function, other functions would work based off 
            of the new queue. 

        Prompt: How should I go about implementing the display function to show the correct order after position changing 
        functions like reordering and promotions?
            I asked Chat this question to help me understand how the queue was working so that I could have a solid 
            foundation to work on. The implementation of the display function helped me understand the queue better and 
            further helped me understand how I should go about implementing the other functions. I asked Chat if the initial 
            way of me implementing the display function was a good start, and Chat responded with it being a good start and 
            that I was on the right track to go about displaying the jobs information. Chat further helped me develop the 
            display function and with the display function completed, it helped me debug the rest of my code. The reason behind 
            choosing this prompt is that there were multiple approaches I had thought of as I was implementing the display 
            function. One of my initial approaches was running through the NodePtr array and print out the jobs in that order. 
            However, this would not work since the NodePtr array would be sorted to job IDs and not be correlated with the actual 
            order of the queue. The NodePtr array could be 102, 103, 104, 105 and the actual queue culd be 103, 102, 104, 105. That 
            when I realized that I would approach the display function differently and instead of running through the NodePtrs array, 
            run through the front pointer, calling the next queue with each iteration of displaying the job information. This helped 
            with not only the display funtion, by every other function since I would have nearly 200 debugging lines that used display 
            or iterating thorugh NodePtrs in some way.

    Debugging and Testing Plan:
        Specific Tests:
            The test that I had done was using the many inputs of project 3 and comparing it with the many outputs of project 3. I 
            constantly used the display method and different kinds of display methods to debug the code and find inconsistencies and 
            flaws. With the many lines of outputs, trying to compare so many lines become mind numbing and I had resorted to the use of 
            text checkers to check if two texts differed in any way. This helped me find issues witht the reorder function and helped me 
            find issues with white spaces as well. 

        Issues and Resolutions:
            Many of the issues that stemmed from this project was incorrectly calling and setting nullptrs. The setting of pointers was 
            crucial to the smoothness and completion of the project. Many nullptrs I had found was using the display function which would 
            stop outputing when encountering a nullptr. This helped me slowly comb through each function and find where I had incorrectly 
            set job pointers as the wrong job or as nullptrs. 

        Verifications:
            The verification of the project was comparing and matching outputs of the outputs given on canvas and the outputs of my code. 
            I read through them, multiple times. And when that hurt my head, I would resort to use the auto grader to check my work. When the 
            autograder became difficult to understand, I resorted to the text checker to check the outputs.  
*/