#

import random
import matplotlib.pyplot as plt

def run():
    pass
    
    ticket = [50, 50]
    ticket.sort()
    
    quantum = 10
    rate = []
    jobLengthOption = range(10, 1000, 20)

    for l in jobLengthOption:
        
        timeAcc = 0
        jobLength = [l, l]
        jobDonePart = [0, 0]
        jobDoneTimes = [0, 0]
        jobDoneStamp = [1, 1]
        while (jobDonePart[0] < jobLength[0] or jobDonePart[1] < jobLength[1]):
            lottery = random.randint(1, 100)
            if ((lottery <= ticket[0] and jobDonePart[0] < jobLength[0]) or jobDonePart[1] >= jobLength[1]):
                # first choice
                oldDone = jobDonePart[0]
                jobDonePart[0] = min(jobDonePart[0] + quantum, jobLength[0])
                timeAcc += jobDonePart[0] - oldDone
                jobDoneTimes[0] += 1
                if (jobDonePart[0] >= jobLength[0]):
                    jobDoneStamp[0] = timeAcc
            else:
                # second choice
                oldDone = jobDonePart[1]
                jobDonePart[1] = min(jobDonePart[1] + quantum, jobLength[1])
                timeAcc += jobDonePart[1] - oldDone
                jobDoneTimes[1] += 1
                if (jobDonePart[1] >= jobLength[1]):
                    jobDoneStamp[1] = timeAcc
        
        # print(jobDoneStamp)
        
        jobDoneStamp.sort()
        if (jobDoneStamp[1] != 0):
            rate.append(100 * jobDoneStamp[0] / jobDoneStamp[1])
        else:
            rate.append(0.0)

    print(rate)
    
    fig = plt.figure()
    plt.ylim(0, 101)
    plt.margins(0)
    plt.xlabel('Length Of Job')
    plt.ylabel('Unfairness (Average) in percentage (%)')
    plt.title('Lottery Fairness & Job Length in Lottery')
    plt.plot(jobLengthOption, rate, color='blue')
    
    plt.savefig('9.2.1.png', dpi=255)
    plt.show()


run()