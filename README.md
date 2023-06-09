# Test Case for Gear Technologies Inc.

## Table of contents:
* [Task Description](#task-description)
* [Input generation](#input-generation)
* [Array dividing](#array-dividing)
* [Medians finding](#medians-finding)
* [Parallel calculations](#parallel-calculations)
* [Errors](#errors)
* [Task 2 Answer](#task-2-answer)

## Task Description
Input is a large array of random integers. Divide array into N parts. 
Using parallel computing perform following processing: 
In each part leave only integers that are in between two medians of bound array parts, 
for the first parts leave numbers lower than median of next part, 
for last part leave the ones greater than bound part, concatenate arrays of output parts.

## Input generation
For the input data, `TestGenerator.cpp` and `TestGenerator.h` were created,
where `random_shuffle` is implemented, which allows you to randomly generate array and the number N.
The data is also written to the `input.txt` file.

## Array dividing
Since the size of the array may not be evenly divisible by the number N, our goal is to divide it into approximately equal parts. To begin with, the `el_row` variable was created, which is responsible for how many ***maximum elements should be in one part***, then we linearly go through each element of the input array and add them to the array of vectors in a certain row, the number of which will increase depending on the number of elements in it. Also, when filling each row, it keeps track of the number of unplaced elements and the number of free rows and changes `el_row`. If we briefly follow the remains in order to evenly distribute them over the rows of the array of vectors.

## Medians finding
Since sometimes the median must be found in a part with an even number of elements, they usually take the arithmetic mean of the two middle values.
```
for(int i = 0; i < n; ++i){
    if(a[i].size() % 2 == 0){
        median.push_back((a[i][a[i].size() / 2] + a[i][a[i].size() / 2 - 1]) / 2);
    }else{
        median.push_back(a[i][a[i].size() / 2]);
    }
}
```
## Parallel calculations
Not sure, but done parallel running like this:
```
for(int i = 0; i < n; i++){
    thread t(calculate, i, n);
    threads.push_back(move(t));
}
for(auto &t: threads){
    t.join();
}
```
Since each vector is sorted using the **MergeSort** algorithm, it is possible to run a **Binary search** on the first **n-1** rows in the `compute` function on the row index. This is how we find the index `ind` of the first element strictly smaller than the target (the median of the next part) and beyond:
* for the zero row, we take elements from `0` to `ind`
* for the rest of the rows (except the last one) we take starting from `a[i].size() / 2` (median) to `ind`
* for the last row, the binary search changes to finding the index ind of the strictly greater element and starting from `ind` to `a[n - 1].size()`

## Errors
Also, an `SIGABRT` error appears in about one out of ten cases. 

## Task 2 Answer
In sports programming, we have always been told that `10^8` simple operations can be performed in `1 second`. Suppose filling the sieve of Eratosthenes in an optimized way, you can find all prime numbers up to `10^7`. So it all depends on the asymptotics of the code and the memory being filled. For the above problem, MergeSort in memory and time takes the sum of all `(a[i].size() * log(a[i].size())` for each vector, binary search `log(a[i].size()` also for each vector. With an array size of 10^5, calculations will fit into 1 second even in the worst case.
