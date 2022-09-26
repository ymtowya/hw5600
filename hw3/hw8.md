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
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 3 -q 5 -i 5 --jlist 20,10,2:0,50,0 -S -c

Job List:
  Job  0: startTime  20 - runTime  10 - ioFreq   2
  Job  1: startTime   0 - runTime  50 - ioFreq   0


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 1
[ time 0 ] Run JOB 1 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 49 (of 50) ]
[ time 1 ] Run JOB 1 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 48 (of 50) ]
[ time 2 ] Run JOB 1 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 47 (of 50) ]
[ time 3 ] Run JOB 1 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 46 (of 50) ]
[ time 4 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 45 (of 50) ]
[ time 5 ] Run JOB 1 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 44 (of 50) ]
[ time 6 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 43 (of 50) ]
[ time 7 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 42 (of 50) ]
[ time 8 ] Run JOB 1 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 41 (of 50) ]
[ time 9 ] Run JOB 1 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 40 (of 50) ]
[ time 10 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 39 (of 50) ]
[ time 11 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 38 (of 50) ]
[ time 12 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 37 (of 50) ]
[ time 13 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 36 (of 50) ]
[ time 14 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 35 (of 50) ]
[ time 15 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 34 (of 50) ]
[ time 16 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 33 (of 50) ]
[ time 17 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 32 (of 50) ]
[ time 18 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 31 (of 50) ]
[ time 19 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 30 (of 50) ]
[ time 20 ] JOB BEGINS by JOB 0
[ time 20 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 9 (of 10) ]
[ time 21 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 8 (of 10) ]
[ time 22 ] IO_START by JOB 0
IO DONE
[ time 22 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 29 (of 50) ]
[ time 23 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 28 (of 50) ]
[ time 24 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 27 (of 50) ]
[ time 25 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 26 (of 50) ]
[ time 26 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 25 (of 50) ]
[ time 27 ] IO_DONE by JOB 0
[ time 27 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 7 (of 10) ]
[ time 28 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 6 (of 10) ]
[ time 29 ] IO_START by JOB 0
IO DONE
[ time 29 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 24 (of 50) ]
[ time 30 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 23 (of 50) ]
[ time 31 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 22 (of 50) ]
[ time 32 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 21 (of 50) ]
[ time 33 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 20 (of 50) ]
[ time 34 ] IO_DONE by JOB 0
[ time 34 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 5 (of 10) ]
[ time 35 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 4 (of 10) ]
[ time 36 ] IO_START by JOB 0
IO DONE
[ time 36 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 19 (of 50) ]
[ time 37 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 18 (of 50) ]
[ time 38 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 17 (of 50) ]
[ time 39 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 16 (of 50) ]
[ time 40 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 15 (of 50) ]
[ time 41 ] IO_DONE by JOB 0
[ time 41 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 3 (of 10) ]
[ time 42 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 2 (of 10) ]
[ time 43 ] IO_START by JOB 0
IO DONE
[ time 43 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 14 (of 50) ]
[ time 44 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 13 (of 50) ]
[ time 45 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 12 (of 50) ]
[ time 46 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 11 (of 50) ]
[ time 47 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 10 (of 50) ]
[ time 48 ] IO_DONE by JOB 0
[ time 48 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 1 (of 10) ]
[ time 49 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 0 (of 10) ]
[ time 50 ] FINISHED JOB 0
[ time 50 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 9 (of 50) ]
[ time 51 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 50) ]
[ time 52 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 50) ]
[ time 53 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 50) ]
[ time 54 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 5 (of 50) ]
[ time 55 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 4 (of 50) ]
[ time 56 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 3 (of 50) ]
[ time 57 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 2 (of 50) ]
[ time 58 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 1 (of 50) ]
[ time 59 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 0 (of 50) ]
[ time 60 ] FINISHED JOB 1

Final statistics:
  Job  0: startTime  20 - response   0 - turnaround  30
  Job  1: startTime   0 - response   0 - turnaround  60

  Avg  1: startTime n/a - response 0.00 - turnaround 45.00


