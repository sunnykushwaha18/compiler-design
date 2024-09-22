### SimpleLang is a basic, high-level programming language designed to work with an 8-bit CPU architecture. Its primary goal is to provide a simple syntax for variable declarations, assignments, arithmetic operations, and conditionals without the complexity of loops or advanced control structures. Below are the design details of SimpleLang, including its syntax, semantics, and examples for each construct.

# 1. Variable Declarations
Syntax:
```
int <variable_name>;
```
## Semantics:
The keyword int is used to declare an integer variable.
Variables must be declared before they are used in assignments or expressions.
Each variable can hold a single 8-bit integer (ranging from 0 to 255).
Uninitialized variables are implicitly set to 0.
Examples:
```
int a;
int b;
int result;
```

Explanation:
The above code declares three variables: a, b, and result. Each variable can store a single integer.
# 2. Assignment Statements
Syntax:
```
<variable_name> = <expression>;
```
Semantics:
The assignment operator = is used to assign the result of an expression to a variable.
The right-hand side (RHS) of the assignment can be either a constant, a variable, or an arithmetic expression.
The left-hand side (LHS) must be a previously declared variable.
The assignment operation stores the evaluated result of the expression into the variable on the LHS.
Examples:
```
a = 10;
b = a + 5;
result = a + b - 2;
```
Explanation:
* a = 10; assigns the value 10 to the variable a.
* b = a + 5; assigns the value of a + 5 to the variable b. If a was 10, then b becomes 15.
result = a + b - 2; computes the value of a + b - 2 and stores the result in result.

# 3. Arithmetic Operations
Syntax:
```
<variable_name> = <expression>;
```
Supported Operators:
```
Addition: +
Subtraction: -
```

>SimpleLang supports basic arithmetic operations: addition and subtraction.
Expressions can involve variables, constants, or a combination of both.
The result of the arithmetic expression is stored in the variable on the left-hand side.

Examples:
```
c = a + b;
d = a - 5;
result = a + b - c;
```
Explanation:
* c = a + b; sums the values of a and b and stores the result in c.
* d = a - 5; subtracts 5 from a and stores the result in d.
* result = a + b - c; performs multiple operations in a single expression and stores the final result in result.

# 4. Conditional Statements
Syntax:
```
if (<condition>) {
    <statements>
}
```
Supported Conditions:
Equality: ==
Semantics:
The if statement is used to execute a block of code only if the given condition evaluates to true.
The condition must be a comparison using the equality operator ==, which compares two variables or expressions.
The block of statements within the curly braces {} is executed if the condition holds true.
There is no else clause in SimpleLang.
Examples:
plaintext
Copy code
if (a == b) {
    result = result + 1;
}
Explanation:
The condition a == b checks if the values of a and b are equal. If true, the statement inside the braces (result = result + 1;) is executed.


# 📜 Complete Example Program
Here’s a full example program that combines variable declarations, assignments, arithmetic operations, and conditionals:

```
// Variable declaration
int a;
int b;
int c;


// Assignment
a = 10;
b = 20;
c = a + b;

// Conditional statement
if (c == 30) {
    c = c + 1;
}
```
Explanation:
Three integer variables a, b, and c are declared.
Values are assigned and operations are performed.
The conditional statement checks if c == 30, and if true, increments c by 1.

# 🚀 Getting Started
To get started with SimpleLang, follow these steps:

Clone the repository:
```
git clone https://github.com/yourusername/simplelang.git'
```

Navigate to the project directory:
```
cd simplelang
```
Compile your SimpleLang programs using the provided compiler.

# 🛠️ Project Structure

simplelang/
├── **lexer**
│   └── lexer.c
├── **parser**
│   └── parser.c
├── **codegen**
│   └── codegen.c
├── **examples**
│   └── example_program.txt
├── **README.md**
└── **LICENSE**


# 📅 Contributing
Contributions are welcome! If you have suggestions or improvements, feel free to open an issue or submit a pull request.

# 📧 Contact
For any inquiries or questions, reach out to us at join-the-team@vicharak.in.

# 🎉 License
This project is licensed under the MIT License - see the LICENSE file for details.

# ✨ Dive into the world of programming with SimpleLang and unleash your creativity! Happy coding! ✨
