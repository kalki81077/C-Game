#pragma once
#include<vector>
// class Tを最大MAXSIZE個確保可能なPoolAllocatorを実装してください
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// コンストラクタ
	PoolAllocator() {
		// TODO: 必要に応じて実装してください
		for (int i = 0; i < MAXSIZE - 1; i++) {
			buffer[i].next = &buffer[i + 1];

		}
		buffer[MAXSIZE - 1].next = nullptr;
		freelist = &buffer[0];

	}

	// デストラクタ
	~PoolAllocator() {
		// TODO: 必要に応じて実装してください
	}

	// 確保できない場合はnullptrを返す事。
	T* Alloc() {
		// TODO: 実装してください
		if (freelist == nullptr)return nullptr;
		T* result = &(freelist->v);
		freelist = freelist->next;
		return result;
	}
	// Free(nullptr)で誤動作しないようにする事。
	void Free(T* addr) {

		// TODO: 実装してください
		if (addr == nullptr) return;
		element_type* elem = reinterpret_cast<element_type*>(addr);
		elem->next = freelist;
		freelist = elem;
	}
private:
	// TODO: 実装してください
	union element_type {
		T v;
		element_type* next;
	};

	element_type buffer[MAXSIZE];

	element_type* freelist;

};

