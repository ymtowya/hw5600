### Evaluation

In evaluating the design and final implementation, we focus on these three parts:

* Turnaround Time

    The way we optimize turnaround time is to avoid the slices during which the processor is not occupied by any process, leaving blank time which is a waste of resource. Therefore, we'll put all processes which issued I\O or being blocked for some reasons to another independent queue, releasing the resources it occupied.<br>
    To quantify this, we'll calculate the whole turnaround time of running multiple processes which have high frequency of I\O issues, to test if they can switch immediately without waste of CPU.

* Response Time

    We'll optimize the response time by running RR to schedule processes of same priority. If time permitted, we can also add a priority boost mechanism to fairly respond to all processes.<br />
    We can quantify this by inputting processes with seperated starting time, to test if the processor can keep the response time for each process respectively low during the admission.

* Complete Time Difference

    Another dimension we can measure fairness is to compare the individual turnaround time for 2 similar processes (inspired by how we measure the lottery scheduler). When input several processes of very similar initial states, the processor is expected to give them equal treatments, meaning their turnaround time should be very similar. If not, there might be distribution problems in the processor.<br>
    For instance, three processes `0,100,1:0,100,1:0,100,1` are expected to start and terminate close to each other.