```

* Priority Boost

Delete `-B 12` For the ones without the boost.

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 3 -q 4 -i 2 --jlist 0,50,0:15,14,2:15,14,2 -S -B 12 -c

Job List:
  Job  0: startTime   0 - runTime  50 - ioFreq   0
  Job  1: startTime  15 - runTime  14 - ioFreq   2
  Job  2: startTime  15 - runTime  14 - ioFreq   2


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 49 (of 50) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 48 (of 50) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 47 (of 50) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 46 (of 50) ]
[ time 4 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 45 (of 50) ]
[ time 5 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 44 (of 50) ]
[ time 6 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 43 (of 50) ]
[ time 7 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 42 (of 50) ]
[ time 8 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 41 (of 50) ]
[ time 9 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 40 (of 50) ]
[ time 10 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 39 (of 50) ]
[ time 11 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 38 (of 50) ]
[ time 12 ] BOOST ( every 12 )
[ time 12 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 37 (of 50) ]
[ time 13 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 36 (of 50) ]
[ time 14 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 35 (of 50) ]
[ time 15 ] JOB BEGINS by JOB 1
[ time 15 ] JOB BEGINS by JOB 2
[ time 15 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 13 (of 14) ]
[ time 16 ] Run JOB 2 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 13 (of 14) ]
[ time 17 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 34 (of 50) ]
[ time 18 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 33 (of 50) ]
[ time 19 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 12 (of 14) ]
[ time 20 ] IO_START by JOB 1
IO DONE
[ time 20 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 12 (of 14) ]
[ time 21 ] IO_START by JOB 2
IO DONE
[ time 21 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 32 (of 50) ]
[ time 22 ] IO_DONE by JOB 1
[ time 22 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 11 (of 14) ]
[ time 23 ] IO_DONE by JOB 2
[ time 23 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 10 (of 14) ]
[ time 24 ] IO_START by JOB 1
IO DONE
[ time 24 ] BOOST ( every 12 )
[ time 24 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 31 (of 50) ]
[ time 25 ] Run JOB 2 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 11 (of 14) ]
[ time 26 ] IO_DONE by JOB 1
[ time 26 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 9 (of 14) ]
[ time 27 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 30 (of 50) ]
[ time 28 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 29 (of 50) ]
[ time 29 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 28 (of 50) ]
[ time 30 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 27 (of 50) ]
[ time 31 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 10 (of 14) ]
[ time 32 ] IO_START by JOB 2
IO DONE
[ time 32 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 8 (of 14) ]
[ time 33 ] IO_START by JOB 1
IO DONE
[ time 33 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 26 (of 50) ]
[ time 34 ] IO_DONE by JOB 2
[ time 34 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 9 (of 14) ]
[ time 35 ] IO_DONE by JOB 1
[ time 35 ] Run JOB 2 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 8 (of 14) ]
[ time 36 ] IO_START by JOB 2
IO DONE
[ time 36 ] BOOST ( every 12 )
[ time 36 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 25 (of 50) ]
[ time 37 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 7 (of 14) ]
[ time 38 ] IO_DONE by JOB 2
[ time 38 ] Run JOB 2 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 7 (of 14) ]
[ time 39 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 24 (of 50) ]
[ time 40 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 23 (of 50) ]
[ time 41 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 22 (of 50) ]
[ time 42 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 21 (of 50) ]
[ time 43 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 6 (of 14) ]
[ time 44 ] IO_START by JOB 1
IO DONE
[ time 44 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 6 (of 14) ]
[ time 45 ] IO_START by JOB 2
IO DONE
[ time 45 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 20 (of 50) ]
[ time 46 ] IO_DONE by JOB 1
[ time 46 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 5 (of 14) ]
[ time 47 ] IO_DONE by JOB 2
[ time 47 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 4 (of 14) ]
[ time 48 ] IO_START by JOB 1
IO DONE
[ time 48 ] BOOST ( every 12 )
[ time 48 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 19 (of 50) ]
[ time 49 ] Run JOB 2 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 5 (of 14) ]
[ time 50 ] IO_DONE by JOB 1
[ time 50 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 3 (of 14) ]
[ time 51 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 18 (of 50) ]
[ time 52 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 17 (of 50) ]
[ time 53 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 16 (of 50) ]
[ time 54 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 15 (of 50) ]
[ time 55 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 4 (of 14) ]
[ time 56 ] IO_START by JOB 2
IO DONE
[ time 56 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 2 (of 14) ]
[ time 57 ] IO_START by JOB 1
IO DONE
[ time 57 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 14 (of 50) ]
[ time 58 ] IO_DONE by JOB 2
[ time 58 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 3 (of 14) ]
[ time 59 ] IO_DONE by JOB 1
[ time 59 ] Run JOB 2 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 2 (of 14) ]
[ time 60 ] IO_START by JOB 2
IO DONE
[ time 60 ] BOOST ( every 12 )
[ time 60 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 13 (of 50) ]
[ time 61 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 1 (of 14) ]
[ time 62 ] IO_DONE by JOB 2
[ time 62 ] Run JOB 2 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 1 (of 14) ]
[ time 63 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 12 (of 50) ]
[ time 64 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 11 (of 50) ]
[ time 65 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 10 (of 50) ]
[ time 66 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 9 (of 50) ]
[ time 67 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 0 (of 14) ]
[ time 68 ] FINISHED JOB 1
[ time 68 ] Run JOB 2 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 0 (of 14) ]
[ time 69 ] FINISHED JOB 2
[ time 69 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 50) ]
[ time 70 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 50) ]
[ time 71 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 50) ]
[ time 72 ] BOOST ( every 12 )
[ time 72 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 5 (of 50) ]
[ time 73 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 4 (of 50) ]
[ time 74 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 3 (of 50) ]
[ time 75 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 2 (of 50) ]
[ time 76 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 1 (of 50) ]
[ time 77 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 0 (of 50) ]
[ time 78 ] FINISHED JOB 0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  78
  Job  1: startTime  15 - response   0 - turnaround  53
  Job  2: startTime  15 - response   1 - turnaround  54

  Avg  2: startTime n/a - response 0.33 - turnaround 61.67
```

