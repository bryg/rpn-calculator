#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

void die() {
        cout << "BAD INPUT\n";
        exit(EXIT_FAILURE);
}

template <class T>
class Stack {
        private:
                int index = -1;
                T data[100];
        public:
                Stack() {}
                bool empty() {return index == -1;}
                int size() {return index + 1;}
                T& top() {
                        if(empty()) {
                                data[0] = {};
                                return data[0];
                        }
                        return data[index];
                }
                void push(const T& new_data) {
                        if (size() >= 100) {
                                cout << "Stack overflow!" << endl;
                                exit(EXIT_FAILURE);
                        }
                        data[++index] = new_data;
                }
                void pop() {
                        if (index < 0) {
                                cout << "Stack underflow!" << endl;
                                exit(EXIT_FAILURE);
                        }
                        index--;
                }
};

int main() {
        int operand;
        char operat;
        bool seen_an_e = false;
        Stack<int> my_stack;

        while (cin) {
                cin >> ws; //Eat whitespace
                int c = cin.peek(); //Peek at next letter to read
                if (c == EOF) break;
                if (!isdigit(c)) { //Should be +,-,*,/,%,^,E
                        cin >> operat;
                        if (operat == '+') {
                                if (my_stack.size() < 2) die();
                                int a = my_stack.top();
                                my_stack.pop();
                                int b = my_stack.top();
                                my_stack.pop();
                                my_stack.push(b + a);
                        } else if (operat == '-') {
                                if (my_stack.size() < 2) die();
                                int a = my_stack.top();
                                my_stack.pop();
                                int b = my_stack.top();
                                my_stack.pop();
                                my_stack.push(b - a);
                        } else if (operat == '*') {
                                if (my_stack.size() < 2) die();
                                int a = my_stack.top();
                                my_stack.pop();
                                int b = my_stack.top();
                                my_stack.pop();
                                my_stack.push(b * a);
                        } else if (operat == '/') {
                                if (my_stack.size() < 2) die();
                                int a = my_stack.top();
                                if (a == 0) die();
                                my_stack.pop();
                                int b = my_stack.top();
                                my_stack.pop();
                                my_stack.push(b / a);
                        } else if (operat == '%') {
                                if (my_stack.size() < 2) die();
                                int a = my_stack.top();
                                if (a == 0) die();
                                my_stack.pop();
                                int b = my_stack.top();
                                my_stack.pop();
                                my_stack.push(b % a);
                        } else if (operat == '^') {
                                if (my_stack.size() < 2) die();
                                int a = my_stack.top();
                                my_stack.pop();
                                int b = my_stack.top();
                                if (a == 0 && b == 0) die();
                                my_stack.pop();
                                my_stack.push(pow(b,a));
                        } else if (operat == 'E') {
                                if (my_stack.size() != 1) die();
                                seen_an_e = true;
                                cout << my_stack.top() << endl;
                        } else die();

                } else { //isdigit(c)
                        cin >> operand;
                        my_stack.push(operand);
                }
        }
        if (!seen_an_e) die();
        if (my_stack.size() != 1) die();
}


