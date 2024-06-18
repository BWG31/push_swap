# push_swap
Create a stack sorting algorithm.

## Table of Contents

- [Overview](#overview)
- [TO DO](#to-do)
- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Build Instructions](#build-instructions)
- [Usage](#usage)

## Overview

*This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.* (extract from subject)

- [Subject](./subject_en.pdf)
- Mark: 125/100

## TO DO
- Add performance report
- Add visualisation GIF
- Add Explanation of algorithm.


## Installation

### Prerequisites

- GCC compiler

### Build Instructions

1. Clone the repository:
   ```sh
   git clone https://github.com/BWG31/push_swap
2. Compile the executable:
    ```sh
    make
## Usage
 - The provided array of numbers represents stack A, with the start of the array representing the top of the stack.
 - The numbers must be unique and within the range of [INT_MIN ... INT_MAX].
 - Standard use:
    ```sh
    ./push_swap <array of numbers to sort>
    # Will output a set of instructions to sort the stack
 - Use with checker:
    ```sh
    ARG="<array of numbers to sort>"; ./push_swap $ARG | ./checker $ARG
    # Will display 'OK' if successful and 'KO' if unsuccessful.
  - The checker will read from the STD input and check if the commands correctly sort the stack provided as argument(s).