* Attempt 2 - With Gaming Tolerance

Add `-S` for being without tolerance.

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -n 3 -q 5 -i 2 --jlist 0,50,0:15,15,3 -c

Job List:
  Job  0: startTime   0 - runTime  50 - ioFreq   0
  Job  1: startTime  15 - runTime  15 - ioFreq   3


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 49 (of 50) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 48 (of 50) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 47 (of 50) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 46 (of 50) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 45 (of 50) ]
[ time 5 ] Run JOB 0 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 44 (of 50) ]
[ time 6 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 43 (of 50) ]
[ time 7 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 42 (of 50) ]
[ time 8 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 41 (of 50) ]
[ time 9 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 40 (of 50) ]
[ time 10 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 39 (of 50) ]
[ time 11 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 38 (of 50) ]
[ time 12 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 37 (of 50) ]
[ time 13 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 36 (of 50) ]
[ time 14 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 35 (of 50) ]
[ time 15 ] JOB BEGINS by JOB 1
[ time 15 ] Run JOB 1 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 14 (of 15) ]
[ time 16 ] Run JOB 1 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 13 (of 15) ]
[ time 17 ] Run JOB 1 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 12 (of 15) ]
[ time 18 ] IO_START by JOB 1
IO DONE
[ time 18 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 34 (of 50) ]
[ time 19 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 33 (of 50) ]
[ time 20 ] IO_DONE by JOB 1
[ time 20 ] Run JOB 1 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 11 (of 15) ]
[ time 21 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 10 (of 15) ]
[ time 22 ] Run JOB 1 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 9 (of 15) ]
[ time 23 ] IO_START by JOB 1
IO DONE
[ time 23 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 32 (of 50) ]
[ time 24 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 31 (of 50) ]
[ time 25 ] IO_DONE by JOB 1
[ time 25 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 8 (of 15) ]
[ time 26 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 7 (of 15) ]
[ time 27 ] Run JOB 1 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 6 (of 15) ]
[ time 28 ] IO_START by JOB 1
IO DONE
[ time 28 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 30 (of 50) ]
[ time 29 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 29 (of 50) ]
[ time 30 ] IO_DONE by JOB 1
[ time 30 ] Run JOB 1 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 5 (of 15) ]
[ time 31 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 28 (of 50) ]
[ time 32 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 27 (of 50) ]
[ time 33 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 26 (of 50) ]
[ time 34 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 25 (of 50) ]
[ time 35 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 4 (of 15) ]
[ time 36 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 3 (of 15) ]
[ time 37 ] IO_START by JOB 1
IO DONE
[ time 37 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 24 (of 50) ]
[ time 38 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 23 (of 50) ]
[ time 39 ] IO_DONE by JOB 1
[ time 39 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 22 (of 50) ]
[ time 40 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 21 (of 50) ]
[ time 41 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 20 (of 50) ]
[ time 42 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 2 (of 15) ]
[ time 43 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 1 (of 15) ]
[ time 44 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 0 (of 15) ]
[ time 45 ] FINISHED JOB 1
[ time 45 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 19 (of 50) ]
[ time 46 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 18 (of 50) ]
[ time 47 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 17 (of 50) ]
[ time 48 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 16 (of 50) ]
[ time 49 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 15 (of 50) ]
[ time 50 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 14 (of 50) ]
[ time 51 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 13 (of 50) ]
[ time 52 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 12 (of 50) ]
[ time 53 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 11 (of 50) ]
[ time 54 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 10 (of 50) ]
[ time 55 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 9 (of 50) ]
[ time 56 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 50) ]
[ time 57 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 50) ]
[ time 58 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 50) ]
[ time 59 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 5 (of 50) ]
[ time 60 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 4 (of 50) ]
[ time 61 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 3 (of 50) ]
[ time 62 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 2 (of 50) ]
[ time 63 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 1 (of 50) ]
[ time 64 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 0 (of 50) ]
[ time 65 ] FINISHED JOB 0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  65
  Job  1: startTime  15 - response   0 - turnaround  30

  Avg  1: startTime n/a - response 0.00 - turnaround 47.50

