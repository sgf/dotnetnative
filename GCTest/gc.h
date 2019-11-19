#pragma once

#include <iostream>
struct Object {
	Object* head;
	Object* tail;
	bool marked;//标记位
};
Object* root = nullptr;
const int32_t HeapSize = 10000;
//堆
Object heap[HeapSize];
Object* freeList = nullptr;


void mark(Object* obj) {
	if (obj == nullptr || obj->marked) return;
	obj->marked = true;
	mark(obj->head);
	mark(obj->tail);
}

void addToFreeList(Object* obj) {
	obj->tail = freeList;
	freeList = obj;
}

//分配
Object* allocate() {
	if (freeList == nullptr) {//out of memory
		//do gc
		for (auto& o : heap)
			o.marked = false;
		mark(root);
		for (auto& o : heap)
			if (!o.marked) addToFreeList(&o);

		if (freeList == nullptr)//still out of memory
			return nullptr;// give up :(
	}
	Object* p = freeList;//把链表当前第一个取出来
	freeList = p->tail;//把链表指向下一个
	return p;
}


//初始化堆
void init_heap() {
	for (auto& x : heap)
		addToFreeList(&x);
}
