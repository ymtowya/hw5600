# Homework 3

## Chapter 8

### Q1

*Q:Run a few randomly-generated problems with just two jobs and
two queues; compute the MLFQ execution trace for each.*

A: Randomly generated 2 jobs, and the results are as follows:

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 2 -j 2 -M 0 -q 5 -m 14 -c
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is   5
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is   5
OPTIONS boost 0
OPTIONS ioTime 5
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime  11 - ioFreq   0
  Job  1: startTime   0 - runTime   6 - ioFreq   0


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] JOB BEGINS by JOB 1
[ time 0 ] Run JOB 0 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 10 (of 11) ]
[ time 1 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 9 (of 11) ]
[ time 2 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 8 (of 11) ]
[ time 3 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 7 (of 11) ]
[ time 4 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 6 (of 11) ]
[ time 5 ] Run JOB 1 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 5 (of 6) ]
[ time 6 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 4 (of 6) ]
[ time 7 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 3 (of 6) ]
[ time 8 ] Run JOB 1 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 2 (of 6) ]
[ time 9 ] Run JOB 1 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 1 (of 6) ]
[ time 10 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 5 (of 11) ]
[ time 11 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 4 (of 11) ]
[ time 12 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 3 (of 11) ]
[ time 13 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 2 (of 11) ]
[ time 14 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 1 (of 11) ]
[ time 15 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 0 (of 6) ]
[ time 16 ] FINISHED JOB 1
[ time 16 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 0 (of 11) ]
[ time 17 ] FINISHED JOB 0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  17
  Job  1: startTime   0 - response   5 - turnaround  16

  Avg  1: startTime n/a - response 2.50 - turnaround 16.50

```

### Q2

*Q:How would you run the scheduler to reproduce each of the examples in the chapter?*

A: 

* Example 1

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 3 -j 1 -M 0 -q 5 -m 40 -c

Job List:
  Job  0: startTime   0 - runTime  33 - ioFreq   0


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 32 (of 33) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 31 (of 33) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 30 (of 33) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 29 (of 33) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 28 (of 33) ]
[ time 5 ] Run JOB 0 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 27 (of 33) ]
[ time 6 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 26 (of 33) ]
[ time 7 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 25 (of 33) ]
[ time 8 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 24 (of 33) ]
[ time 9 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 23 (of 33) ]
[ time 10 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 22 (of 33) ]
[ time 11 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 21 (of 33) ]
[ time 12 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 20 (of 33) ]
[ time 13 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 19 (of 33) ]
[ time 14 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 18 (of 33) ]
[ time 15 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 17 (of 33) ]
[ time 16 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 16 (of 33) ]
[ time 17 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 15 (of 33) ]
[ time 18 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 14 (of 33) ]
[ time 19 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 13 (of 33) ]
[ time 20 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 12 (of 33) ]
[ time 21 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 11 (of 33) ]
[ time 22 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 10 (of 33) ]
[ time 23 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 9 (of 33) ]
[ time 24 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 8 (of 33) ]
[ time 25 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 7 (of 33) ]
[ time 26 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 6 (of 33) ]
[ time 27 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 5 (of 33) ]
[ time 28 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 4 (of 33) ]
[ time 29 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 3 (of 33) ]
[ time 30 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 2 (of 33) ]
[ time 31 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 1 (of 33) ]
[ time 32 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 0 (of 33) ]
[ time 33 ] FINISHED JOB 0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  33

  Avg  0: startTime n/a - response 0.00 - turnaround 33.00

```

* Example 2

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 3 -M 0 -q 5 -m 40 -c --jlist 0,40,0:20,10,0

Job List:
  Job  0: startTime   0 - runTime  40 - ioFreq   0
  Job  1: startTime  20 - runTime  10 - ioFreq   0


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 39 (of 40) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 38 (of 40) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 37 (of 40) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 36 (of 40) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 35 (of 40) ]
[ time 5 ] Run JOB 0 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 34 (of 40) ]
[ time 6 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 33 (of 40) ]
[ time 7 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 32 (of 40) ]
[ time 8 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 31 (of 40) ]
[ time 9 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 30 (of 40) ]
[ time 10 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 29 (of 40) ]
[ time 11 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 28 (of 40) ]
[ time 12 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 27 (of 40) ]
[ time 13 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 26 (of 40) ]
[ time 14 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 25 (of 40) ]
[ time 15 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 24 (of 40) ]
[ time 16 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 23 (of 40) ]
[ time 17 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 22 (of 40) ]
[ time 18 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 21 (of 40) ]
[ time 19 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 20 (of 40) ]
[ time 20 ] JOB BEGINS by JOB 1
[ time 20 ] Run JOB 1 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 9 (of 10) ]
[ time 21 ] Run JOB 1 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 8 (of 10) ]
[ time 22 ] Run JOB 1 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 7 (of 10) ]
[ time 23 ] Run JOB 1 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 6 (of 10) ]
[ time 24 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 5 (of 10) ]
[ time 25 ] Run JOB 1 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 4 (of 10) ]
[ time 26 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 3 (of 10) ]
[ time 27 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 2 (of 10) ]
[ time 28 ] Run JOB 1 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 1 (of 10) ]
[ time 29 ] Run JOB 1 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 0 (of 10) ]
[ time 30 ] FINISHED JOB 1
[ time 30 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 19 (of 40) ]
[ time 31 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 18 (of 40) ]
[ time 32 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 17 (of 40) ]
[ time 33 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 16 (of 40) ]
[ time 34 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 15 (of 40) ]
[ time 35 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 14 (of 40) ]
[ time 36 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 13 (of 40) ]
[ time 37 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 12 (of 40) ]
[ time 38 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 11 (of 40) ]
[ time 39 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 10 (of 40) ]
[ time 40 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 9 (of 40) ]
[ time 41 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 40) ]
[ time 42 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 40) ]
[ time 43 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 40) ]
[ time 44 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 5 (of 40) ]
[ time 45 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 4 (of 40) ]
[ time 46 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 3 (of 40) ]
[ time 47 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 2 (of 40) ]
[ time 48 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 1 (of 40) ]
[ time 49 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 0 (of 40) ]
[ time 50 ] FINISHED JOB 0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  50
  Job  1: startTime  20 - response   0 - turnaround  10

  Avg  1: startTime n/a - response 0.00 - turnaround 30.00


