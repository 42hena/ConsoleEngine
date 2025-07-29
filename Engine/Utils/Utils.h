#ifndef __UTILS_H__
#define __UTILS_H__

#include <Windows.h>

namespace Utils
{
	// �� ���� ���� �ٲ� �� ����ϴ� �Լ�
	template <typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	// �ܼ� ��� �ڵ� �������� �Լ�
	inline HANDLE GetConsoleHandle()
	{
		return GetStdHandle(STD_OUTPUT_HANDLE);
	}

	// �ܼ� Ŀ�� ��ġ �̵� �Լ�
	inline void SetConsolePosition(COORD coord)
	{
		SetConsoleCursorPosition(GetConsoleHandle(), coord);
	}

	// �ܼ� �ؽ�Ʈ ���� ���� �Լ�
	inline void SetConsoleTextColor(WORD color)
	{
		SetConsoleTextAttribute(GetConsoleHandle(), color);
	}
}

#endif
