#include <iostream>
#include "parser.cpp"

// Simple code generator that traverses the AST and generates assembly-like output
void generateCode(ASTNode* node) {
    if (auto* num = dynamic_cast<NumberNode*>(node)) {
        std::cout << "PUSH " << num->value << std::endl;
    } 
    else if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
        generateCode(binOp->left);  // Generate code for the left operand
        generateCode(binOp->right); // Generate code for the right operand
        
        // Generate code for the operation
        switch (binOp->op) {
            case '+': 
                std::cout << "ADD" << std::endl; 
                break;
            case '-': 
                std::cout << "SUB" << std::endl; 
                break;
            case '*': 
                std::cout << "MUL" << std::endl; 
                break;
            case '/': 
                std::cout << "DIV" << std::endl; 
                break;
            default: 
                std::cerr << "Error: Unknown operator '" << binOp->op << "'" << std::endl;
                exit(1); // Exit on unknown operator
        }
    } 
    else {
        std::cerr << "Error: Invalid AST node type." << std::endl;
        exit(1); // Exit on invalid node
    }
}

// // Example usage
// int main() {
//     std::string input = "(12 + 24) * 3 - 5 / (2 + 3)";
    
//     // Tokenize the input string
//     std::vector<Token> tokens = lexer(input);
    
//     // Parse the expression
//     int pos = 0;
//     ASTNode* ast = parseExpression(tokens, pos);
    
//     // Generate code from the AST
//     generateCode(ast);
    
//     // Clean up AST nodes (implement your own destructor for a complete cleanup)
//     // In a real application, you'd implement cleanup to avoid memory leaks.

//     return 0;
// }
