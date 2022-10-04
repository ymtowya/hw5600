// #include "mlfq.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef NULL
    #define NULL 0
#endif

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

typedef unsigned int timestamp;

struct MLFQ_Job
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
} ;

struct MLFQ_Job_Queue
{
    /* data */
    int queue_id;
    int priority;
    int quantum_time;
    MLFQ_Job* header;
    MLFQ_Job* tail;
} ;

struct MLFQ_Processor
{
    /* data */
    MLFQ_Job_Queue* header;
    int queue_count;
} ;


typedef int bool;

#define HIGHEST_PRIORITY 0
#define IO_COST_TIME 5
#define INIT_ALLOT 5

int job_count = 10;
MLFQ_Job *job_queue;
MLFQ_Processor* processor;

void addNewProcess(timestamp currTime) {
    for (int i = 0; i < job_count; ++i) {
        if ((job_queue + i)->job_arrive_time == currTime) {
            // add the job
            MLFQ_Job* tailJob = processor->header->tail;
            tailJob->next = job_queue + i;
            processor->header->tail = job_queue + i;
            (job_queue + i)->priority = HIGHEST_PRIORITY;
            (job_queue + i)->next = NULL;
        }
    }
}

bool isEmptyQueue(MLFQ_Job_Queue* queue) {
    if (queue->header == NULL) {
        return true;
    }
    return false;
}

MLFQ_Job_Queue* getHighestJobQueue() {
    int currQueueIndex = 0;
    MLFQ_Job_Queue* currQueue = NULL;
    MLFQ_Job* resJob = NULL;
    while (currQueueIndex < processor->queue_count) {
        currQueue = processor->header + currQueueIndex;
        if (currQueue != NULL && !isEmptyQueue(currQueue)) {
            resJob = currQueue->header;
            break;
        }
        ++currQueueIndex;
    }
    return currQueue;
}

bool isIssueIO(MLFQ_Job* job, timestamp currTime) {
    if (job == NULL) {
        return false;
    }
    for (int i = 0; i < job->job_io_issue_count; ++i) {
        if (currTime == job->job_io_issue_time[i]) {
            return true;
        }
    }
    return false;
}

void removeJobFromQueue(MLFQ_Job* job, MLFQ_Job_Queue* queue) {
    if (job == NULL) {
        return;
    }
    MLFQ_Job* pre = queue->header;
    if (pre == job) {
        queue->header = job->next;
    } else {
        while (pre->next != job) {
            pre = pre->next;
        }
        pre->next = job->next;
        // job->priority = -1;
        job->next = NULL;
    }
    if (queue->tail == job) {
        queue->tail = NULL;
    }
    
}

bool hasJobComingFuture(int currTime, int totalTime) {
    for (int i = 0; i < job_count; ++i) {
        if (currTime < (job_queue + i)->job_arrive_time
            && (job_queue + i)->job_arrive_time < totalTime) {
            return true;
        }
    }
    return false;
}

bool addJobToQueue(MLFQ_Job* job, MLFQ_Job_Queue* queue) {
    if (job == NULL) {
        return false;
    }
    MLFQ_Job* currTail = queue->tail;
    if (currTail = NULL) {
        queue->header = job;
        queue->tail = job;
    } else {
        currTail->next = job;
        queue->tail = job;
        job->next = NULL;
    }
    return true;
}

MLFQ_Job_Queue* getQueueByPriority(int priority) {
    if (priority < HIGHEST_PRIORITY) {
        return NULL;
    } else if (priority >= HIGHEST_PRIORITY + processor->queue_count) {
        return processor->header + processor->queue_count - 1;
    }
    return processor->header + priority - HIGHEST_PRIORITY;
}

void run(int totalTime) {
    timestamp currTime = 0;
    MLFQ_Job* currJobPt = NULL;
    MLFQ_Job_Queue* currQueue = NULL;
    
    while (currTime < totalTime) {
        printf("time[%d] : \n", currTime);
        // check for new process
        addNewProcess(currTime);
        // check J
        if (currJobPt == NULL) {
            currQueue = getHighestJobQueue();
            if (currQueue != NULL) {
                currJobPt = currQueue->header;
            } else if (!hasJobComingFuture(currTime, totalTime)) {
                printf("FINISHED\n");
                break;
            }
        }
        // operate J
        if (isIssueIO(currJobPt, currTime)) {
            printf("Job[%d] issues IO\n", currJobPt->job_id);
            currJobPt->job_arrive_time = currTime + IO_COST_TIME;
            MLFQ_Job* tmpNext = currJobPt->next;
            removeJobFromQueue(currJobPt, currQueue);
            currJobPt = tmpNext;
            continue;
        } else {
            // run J
            if (currJobPt->job_run_left_time <= 1) {
                // complete
                printf("Job[%d] is completed\n", currJobPt->job_id);
                currJobPt->job_run_left_time = 0;
                removeJobFromQueue(currJobPt, currQueue);
            } else {
                currJobPt->job_run_left_time -= 1;
                currJobPt->allotTime -= 1;
                printf("Job[%d] runs\n", currJobPt->job_id);
                if (currJobPt->allotTime == 0) {
                    // down-grade its priority
                    const int prePriority = currJobPt->priority;
                    removeJobFromQueue(currJobPt, currQueue);
                    currJobPt->priority = prePriority + 1;
                    MLFQ_Job_Queue* nextQueue = getQueueByPriority(currJobPt->priority);
                    currJobPt->allotTime = INIT_ALLOT; // but not nextQueue->quantum_time ! 2 different concept!
                    addJobToQueue(currJobPt, nextQueue);
                    printf("Job[%d] is downgraded to priority [%d]\n", currJobPt->job_id, currJobPt->priority);
                }
            }
        }
        // increment
        currJobPt = currJobPt->next;
        ++currTime;
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    printf("/-----------------------/\n");
    printf("/------------INIT-----------/\n");
    const int queue_count = 4;
    MLFQ_Processor pro = {
        .queue_count = queue_count,
        .header = (MLFQ_Job_Queue *) malloc(queue_count * sizeof(MLFQ_Job_Queue))
    };
    processor = &pro;
    for (int i = 0; i < queue_count; ++i) {
        (processor->header + i)->priority = i;
        (processor->header + i)->queue_id = i;
        (processor->header + i)->header = NULL;
        (processor->header + i)->tail = NULL;
    }
    MLFQ_Job jobs[] = {
        { .job_id=0, .job_arrive_time=4, .priority=0, .allotTime=INIT_ALLOT, .job_run_left_time=12, .job_io_issue_count=0, .job_io_issue_count=NULL}
        ,{ .job_id=1, .job_arrive_time=2, .priority=0, .allotTime=INIT_ALLOT, .job_run_left_time=16, .job_io_issue_count=0, .job_io_issue_count=NULL}
        ,{ .job_id=2, .job_arrive_time=6, .priority=0, .allotTime=INIT_ALLOT, .job_run_left_time=11, .job_io_issue_count=0, .job_io_issue_count=NULL}
        ,{ .job_id=3, .job_arrive_time=10, .priority=0, .allotTime=INIT_ALLOT, .job_run_left_time=20, .job_io_issue_count=0, .job_io_issue_count=NULL}
        ,{ .job_id=4, .job_arrive_time=1, .priority=0, .allotTime=INIT_ALLOT, .job_run_left_time=5, .job_io_issue_count=0, .job_io_issue_count=NULL}
    };
    job_queue = jobs;
    job_count = 5;
    run(400);
    printf("/-----------------------/\n");
    return 0;
}
