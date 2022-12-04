#pragma once
#include<vector>
// class T���ő�MAXSIZE�m�ۉ\��PoolAllocator���������Ă�������
template<class T, size_t MAXSIZE> class PoolAllocator
{
public:
	// �R���X�g���N�^
	PoolAllocator() {
		// TODO: �K�v�ɉ����Ď������Ă�������
		for (int i = 0; i < MAXSIZE - 1; i++) {
			buffer[i].next = &buffer[i + 1];

		}
		buffer[MAXSIZE - 1].next = nullptr;
		freelist = &buffer[0];

	}

	// �f�X�g���N�^
	~PoolAllocator() {
		// TODO: �K�v�ɉ����Ď������Ă�������
	}

	// �m�ۂł��Ȃ��ꍇ��nullptr��Ԃ����B
	T* Alloc() {
		// TODO: �������Ă�������
		if (freelist == nullptr)return nullptr;
		T* result = &(freelist->v);
		freelist = freelist->next;
		return result;
	}
	// Free(nullptr)�Ō듮�삵�Ȃ��悤�ɂ��鎖�B
	void Free(T* addr) {

		// TODO: �������Ă�������
		if (addr == nullptr) return;
		element_type* elem = reinterpret_cast<element_type*>(addr);
		elem->next = freelist;
		freelist = elem;
	}
private:
	// TODO: �������Ă�������
	union element_type {
		T v;
		element_type* next;
	};

	element_type buffer[MAXSIZE];

	element_type* freelist;

};