```

* Better Parameter

```
E:\proj\cs\hw5600\hw3>python ./mlfq.py -Q 5,10,15 --jlist 0,50,0:0,50,0 -c

Job List:
  Job  0: startTime   0 - runTime  50 - ioFreq   0
  Job  1: startTime   0 - runTime  50 - ioFreq   0


Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] JOB BEGINS by JOB 1
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 49 (of 50) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 48 (of 50) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 47 (of 50) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 46 (of 50) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 45 (of 50) ]
[ time 5 ] Run JOB 1 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 49 (of 50) ]
[ time 6 ] Run JOB 1 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 48 (of 50) ]
[ time 7 ] Run JOB 1 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 47 (of 50) ]
[ time 8 ] Run JOB 1 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 46 (of 50) ]
[ time 9 ] Run JOB 1 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 45 (of 50) ]
[ time 10 ] Run JOB 0 at PRIORITY 1 [ TICKS 9 ALLOT 1 TIME 44 (of 50) ]
[ time 11 ] Run JOB 0 at PRIORITY 1 [ TICKS 8 ALLOT 1 TIME 43 (of 50) ]
[ time 12 ] Run JOB 0 at PRIORITY 1 [ TICKS 7 ALLOT 1 TIME 42 (of 50) ]
[ time 13 ] Run JOB 0 at PRIORITY 1 [ TICKS 6 ALLOT 1 TIME 41 (of 50) ]
[ time 14 ] Run JOB 0 at PRIORITY 1 [ TICKS 5 ALLOT 1 TIME 40 (of 50) ]
[ time 15 ] Run JOB 0 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 39 (of 50) ]
[ time 16 ] Run JOB 0 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 38 (of 50) ]
[ time 17 ] Run JOB 0 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 37 (of 50) ]
[ time 18 ] Run JOB 0 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 36 (of 50) ]
[ time 19 ] Run JOB 0 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 35 (of 50) ]
[ time 20 ] Run JOB 1 at PRIORITY 1 [ TICKS 9 ALLOT 1 TIME 44 (of 50) ]
[ time 21 ] Run JOB 1 at PRIORITY 1 [ TICKS 8 ALLOT 1 TIME 43 (of 50) ]
[ time 22 ] Run JOB 1 at PRIORITY 1 [ TICKS 7 ALLOT 1 TIME 42 (of 50) ]
[ time 23 ] Run JOB 1 at PRIORITY 1 [ TICKS 6 ALLOT 1 TIME 41 (of 50) ]
[ time 24 ] Run JOB 1 at PRIORITY 1 [ TICKS 5 ALLOT 1 TIME 40 (of 50) ]
[ time 25 ] Run JOB 1 at PRIORITY 1 [ TICKS 4 ALLOT 1 TIME 39 (of 50) ]
[ time 26 ] Run JOB 1 at PRIORITY 1 [ TICKS 3 ALLOT 1 TIME 38 (of 50) ]
[ time 27 ] Run JOB 1 at PRIORITY 1 [ TICKS 2 ALLOT 1 TIME 37 (of 50) ]
[ time 28 ] Run JOB 1 at PRIORITY 1 [ TICKS 1 ALLOT 1 TIME 36 (of 50) ]
[ time 29 ] Run JOB 1 at PRIORITY 1 [ TICKS 0 ALLOT 1 TIME 35 (of 50) ]
[ time 30 ] Run JOB 0 at PRIORITY 0 [ TICKS 14 ALLOT 1 TIME 34 (of 50) ]
[ time 31 ] Run JOB 0 at PRIORITY 0 [ TICKS 13 ALLOT 1 TIME 33 (of 50) ]
[ time 32 ] Run JOB 0 at PRIORITY 0 [ TICKS 12 ALLOT 1 TIME 32 (of 50) ]
[ time 33 ] Run JOB 0 at PRIORITY 0 [ TICKS 11 ALLOT 1 TIME 31 (of 50) ]
[ time 34 ] Run JOB 0 at PRIORITY 0 [ TICKS 10 ALLOT 1 TIME 30 (of 50) ]
[ time 35 ] Run JOB 0 at PRIORITY 0 [ TICKS 9 ALLOT 1 TIME 29 (of 50) ]
[ time 36 ] Run JOB 0 at PRIORITY 0 [ TICKS 8 ALLOT 1 TIME 28 (of 50) ]
[ time 37 ] Run JOB 0 at PRIORITY 0 [ TICKS 7 ALLOT 1 TIME 27 (of 50) ]
[ time 38 ] Run JOB 0 at PRIORITY 0 [ TICKS 6 ALLOT 1 TIME 26 (of 50) ]
[ time 39 ] Run JOB 0 at PRIORITY 0 [ TICKS 5 ALLOT 1 TIME 25 (of 50) ]
[ time 40 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 24 (of 50) ]
[ time 41 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 23 (of 50) ]
[ time 42 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 22 (of 50) ]
[ time 43 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 21 (of 50) ]
[ time 44 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 20 (of 50) ]
[ time 45 ] Run JOB 1 at PRIORITY 0 [ TICKS 14 ALLOT 1 TIME 34 (of 50) ]
[ time 46 ] Run JOB 1 at PRIORITY 0 [ TICKS 13 ALLOT 1 TIME 33 (of 50) ]
[ time 47 ] Run JOB 1 at PRIORITY 0 [ TICKS 12 ALLOT 1 TIME 32 (of 50) ]
[ time 48 ] Run JOB 1 at PRIORITY 0 [ TICKS 11 ALLOT 1 TIME 31 (of 50) ]
[ time 49 ] Run JOB 1 at PRIORITY 0 [ TICKS 10 ALLOT 1 TIME 30 (of 50) ]
[ time 50 ] Run JOB 1 at PRIORITY 0 [ TICKS 9 ALLOT 1 TIME 29 (of 50) ]
[ time 51 ] Run JOB 1 at PRIORITY 0 [ TICKS 8 ALLOT 1 TIME 28 (of 50) ]
[ time 52 ] Run JOB 1 at PRIORITY 0 [ TICKS 7 ALLOT 1 TIME 27 (of 50) ]
[ time 53 ] Run JOB 1 at PRIORITY 0 [ TICKS 6 ALLOT 1 TIME 26 (of 50) ]
[ time 54 ] Run JOB 1 at PRIORITY 0 [ TICKS 5 ALLOT 1 TIME 25 (of 50) ]
[ time 55 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 24 (of 50) ]
[ time 56 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 23 (of 50) ]
[ time 57 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 22 (of 50) ]
[ time 58 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 21 (of 50) ]
[ time 59 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 20 (of 50) ]
[ time 60 ] Run JOB 0 at PRIORITY 0 [ TICKS 14 ALLOT 1 TIME 19 (of 50) ]
[ time 61 ] Run JOB 0 at PRIORITY 0 [ TICKS 13 ALLOT 1 TIME 18 (of 50) ]
[ time 62 ] Run JOB 0 at PRIORITY 0 [ TICKS 12 ALLOT 1 TIME 17 (of 50) ]
[ time 63 ] Run JOB 0 at PRIORITY 0 [ TICKS 11 ALLOT 1 TIME 16 (of 50) ]
[ time 64 ] Run JOB 0 at PRIORITY 0 [ TICKS 10 ALLOT 1 TIME 15 (of 50) ]
[ time 65 ] Run JOB 0 at PRIORITY 0 [ TICKS 9 ALLOT 1 TIME 14 (of 50) ]
[ time 66 ] Run JOB 0 at PRIORITY 0 [ TICKS 8 ALLOT 1 TIME 13 (of 50) ]
[ time 67 ] Run JOB 0 at PRIORITY 0 [ TICKS 7 ALLOT 1 TIME 12 (of 50) ]
[ time 68 ] Run JOB 0 at PRIORITY 0 [ TICKS 6 ALLOT 1 TIME 11 (of 50) ]
[ time 69 ] Run JOB 0 at PRIORITY 0 [ TICKS 5 ALLOT 1 TIME 10 (of 50) ]
[ time 70 ] Run JOB 0 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 9 (of 50) ]
[ time 71 ] Run JOB 0 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 50) ]
[ time 72 ] Run JOB 0 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 50) ]
[ time 73 ] Run JOB 0 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 50) ]
[ time 74 ] Run JOB 0 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 5 (of 50) ]
[ time 75 ] Run JOB 1 at PRIORITY 0 [ TICKS 14 ALLOT 1 TIME 19 (of 50) ]
[ time 76 ] Run JOB 1 at PRIORITY 0 [ TICKS 13 ALLOT 1 TIME 18 (of 50) ]
[ time 77 ] Run JOB 1 at PRIORITY 0 [ TICKS 12 ALLOT 1 TIME 17 (of 50) ]
[ time 78 ] Run JOB 1 at PRIORITY 0 [ TICKS 11 ALLOT 1 TIME 16 (of 50) ]
[ time 79 ] Run JOB 1 at PRIORITY 0 [ TICKS 10 ALLOT 1 TIME 15 (of 50) ]
[ time 80 ] Run JOB 1 at PRIORITY 0 [ TICKS 9 ALLOT 1 TIME 14 (of 50) ]
[ time 81 ] Run JOB 1 at PRIORITY 0 [ TICKS 8 ALLOT 1 TIME 13 (of 50) ]
[ time 82 ] Run JOB 1 at PRIORITY 0 [ TICKS 7 ALLOT 1 TIME 12 (of 50) ]
[ time 83 ] Run JOB 1 at PRIORITY 0 [ TICKS 6 ALLOT 1 TIME 11 (of 50) ]
[ time 84 ] Run JOB 1 at PRIORITY 0 [ TICKS 5 ALLOT 1 TIME 10 (of 50) ]
[ time 85 ] Run JOB 1 at PRIORITY 0 [ TICKS 4 ALLOT 1 TIME 9 (of 50) ]
[ time 86 ] Run JOB 1 at PRIORITY 0 [ TICKS 3 ALLOT 1 TIME 8 (of 50) ]
[ time 87 ] Run JOB 1 at PRIORITY 0 [ TICKS 2 ALLOT 1 TIME 7 (of 50) ]
[ time 88 ] Run JOB 1 at PRIORITY 0 [ TICKS 1 ALLOT 1 TIME 6 (of 50) ]
[ time 89 ] Run JOB 1 at PRIORITY 0 [ TICKS 0 ALLOT 1 TIME 5 (of 50) ]
[ time 90 ] Run JOB 0 at PRIORITY 0 [ TICKS 14 ALLOT 1 TIME 4 (of 50) ]
[ time 91 ] Run JOB 0 at PRIORITY 0 [ TICKS 13 ALLOT 1 TIME 3 (of 50) ]
[ time 92 ] Run JOB 0 at PRIORITY 0 [ TICKS 12 ALLOT 1 TIME 2 (of 50) ]
[ time 93 ] Run JOB 0 at PRIORITY 0 [ TICKS 11 ALLOT 1 TIME 1 (of 50) ]
[ time 94 ] Run JOB 0 at PRIORITY 0 [ TICKS 10 ALLOT 1 TIME 0 (of 50) ]
[ time 95 ] FINISHED JOB 0
[ time 95 ] Run JOB 1 at PRIORITY 0 [ TICKS 14 ALLOT 1 TIME 4 (of 50) ]
[ time 96 ] Run JOB 1 at PRIORITY 0 [ TICKS 13 ALLOT 1 TIME 3 (of 50) ]
[ time 97 ] Run JOB 1 at PRIORITY 0 [ TICKS 12 ALLOT 1 TIME 2 (of 50) ]
[ time 98 ] Run JOB 1 at PRIORITY 0 [ TICKS 11 ALLOT 1 TIME 1 (of 50) ]
[ time 99 ] Run JOB 1 at PRIORITY 0 [ TICKS 10 ALLOT 1 TIME 0 (of 50) ]
[ time 100 ] FINISHED JOB 1

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  95
  Job  1: startTime   0 - response   5 - turnaround 100

  Avg  1: startTime n/a - response 2.50 - turnaround 97.50


