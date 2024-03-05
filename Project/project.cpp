#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<string.h>
#include<stdlib.h> //rand함수 사용
#include<time.h> //rand함수를 위해서

void how_use(); // 보드게임카페 이용 방법
void find_game(); // 보드게임 찾기
void recommen_game(); // 보드게임 추천
void order_menu(); // 음료 주문
void first_turn(); // 선 정하기

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
	{ "스플렌더","2인~4인","ㅂ-ㅅ",2,4 },
	{ "루미큐브","2인~6인","ㄹ-ㅁ",2,6 },
	{ "다빈치코드","2인~4인","ㄱ-ㄴ-ㄷ",2,4 },
	{ "할리갈리","2인~4인","ㅍ-ㅎ",2,4 },
	{ "노터치크라켄","3인~8인","ㄱ-ㄴ-ㄷ",3,8 },
	{ "렉시오","3인~4인","ㄹ-ㅁ",3,4 },
	{ "큐윅스","2인~5인","ㅋ-ㅌ",2,5 },
	{ "도미니언","2인~4인","ㄱ-ㄴ-ㄷ",2,4 },
	{ "센츄리","2인~4인","ㅂ-ㅅ",2,4 },
	{ "카탄","2인~4인","ㅋ-ㅌ",2,4 },
	{ "스파이폴","3인~8인","ㅂ-ㅅ",3,8 },
	{ "블리츠","3인~6인","ㅂ-ㅅ",3,6 },
	{ "텔레스트레이션","4인~8인","ㅋ-ㅌ",4,8 },
	{ "선물입니다","2인~6인","ㅂ-ㅅ",2,6 },
	{ "개조심","2인~","ㄱ-ㄴ-ㄷ",2,10 },
	{ "우노","2인~6인","ㅇ-ㅈ",2,6 },
	{ "젠가","2인~","ㅇ-ㅈ",2,10 },
	{ "스컬킹","2인~6인","ㅂ-ㅅ",2,6 },
	{ "기즈모","2인~4인","ㄱ-ㄴ-ㄷ",2,4 },
	{ "더마인드","2인~4인","ㄱ-ㄴ-ㄷ",2,4 }
};

snack Snacks[15]{
	{"아메리카노",3000,0},
	{"카페라떼",3500,0},
	{"돌체라떼",4500,0},
	{"바닐라라떼",3900,0},
	{"다방커피",3500,0},
	{"더블초코라떼",4000,0},
	{"녹차라떼",4500,0},
	{"리얼딸기라떼",4500,0},
	{"미숫가루라떼",3900,0},
	{"체리콕",3000,0},
	{"감자튀김",4500,0},
	{"허니버터갈릭 감자튀김",5500,0},
	{"로제 떡볶이",7200,0},
	{"크리스피 순살 치킨",6900,0},
	{"바닐라 아이스크림",3000,0}
};

