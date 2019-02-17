# Deadlock-avoidance-cpp-safety-algorithm
A program that finds the proper sequence to prevent a deadlock. It's my homework.
There are three types of resources: A, B and C; A, B and C are just placeholder names. Add more if you want to.
There is a limited number of instances of each of these resources defined in MAX_A, MAX_B and MAX_C.
The program takes the following as input:
i) Number of processes accessing the limited resources
ii) Instances of each type of resource required by each of the processes.
And does the following:
Automatically assigns instances of the required resources to each of the processes so as to keep them from starving.
Then checks if there are enough resources of the three types to complete execution of all the process in a timely
fashion. If there are it gives an order of execution such that all processes may be executed.
Note that this is not a unique order but the easiest to arrive at.