```

### Q3

By setting only one queue. `-n 1`<br />
In this way, all jobs have same priority and stay on the same queue, then they are all run by a RR.

### Q4

This command
`python ./mlfq.py --jlist 1,100,8:0,20,0 -S -n 2 -q 10 -i 1 -c` sets the rate to 90%.<br/>
Just multiply by 10, we get 
`python ./mlfq.py --jlist 1,1000,98:0,700,0 -S -n 2 -q 100 -i 1 -c` which is the 99%.

### Q5

`python ./mlfq.py -j 23 -m 100 -n 2 -q 10 -B 200 -c -M 0` <br>
We get the number by `10 / 5% = 200`, which means that even the job was down-graded to the lowest queue, after 200 ms it got promoted to the top priority queue and can take the CPU for a slice of time, occupying at least 5% of the time.

### Q6

*Q:One question that arises in scheduling is which end of a queue to
add a job that just finished I/O; the -I flag changes this behavior
for this scheduling simulator. Play around with some workloads
and see if you can see the effect of this flag.*

A:

`python ./mlfq.py --jlist 0,40,0:0,30,3:0,30,3 -q 4 -n 3 -i 3 -c`
`python ./mlfq.py --jlist 0,40,0:0,30,3:0,30,3 -q 4 -n 3 -i 3 -c -I`
Without this flag, the job is added to the end of the queue.
Otherwise it's inserted to the beginning of the queue.