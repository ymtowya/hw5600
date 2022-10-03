
typedef unsigned int timestamp;

typedef struct 
{
    /* data */
    int job_id;
    timestamp job_arrive_time;
    int job_run_left_time;
    timestamp* job_io_issue_time;
    int job_io_issue_count;
    int allotTime;
    int priority;
    MLFQ_Job* next;
} MLFQ_Job;

typedef struct
{
    /* data */
    int queue_id;
    int priority;
    int quantum_time;
    MLFQ_Job* header;
    MLFQ_Job* tail;
} MLFQ_Job_Queue;

typedef struct
{
    /* data */
    MLFQ_Job_Queue* header;
    int queue_count;
} MLFQ_Processor;

