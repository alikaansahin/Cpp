#ifndef UNTITLED_ALGEBRAICEXPRESSION_H
#define UNTITLED_ALGEBRAICEXPRESSION_H

#include <string>

using namespace std;

double evaluatePostfix(string exp);

bool isOperand(char ch);

bool isOperator(char ch);

int precedence(char op);


string infix2postfix(string exp);


#endif //UNTITLED_ALGEBRAICEXPRESSION_H
