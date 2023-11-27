#include <iostream>
#include <string>
#include <time.h>
//Создание структуры элемента списка
struct RaceInfo
{
	std::string surname;//Фамилия
	int age;//Возраст
	time_t  startTime;//Начало забега
	time_t  endTime;//Конец забега
	RaceInfo* next;//Следующий элемент списка
};
//Создание структуры головы списка
struct HeadRaceInfo
{
	int count;//Количество элементов
	RaceInfo* next;//Первый элемент списка
};

HeadRaceInfo* Head;//Переменная заголовка списка

RaceInfo* findWinner(int minAge, int maxAge) {//Функция по поиску чемпионов
	RaceInfo *p, *winner = NULL;//Переменные для сравнения и перебора списка
	if (Head->count != 0) {//Если в списке есть элементы
		p = Head->next;//Меняем указатель на след элемент
		while (true) {//Бесконечный цикл
			if (p->age > minAge and p->age < maxAge) {//Если попадает в диапозон
				if (winner == NULL) winner = p;//Если победителя пока нет то единственный участник уже победитель:)
				else//Иначе
				{
					if (winner->endTime - winner->startTime > p->startTime - p->startTime) {//Сравниваем время у двух участников
						winner = p;//Быстрейший это и есть победитель
					}
				}
			}
			if (p->next == nullptr) break; else//Если нет следующего элемента выходим из цикла
			{
				p = p->next;//Иначе переходим на след элемент
			}
		}
	}

	return winner;//Возвращем победителя
}

void Sort(int mode) {//Функция сортировки, 3 режима сортировки имеют почти одинаковую логику, так что распишем только одну
	RaceInfo *p = Head->next, *p1, *temp;//Переменные для сравнения двух элементов, а так же temp для поиска 
	switch (mode)//Ветвление switch
	{
	case 1: //Если mode 1 
		if (Head->count >= 2) {//Если у нас в списке 2 и более элементов можно сортировать
			while (true)//Бесконечный цикл
			{
			    if (p->next != nullptr)//Если у первого указателя есть следующий элемент
				{
					p1 = p->next;//Назначем его как второй указатель
				}
				else break;//Иначе выходим из цикла
				if (p1->surname.compare(p->surname) > 0)//Сравниваем фамилии
				{
					if (Head->next == p) {//Если первый указатель это первый элемент списка
						Head->next = p1;//Меняем указатель на первый элемент списка на второй 
						p->next = p1->next;//У первого указателя меняем указатель на следующий элемент как указатель на следующий элемент у второго
						p1->next = p;//Меняем указатель на следуюзий элемент у второго на первый указатель
					}
					else {//Если первый указатель это не первый элемент списка то его надо найти
						temp = Head->next;//Ищем 
						while (true)
						{
							if (temp->next == p)
							{
								temp->next = p1;
								p->next = p1->next;
								p1->next = p;
								break;
							}
							if (temp->next == nullptr) break; else temp = temp->next;
						}
					}
				}
				else if(p->next!= nullptr)//Если следующего элемента нет, выходим из цикла
				{
					p = p->next;
				}
				else break;
			}
		}
		break;
	case 2:
		if (Head->count >= 2) {
			while (true)
			{
				if (p->next != nullptr)
				{
					p1 = p->next;
				}
				else break;
				if (p1->age > p->age)
				{
					if (Head->next == p) {
						Head->next = p1;
						p->next = p1->next;
						p1->next = p;
					}
					else {
						temp = Head->next;
						while (true)
						{
							if (temp->next == p)
							{
								temp->next = p1;
								p->next = p1->next;
								p1->next = p;
								break;
							}
							if (temp->next == nullptr) break; else temp = temp->next;
						}
					}
				}
				else if (p->next != nullptr)
				{
					p = p->next;
				}
				else break;
			}
		}
		break;
	case 3:
		if (Head->count >= 2) {
			while (true)
			{
				if (p->next != nullptr)
				{
					p1 = p->next;
				}
				else break;
				if (p1->endTime - p1->startTime > p->startTime - p->startTime)
				{
					if (Head->next == p) {
						Head->next = p1;
						p->next = p1->next;
						p1->next = p;
					}
					else {
						temp = Head->next;
						while (true)
						{
							if (temp->next == p)
							{
								temp->next = p1;
								p->next = p1->next;
								p1->next = p;
								break;
							}
							if (temp->next == nullptr) break; else temp = temp->next;
						}
					}
				}
				else if (p->next != nullptr)
				{
					p = p->next;
				}
				else break;
			}
		}
		break;
	default:
		break;
	}
}

