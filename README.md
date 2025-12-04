# Beecrowd 1550 - Inversion (C/C99 Solution)

Academic project developed for the Algorithms and Data Structures II course.

This project implements a solution for the "Inversion" problem (Beecrowd 1550) using Breadth-First Search (BFS) written in C. It calculates the minimum number of operations required to transform an initial number A into a target number B.

The solution models the problem as an unweighted graph where operations (add 1, reverse digits) represent edges between numeric states.

## Features

- Shortest path calculation using Breadth-First Search.

- Custom Queue implementation for efficient graph traversal.

- Handles integer reversal logic and state visitation tracking.

- Complexity: O(V + E), optimized for constraints A < B < 10000.

## How to Compile and Run

Compile the code using GCC:

gcc main.c -o inversion

Run the executable:

./inversion

## Input and Output

The program accepts inputs via standard input (stdin).

Input Format:
The first line contains an integer T (number of test cases).
Each following line contains two integers A and B (Initial Number and Target Number).

Example Input:
4
1 9
100 301
808 909
133 233

Example Output:
8
4
3
3
