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

#include <iostream>
#include <string>
#include <cassert>

struct Child {
    int code;
    Child* next;
    std::string id;
    std::string name;
};

/** 使用内存池来避免频繁的内存分配，提高性能 */
Child* allocateChild();

/** 初始化链表 
 * @param n 小孩数
*/
Child* initChildrenLinkedList(int n);

/** 跳过几个小孩
 * @param head 待跳过头指针
 * @param k 跳过 k 个小孩
 * @return 返回 head 后第 k 个小孩的地址，其 next 为跳过的小孩
*/
Child* skip(Child* head, int k);

/** 移除小孩
 * @param prev 前一个小孩
 * @param node 待移除的小孩
 * @return 是否能成功移除小孩，若不能说明仅剩一个小孩
*/
bool remove(Child* prev, Child* node = NULL);