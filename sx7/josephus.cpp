/**
 * Copyleft 2021 (Ɔ) Huang Kaisheng <2020215138@stu.cqupt.edu.cn>
 * 
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <http://unlicense.org/>
 */ 
#include "josephus.h"

Child* allocateChild() {
    const int MAXN = 200000;                // 内存池大小
    static Child _mempool[MAXN];            // 开辟内存池
    static unsigned int index = 0;          // 内存池计数
    if (index == MAXN) return NULL;         // 避免内存池下标越界
    else return &_mempool[index++];         // 返回元素
}

Child* initChildrenLinkedList(int n) {
    Child *head = NULL, *prev = NULL, *current = NULL;
    for (int i = 1; i <= n; i++) {
        current = allocateChild();          // 从内存池中分配
        assert(current != NULL);
        if (head == NULL) {                 // 如果为第一个元素，头指针未设置
            head = prev = current;
        }
        else {
            prev->next = current;           // 先设置上一个元素的 next 指针
            prev = current;                 // 将当前元素地址赋给 prev，以供下一次循环使用
        }
        current->code = i;
        std::cin >> current->id >> current->name;
    }
    current->next = head;                   // 将最后一个元素的 next 指针指向头指针，形成圈
    return head;
}

Child* skip(Child* head, int k) {
    for (int i = 1; i < k; i++) {
        assert(head != NULL);
        head = head->next;
    }
    return head;
}

bool remove(Child* prev, Child* node) {
    if (node == NULL)
        node = prev->next;
    if (node != prev) {                     // 判断是否仅剩一个小孩
        prev->next = node->next;
        return true;
    }
    else return false;
}

int main(int argc, char const *argv[]) {
    int n, m, k;
    std::cin >> n >> m >> k;
    Child* head = initChildrenLinkedList(n);            // 初始化链表并从标准输入流读取小孩信息
    Child* prev = skip(head, k - 1), *current = prev;   // 找到开始数的第一个小孩和[他/她]的前一个小孩
    do {
        prev = skip(current, m);                        // 开始数 m 个小孩
        current = prev->next;
    } while (remove(prev, current));                    // 若无法再移除则表明此时是最后一个小孩，结束循环。
    std::cout << "Winner: \nThe child " << current->code << ",\n   whose student ID is " 
                << current->id << " and name is " << current->name << std::endl;
    return 0;
}