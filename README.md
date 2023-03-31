# Test Case for Gear Technologies Inc.

## Table of contents:
* [Task Description](#task_description)
* [Input generation](#input_generation)
* [Array dividing](#array_dividing)
* [Medians finding](#medians_finding)
* [Parallel calculations](#algorithms_and_data_structures)
* [Errors](#errors)

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
## Medians finding

## Parallel calculations

## Errors
