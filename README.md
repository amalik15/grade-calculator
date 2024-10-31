# grade-calculator

This is a weighted grade calculator written in C.

## Overview

The calculator takes user input in the form of strings to categorize and calculate grades.

## Input Format

-   A string beginning with `$` indicates a category.

    -   Example: `$homework 0.15`
        -   Category: `homework`
        -   Weight of overall grade: `15%`
    -   The number after the decimal must be a **decimal**.

-   After entering a category string, grades for that category should be inputted (one grade per line). The grades can be inputted as a fraction, decimal, or percent.

### Examples

-   Percent: `50%`, `100%`
-   Fraction: `24/30`
-   Decimal: `0.85`

**Note:**

-   When entering a fraction, use whole numbers.
-   When entering a grade as a percent, add the percent sign at the end.

## Example User Input

```plaintext
$homework 0.1
24/30
30/30
30/30
30/30
30/30
27/30
15/30
30/30
30/30
30/30
$midterm1 0.2
21/40
$midterm2 0.2
39/50
$final 0.5
53/100
```

## How to Run

To run the `main.c` file, follow these steps:

1. **Compile the program**:

    ```sh
    gcc -o grade_calculator main.c
    ```

2. **Run the executable**:
    ```sh
    ./grade_calculator
    ```

Make sure you have `gcc` installed on your system. If not, you can install it using your package manager.

For example, on Ubuntu, you can install `gcc` using:

```sh
sudo apt-get install gcc
```

On Windows, you can use MinGW to install `gcc`.
