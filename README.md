# Milestone2
In this project, we created a server that can handle various clients calls (e.g. invert words, find the shortest path in matrix).
Our server can do it through parallel or serial handling.
When the server solves the client's problem, it returns the desired solution.
To make this happened, the most efficient way, we used some search algorithms and design patterns.

Before you run Milestone2 you will also need to:
- send the server a port. (else the port will be 5600, by default)
- send to the server (after you connect) a matrix, "start" and "end" positions, "end" string.

# How to run the program?
In order to run the project you need to clone it, and use the following command:
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
 
# Github link
[Our Project](https://github.com/amitkoz/Milestone-2.git)
