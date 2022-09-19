# Homework 2

## Chapter 5 Simulator Part

### Q1

*Q: Run ./fork.py -s 10 and see which actions are taken?*

<br>The running result is like this:<br>

```
E:\proj\cs\hw5600\hw2>python ./fork.py -s 10 -c

ARG seed 10
ARG fork_percentage 0.7
ARG actions 5
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: a forks c
                               a
                               ├── b
                               └── c
Action: c EXITS
                               a
                               └── b
Action: a forks d
                               a
                               ├── b
                               └── d
Action: a forks e
                               a
                               ├── b
                               ├── d
                               └── e
E:\proj\cs\hw5600\hw2>python ./fork.py -s 3 -c

ARG seed 3
ARG fork_percentage 0.7
ARG actions 5
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: b forks c
                               a
                               └── b
                                   └── c
Action: a forks d
                               a
                               ├── b
                               │   └── c
                               └── d
Action: d forks e
                               a
                               ├── b
                               │   └── c
                               └── d
                                   └── e
Action: b forks f
                               a
                               ├── b
                               │   ├── c
                               │   └── f
                               └── d
                                   └── e
E:\proj\cs\hw5600\hw2>python ./fork.py -s 6 -a 8 -c

ARG seed 6
ARG fork_percentage 0.7
ARG actions 8
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: b forks c
                               a
                               └── b
                                   └── c
Action: c forks d
                               a
                               └── b
                                   └── c
                                       └── d
Action: d forks e
                               a
                               └── b
                                   └── c
                                       └── d
                                           └── e
Action: e forks f
                               a
                               └── b
                                   └── c
                                       └── d
                                           └── e
                                               └── f
Action: c EXITS
                               a
                               ├── b
                               ├── d
                               ├── e
                               └── f
Action: e forks g
                               a
                               ├── b
                               ├── d
                               ├── e
                               │   └── g
                               └── f
Action: e forks h
                               a
                               ├── b
                               ├── d
                               ├── e
                               │   ├── g
                               │   └── h
                               └── f

```


### Q2

*Q: Run the simulator with a large number of actions and vary the for_percentage from 0.1 to 0.9.?*

<br>The running result is like this:<br>

