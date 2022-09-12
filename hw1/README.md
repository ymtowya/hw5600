## HW 1

* Quick Link


* Question 1

*Q:Run process-run.py with the following flags: -l 5:100,5:100.
What should the CPU utilization be 
(e.g., the percent of time the CPU is in use?) 
Why do you know this? Use the -c and -p flags to see if you were right.*

A:The CPU utilization would be 100% because there are no IOs, only CPU dealing with the instructions.  
And run the flags with -c to certify this:

```
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 5:100,5:100 -c -p
Time        PID: 0        PID: 1           CPU           IOs
  1        RUN:cpu         READY             1          
  2        RUN:cpu         READY             1          
  3        RUN:cpu         READY             1          
  4        RUN:cpu         READY             1          
  5        RUN:cpu         READY             1          
  6           DONE       RUN:cpu             1          
  7           DONE       RUN:cpu             1          
  8           DONE       RUN:cpu             1          
  9           DONE       RUN:cpu             1          
 10           DONE       RUN:cpu             1          

Stats: Total Time 10
Stats: CPU Busy 10 (100.00%)
Stats: IO Busy  0 (0.00%)
```

* Question 2

*Q:Now run with these flags: ./process-run.py -l 4:100,1:0.
These flags specify one process with 4 instructions (all to use the
CPU), and one that simply issues an I/O and waits for it to be done.
How long does it take to complete both processes? Use -c and -p
to find out if you were right.*

