Name: Lisul Elvitigala
ID: 116152790
Course: CSE 220: Systems Fundamentals I - Spring 2026 
Professor: Abid Malik

Overview:
Welcome to my repository! This codebase contains all of my implementations for Homework 3: Bit Operations Using C. For test cases, all assertions have been declared using the Criterion framework in `test_hw3.c`, which you can run using the `make test` command.

My codebase's file structure:
SPRCSE220-lelvitigala-116152790/
├── .gitignore
├── HW3_main.c
├── Makefile
├── MyBitManipulation.h
├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c
├── MyIntegers.h
├── MyIntegers.c
├── README.txt
└── test_hw3.c

How to compile and run the tests?
1. `make clean`
2. `make test`
3. `./test_hw3`

Edge Case Handling and Assumptions Made:
For the following parts, each section details how I handled edge cases and any assumptions I made.
* Part 1 (`MyBitManipulation.c`)
    * ToggleBit(int num, int pos) --> If 0 > pos or pos > 31, my implementation of the function returns the original number to indicate to the user that an out-of-range position was inputted.
    * GetMSB(int num) --> When a negative number is passed, the function will correctly output the sign bit as the MSB (returning 31)! An input of 0 will return -1.
    * ClearBitRange(int num, int start, int end) --> We perform boundary checks to check start >= 0, end <= 31, and start <= end to actually perform the clearing. I also added a manual check for when start = 0 and end = 31 to prevent the undefined 32 shift behavior.
    * RotateLeft(uint32_t num, int d) --> We can safely assume d is strictly positive (as mentioned on Piazza). To optimize, I also used d &= 31 as a faster bitwise operation to calculate d % 32.
    * SwapOddEvenBits(int num) --> Uses typed unsigned 32-bit masks (0xAAAAAAAA and 0x55555555) to extract the odd/even values to perform a right/left shift.
* Part 2 (`Myfloat.c`)
    * Discarded values are represented as 0.0f: If the sign-bit is anything other than 0 or 1, discard the value safely by returning `0.0f`. If the exponent evaluates to 0xFF, my program will catch this before creating the IEEE 754 float (returning `0.0f` as a fallback).
    * Invalid sign bit or datatypes --> I casted the inputs to `uint32_t` and masked with `0x1u` for the sign bit, `0xFFu` for the exponent, and `0x7FFFFFu` for the fraction part. I also strictly enforced 8-bit and 32-bit boundaries as mentioned on Piazza; all other input is discarded (preventing larger data types or any unexpected characters from crashing our program).
    * NaN and Infinity handling --> Rather than returning their standard representations, if the arguments provided form the IEEE 754 bit-patterns for Infinity or Nan, the function will use the methods described in the above bullet to process, then throw out the input without causing any undefined behavior.

* Part 3 (`MyIntegers.c`)
    * Invalid formatting for arguments --> If `source_repr` or `target_repr` is not either '2' or 'S', the program will print "error\n" and return.
    * Identical target + source --> If both representations are the same, no conversion is performed! The original integer is printed using the goto print_final_hex method (adds padding to keep result displayed as 8 digits). 
    * Two's complement to sign/mag overflow --> I specifically note down the case of -2^31 (`0x80000000`) because this number cannot be represented in sign/mag, thus printing "undefined\n" and returning.
    * Handling -0 for sign/mag: Due to sign/mag representation's two representations of 0 (+0 and -0), If -0 (`0x80000000`) is a result, it is manually overriden to output +0 (`0x00000000`) before printing.

Lastly, in terms of software engineering conventions I used, I compiled a list of notable ones:
* I used meaningful variable names (`sign_bit`, `magnitude`, `even_bits_mask`, `odd_bits_mask`, etc.) to take note of all bitwise logic through the name's meaning.
* I provided inline comments to explain complex bitwise operations/masking as well as shifting operations to clarify the mathematical intent to the graders/TAs.
* All standard C formatting, spacing, and indentation guidelines were followed throughout!
