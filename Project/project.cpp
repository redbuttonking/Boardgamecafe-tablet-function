#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<string.h>
#include<stdlib.h> //rand�Լ� ���
#include<time.h> //rand�Լ��� ���ؼ�

void how_use(); // �������ī�� �̿� ���
void find_game(); // ������� ã��
void recommen_game(); // ������� ��õ
void order_menu(); // ���� �ֹ�
void first_turn(); // �� ���ϱ�

typedef struct game {

	char name [20];
	char people [20];
	char site [10] ;
	int min_player;
	int max_player;
}game;

typedef struct snack {

	char name[30];
	int price;
	int count;
}snack;

game Games[20]{
	{ "���÷���","2��~4��","��-��",2,4 },
	{ "���ť��","2��~6��","��-��",2,6 },
	{ "�ٺ�ġ�ڵ�","2��~4��","��-��-��",2,4 },
	{ "�Ҹ�����","2��~4��","��-��",2,4 },
	{ "����ġũ����","3��~8��","��-��-��",3,8 },
	{ "���ÿ�","3��~4��","��-��",3,4 },
	{ "ť����","2��~5��","��-��",2,5 },
	{ "���̴Ͼ�","2��~4��","��-��-��",2,4 },
	{ "����","2��~4��","��-��",2,4 },
	{ "īź","2��~4��","��-��",2,4 },
	{ "��������","3��~8��","��-��",3,8 },
	{ "����","3��~6��","��-��",3,6 },
	{ "�ڷ���Ʈ���̼�","4��~8��","��-��",4,8 },
	{ "�����Դϴ�","2��~6��","��-��",2,6 },
	{ "������","2��~","��-��-��",2,10 },
	{ "���","2��~6��","��-��",2,6 },
	{ "����","2��~","��-��",2,10 },
	{ "����ŷ","2��~6��","��-��",2,6 },
	{ "�����","2��~4��","��-��-��",2,4 },
	{ "�����ε�","2��~4��","��-��-��",2,4 }
};

snack Snacks[15]{
	{"�Ƹ޸�ī��",3000,0},
	{"ī���",3500,0},
	{"��ü��",4500,0},
	{"�ٴҶ��",3900,0},
	{"�ٹ�Ŀ��",3500,0},
	{"�������ڶ�",4000,0},
	{"������",4500,0},
	{"��������",4500,0},
	{"�̼������",3900,0},
	{"ü����",3000,0},
	{"����Ƣ��",4500,0},
	{"��Ϲ��Ͱ��� ����Ƣ��",5500,0},
	{"���� ������",7200,0},
	{"ũ������ ���� ġŲ",6900,0},
	{"�ٴҶ� ���̽�ũ��",3000,0}
};

void main() {


	int num = 1;
	printf("ȯ���մϴ�! ������� ī�� �����ư�Դϴ�! \n");

	while (1)
	{
	
			if (num == 0)
				break;
			printf("\n");
			printf("���ϴ� ���񽺸� �Է� ���ּ���<����:0> \n");
			printf("\n");
			printf("--------------------------------\n");
			printf("|1. �������ī�� �̿� ���	|\n");
			printf("|2. ������� ã��		|\n");
			printf("|3. ������� ��õ		|\n");
			printf("|4. ���� �ֹ��ϱ�		|\n");
			printf("|5. �� ���ϱ�			|\n");
			printf("--------------------------------\n");
			printf("\n");
			scanf("%d", &num);

			switch (num)
			{
			case 1:
				how_use();
				break;
			case 2:
				find_game();
				break;
			case 3:
				recommen_game();
				break;
			case 4:
				order_menu();
				break;
			case 5:
				first_turn();
				break;
			default:
				continue;
			}
	}
}


