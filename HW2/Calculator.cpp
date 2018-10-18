#include "Calculator.h"

Calculator::Calculator(string input) {
    this->stack = new Stack();
    this->infixExpression = input;
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
        if (regex_match(token, integer)) {
            postfix += token + " ";
            iss >> token;
        } else if (token == "(") {
            this->stack->push(new StackItem(token));
            iss >> token;
        } else if (token == ")") {
            while (stack->head->op != OPERATOR_LEFTPAR) {
                postfix += stack->pop()->toString() + " ";
            }
            stack->pop();
            iss >> token;
        } else {
            if(stack->isEmpty() || stack->top()->op == OPERATOR_LEFTPAR || ((!(token == "-" || token == "+") && !(stack->top()->op == OPERATOR_MULTIPLICATION || stack->top()->op == OPERATOR_DIVISION)))){
                stack->push(new StackItem(token));
                iss >> token;
            }else {
                while (!stack->isEmpty()) {
                    if ((stack->top()->op != OPERATOR_LEFTPAR && stack->top()->op != OPERATOR_RIGHTPAR) && (token == "-" || token == "+")) {
                        postfix += (stack->pop()->toString()) + " ";
                    } else if ((token == "*" || token == "/") && (stack->top()->op == OPERATOR_MULTIPLICATION || stack->top()->op == OPERATOR_DIVISION)) {
                        postfix += (stack->pop()->toString()) + " ";
                    } else {
                        stack->push(new StackItem(token));
                        iss >> token;
                        break;
                    }
                }
            }
        }
    }
    while (!stack ->isEmpty()) {
        postfix += (stack->pop()->toString()) + " ";
    }
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
    while(token != ";"){
        if(regex_match(token,integer)) {
            this->stack->push(new StackItem(token));
            iss >> token;
        }else{
            int n1 = this->stack->pop()->n;
            int n2 = this->stack->pop()->n;
            this->stack->push(new StackItem(to_string(operate(token,n1,n2))));
            iss >> token;
        }
    }


    return this->stack->top()->n;
}

int Calculator::operate(string op,int n1,int n2){
    switch (op.at(0)){
        case '+': return n1 + n2;
        case '-': return n2 - n1;
        case '*': return n1 * n2;
        case '/': return n2 / n1;
        default:break;
    }
return 0;
}
