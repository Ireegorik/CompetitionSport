#include <iostream>
#include <string>
#include <time.h>
//�������� ��������� �������� ������
struct RaceInfo
{
	std::string surname;//�������
	int age;//�������
	time_t  startTime;//������ ������
	time_t  endTime;//����� ������
	RaceInfo* next;//��������� ������� ������
};
//�������� ��������� ������ ������
struct HeadRaceInfo
{
	int count;//���������� ���������
	RaceInfo* next;//������ ������� ������
};

HeadRaceInfo* Head;//���������� ��������� ������

RaceInfo* findWinner(int minAge, int maxAge) {//������� �� ������ ���������
	RaceInfo *p, *winner = NULL;//���������� ��� ��������� � �������� ������
	if (Head->count != 0) {//���� � ������ ���� ��������
		p = Head->next;//������ ��������� �� ���� �������
		while (true) {//����������� ����
			if (p->age > minAge and p->age < maxAge) {//���� �������� � ��������
				if (winner == NULL) winner = p;//���� ���������� ���� ��� �� ������������ �������� ��� ����������:)
				else//�����
				{
					if (winner->endTime - winner->startTime > p->startTime - p->startTime) {//���������� ����� � ���� ����������
						winner = p;//���������� ��� � ���� ����������
					}
				}
			}
			if (p->next == nullptr) break; else//���� ��� ���������� �������� ������� �� �����
			{
				p = p->next;//����� ��������� �� ���� �������
			}
		}
	}

	return winner;//��������� ����������
}