void main() {


	int num = 1;
	printf("환영합니다! 보드게임 카페 레드버튼입니다! \n");

	while (1)
	{
	
			if (num == 0)
				break;
			printf("\n");
			printf("원하는 서비스를 입력 해주세요<종료:0> \n");
			printf("\n");
			printf("--------------------------------\n");
			printf("|1. 보드게임카페 이용 방법	|\n");
			printf("|2. 보드게임 찾기		|\n");
			printf("|3. 보드게임 추천		|\n");
			printf("|4. 음료 주문하기		|\n");
			printf("|5. 선 정하기			|\n");
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


void how_use() {// 보드게임카페 이용 방법
	printf("==================================================================================================\n");
	printf("\n");
	printf("<이용 요금> \n");
	printf("1인 1주문 필수\n");
	printf("평일 1인 1시간당 2400원 / 주말 1인 1시간당 3000원\n");
	printf("+ 평일 정액 요금제 (4시간 음료 포함_9900원, 4시간 음료 미포함_7900)\n");
	printf("\n");
	printf("<매장 이용 방법>\n");
	printf("1. 음료 결제는 선불, 게임비 결제는 후불입니다. \n");
	printf("2. 밖에 있는 보드게임은 자유롭게 가져가 이용해주세요.\n");
	printf("3. 사용후 게임은 게임 반납대에 놓아주세요.\n");
	printf("4. 게임별로 필요한 도구(추리노트,타이머,다이스타워 등)은 게임 추천판 앞에 진열되어 있습니다.\n");
	printf("\n");
	printf("==================================================================================================\n");
}
void find_game() {// 보드게임 찾기
	int i;
	char inpu[30];
	while (1)
	{
		printf("\n");
		printf("<보드게임 찾기>\n");
		printf("게임 이름을 입력해주세요.(menu:0):");
		scanf("%s", &inpu);
		if (inpu[0] == '0') {
			break;
		}
		for (i = 0; i < 20; i++) {
			if (strcmp(inpu, Games[i].name) == 0) { // strcmp 함수
				printf("=========================================\n");
				printf("\n");
				printf("보드게임 이름 :%s\n", Games[i].name);
				printf("게임 가능 인원 :%s\n", Games[i].people);
				printf("보드게임 진열 위치 :%s\n", Games[i].site);
				printf("\n");
				printf("=========================================\n");
				break;
			}
			else {
				if (i == 19) {
					printf("\n");
					printf("=========================================\n");
					printf("%s 은(는) 매장에 없습니다!\n", inpu);
					printf("=========================================\n");
					printf("\n");
				}
				continue;
			}
		};
	}
} 
void recommen_game() {// 보드게임 추천
	int ran,num;
	srand((unsigned)time(NULL));
	printf("<보드게임 추천>\n");
	while (1)
	{
		printf("\n");
		printf("함께 플레이할 인원을 입력해주세요.<menu:0>:");
		scanf("%d", &num);
		if (num == 0)
			break;

		while (1)
		{
			ran = rand() % 19;
			if (Games[ran].min_player <= num && num <= Games[ran].max_player) {
				printf("\n");
				printf("%s 추천!!\n", Games[ran].name);
				printf("=========================================\n");
				break;
			}
			else if (num == 1) {
				printf("\n");
				printf("1명을 위한 게임은 없습니다.\n");
				printf("다시 입력해주세요.\n");
				printf("=========================================\n");
				break;
			}
			else if (num>10) {
				printf("\n");
				printf("10인 초과 게임은 없습니다.\n");
				printf("다시 입력해주세요.\n");
				printf("=========================================\n");
				break;
			}else {
				continue;
			}
		}

	}
} 
void order_menu() {// 음료 주문
	
	int sum=0,i,n=1,y=0;

	printf("\n");
	printf("<===============메뉴==============>\n");
	for (i = 0; i < 15; i++) {
		printf("%d. <%s> : %d원\n",i+1, Snacks[i].name, Snacks[i].price);
	}
	printf("<==================================>\n");
	printf("\n");
	printf("원하시는 메뉴의 번호를 입력해주세요.<주문완료:0>");

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
			default: printf("잘못된 입력입니다.다시 입력해주세요.\n"); continue;
		}
	}
	for (int i = 0; i < 15; i++) {

		if (Snacks[i].count == 0)
			y++;
		if (y == 14)
			return;
	}
	printf("==========================================\n");
	printf("<주문하신 음료>\n");
	for (int i = 0; i < 15; i++) {
		if (Snacks[i].count == 0)
			continue;
		else {
			if (0 <= i && i <= 9) {
				printf("%s : %d잔\n", Snacks[i].name, Snacks[i].count);
			}
			else {
				printf("%s : %d개\n", Snacks[i].name, Snacks[i].count);
			}
		}

	}
	for (int i = 0; i < 15; i++) {
		if (Snacks[i].count != 0)
			Snacks[i].count = 0;
	}
	printf("-------------------------------------------\n");
	printf("\n");
	printf("총 금액 %d원 입니다.\n", sum);
	printf("준비되면 태블릿으로 호출 하겠습니다.\n");
	printf("오실때 결제하실 카드와 방번호칩을 가져와 주세요.\n");
	printf("\n");
	printf("==========================================\n");
} 
void first_turn() { // 선 정하기
	int ran1,ran2,num;
	srand((unsigned)time(NULL));
	printf("<게임 선 정하기>\n");
	while (1)
	{
		printf("\n");
		printf("함께 플레이 하는 인원을 입력해주세요.<menu:0>:");
		scanf("%d", &num);
		if (num == 0)
			break;

		ran1 = rand() % num;
		ran2 = rand() % 2;

		if (ran2 == 0) {
			printf("%d번째 사람부터 시계방향! Start!\n",ran1+1);
		}else{
			printf("%d번째 사람부터 반시계방향! Start!\n", ran1+1);
		}
		
	}
}