A: It would take 11 time units to complete these 2 processes.  
We get this by adding: 4 (# of P0 instructions) + 1 (for P0 to be DONE) + 5 (# of P1 needs to wait for IO) + 1 (for P1 to be DONE) = 11 in total.  

And as the running result shows:

```
mtowya@TowyadeMacBook-Pro cpu-intro % ls
README.md	process-run.py
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 4:100,1:0 -c -p
Time        PID: 0        PID: 1           CPU           IOs
  1        RUN:cpu         READY             1          
  2        RUN:cpu         READY             1          
  3        RUN:cpu         READY             1          
  4        RUN:cpu         READY             1          
  5           DONE        RUN:io             1          
  6           DONE       WAITING                           1
  7           DONE       WAITING                           1
  8           DONE       WAITING                           1
  9           DONE       WAITING                           1
 10           DONE       WAITING                           1
 11*          DONE   RUN:io_done             1          

Stats: Total Time 11
Stats: CPU Busy 6 (54.55%)
Stats: IO Busy  5 (45.45%)
```

Total time is 11.

* Question 3

*Q: Switch the order of the processes: -l 1:0,4:100. What happens
now? Does switching the order matter? Why? (As always, use -c
and -p to see if you were right)*

A: After switching the order, the processes are completed in shorted time because P1 can be done while P0 is waiting for IO. The order matters because if the IO process is running first, the other process's instructions can be run in the following time, which cannot be done if not switched.  

And the running result shows:
```
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 1:0,4:100 -c -p
Time        PID: 0        PID: 1           CPU           IOs
  1         RUN:io         READY             1          
  2        WAITING       RUN:cpu             1             1
  3        WAITING       RUN:cpu             1             1
  4        WAITING       RUN:cpu             1             1
  5        WAITING       RUN:cpu             1             1
  6        WAITING          DONE                           1
  7*   RUN:io_done          DONE             1          

Stats: Total Time 7
Stats: CPU Busy 6 (85.71%)
Stats: IO Busy  5 (71.43%)
```

* Question 4

*Q: What happens when you run the following two processes (-l 1:0,4:100
-c -S SWITCH ON END), one doing I/O and the other doing CPU
work?*

A: Unlike what we saw in Question 3, this time the process will not switch to the other process dealing with instructions (i.e. P1) while P0 is waiting for an I/O. This time it will wait for the I/O until P0 is done, meanwhile blocking all the processes from running. P1 can only run after P0 is done.  

And we can see the running result:
```
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 1:0,4:100 -c -p -S SWITCH_ON_END
Time        PID: 0        PID: 1           CPU           IOs
  1         RUN:io         READY             1          
  2        WAITING         READY                           1
  3        WAITING         READY                           1
  4        WAITING         READY                           1
  5        WAITING         READY                           1
  6        WAITING         READY                           1
  7*   RUN:io_done         READY             1          
  8           DONE       RUN:cpu             1          
  9           DONE       RUN:cpu             1          
 10           DONE       RUN:cpu             1          
 11           DONE       RUN:cpu             1          

Stats: Total Time 11
Stats: CPU Busy 6 (54.55%)
Stats: IO Busy  5 (45.45%)
```

* Question 5

*Q: Now, run the same processes, but with the switching behavior set
to switch to another process whenever one is WAITING for I/O (-l
1:0,4:100 -c -S SWITCH ON IO). What happens now? Use -c
and -p to confirm that you are right.*

A: This time it will return to what we have in Question 3 that while P0 is waiting for I/O, P1 will be running, and the total time for these processed will decrease. This is because now we switch from P0 to P1 on I/O waiting time.  

And the running result is like:
```
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 1:0,4:100 -c -p -S SWITCH_ON_IO
Time        PID: 0        PID: 1           CPU           IOs
  1         RUN:io         READY             1          
  2        WAITING       RUN:cpu             1             1
  3        WAITING       RUN:cpu             1             1
  4        WAITING       RUN:cpu             1             1
  5        WAITING       RUN:cpu             1             1
  6        WAITING          DONE                           1
  7*   RUN:io_done          DONE             1          

Stats: Total Time 7
Stats: CPU Busy 6 (85.71%)
Stats: IO Busy  5 (71.43%)
```

* Question 6

*Q: What happens when you
run this combination of processes? (Run ./process-run.py -l
3:0,5:100,5:100,5:100 -S SWITCH ON IO -I IO RUN LATER
-c -p) Are system resources being effectively utilized?*

A: After changing this -I flag to IO_RUN_LATER, the process would not resume and run after its I/O is completed. Instead, other processes (of CPU instructions) will be running, and the initial I/O process will remain at the 'READY' state, waiting until all other processes are not running, then it will be able to run. In this case, it's P0 kept on READY state while P1~P3 runs.<br>
No. it's not effective. Because P0 consumed extra time units to complete othere I/Os while all other processes are DONE already and waiting for P0. It's a waste of resource.

As shown by the running result:

```
mtowya@TowyadeMacBook-Pro ostep % cd cpu-intro
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p
Time        PID: 0        PID: 1        PID: 2        PID: 3           CPU           IOs
  1         RUN:io         READY         READY         READY             1          
  2        WAITING       RUN:cpu         READY         READY             1             1
  3        WAITING       RUN:cpu         READY         READY             1             1
  4        WAITING       RUN:cpu         READY         READY             1             1
  5        WAITING       RUN:cpu         READY         READY             1             1
  6        WAITING       RUN:cpu         READY         READY             1             1
  7*         READY          DONE       RUN:cpu         READY             1          
  8          READY          DONE       RUN:cpu         READY             1          
  9          READY          DONE       RUN:cpu         READY             1          
 10          READY          DONE       RUN:cpu         READY             1          
 11          READY          DONE       RUN:cpu         READY             1          
 12          READY          DONE          DONE       RUN:cpu             1          
 13          READY          DONE          DONE       RUN:cpu             1          
 14          READY          DONE          DONE       RUN:cpu             1          
 15          READY          DONE          DONE       RUN:cpu             1          
 16          READY          DONE          DONE       RUN:cpu             1          
 17    RUN:io_done          DONE          DONE          DONE             1          
 18         RUN:io          DONE          DONE          DONE             1          
 19        WAITING          DONE          DONE          DONE                           1
 20        WAITING          DONE          DONE          DONE                           1
 21        WAITING          DONE          DONE          DONE                           1
 22        WAITING          DONE          DONE          DONE                           1
 23        WAITING          DONE          DONE          DONE                           1
 24*   RUN:io_done          DONE          DONE          DONE             1          
 25         RUN:io          DONE          DONE          DONE             1          
 26        WAITING          DONE          DONE          DONE                           1
 27        WAITING          DONE          DONE          DONE                           1
 28        WAITING          DONE          DONE          DONE                           1
 29        WAITING          DONE          DONE          DONE                           1
 30        WAITING          DONE          DONE          DONE                           1
 31*   RUN:io_done          DONE          DONE          DONE             1          

Stats: Total Time 31
Stats: CPU Busy 21 (67.74%)
Stats: IO Busy  15 (48.39%)
```

* Question 7

*Q: Now run the same processes, but with -I IO RUN IMMEDIATE set,
which immediately runs the process that issued the I/O. How does
this behavior differ? Why might running a process that just completed an I/O again be a good idea?*

A: This time, as soon as the I/O completes, its 'issuer' process would immediately resume running, cutting in the line. Other processes will wait until it becomes DONE or WAITING again and release the resources.<br>
This path is a good idea because very often, the process which waited for I/O will possibly issue another I/O again, and it will save resources and time to resume it once I/O is completed, so as to bring the following I/Os forward, and other processes can run while it's WAITING again. In this way, all the processes can be completed in shorter time and in general be more effective.
<br>
As the running result shows:

```
mtowya@TowyadeMacBook-Pro cpu-intro % ./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_IMMEDIATE -c -p
Time        PID: 0        PID: 1        PID: 2        PID: 3           CPU           IOs
  1         RUN:io         READY         READY         READY             1          
  2        WAITING       RUN:cpu         READY         READY             1             1
  3        WAITING       RUN:cpu         READY         READY             1             1
  4        WAITING       RUN:cpu         READY         READY             1             1
  5        WAITING       RUN:cpu         READY         READY             1             1
  6        WAITING       RUN:cpu         READY         READY             1             1
  7*   RUN:io_done          DONE         READY         READY             1          
  8         RUN:io          DONE         READY         READY             1          
  9        WAITING          DONE       RUN:cpu         READY             1             1
 10        WAITING          DONE       RUN:cpu         READY             1             1
 11        WAITING          DONE       RUN:cpu         READY             1             1
 12        WAITING          DONE       RUN:cpu         READY             1             1
 13        WAITING          DONE       RUN:cpu         READY             1             1
 14*   RUN:io_done          DONE          DONE         READY             1          
 15         RUN:io          DONE          DONE         READY             1          
 16        WAITING          DONE          DONE       RUN:cpu             1             1
 17        WAITING          DONE          DONE       RUN:cpu             1             1
 18        WAITING          DONE          DONE       RUN:cpu             1             1
 19        WAITING          DONE          DONE       RUN:cpu             1             1
 20        WAITING          DONE          DONE       RUN:cpu             1             1
 21*   RUN:io_done          DONE          DONE          DONE             1          

Stats: Total Time 21
Stats: CPU Busy 21 (100.00%)
Stats: IO Busy  15 (71.43%)
```

* Question 8

*Q: Now run with some randomly generated processes: -s 1 -l 3:50,3:50
or -s 2 -l 3:50,3:50 or -s 3 -l 3:50,3:50. See if you can
predict how the trace will turn out. What happens when you use
the flag -I IO RUN IMMEDIATE vs. -I IO RUN LATER? What happens when you use -S SWITCH ON IO vs. -S SWITCH ON END?*

A: It's hard to predict the trace because this time it's all in random. We cannot predict which process will issue an I/O, or the issue order inside the process. <br>
