#include <stack>
#include <string>
#include "AlgebraicExpression.h"

using namespace std;

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

string infix2postfix(const string exp) {
    string postfixExp;
    stack<char> operatorStack;

    for (char ch: exp) {
        switch (ch) {
            case '0' ... '9':
                postfixExp += ch;
                break;
            case '*' ... '/':
                while (!operatorStack.empty() && operatorStack.top() != '(' &&
                       precedence(ch) <= precedence(operatorStack.top())) {
                    postfixExp += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
                break;
            case '(':
                operatorStack.push(ch);
                break;
            case ')':
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfixExp += operatorStack.top();
                    operatorStack.pop();
                }
                if (!operatorStack.empty() && operatorStack.top() == '(') {
                    operatorStack.pop();
                    break;
                }
        }
    }
    while (!operatorStack.empty()) {
        postfixExp += operatorStack.top();
        operatorStack.pop();
    }
    return postfixExp;
}

double evaluatePostfix(const string exp) {
    stack<double> operandStack;

    for (char ch: exp) {
        if (isOperand(ch)) {
            double operand = ch - '0';
            operandStack.push(operand);
        } else if (isOperator(ch)) {

            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            double result;
            switch (ch) {
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
            }
            operandStack.push(result);
        }
    }
    return operandStack.top();
}