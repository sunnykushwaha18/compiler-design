SimpleLang is a basic, high-level programming language designed to work with an 8-bit CPU architecture. Its primary goal is to provide a simple syntax for variable declarations, assignments, arithmetic operations, and conditionals without the complexity of loops or advanced control structures. Below are the design details of SimpleLang, including its syntax, semantics, and examples for each construct.

1. Variable Declarations
Syntax:
plaintext
Copy code
int <variable_name>;
Semantics:
The keyword int is used to declare an integer variable.
Variables must be declared before they are used in assignments or expressions.
Each variable can hold a single 8-bit integer (ranging from 0 to 255).
Uninitialized variables are implicitly set to 0.
Examples:
plaintext
Copy code
int a;
int b;
int result;
Explanation:
The above code declares three variables: a, b, and result. Each variable can store a single integer.
2. Assignment Statements
Syntax:
plaintext
Copy code
<variable_name> = <expression>;
Semantics:
The assignment operator = is used to assign the result of an expression to a variable.
The right-hand side (RHS) of the assignment can be either a constant, a variable, or an arithmetic expression.
The left-hand side (LHS) must be a previously declared variable.
The assignment operation stores the evaluated result of the expression into the variable on the LHS.
Examples:
plaintext
Copy code
a = 10;
b = a + 5;
result = a + b - 2;
Explanation:
a = 10; assigns the value 10 to the variable a.
b = a + 5; assigns the value of a + 5 to the variable b. If a was 10, then b becomes 15.
result = a + b - 2; computes the value of a + b - 2 and stores the result in result.
3. Arithmetic Operations
Syntax:
plaintext
Copy code
<variable_name> = <expression>;
Supported Operators:
Addition: +
Subtraction: -
Semantics:
SimpleLang supports basic arithmetic operations: addition and subtraction.
Expressions can involve variables, constants, or a combination of both.
The result of the arithmetic expression is stored in the variable on the left-hand side.
Examples:
plaintext
Copy code
c = a + b;
d = a - 5;
result = a + b - c;
Explanation:
c = a + b; sums the values of a and b and stores the result in c.
d = a - 5; subtracts 5 from a and stores the result in d.
result = a + b - c; performs multiple operations in a single expression and stores the final result in result.
4. Conditional Statements
Syntax:
plaintext
Copy code
if (<condition>) {
    <statements>
}
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
5. Complete Example Program in SimpleLang
Here is a full example program that combines variable declarations, assignments, arithmetic operations, and conditionals:

plaintext
Copy code
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
Explanation:
Three integer variables a, b, and c are declared.
The values 10 and 20 are assigned to a and b, respectively.
The value of a + b (which is 30) is stored in c.
The conditional statement checks if c == 30. Since this is true, the block inside the if statement is executed, and c is incremented by 1.
Summary of Syntax
Construct	Syntax	Example
Variable Declaration	int <variable_name>;	int a;
Assignment	<variable_name> = <expression>;	a = 10;
Addition	<variable_name> = <var1> + <var2>;	c = a + b;
Subtraction	<variable_name> = <var1> - <var2>;	d = a - 5;
Conditional	if (<condition>) { <statements> }	if (a == b) { a = a + 1; }
Semantics Summary
Variables: Variables are declared with the keyword int and store 8-bit integer values.
Assignments: Variables can be assigned values or expressions, evaluated at runtime.
Arithmetic: Basic arithmetic operations (+, -) can be performed on variables and constants.
Conditionals: The if statement allows conditional execution of code based on a comparison (only equality == is supported).
This completes the syntax and semantics design for SimpleLang, a simple yet powerful language designed for 8-bit CPUs.