#include "LinkedList_Stack.h"
#include <iostream>

using namespace std;

int main() {
    LinkedListStack stack;

    // 测试入栈操作
    cout << "== 入栈 ==" << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << "Pushing: " << i << endl;
        stack.push(i);
    }

    // 打印栈的内容
    cout << "== 当前栈 ==" << endl;
    vector<int> vec = stack.toVector();
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // 测试出栈操作
    cout << "== 出栈 ==" << endl;
    while (!stack.isEmpty()) {
        cout << "Popping: " << stack.pop() << endl;
    }

    // 检查栈是否为空
    cout << "栈是否为空: " << (stack.isEmpty() ? "是" : "否") << endl;

    // 尝试从空栈中弹出元素
    try {
        stack.pop();
    } catch (const out_of_range& e) {
        cerr << "错误: " << e.what() << endl;
    }

    return 0;
}
