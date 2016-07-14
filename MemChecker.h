#ifndef MEMCHECKER_H_
#define MEMCHECKER_H_
#include <iostream>
#include <map>
using namespace std;

//ȫ�ֲ���������
void* operator new(size_t size, const char* file, long line);
void operator delete(void* p);
void operator delete[](void* p);


//ͨ��MemChecker��ʵ����һ�����󣬳�����ÿ��ʹ��new������ͬ�ļ���
//���кű�����һ��������delete��Ὣ��Ӧָ��Ӹ�������ɾ����
//�������ʱ����������Ƿ���δ�ͷŵ�ָ�룬����������ڴ�й¶

class MemChecker
{
private:
	//����һ���ڲ���
	class Entry
	{
	public:
		Entry(const char* file = nullptr, long line = 0)
			:file_(file)
			, line_(line)
		{}
		inline const char*File()const
		{
			return file_;
		}
		inline  long Line()const
		{
			return line_;
		}
	private:
		const char* file_;
		long line_;
	};
public:
	MemChecker();
	~MemChecker();
	void Add(void* pointer, const char* file, long line);
	void Remove(void* pointer);
	void Dump();
	static bool Ready;
private:
	map<void*, Entry> pointer_map_;
};

extern MemChecker mch;
	
#endif //!MEMCHECKER_H_