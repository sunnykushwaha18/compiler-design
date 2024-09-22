#include <iostream>
#include <vector>
#include <string>
#include <cctype> // For isdigit and isspace
#include <cstring>

// Token types
enum TokenType { NUMBER, ADD, SUB, MUL, DIV, LPAREN, RPAREN, INVALID };

// Token structure
struct Token {
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}
};

// Helper function to create a Token for operators or parentheses
Token createSingleCharToken(char current) {
    switch (current) {
        case '+': return Token(ADD, "+");
        case '-': return Token(SUB, "-");
        case '*': return Token(MUL, "*");
        case '/': return Token(DIV, "/");
        case '(': return Token(LPAREN, "(");
        case ')': return Token(RPAREN, ")");
        default:  return Token(INVALID, std::string(1, current)); // For invalid characters
    }
}

// Lexer function that converts a string into a list of tokens
std::vector<Token> lexer(const std::string& input) {
    std::vector<Token> tokens;

    for (size_t i = 0; i < input.size(); ++i) {
        char current = input[i];

        // Skip whitespace
        if (isspace(current)) {
            continue;
        }

        // Recognize numbers (multi-digit)
        if (isdigit(current)) {
            std::string num;
            while (i < input.size() && isdigit(input[i])) {
                num += input[i];
                i++;
            }
            i--;  // Step back to prevent skipping the next character
            tokens.push_back(Token(NUMBER, num));
        }
        // Recognize operators and parentheses
        else if (strchr("+-*/()", current)) {
            tokens.push_back(createSingleCharToken(current));
        }
        // Handle unexpected characters
        else {
            tokens.push_back(Token(INVALID, std::string(1, current)));
            std::cerr << "Warning: Unrecognized character '" << current << "' at position " << i << std::endl;
        }
    }

    return tokens;
}

// int main() {
//     std::string input = "12 + 24 * (35 - 10) / 5";

//     // Tokenize the input string
//     std::vector<Token> tokens = lexer(input);

//     // Print the tokens
//     for (const auto& token : tokens) {
//         std::cout << "Token(Type: " << token.type << ", Value: " << token.value << ")\n";
//     }

//     return 0;
// }
