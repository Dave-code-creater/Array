# Array Functions

This program provides a set of functions for working with arrays in C. The functions allow you to perform various operations on arrays, such as creating an array, reading and printing the array, calculating the sum of all elements, copying the array, and finding the number of duplicate numbers in the array.

## Table of Contents
- [Overview](#overview)
- [Requirements](#requirements)
- [Usage](#usage)
- [Functions](#functions)
- [Customization](#customization)
- [Advanced Usage](#advanced-usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project offers a comprehensive toolkit of array-manipulation functions in C programming. These functions empower you to execute a multitude of array-related tasks effortlessly. You can initialize arrays, read and display their contents, compute the cumulative sum of elements, duplicate arrays efficiently, and detect the presence of duplicate numbers within the array. Whether you're a beginner learning the basics or a seasoned coder tackling more complex array operations, this program equips you with the essential tools to work seamlessly with arrays in the C language.


## Requirement

To be able executing my code, you need the following:

- C Compiler: A C compiler is essential to compile and execute the C code. Recommended options include GCC (GNU Compiler Collection), which is available for various platforms, including Linux, macOS, and Windows (through MinGW or other ports).

- Text Editor or IDE: You'll require a text editor or integrated development environment (IDE) to edit and manage your C code. Some popular choices include Visual Studio Code, Code::Blocks, or Dev-C++.

- Operating System Compatibility: Ensure that your chosen development environment and C compiler are compatible with your operating system (Linux, macOS, Windows, etc.).

- Standard C Library: Your code appears to rely on standard C library functions, which are typically included with most C compilers. No additional libraries should be necessary for this project.

## Usage

1. Dowload the Script: Clone or download the script to your computer using the provided link

2. Compile the Project: Compile the C project by using a C compiler compatible with your operating system. You can typically do this by navigating to the project directory in the terminal (Linux/macOS) or command prompt (Windows) and executing the compilation command, such as:

~~~ 
shell
gcc -o my_program my_program.c
~~~

- (Optional)Replace my_program with your desired executable name and my_program.c with the name of your main C source code file.

3. Run the Executable: Execute the compiled program by running the generated executable in the terminal or command prompt:

~~~
shell

./my_program
~~~
- Replace my_program with the name you provided during compilation.

- Interact with the Program: Follow the on-screen instructions provided by your program to utilize the array functions. This may include tasks like creating arrays, reading their contents, calculating sums, copying arrays, checking for duplicates, and more.

- Compile and Execute Your Own Code: If you wish to integrate these array functions into your own C programs, include the "array.h" header in your code and compile it along with "array.c" to access the functions.

- Ensure Correct Paths: If you encounter issues related to file paths or dependencies within your C code, ensure that your directory paths and configurations are correctly specified within your code.

4. Customize for Your Project: If desired, customize the functions or adapt them to your specific project requirements.

## Functions

- int Length_Of_Array(void)
    This function prompts the user to input the desired length of an array.
    It validates the input to ensure it's a positive integer.
    Returns the length of the array.

- int* Create_Array(int Length)
    Allocates dynamic memory for an integer array of the specified length.
    Reads integer values from the user for each element in the array.
    Returns a pointer to the created array.

- void Read_Array(int* Array, int Length)
    Prints the elements of the provided integer array.

- void Read_Inverse_Array(int* Array, int Length)
    Prints the elements of the provided integer array in reverse order.

- int Sum_Of_All_Element(int* Array, int Length)
    Calculates and returns the sum of all elements in the provided integer array.

- int* Copy_Array(int* Array, int Length)
    Creates a new integer array and copies the elements from the provided array into it.
        Returns a pointer to the new array.

- bool Contains_Duplicate_Element(int* Array, int Length)
    Checks if the provided integer array contains any duplicate elements.
    Returns true if duplicates are found, otherwise false.

- int* Get_Concatenation(int* Array, int Length)
    Creates a new integer array that is twice the length of the provided array.
    Copies the elements from the provided array into the new array twice.
    Returns a pointer to the new array.

- int* Create_Array_3X3_Size(void)
    Creates a 3x3 integer array and allows the user to input values for each element.
    Returns a pointer to the created 3x3 array.

- void Print_3x3_Size(int* Array)
    Prints the values of a 3x3 integer array, assuming it is passed as a 1D array. Note that this function may not work as expected because a 2D array is being treated as a 1D array.

## Adnaced Usage

At this point, the project still under develop, therefore, This could have more and more function. However, you could modified those function to fit with the specific requirements in your program.


## Contributing

If you'd like to contribute to this project, feel free to fork it, make improvements, and submit a pull request. Contributions such as additional features, better error handling, or improved documentation are welcome.

## License

This project is licensed under the GNU GENERAUL PUBLIC LICENSE


Please review the README file and make any necessary adjustments to fit your requirements.


Example usage:

```c
#include <stdio.h>
#include "array.h"

int main()
{
    int length = Length_Of_Array();
    int* array = Create_Array(length);

    printf("Original array:\n");
    Read_Array(array, length);

    printf("Inverse array:\n");
    Read_Inverse_Array(array, length);

    int sum = Sum_Of_All_Element(array, length);
    printf("Sum of all elements: %d\n", sum);

    int* arrayCopy = Copy_Array(array, length);
    printf("Copied array:\n");
    Read_Array(arrayCopy, length);

    int duplicateCount = Number_Of_Duplicate_Number(array, length);
    printf("Number of duplicate numbers: %d\n", duplicateCount);

    // Free dynamically allocated memory
    free(array);
    free(arrayCopy);

    return 0;
}
```



