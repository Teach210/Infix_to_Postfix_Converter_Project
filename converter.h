#include <iostream>
#include <stack>
#include <string>
#include <cctype>

class InfixToPostfixConverter {
private:
    std::string postfixExpression;

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

public:
    InfixToPostfixConverter() {}

    void Convert(const std::string& infixExpression) {
        postfixExpression.clear();
        std::stack<char> operators;

        for (char c : infixExpression) {
            if (std::isalpha(c)) {
                postfixExpression += c;
            }
            else if (c == '(') {
                operators.push(c);
            }
            else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfixExpression += operators.top();
                    operators.pop();
                }
                operators.pop(); // Discard '('
            }
            else if (c == ' ') {
                continue;
            }
            else {
                while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                    postfixExpression += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty()) {
            postfixExpression += operators.top();
            operators.pop();
        }
    }

    std::string GetPostfixExpression() const {
        return postfixExpression;
    }
};