void ShowInterface(int mode)//Функция отрисовки интрефейса
{
	int input;//Переменная ввода
	system("cls");//Очистка консоли
	std::cout << "========================================\n";
	std::cout << "|         Champion finder 9500         |\n";//Вывод крутого названия программы
	std::cout << "========================================\n";

	switch (mode)//ветвление switch
	{
	case 1:
	{
		std::cout << "|                 Menu                 |\n";//Вывод пунктов меню
		std::cout << "========================================\n";
		std::cout << "1.Enter Participants\n";
		std::cout << "2.Show Participants\n";
		std::cout << "3.Show Winners\n";
		std::cout << "4.Sort\n";
		std::cout << "5.Exit\n";
		std::cin >> input;//Ввод выбора пользователя
		switch (input)//ветвление switch
		{
		case 1:
			ShowInterface(2);//Отрисовать добавление записи
			break;
		case 2:
			ShowInterface(3);//Отрисовать показ участников
			break;
		case 3:
			ShowInterface(4);//Отривсовать показ победителей
			break;
		case 4:
			std::cout << "1 Sort by surname. 2 Sort by age. 3 Sort by time\n";// Выбор типа сортировки
			std::cin >> input;
			switch (input)
			{
			case 1: 
				for (int i = 0; i < 3; i++) {
					Sort(1);//Запуск сортировки 3 раза
				}
				break;
			case 2:
				for (int i = 0; i < 3; i++) {
					Sort(2);//Запуск сортировки 3 раза
				}
				break;
			case 3:
				for (int i = 0; i < 3; i++) {
					Sort(3);//Запуск сортировки 3 раза
				}
				break;
			}
			ShowInterface(1);//После сортировки вернуться в меню
			break;
		default:
			break;
		}
	}
		break;
	case 2:
	{
		RaceInfo* info = new RaceInfo();//Создания временной записи для добавления
		std::string Temp = "";//Временая переменная

		info->startTime = time(NULL);//Инициализация времени старта
		info->endTime = time(NULL);//Инициализация времени финиша

		const char *zStart;//Временная переменая для преоброзования
		struct tm *now = localtime(&info->startTime);//Переменная для доступа к часам, минутам, секундам
		char *cstr;//Временная переменная для преоброзования
		int input;//Переменная ввода
		int hh, mm, ss;//Часы минуты и секунды

		std::cout << "Enter surname:";//Вывод сообщения
		std::cin >> info->surname;//Ввод данных
		std::cout << "Enter age:";//Вывод сообщения
		std::cin >> info->age;//Ввод данных

		std::cout << "Enter start time (HH:MM:SS): ";//Вывод сообщения
		Temp = "";//Иницализация переменной
		std::cin >> Temp;//Ввод с клавиаторы
		zStart = Temp.c_str();//преоброзования строки в константу
		sscanf(zStart, "%d:%d:%d",&hh,&mm,&ss);//Достаем данные из строки
		now->tm_hour = hh;//Записываем в tm 
		now->tm_min = mm;//Записываем в tm 
		now->tm_sec = ss;//Записываем в tm 
		info->startTime = mktime(now);//Преобразуем tm в time_t

		std::cout << "Enter end time (HH:MM:SS): ";//Вывод сообщения
		Temp = "";//Иницализация переменной
		std::cin >> Temp;//Ввод с клавиаторы
		zStart = Temp.c_str();//преоброзования строки в константу
		sscanf(zStart, "%d:%d:%d", &hh, &mm, &ss);//Достаем данные из строки
		now->tm_hour = hh;//Записываем в tm 
		now->tm_min = mm;//Записываем в tm 
		now->tm_sec = ss;//Записываем в tm 
		info->endTime = mktime(now);//Преобразуем tm в time_t

		info->next = nullptr;//Указываем что это последний элемент списка, так как будет добавлен в конец
		if (Head->count == 0) {//Если нет элементов то этот будет добавлен как 1
			Head->next = info;
			Head->count = Head->count + 1;
		}
		else//Иначе перебераем список пока не дайдем до последнего
		{
			RaceInfo* p = Head->next;
			while (true)
			{
				if (p->next == nullptr)
				{
					p->next = info;
					Head->count = Head->count + 1;
					break;
				}
				else
				{
					p = p->next;
				}

			}
		}
		std::cout << "Entry added(Press Enter to continue): ";//Вывод сообщения
		std::cin >> input;
		ShowInterface(1);//Обратно в меню
	}
		break;
	case 3:
	{
		std::cout << "|          Participants List           |\n";//Вывод участников
		std::cout << "========================================\n";
		std::cout << "|Surname|Age|Start time|End time|           |\n";//Вывод шаблона
		if (Head->count != 0) {
			RaceInfo *p = Head->next;
			while (true) {
				struct tm *start = new struct tm(), *end = new struct tm();//Временные переменные
				start = localtime(&p->startTime);//Получаем время старта
				std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";//Выводим
				end = localtime(&p->endTime);//Получаем время финиша
				std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";//Выводим
				//printf("|%14|%3d|    %02d:%02d:%02d    |   %02d:%02d:%02d   |           |\n",p->surname,p->age); Вариант который не получился, а должно было быть красиво(
				if (p->next == nullptr) break; else// следующий элемент
				{
					p = p->next;
				}
			}
		}
	    std::cin >> input;
	    ShowInterface(1);//Обратно в меню
	}
		break;
	case 4:
	{
		std::cout << "|             Winners List             |\n";//Список победителей
		std::cout << "========================================\n";
		std::cout << "[ 5 -  15y.]:";//Диапозон 
		RaceInfo *p = findWinner(5, 15);//Запуск поиска победителей
		if (p != NULL) {//Вывод
			struct tm *start = new struct tm(), *end = new struct tm();
			start = localtime(&p->startTime);
			std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";
			end = localtime(&p->endTime);
			std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";

		}
		
		std::cout << "[ 16-  25y.]:";//Диапозон 
	    p = findWinner(16, 25);//Запуск поиска победителей
		if (p != NULL) {//Вывод
			struct tm *start = new struct tm(), *end = new struct tm();
			start = localtime(&p->startTime);
			std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";
			end = localtime(&p->endTime);
			std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";

		}
		std::cout << "[ 26-  99y.]:";//Диапозон 
		p = findWinner(26, 99);//Запуск поиска победителей
		if (p != NULL) {//Вывод
			struct tm *start = new struct tm(), *end = new struct tm();
			start = localtime(&p->startTime);
			std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";
			end = localtime(&p->endTime);
			std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";

		}
		std::cin >> input;
		std::cout << "========================================\n";
		ShowInterface(1);
	}
		break;

	default:
		break;
	}
}


int main() {//Старт программы
	Head = new HeadRaceInfo();//Создание заголовка списка
	Head->count = 0;//0 элементов списка

	ShowInterface(1);//Отрисовка меню программы
}