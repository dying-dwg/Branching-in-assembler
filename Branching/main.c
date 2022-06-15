#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	short int A, B, C;
	char P;

	printf("Enter A, B, C  ");
	scanf_s("%hi %hi %hi", &A, &B, &C);

	__asm
	{
		movsx EAX, A
		movsx EBX, B
		movsx ECX, C
		mov P, 0		// Вывод нуля, если никаких равенства не найдётся

		cmp EAX, EBX
		jne check	// A != B

		cmp EBX, ECX
		jne P1		// A = B != C
		mov P, 2	// A = B = C
		jmp end

		check :
		cmp EBX, ECX
			je P1		// A != B; B = C
						// A != B != C;  Начинается проверка: A = C?

			cmp EAX, ECX
			jne end		// A != B; A != C
			P1 : mov P, 1	// A != B; A = C
			jmp end
			end :				// Выход из программы

	}

	printf("\nP = %d", P);
}