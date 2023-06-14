# Queues

A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle, where the element that is inserted first is the first one to be removed. It models a real-world queue or line, where elements are added at the rear (enqueue) and removed from the front (dequeue). Queues are commonly used in algorithms and systems where processing elements in the order of their arrival is important.

## Overview

A queue is an ordered collection of elements, where new elements are added at one end called the rear and elements are removed from the other end called the front. This ordering ensures that the element that has been in the queue the longest is the first one to be removed.

## Key Features

-   **FIFO (First-In-First-Out) Principle**: Elements are processed in the same order they were added, resembling a real-life queue.
-   **Enqueue**: Adding an element to the rear of the queue.
-   **Dequeue**: Removing an element from the front of the queue.
-   **Peek**: Viewing the element at the front of the queue without removing it.
-   **Empty Check**: Determining whether the queue is empty or not.
-   **Size**: Getting the number of elements currently in the queue.

## Operations

-   **Enqueue**: Adds an element to the rear of the queue.
-   **Dequeue**: Removes and returns the element at the front of the queue.
-   **Peek/Front**: Returns the element at the front of the queue without removing it.
-   **isEmpty**: Checks if the queue is empty.
-   **Size**: Returns the number of elements in the queue.

## Use Cases

Queues are used in various scenarios where the FIFO principle is required, such as:

-   **Process Scheduling**: In operating systems, queues are used to schedule processes for execution, ensuring fairness and order.
-   **Breadth-First Search**: Queues are used in graph traversal algorithms like breadth-first search (BFS) to explore all vertices at the same level before moving to the next level.
-   **Printing Tasks**: In printer spooling, the print jobs are stored in a queue and processed one by one in the order of their arrival.
-   **Message Queues**: Queues are used in messaging systems to store and deliver messages between components or processes.
-   **Buffering**: Queues can be used as buffers in scenarios where there is a mismatch between the speed of producer and consumer processes.
-   **Request Handling**: In web servers, queues can be used to handle incoming requests in the order of their arrival.

## Implementation

Queues can be implemented using arrays or linked lists. Array-based implementations have a fixed size, while linked list implementations can dynamically grow as needed.

## Conclusion

Queues are an important data structure that follows the First-In-First-Out principle. They are widely used in various applications, including process scheduling, graph traversal, message passing, and more. Understanding queues and their operations is crucial for building efficient algorithms and solving problems that require order-based processing.
