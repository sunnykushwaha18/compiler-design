#include <iostream>
#include <vector>
#include <string>
#include "lexer.cpp"

// Abstract Syntax Tree (AST) Nodes
struct ASTNode {
    virtual ~ASTNode() {}
};

struct BinaryOpNode : ASTNode {
    char op;
    ASTNode* left;
    ASTNode* right;

    BinaryOpNode(char operator_, ASTNode* leftNode, ASTNode* rightNode)
        : op(operator_), left(leftNode), right(rightNode) {}
};

struct NumberNode : ASTNode {
    int value;

    NumberNode(int val) : value(val) {}
};

// Forward declaration for parsing functions
ASTNode* parseExpression(std::vector<Token>& tokens, int& pos);

// Function to parse a factor (numbers and parenthesized expressions)
ASTNode* parseFactor(std::vector<Token>& tokens, int& pos) {
    if (tokens[pos].type == NUMBER) {
        int value = std::stoi(tokens[pos++].value);
        return new NumberNode(value);
    } else if (tokens[pos].type == LPAREN) {
        pos++; // Consume '('
        ASTNode* node = parseExpression(tokens, pos);
        if (tokens[pos].type != RPAREN) {
            std::cerr << "Expected ')', got: " << tokens[pos].value << std::endl;
            exit(1);
        }
        pos++; // Consume ')'
        return node;
    }
    std::cerr << "Unexpected token: " << tokens[pos].value << std::endl;
    exit(1);
}

// Function to parse a term (handles multiplication and division)
ASTNode* parseTerm(std::vector<Token>& tokens, int& pos) {
    ASTNode* left = parseFactor(tokens, pos);

    while (pos < tokens.size() && (tokens[pos].type == MUL || tokens[pos].type == DIV)) {
        char op = tokens[pos].value[0];
        pos++;
        ASTNode* right = parseFactor(tokens, pos);
        left = new BinaryOpNode(op, left, right);
    }

    return left;
}

// Function to parse an expression (handles addition and subtraction)
ASTNode* parseExpression(std::vector<Token>& tokens, int& pos) {
    ASTNode* left = parseTerm(tokens, pos);

    while (pos < tokens.size() && (tokens[pos].type == ADD || tokens[pos].type == SUB)) {
        char op = tokens[pos].value[0];
        pos++;
        ASTNode* right = parseTerm(tokens, pos);
        left = new BinaryOpNode(op, left, right);
    }

    return left;
}

// Example usage
// int main() {
//     std::string input = "(12 + 24) * 3 - 5 / (2 + 3)";
    
//     // Tokenize the input string
//     std::vector<Token> tokens = lexer(input);
    
//     // Parse the expression
//     int pos = 0;
//     ASTNode* ast = parseExpression(tokens, pos);
    
//     // Clean up AST nodes (implement your own destructor for a complete cleanup)
//     // In a real application, you'd implement cleanup to avoid memory leaks.

//     return 0;
// }
