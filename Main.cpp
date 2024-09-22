#include <iostream>
#include <string>
#include "code_generator.cpp"

// Function to delete the AST nodes
void deleteAST(ASTNode* node) {
    if (auto* binOp = dynamic_cast<BinaryOpNode*>(node)) {
        deleteAST(binOp->left);  // Recursively delete left subtree
        deleteAST(binOp->right); // Recursively delete right subtree
        delete binOp;            // Delete the binary operator node
    } else if (auto* num = dynamic_cast<NumberNode*>(node)) {
        delete num;              // Delete the number node
    }
}

int main() {
    std::string input = "43 * 6 + 5 * 6 - 2 + 8"; // Input expression
    std::vector<Token> tokens = lexer(input);      // Tokenize the input

    int pos = 0;
    ASTNode* ast = parseExpression(tokens, pos);   // Parse tokens into an AST

    std::cout << "Generated Assembly:" << std::endl;
    generateCode(ast);                              // Generate assembly-like output

    // Clean up AST nodes
    deleteAST(ast);                                 // Delete the entire AST

    return 0;
}
