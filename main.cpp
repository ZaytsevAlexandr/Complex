#include "Complex.h"
#define OS_MODE 1 // 1 - windows, 0 - other

#if OS_MODE==1
#include <Windows.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")
#endif

int main() {

#if OS_MODE==1
	PlaySound(TEXT("soundbar.wav"), NULL, SND_FILENAME | SND_ASYNC);
	setlocale(LC_CTYPE, "rus");
#endif

#if OS_MODE==1
	std::cout << "Внимание! Обязательно вводите нулевые элементы (a+0i, 0+bi, 0+0i)!" << std::endl;
#else
	std::cout << "Attention! Enter null elements correctly (a + 0i, 0 + bi, 0 + 0i)!" << std::endl;
#endif
	Complex number1;

#if OS_MODE==1
	std::cout << "Введите первое комплексное число в формате b+ai: ";
#else
	std::cout << "Input first complex number in format b+ai: ";
#endif

	std::cin >> number1;
	std::cout << std::endl;

#if OS_MODE==1
	std::cout << "Отлично! Вы ввели: ";
#else
	std::cout << "Great! You've entered: ";
#endif

	std::cout << number1 << std::endl;

	Complex number2;

#if OS_MODE==1
	std::cout << "Введите второе комплексное число в формате b+ai: ";
#else
	std::cout << "Input second complex number in format b+ai: ";
#endif

	std::cin >> number2;

#if OS_MODE==1
	std::cout << "Отлично! Вы ввели: ";
#else
	std::cout << "Great! You've entered: ";
#endif

	std::cout << number2 << std::endl;
	std::cout << std::endl;

#if OS_MODE==1
	std::cout << "Введите целое число, на которое хотите умножить ваше первое комплексное число: ";
#else
	std::cout << "Enter the integer by which you want to multiply your first complex number: ";
#endif

	int intNumber;
	std::cin >> intNumber;

#if OS_MODE==1
	std::cout << "Отлично! Вы ввели: ";
#else
	std::cout << "Great! You've entered: ";
#endif

	std::cout << intNumber << std::endl;
	std::cout << std::endl;

#if OS_MODE==1
	std::cout << "Вот иллюстрация работы программы: ";
#else
	std::cout << "Illustration of working this programm is below: ";
#endif

#if OS_MODE==1
	std::cout << "Сумма двух комплексных чисел: ";
#else
	std::cout << "Summary of two complex numbers: ";
#endif
	std::cout << number1 + number2 << std::endl;

#if OS_MODE==1
	std::cout << "Разность двух комплексных чисел: ";
#else
	std::cout << "Substract of two complex numbers: ";
#endif
	std::cout << number1 - number2 << std::endl;

#if OS_MODE==1
	std::cout << "Произведение двух комплексных чисел: ";
#else
	std::cout << "Multiply of two complex numbers: ";
#endif
	std::cout << number1 * number2 << std::endl;

#if OS_MODE==1
	std::cout << "Умножение первого комплексного числа на действительное целое число: ";
#else
	std::cout << "Multiply first complex number by integer: ";
#endif
	std::cout << number1 * intNumber << std::endl;

#if OS_MODE==1
	std::cout << "Умножение второго комплексного числа на действительное целое число: ";
#else
	std::cout << "Multiply second complex number by integer: ";
#endif
	std::cout << number2 * intNumber << std::endl;

#if OS_MODE==1
	std::cout << "Пре-инкремент действительной части обоих комплексных чисел: ";
#else
	std::cout << "Pre-increment real part of both complex numbers: ";
#endif
	std::cout << ++number1 << ", " << ++number2 << std::endl;

#if OS_MODE==1
	std::cout << "Пре-декремент действительной части обоих комплексных чисел: ";
#else
	std::cout << "Pre-decrement real part of both complex numbers: ";
#endif
	std::cout << --number1 << ", " << --number2 << std::endl;

#if OS_MODE==1
	std::cout << "Пост-инкремент и пост-декремент точно работают, честно." << std::endl;
#else
	std::cout << "Post-increment and post-decrement definitely work correctly." << std::endl;
#endif

#if OS_MODE==1
	std::cout << "Вот действительные части ваших двух комплексных чисел: ";
#else
	std::cout << "Here is the real parts of your both complex numbers: ";
#endif
	std::cout << number1.getRe() << ", " << number2.getRe() << std::endl;

#if OS_MODE==1
	std::cout << "Вот мнимые части ваших двух комплексных чисел: " << std::endl;
#else
	std::cout << "Here is the imaginary parts of your both complex numbers: ";
#endif
	std::cout << number1.getIm() << ", " << number2.getIm() << std::endl;

	std::string filePath = "numbers.txt";
	if (save(filePath, number1)) {
#if OS_MODE==1
		std::cout << "Первое комплексное число сохранено." << std::endl;
#else
		std::cout << "First complex number saved." << std::endl;
#endif
	}
	if (save(filePath, number2)) {
#if OS_MODE==1
		std::cout << "Второе комплексное число сохранено." << std::endl;
#else
		std::cout << "Second complex number saved." << std::endl;
#endif
	}

#if OS_MODE==1
	std::cout << "Чтобы выйти, нажмите любую клавишу." << std::endl;
#else
	std::cout << "To quit press any button." << std::endl;
#endif
	while (!_kbhit()) {}
	PlaySound(NULL, NULL, SND_PURGE);
}