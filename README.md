# About
Implemented insertionSort, quickSort and modified version of quickSort algorithms to measure running time of them with different cases.<br>
There are 4 automated tests (A1-A2-B1-B2) for measuring running time: 

A1 --> input size = 4095, input type = random integers<br>
A2 --> input size = 32737, input type = random integers<br>
B1 --> input size = 4095, input type = integers with decreasing order<br>
B2 --> input size = 32737, input type = integers with decreasing order<br>

My system specs provided in systemSpecs.txt<br>
My system's test results in Table.ods<br>

About modified version of quickSort --> In quickSort function with each recursive call, subarray's size is checked<br>
if it is less than 12 then sorting process will be done with insertionSort.
