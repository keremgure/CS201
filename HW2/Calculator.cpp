#include <utility>

#include "Calculator.h"

Calculator::Calculator(string input) {
    this->stack = new Stack();
    this->infixExpression = std::move(input);
    this->postfixExpression = getPostfix();

}

Calculator::~Calculator() {
    delete stack;
}

string Calculator::getPostfix() {
    string postfix;
    regex integer("(\\+|-)?[[:digit:]]+");
    istringstream iss(infixExpression);
    string token;
    iss >> token;
    while (token != ";") {
        //Check if the token is a integer.
        if (regex_match(token, integer)) {
            postfix += token + " ";
            iss >> token;
        //Check if the token is a "(".
        } else if (token == "(") {
            this->stack->push(new StackItem(token));
            iss >> token;
        //Check if the token is a ")".
        } else if (token == ")") {
            //Pop out all elements from stack until we hit a "(".
            while (stack->head->op != OPERATOR_LEFTPAR) {
                postfix += stack->pop()->toString() + " ";
            }//Pop the "(" but not include.
            stack->pop();
            iss >> token;
        } else {
            //If nothing holds meaning the token is a operator " * / - + ".
            if (stack->isEmpty() || stack->top()->op == OPERATOR_LEFTPAR || hasHigherPrecedence(token,stack->top())) {
                stack->push(new StackItem(token));
                iss >> token;
            } else {
                while (!stack->isEmpty()) {
                    //Here the top element of stack needs to have equal or higher precedence so in order to achieve that we can simply say that, token doesn't have higher precedence over top element.
                    if ((stack->top()->op != OPERATOR_LEFTPAR) && !hasHigherPrecedence(token,stack->top())) {
                        postfix += (stack->pop()->toString()) + " ";
                    }else {
                        stack->push(new StackItem(token));
                        iss >> token;
                        break;
                    }
                }
            }
        }
    }//Pop and include the leftover operations in the stack.
    while (!stack->isEmpty()) {
        postfix += (stack->pop()->toString()) + " ";
    }// For convenience reasons add the ;.
    postfix += " ;";
    return postfix;
}


int Calculator::calculate() {
    this->stack = this->stack->flush();
    this->stack = new Stack();
    regex integer("(\\+|-)?[[:digit:]]+");
    istringstream iss(postfixExpression);
    string token;
    iss >> token;
    while (token != ";") {
        //If integer push to stack.
        if (regex_match(token, integer)) {
            this->stack->push(new StackItem(token));
            iss >> token;
        } else {
            //Pop 2 items do the operation and push back.
            int n1 = this->stack->pop()->n;
            int n2 = this->stack->pop()->n;
            this->stack->push(new StackItem(to_string(operate(token, n1, n2))));
            iss >> token;
        }
    }
    return this->stack->top()->n;
}

int Calculator::operate(string op, int n1, int n2) {
    switch (op.at(0)) {
        case '+':
            return n1 + n2;
        case '-':
            return n2 - n1;
        case '*':
            return n1 * n2;
        case '/':
            return n2 / n1;
        default:
            return 0;
    }
}

bool Calculator::hasHigherPrecedence(string op,StackItem* item) {
    if(item->op == OPERATOR_MULTIPLICATION || item->op == OPERATOR_DIVISION)
        return false;
    else return (op == "*" || op == "/");

}