```
E:\proj\cs\hw5600\hw2>python ./fork.py -f 0.1 -a 15 -c

ARG seed -1
ARG fork_percentage 0.1
ARG actions 15
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: b EXITS
                               a
Action: a forks c
                               a
                               └── c
Action: c EXITS
                               a
Action: a forks d
                               a
                               └── d
Action: d EXITS
                               a
Action: a forks e
                               a
                               └── e
Action: a forks f
                               a
                               ├── e
                               └── f
Action: e EXITS
                               a
                               └── f
Action: f EXITS
                               a
Action: a forks g
                               a
                               └── g
Action: g EXITS
                               a
Action: a forks h
                               a
                               └── h
Action: h EXITS
                               a
Action: a forks i
                               a
                               └── i
E:\proj\cs\hw5600\hw2>python ./fork.py -f 0.4 -a 15 -c

ARG seed -1
ARG fork_percentage 0.4
ARG actions 15
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: a forks c
                               a
                               ├── b
                               └── c
Action: b forks d
                               a
                               ├── b
                               │   └── d
                               └── c
Action: b forks e
                               a
                               ├── b
                               │   ├── d
                               │   └── e
                               └── c
Action: d forks f
                               a
                               ├── b
                               │   ├── d
                               │   │   └── f
                               │   └── e
                               └── c
Action: c forks g
                               a
                               ├── b
                               │   ├── d
                               │   │   └── f
                               │   └── e
                               └── c
                                   └── g
Action: c forks h
                               a
                               ├── b
                               │   ├── d
                               │   │   └── f
                               │   └── e
                               └── c
                                   ├── g
                                   └── h
Action: c EXITS
                               a
                               ├── b
                               │   ├── d
                               │   │   └── f
                               │   └── e
                               ├── g
                               └── h
Action: g EXITS
                               a
                               ├── b
                               │   ├── d
                               │   │   └── f
                               │   └── e
                               └── h
Action: d EXITS
                               a
                               ├── b
                               │   └── e
                               ├── h
                               └── f
Action: b forks i
                               a
                               ├── b
                               │   ├── e
                               │   └── i
                               ├── h
                               └── f
Action: e forks j
                               a
                               ├── b
                               │   ├── e
                               │   │   └── j
                               │   └── i
                               ├── h
                               └── f
Action: e forks k
                               a
                               ├── b
                               │   ├── e
                               │   │   ├── j
                               │   │   └── k
                               │   └── i
                               ├── h
                               └── f
Action: k EXITS
                               a
                               ├── b
                               │   ├── e
                               │   │   └── j
                               │   └── i
                               ├── h
                               └── f
Action: e EXITS
                               a
                               ├── b
                               │   └── i
                               ├── h
                               ├── f
                               └── j
E:\proj\cs\hw5600\hw2>python ./fork.py -f 0.8 -a 15 -c

ARG seed -1
ARG fork_percentage 0.8
ARG actions 15
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: a forks c
                               a
                               ├── b
                               └── c
Action: b forks d
                               a
                               ├── b
                               │   └── d
                               └── c
Action: d forks e
                               a
                               ├── b
                               │   └── d
                               │       └── e
                               └── c
Action: e EXITS
                               a
                               ├── b
                               │   └── d
                               └── c
Action: b forks f
                               a
                               ├── b
                               │   ├── d
                               │   └── f
                               └── c
Action: d forks g
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   └── f
                               └── c
Action: g forks h
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   │       └── h
                               │   └── f
                               └── c
Action: b forks i
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   │       └── h
                               │   ├── f
                               │   └── i
                               └── c
Action: c forks j
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   │       └── h
                               │   ├── f
                               │   └── i
                               └── c
                                   └── j
Action: i forks k
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   │       └── h
                               │   ├── f
                               │   └── i
                               │       └── k
                               └── c
                                   └── j
Action: b forks l
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   │       └── h
                               │   ├── f
                               │   ├── i
                               │   │   └── k
                               │   └── l
                               └── c
                                   └── j
Action: k forks m
                               a
                               ├── b
                               │   ├── d
                               │   │   └── g
                               │   │       └── h
                               │   ├── f
                               │   ├── i
                               │   │   └── k
                               │   │       └── m
                               │   └── l
                               └── c
                                   └── j
Action: d forks n
                               a
                               ├── b
                               │   ├── d
                               │   │   ├── g
                               │   │   │   └── h
                               │   │   └── n
                               │   ├── f
                               │   ├── i
                               │   │   └── k
                               │   │       └── m
                               │   └── l
                               └── c
                                   └── j
Action: d forks o
                               a
                               ├── b
                               │   ├── d
                               │   │   ├── g
                               │   │   │   └── h
                               │   │   ├── n
                               │   │   └── o
                               │   ├── f
                               │   ├── i
                               │   │   └── k
                               │   │       └── m
                               │   └── l
                               └── c
                                   └── j

```


### Q3

*Q:Switch the output by using the -t flag (e.g., run ./fork.py -t). Given a set of process trees, can you tell which actions were taken?*

<br>Adding the `-t` flag would display the process trees instead of the actions (if there is no `-c` flag).
<br>The result is like this.<br>

```
E:\proj\cs\hw5600\hw2>python ./fork.py -f 0.4 -a 10 -s 3

ARG seed 3
ARG fork_percentage 0.4
ARG actions 10
ARG action_list
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action: a forks b
Process Tree?
Action: b forks c
Process Tree?
Action: c forks d
Process Tree?
Action: a forks e
Process Tree?
Action: c EXITS
Process Tree?
Action: b EXITS
Process Tree?
Action: e EXITS
Process Tree?
Action: d EXITS
Process Tree?
Action: a forks f
Process Tree?
Action: f EXITS
Process Tree?
E:\proj\cs\hw5600\hw2>python ./fork.py -f 0.4 -a 10 -s 3 -t

ARG seed 3
ARG fork_percentage 0.4
ARG actions 10
ARG action_list
ARG show_tree True
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action?
                               a
                               └── b
Action?
                               a
                               └── b
                                   └── c
Action?
                               a
                               └── b
                                   └── c
                                       └── d
Action?
                               a
                               ├── b
                               │   └── c
                               │       └── d
                               └── e
Action?
                               a
                               ├── b
                               ├── e
                               └── d
Action?
                               a
                               ├── e
                               └── d
Action?
                               a
                               └── d
Action?
                               a
Action?
                               a
                               └── f
Action?
                               a
```

### Q4

*Q:Let’s create a specific example: ./fork.py -A a+b,b+c,c+d,c+e,c-. 
This example has process ’a’ create ’b’, which in turn creates ’c’,
which then creates ’d’ and ’e’. However, then, ’c’ exits. What do
you think the process tree should like after the exit? What if you
use the -R flag?*

<br>When the 'c' exits, its children processes are 'reparented' as the root process 'a'.
<br>Therefore, all the processes 'b','d',and 'e' are all direct children of 'a'.
<br> After we use the -R flag, the children processes of 'c' became 'c''s direct parent's children, i.e. 'b''s children. 
<br>The result is like this.

