#include <iostream>//подключение возможности работы с потоками ввода и вывода
using namespace std;//указываем компилятору импортировать все имена из пространства имен std в текущую область видимости

int main()
{
	cout << "Good Time Of Day!" << endl;
	char ans;//объявление переменной для записи ответа пользователя о продолжении использования программы
	do {
		int size;//объявление переменной для записи размера массива
		cout << "Enter the size of the array: ";
		cin >> size;//инициализация переменной для записи размера массива
		while ((cin.fail()) || (size <= 0)) {//вход в цикл, который будет запрашивать ввод размера массива всякий раз, когда его размер не будет являтся целым положительным значением
			cout << "Erorr, please, enter a positive integer: ";//сообщение об ошибке и просьба ввести данные заново
			cin.clear();//сброс состояния ошибки
			cin.ignore(10000, '\n');//пропуск 10000 веденных элементов 
			cin >> size;//инициализация переменной для записи размера массива
		}
		cin.ignore(10000, '\n');//пропуск элементов, на случай ввода пользователем "4а", например
		char* array = new char[size];//создание динамического массива заданного размера
		for (int i=0;i<size;i++) {//цикл на ввод элементов массива
		
			cout << "Enter an " << i+1 << " array element: ";
			cin >> array[i];//ввод элемента массива
			cin.ignore(10000, '\n'); 
		}
		int positions;//объявление переменной количества позиций сдвига
		cout << "Enter the number of shift positions: ";
		cin >> positions;//инициализация переменной
		while ((cin.fail()) || (positions < 0)) {//вход в цикл, который будет запрашивать ввод k всякий раз, когда positions не будет являться положительным целым числом
		
			cout << "Erorr, please, enter the number of shift positions again: ";
			cin.clear();//сброс состояния ошибки
			cin.ignore(10000, '\n');//пропуск 10000 веденных элементов 
			cin >> positions;
		}
		positions = positions % size;
		cin.ignore(10000, '\n');//пропуск 10000 элементов, на случай ввода пользователем "4а", например
		for (int t = 0; t< positions;t++) {//вход в цикл, который сдвинет наш массив влево на одну позицию positions раз
		
			const char first = array[0];//сохраняем первый элемент массива в переменную first
			for (int i = 0; i < (size-1); i++) {//цикл, который сдвигает все элементы до предпоследнего на 1 позицию влево
			
				array[i] = array[i + 1];
			}
			array[size - 1] = first;//присваеваем последнему элементу значение сохраненного
		}
		for (int i = 0; i < size; i++) {//вход в цикл, который пробегает по всем элементам массива и выводит их на экран
		
			cout << array[i];//вывод на экран элемента массива
		}
		delete[]array;//освобождение памяти
		cout << endl;
		cout << "Continue? (y or n): ";//спрашиваем у пользователя, хочет ли он продолжить
		cin >> ans;//ввод ответа от пользователя
		while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N') {
			cout << "Do you want to continue? Please, enter y or n: ";
			cin.ignore(10000, '\n');
			cin >> ans;
		}
		cin.ignore(10000, '\n');
		if (ans == 'y' || ans == 'Y') {
			cout << endl;//отступ между программами для красоты
		}
	} while (ans == 'y' || ans == 'Y');//запуск цикла заново,в случае, если пользователь захочет продолжить использовать программу
	return 0;//возврат 0 и завершение работы программы
}
