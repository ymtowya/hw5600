#include "mlfq.h"

#ifndef NULL
    #define NULL 0
#endif

#ifndef true
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

typedef int bool;

#define HIGHEST_PRIORITY 0
#define IO_COST_TIME 5
#define INIT_ALLOT 5

const int job_count = 10;
MLFQ_Job job_queue[];
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
        return;
    }
    MLFQ_Job* currTail = queue->tail;
    currTail->next = job;
    queue->tail = job;
    job->next = NULL;
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
        // check for new process
        addNewProcess(currTime);
        // check J
        if (currJobPt == NULL || currJobPt->next == NULL) {
            currQueue = getHighestJobQueue();
            if (currQueue != NULL) {
                currJobPt = currQueue->header;
            } else if (!hasJobComingFuture(currTime, totalTime)) {
                break;
            }
        }
        // operate J
        if (isIssueIO(currJobPt, currTime)) {
            currJobPt->job_arrive_time = currTime + IO_COST_TIME;
            MLFQ_Job* tmpNext = currJobPt->next;
            removeJobFromQueue(currJobPt, currQueue);
            currJobPt = tmpNext;
            continue;
        } else {
            // run J
            if (currJobPt->job_run_left_time <= 1) {
                // complete
                currJobPt->job_run_left_time = 0;
                removeJobFromQueue(currJobPt, currQueue);
            } else {
                currJobPt->job_run_left_time -= 1;
                currJobPt->allotTime -= 1;
                if (currJobPt->allotTime == 0) {
                    // down-grade its priority
                    const int prePriority = currJobPt->priority;
                    removeJobFromQueue(currJobPt, currQueue);
                    currJobPt->priority = prePriority + 1;
                    MLFQ_Job_Queue* nextQueue = getQueueByPriority(currJobPt->priority);
                    currJobPt->allotTime = INIT_ALLOT; // but not nextQueue->quantum_time ! 2 different concept!
                    addJobToQueue(currJobPt, nextQueue);
                }
            }
        }
        // increment
        currJobPt = currJobPt->next;
        ++currTime;
    }
}