void Sort(int mode) {//������� ����������, 3 ������ ���������� ����� ����� ���������� ������, ��� ��� �������� ������ ����
	RaceInfo *p = Head->next, *p1, *temp;//���������� ��� ��������� ���� ���������, � ��� �� temp ��� ������ 
	switch (mode)//��������� switch
	{
	case 1: //���� mode 1 
		if (Head->count >= 2) {//���� � ��� � ������ 2 � ����� ��������� ����� �����������
			while (true)//����������� ����
			{
			    if (p->next != nullptr)//���� � ������� ��������� ���� ��������� �������
				{
					p1 = p->next;//�������� ��� ��� ������ ���������
				}
				else break;//����� ������� �� �����
				if (p1->surname.compare(p->surname) > 0)//���������� �������
				{
					if (Head->next == p) {//���� ������ ��������� ��� ������ ������� ������
						Head->next = p1;//������ ��������� �� ������ ������� ������ �� ������ 
						p->next = p1->next;//� ������� ��������� ������ ��������� �� ��������� ������� ��� ��������� �� ��������� ������� � �������
						p1->next = p;//������ ��������� �� ��������� ������� � ������� �� ������ ���������
					}
					else {//���� ������ ��������� ��� �� ������ ������� ������ �� ��� ���� �����
						temp = Head->next;//���� 
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
				else if(p->next!= nullptr)//���� ���������� �������� ���, ������� �� �����
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

void ShowInterface(int mode)//������� ��������� ����������
{
	int input;//���������� �����
	system("cls");//������� �������
	std::cout << "========================================\n";
	std::cout << "|         Champion finder 9500         |\n";//����� ������� �������� ���������
	std::cout << "========================================\n";

	switch (mode)//��������� switch
	{
	case 1:
	{
		std::cout << "|                 Menu                 |\n";//����� ������� ����
		std::cout << "========================================\n";
		std::cout << "1.Enter Participants\n";
		std::cout << "2.Show Participants\n";
		std::cout << "3.Show Winners\n";
		std::cout << "4.Sort\n";
		std::cout << "5.Exit\n";
		std::cin >> input;//���� ������ ������������
		switch (input)//��������� switch
		{
		case 1:
			ShowInterface(2);//���������� ���������� ������
			break;
		case 2:
			ShowInterface(3);//���������� ����� ����������
			break;
		case 3:
			ShowInterface(4);//����������� ����� �����������
			break;
		case 4:
			std::cout << "1 Sort by surname. 2 Sort by age. 3 Sort by time\n";// ����� ���� ����������
			std::cin >> input;
			switch (input)
			{
			case 1: 
				for (int i = 0; i < 3; i++) {
					Sort(1);//������ ���������� 3 ����
				}
				break;
			case 2:
				for (int i = 0; i < 3; i++) {
					Sort(2);//������ ���������� 3 ����
				}
				break;
			case 3:
				for (int i = 0; i < 3; i++) {
					Sort(3);//������ ���������� 3 ����
				}
				break;
			}
			ShowInterface(1);//����� ���������� ��������� � ����
			break;
		default:
			break;
		}
	}
		break;
	case 2:
	{
		RaceInfo* info = new RaceInfo();//�������� ��������� ������ ��� ����������
		std::string Temp = "";//�������� ����������

		info->startTime = time(NULL);//������������� ������� ������
		info->endTime = time(NULL);//������������� ������� ������

		const char *zStart;//��������� ��������� ��� ��������������
		struct tm *now = localtime(&info->startTime);//���������� ��� ������� � �����, �������, ��������
		char *cstr;//��������� ���������� ��� ��������������
		int input;//���������� �����
		int hh, mm, ss;//���� ������ � �������

		std::cout << "Enter surname:";//����� ���������
		std::cin >> info->surname;//���� ������
		std::cout << "Enter age:";//����� ���������
		std::cin >> info->age;//���� ������

		std::cout << "Enter start time (HH:MM:SS): ";//����� ���������
		Temp = "";//������������ ����������
		std::cin >> Temp;//���� � ����������
		zStart = Temp.c_str();//�������������� ������ � ���������
		sscanf(zStart, "%d:%d:%d",&hh,&mm,&ss);//������� ������ �� ������
		now->tm_hour = hh;//���������� � tm 
		now->tm_min = mm;//���������� � tm 
		now->tm_sec = ss;//���������� � tm 
		info->startTime = mktime(now);//����������� tm � time_t

		std::cout << "Enter end time (HH:MM:SS): ";//����� ���������
		Temp = "";//������������ ����������
		std::cin >> Temp;//���� � ����������
		zStart = Temp.c_str();//�������������� ������ � ���������
		sscanf(zStart, "%d:%d:%d", &hh, &mm, &ss);//������� ������ �� ������
		now->tm_hour = hh;//���������� � tm 
		now->tm_min = mm;//���������� � tm 
		now->tm_sec = ss;//���������� � tm 
		info->endTime = mktime(now);//����������� tm � time_t

		info->next = nullptr;//��������� ��� ��� ��������� ������� ������, ��� ��� ����� �������� � �����
		if (Head->count == 0) {//���� ��� ��������� �� ���� ����� �������� ��� 1
			Head->next = info;
			Head->count = Head->count + 1;
		}
		else//����� ���������� ������ ���� �� ������ �� ����������
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
		std::cout << "Entry added(Press Enter to continue): ";//����� ���������
		std::cin >> input;
		ShowInterface(1);//������� � ����
	}
		break;
	case 3:
	{
		std::cout << "|          Participants List           |\n";//����� ����������
		std::cout << "========================================\n";
		std::cout << "|Surname|Age|Start time|End time|           |\n";//����� �������
		if (Head->count != 0) {
			RaceInfo *p = Head->next;
			while (true) {
				struct tm *start = new struct tm(), *end = new struct tm();//��������� ����������
				start = localtime(&p->startTime);//�������� ����� ������
				std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";//�������
				end = localtime(&p->endTime);//�������� ����� ������
				std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";//�������
				//printf("|%14|%3d|    %02d:%02d:%02d    |   %02d:%02d:%02d   |           |\n",p->surname,p->age); ������� ������� �� ���������, � ������ ���� ���� �������(
				if (p->next == nullptr) break; else// ��������� �������
				{
					p = p->next;
				}
			}
		}
	    std::cin >> input;
	    ShowInterface(1);//������� � ����
	}
		break;
	case 4:
	{
		std::cout << "|             Winners List             |\n";//������ �����������
		std::cout << "========================================\n";
		std::cout << "[ 5 -  15y.]:";//�������� 
		RaceInfo *p = findWinner(5, 15);//������ ������ �����������
		if (p != NULL) {//�����
			struct tm *start = new struct tm(), *end = new struct tm();
			start = localtime(&p->startTime);
			std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";
			end = localtime(&p->endTime);
			std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";

		}
		
		std::cout << "[ 16-  25y.]:";//�������� 
	    p = findWinner(16, 25);//������ ������ �����������
		if (p != NULL) {//�����
			struct tm *start = new struct tm(), *end = new struct tm();
			start = localtime(&p->startTime);
			std::cout << "|" << p->surname.substr(0, 14) << "|" << p->age << "|" << start->tm_hour << ":" << start->tm_min << ":" << start->tm_sec << "|";
			end = localtime(&p->endTime);
			std::cout << end->tm_hour << ":" << end->tm_min << ":" << end->tm_sec << "|\n";

		}
		std::cout << "[ 26-  99y.]:";//�������� 
		p = findWinner(26, 99);//������ ������ �����������
		if (p != NULL) {//�����
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


int main() {//����� ���������
	Head = new HeadRaceInfo();//�������� ��������� ������
	Head->count = 0;//0 ��������� ������

	ShowInterface(1);//��������� ���� ���������
}