```
E:\proj\cs\hw5600\hw2>python ./fork.py -A a+b,b+c,c+d,c+e,c- -c

ARG seed -1
ARG fork_percentage 0.7
ARG actions 5
ARG action_list a+b,b+c,c+d,c+e,c-
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: b forks c
                               a
                               └── b
                                   └── c
Action: c forks d
                               a
                               └── b
                                   └── c
                                       └── d
Action: c forks e
                               a
                               └── b
                                   └── c
                                       ├── d
                                       └── e
Action: c EXITS
                               a
                               ├── b
                               ├── d
                               └── e

E:\proj\cs\hw5600\hw2>python ./fork.py -A a+b,b+c,c+d,c+e,c- -c -R

ARG seed -1
ARG fork_percentage 0.7
ARG actions 5
ARG action_list a+b,b+c,c+d,c+e,c-
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent True
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: b forks c
                               a
                               └── b
                                   └── c
Action: c forks d
                               a
                               └── b
                                   └── c
                                       └── d
Action: c forks e
                               a
                               └── b
                                   └── c
                                       ├── d
                                       └── e
Action: c EXITS
                               a
                               └── b
                                   ├── d
                                   └── e

```

### Q5

*Q:Run ./fork.py
-F and see if you can write down the final tree by looking at the
series of actions generated. Use different random seeds to try this a
few times.*

We tried this for couple times.
<br>
First Try

```
E:\proj\cs\hw5600\hw2>python fork.py -F

                           Process Tree:
                               a

Action: a forks b
Action: a forks c
Action: b EXITS
Action: c EXITS
Action: a forks d

                        Final Process Tree?
```
would look like this
```
a
└──d
```
Second Try
```
E:\proj\cs\hw5600\hw2>python fork.py -s 71 -F

                           Process Tree:
                               a

Action: a forks b
Action: b forks c
Action: c EXITS
Action: a forks d
Action: a forks e

                        Final Process Tree?
```
would look like this
```
a
└──b
└──d
└──e
```

### Q6

*Q:Use both -t and -F together. This shows the final process
tree, but then asks you to fill in the actions that took place. By looking at the tree, can you determine the exact actions that took place?
In which cases can you tell? In which can’t you tell??*

We can see the number of steps and the final process tree. With the given information, we can know that some processed are forked during the program, but unknown of in which order they took place, and who are their parents (because it could be the case that they became orphan processes and re-parented). Only those processes whose parents are not 'a' (or the `init` process) can be determined that their parent once `fork()`ed and got them as children process.<br /><br />

For instance,
```
E:\proj\cs\hw5600\hw2>python fork.py -s 71 -F -a 10 -t

                           Process Tree:
                               a

Action?
Action?
Action?
Action?
Action?
Action?
Action?
Action?
Action?
Action?

                        Final Process Tree:
                               a
                               ├── b
                               │   └── h
                               ├── e
                               ├── f
                               │   └── i
                               └── g

```

We know for sure that there were steps like 


```
b forks h
```

or 

```
f forks i
```

But for the rest part we have no clue yet.

## Chapter 5 Code Part

### Q1

*Q:Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?*

A: The value of the variable in the child process is the same as it was before the `fork()`, i.e. 100.
<br /> After the inner change, each variable has the value of what their process changed them into, i.e. in my code it's 99 for the child, 101 in the parent.

```
mtowya@TowyadeMacBook-Pro hw2 % ./p1
x in the parent process -init: 100
x in the parent process -after: 101
x in the child process -init: 100
x in the child process -after: 99
```

### Q2

*Q:Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?*

A: Yes, they both can. And they will both write into the file, ordered by the scheduler (which we cannot predict).
<br/> The result is in the file `02.dat`. I ran p2 for several times to show the random schedule.

### Q3

*Q:Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?*

A: As shown in the `03.c`.

### Q4

*Q:Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?
?*

A: As shown in the `04.c`.

### Q5

*Q: Write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child??*

A: It returns the pid of the returned child. <br />
In the child it return -1.

### Q6

*Q:Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be
useful?*

A: It takes the parameter of the Pid of the child process.
```
mtowya@TowyadeMacBook-Pro hw2 % gcc -o p6 06.c -Wall
mtowya@TowyadeMacBook-Pro hw2 % ./p6
Child: -1
Parent: 76383
```
It is useful when the process is a parent and knows the child Pid it is waiting for.

### Q7

*Q:Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?*

A: There will be no output.

## Chapter 6

## Chapter 7
