# Monty Interpreter

The Monty Interpreter is a tool that processes Monty byte code files and executes the instructions to manipulate a unique stack data structure. This interpreter follows the Monty scripting language specification and provides a way to execute Monty programs.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Instructions](#instructions)
- [Stack and Queue Concepts](#stack-and-queue-concepts)
- [Common Use Cases](#common-use-cases)
- [Global Variables Usage](#global-variables-usage)
- [Team](#team)

## Introduction

Monty Interpreter is designed to execute Monty byte code files (usually with a `.m` extension) that contain instructions for manipulating a stack. It reads the instructions, performs the necessary stack operations, and produces the output based on the executed instructions.

## Features

- Reads Monty byte code files and interprets the instructions.
- Implements a stack data structure for instruction execution.
- Handles instructions such as `push`, `pop`, arithmetic operations, and more.
- Provides error handling for invalid instructions and stack operations.
- Offers a flexible and extensible architecture for adding new instructions.

## Usage

1. Clone this repository to your local machine.
   ```sh
   git clone https://github.com/ugwujustine/monty.git
   ```
2. Compile and build the Monty Interpreter.
   ```sh
   gcc -Wall -Werror -Wextra -pedantic *.c -o monty
   ```
3. Run.
    ```sh
    ./monty <file.m>
    ```

## Instructions

The Monty Interpreter supports various instructions including:
- `push`: Pushes an element onto the stack.
- `pop`: Removes the top element from the stack.
- Arithmetic operations: `add`, `sub`, `mul`, `div`, `mod`.
- `pall`: Prints all elements in the stack.
- ... (list of other instructions)

## Stack and Queue Concepts

- **Stack (LIFO - Last-In-First-Out):** A stack is a linear data structure where elements are inserted and removed from the same end, known as the top. The last element inserted is the first one to be removed.

- **Queue (FIFO - First-In-First-Out):** A queue is a linear data structure where elements are inserted at the rear and removed from the front. The first element inserted is the first one to be removed.

## Common Use Cases

- **Stacks:**
  - Expression evaluation (postfix notation).
  - Undo/redo functionality.

  - Function call management (call stack).

- **Queues:**
  - Task scheduling.
  - Breadth-first search algorithms.
  - Print spooling.

## Global Variables Usage

Global variables are used sparingly in the Monty Interpreter to ensure encapsulation and modularity. They might be used for critical data or configuration settings that need to be accessed across multiple functions or modules.


## Author 🖊️:
* **AZZA MOHAMED** [AZZA](https://github.com/medazza)- ALX-Africa SE Student cohort 17