```

* Example 3

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 3 -q 5 -c --jlist 0,60,0:20,10,1
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 3
OPTIONS allotments for queue  2 is   1
OPTIONS quantum length for queue  2 is   5
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is   5
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is   5
OPTIONS boost 0
OPTIONS ioTime 5
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime  60 - ioFreq   0
  Job  1: startTime  20 - runTime  10 - ioFreq   1


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 59 (of 60) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 58 (of 60) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 57 (of 60) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 56 (of 60) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 55 (of 60) ]
[ time 5 ] Run JOB 0 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 54 (of 60) ]
[ time 6 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 53 (of 60) ]
[ time 7 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 52 (of 60) ]
[ time 8 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 51 (of 60) ]
[ time 9 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 50 (of 60) ]
[ time 10 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 49 (of 60) ]
[ time 11 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 48 (of 60) ]
[ time 12 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 47 (of 60) ]
[ time 13 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 46 (of 60) ]
[ time 14 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 45 (of 60) ]
[ time 15 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 44 (of 60) ]
[ time 16 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 43 (of 60) ]
[ time 17 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 42 (of 60) ]
[ time 18 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 41 (of 60) ]
[ time 19 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 40 (of 60) ]
[ time 20 ] JOB BEGINS by JOB 1
[ time 20 ] Run JOB 1 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 9 (of 10) ]
[ time 21 ] IO_START by JOB 1
IO DONE
[ time 21 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 39 (of 60) ]
[ time 22 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 38 (of 60) ]
[ time 23 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 37 (of 60) ]
[ time 24 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 36 (of 60) ]
[ time 25 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 35 (of 60) ]
[ time 26 ] IO_DONE by JOB 1
[ time 26 ] Run JOB 1 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 8 (of 10) ]
[ time 27 ] IO_START by JOB 1
IO DONE
[ time 27 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 34 (of 60) ]
[ time 28 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 33 (of 60) ]
[ time 29 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 32 (of 60) ]
[ time 30 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 31 (of 60) ]
[ time 31 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 30 (of 60) ]
[ time 32 ] IO_DONE by JOB 1
[ time 32 ] Run JOB 1 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 7 (of 10) ]
[ time 33 ] IO_START by JOB 1
IO DONE
[ time 33 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 29 (of 60) ]
[ time 34 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 28 (of 60) ]
[ time 35 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 27 (of 60) ]
[ time 36 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 26 (of 60) ]
[ time 37 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 25 (of 60) ]
[ time 38 ] IO_DONE by JOB 1
[ time 38 ] Run JOB 1 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 6 (of 10) ]
[ time 39 ] IO_START by JOB 1
IO DONE
[ time 39 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 24 (of 60) ]
[ time 40 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 23 (of 60) ]
[ time 41 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 22 (of 60) ]
[ time 42 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 21 (of 60) ]
[ time 43 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 20 (of 60) ]
[ time 44 ] IO_DONE by JOB 1
[ time 44 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 5 (of 10) ]
[ time 45 ] IO_START by JOB 1
IO DONE
[ time 45 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 19 (of 60) ]
[ time 46 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 18 (of 60) ]
[ time 47 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 17 (of 60) ]
[ time 48 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 16 (of 60) ]
[ time 49 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 15 (of 60) ]
[ time 50 ] IO_DONE by JOB 1
[ time 50 ] Run JOB 1 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 4 (of 10) ]
[ time 51 ] IO_START by JOB 1
IO DONE
[ time 51 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 14 (of 60) ]
[ time 52 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 13 (of 60) ]
[ time 53 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 12 (of 60) ]
[ time 54 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 11 (of 60) ]
[ time 55 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 10 (of 60) ]
[ time 56 ] IO_DONE by JOB 1
[ time 56 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 3 (of 10) ]
[ time 57 ] IO_START by JOB 1
IO DONE
[ time 57 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 9 (of 60) ]
[ time 58 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 60) ]
[ time 59 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 60) ]
[ time 60 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 60) ]
[ time 61 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 5 (of 60) ]
[ time 62 ] IO_DONE by JOB 1
[ time 62 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 2 (of 10) ]
[ time 63 ] IO_START by JOB 1
IO DONE
[ time 63 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 4 (of 60) ]
[ time 64 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 3 (of 60) ]
[ time 65 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 2 (of 60) ]
[ time 66 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 1 (of 60) ]
[ time 67 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 0 (of 60) ]
[ time 68 ] FINISHED JOB 0
[ time 68 ] IO_DONE by JOB 1
[ time 68 ] Run JOB 1 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 1 (of 10) ]
[ time 69 ] IO_START by JOB 1
IO DONE
[ time 69 ] IDLE
[ time 70 ] IDLE
[ time 71 ] IDLE
[ time 72 ] IDLE
[ time 73 ] IDLE
[ time 74 ] IO_DONE by JOB 1
[ time 74 ] Run JOB 1 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 0 (of 10) ]
[ time 75 ] FINISHED JOB 1

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  68
  Job  1: startTime  20 - response   0 - turnaround  55

  Avg  1: startTime n/a - response 0.00 - turnaround 61.50


```