void how_use() {// �������ī�� �̿� ���
	printf("==================================================================================================\n");
	printf("\n");
	printf("<�̿� ���> \n");
	printf("1�� 1�ֹ� �ʼ�\n");
	printf("���� 1�� 1�ð��� 2400�� / �ָ� 1�� 1�ð��� 3000��\n");
	printf("+ ���� ���� ����� (4�ð� ���� ����_9900��, 4�ð� ���� ������_7900)\n");
	printf("\n");
	printf("<���� �̿� ���>\n");
	printf("1. ���� ������ ����, ���Ӻ� ������ �ĺ��Դϴ�. \n");
	printf("2. �ۿ� �ִ� ��������� �����Ӱ� ������ �̿����ּ���.\n");
	printf("3. ����� ������ ���� �ݳ��뿡 �����ּ���.\n");
	printf("4. ���Ӻ��� �ʿ��� ����(�߸���Ʈ,Ÿ�̸�,���̽�Ÿ�� ��)�� ���� ��õ�� �տ� �����Ǿ� �ֽ��ϴ�.\n");
	printf("\n");
	printf("==================================================================================================\n");
}
void find_game() {// ������� ã��
	int i;
	char inpu[30];
	while (1)
	{
		printf("\n");
		printf("<������� ã��>\n");
		printf("���� �̸��� �Է����ּ���.(menu:0):");
		scanf("%s", &inpu);
		if (inpu[0] == '0') {
			break;
		}
		for (i = 0; i < 20; i++) {
			if (strcmp(inpu, Games[i].name) == 0) { // strcmp �Լ�
				printf("=========================================\n");
				printf("\n");
				printf("������� �̸� :%s\n", Games[i].name);
				printf("���� ���� �ο� :%s\n", Games[i].people);
				printf("������� ���� ��ġ :%s\n", Games[i].site);
				printf("\n");
				printf("=========================================\n");
				break;
			}
			else {
				if (i == 19) {
					printf("\n");
					printf("=========================================\n");
					printf("%s ��(��) ���忡 �����ϴ�!\n", inpu);
					printf("=========================================\n");
					printf("\n");
				}
				continue;
			}
		};
	}
} 
void recommen_game() {// ������� ��õ
	int ran,num;
	srand((unsigned)time(NULL));
	printf("<������� ��õ>\n");
	while (1)
	{
		printf("\n");
		printf("�Բ� �÷����� �ο��� �Է����ּ���.<menu:0>:");
		scanf("%d", &num);
		if (num == 0)
			break;

		while (1)
		{
			ran = rand() % 19;
			if (Games[ran].min_player <= num && num <= Games[ran].max_player) {
				printf("\n");
				printf("%s ��õ!!\n", Games[ran].name);
				printf("=========================================\n");
				break;
			}
			else if (num == 1) {
				printf("\n");
				printf("1���� ���� ������ �����ϴ�.\n");
				printf("�ٽ� �Է����ּ���.\n");
				printf("=========================================\n");
				break;
			}
			else if (num>10) {
				printf("\n");
				printf("10�� �ʰ� ������ �����ϴ�.\n");
				printf("�ٽ� �Է����ּ���.\n");
				printf("=========================================\n");
				break;
			}else {
				continue;
			}
		}

	}
} 
void order_menu() {// ���� �ֹ�
	
	int sum=0,i,n=1,y=0;

	printf("\n");
	printf("<===============�޴�==============>\n");
	for (i = 0; i < 15; i++) {
		printf("%d. <%s> : %d��\n",i+1, Snacks[i].name, Snacks[i].price);
	}
	printf("<==================================>\n");
	printf("\n");
	printf("���Ͻô� �޴��� ��ȣ�� �Է����ּ���.<�ֹ��Ϸ�:0>");

	while (1)
	{
		if (n == 0)
			break;
		scanf("%d", &n);
		switch (n)
		{ 
			case 0: break;
			case 1:	sum += Snacks[0].price; Snacks[0].count++;	break;
			case 2: sum += Snacks[1].price; Snacks[1].count++; break;
			case 3:	sum += Snacks[2].price; Snacks[2].count++; break;
			case 4: sum += Snacks[3].price; Snacks[3].count++; break;
			case 5: sum += Snacks[4].price; Snacks[4].count++; break;
			case 6: sum += Snacks[5].price; Snacks[5].count++; break;
			case 7: sum += Snacks[6].price; Snacks[6].count++; break;
			case 8: sum += Snacks[7].price; Snacks[7].count++; break;
			case 9: sum += Snacks[8].price; Snacks[8].count++; break;
			case 10: sum += Snacks[9].price; Snacks[9].count++; break;
			case 11: sum += Snacks[10].price; Snacks[10].count++; break;
			case 12: sum += Snacks[11].price; Snacks[11].count++; break;
			case 13: sum += Snacks[12].price; Snacks[12].count++; break;
			case 14: sum += Snacks[13].price; Snacks[13].count++; break;
			case 15: sum += Snacks[14].price; Snacks[14].count++; break;
			default: printf("�߸��� �Է��Դϴ�.�ٽ� �Է����ּ���.\n"); continue;
		}
	}
	for (int i = 0; i < 15; i++) {

		if (Snacks[i].count == 0)
			y++;
		if (y == 14)
			return;
	}
	printf("==========================================\n");
	printf("<�ֹ��Ͻ� ����>\n");
	for (int i = 0; i < 15; i++) {
		if (Snacks[i].count == 0)
			continue;
		else {
			if (0 <= i && i <= 9) {
				printf("%s : %d��\n", Snacks[i].name, Snacks[i].count);
			}
			else {
				printf("%s : %d��\n", Snacks[i].name, Snacks[i].count);
			}
		}

	}
	for (int i = 0; i < 15; i++) {
		if (Snacks[i].count != 0)
			Snacks[i].count = 0;
	}
	printf("-------------------------------------------\n");
	printf("\n");
	printf("�� �ݾ� %d�� �Դϴ�.\n", sum);
	printf("�غ�Ǹ� �º����� ȣ�� �ϰڽ��ϴ�.\n");
	printf("���Ƕ� �����Ͻ� ī��� ���ȣĨ�� ������ �ּ���.\n");
	printf("\n");
	printf("==========================================\n");
} 
void first_turn() { // �� ���ϱ�
	int ran1,ran2,num;
	srand((unsigned)time(NULL));
	printf("<���� �� ���ϱ�>\n");
	while (1)
	{
		printf("\n");
		printf("�Բ� �÷��� �ϴ� �ο��� �Է����ּ���.<menu:0>:");
		scanf("%d", &num);
		if (num == 0)
			break;

		ran1 = rand() % num;
		ran2 = rand() % 2;

		if (ran2 == 0) {
			printf("%d��° ������� �ð����! Start!\n",ran1+1);
		}else{
			printf("%d��° ������� �ݽð����! Start!\n", ran1+1);
		}
		
	}
}