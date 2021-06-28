#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define no {NULL}

void func1(int* arr, int len) { //1차원배열 출력 (1번)
	for (int i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void func2(int** arr, int x, int y) {//2차원배열 출력 (2번)
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("(%d)\t", arr[i][j]);
		}
		printf("\n");
	}
}
void swapNum(int* a, int* b) { //두개의 값 자리 바꾸기 (3번)
	int temp = *a;
	*a = *b;
	*b = temp;
}
int funcAvg(int* arr, int len, int* result) { //평균값 저장 (4, 5번)
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
		//printf("%d\t", arr[i]);
	}
	result = sum / len;
	return result;
}
typedef struct { //정수형 번호, 영단어, 한글뜻 구조체 (6번)
	int number;
	char eng[20];
	char kor[40];
}Dictionary;

typedef struct { //학생 점수 구조체 (7번)
	char name[20];
	float grade;
}Student;

void bubbleSort(Student* S) { //버블 정렬 (7번)
	Student temp;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (S[i].grade > S[j].grade) {
				temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
}

void problem1() { //1차원 배열을 전달받아 배열의 요소를 모두 출력하는 함수 func1
	printf("1. 1차원 배열을 전달받아 배열의 요소를 모두 출력하는 함수를 구현\n");
	int size;
	printf("배열 길이 : ");
	scanf_s("%d", &size);
	int* numArr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		numArr[i] = i+1;
	}
	func1(numArr, size);
	free(numArr);
	system("pause");
}
void problem2() { //2차원 배열을 전달받아 배열의 요소를 행과 열로 출력 func2
	printf("2. 2차원 배열을 전달받아 배열의 요소를 2차원의 행과 열로 출력");
	int positX;
	int positY;
	printf("행렬 크기(입력서식:x y) : ");
	scanf_s("%d %d", &positX, &positY);
	int** numArr;
	numArr = (int*)malloc(sizeof(int) * positX);
	for (int i = 0; i < positX; i++) {
		numArr[i] = (int*)malloc(sizeof(int) * positY);
	}
	for (int i = 0; i < positX; i++) {
		for (int j = 0; j < positY; j++) {
			numArr[i][j] = 10 * (i + 1) + (j + 1);
		}
	}
	func2(numArr, positX, positY);
	//for (int i = 0; i < positY; i++) free(numArr[i]);
	free(numArr);
	system("pause");
}
void problem3() { //2개의 정수를 입력받아 call-by-reference로 값을 바꿔주는 함수 swapNum
	printf("3. 2개 정수 값을 입력받아 그 값을 서로 바꿔주는 함수를 구현 (call-by-reference로 구현)\n");
	int num1, num2 = 0;
	printf("두 개의 정수 입력 : ");
	scanf_s("%d %d", &num1, &num2);
	printf("변경 전 : %d %d\n", num1, num2);
	swapNum(&num1, &num2);
	printf("변경 후 : %d %d\n", num1, num2);
	system("pause");
}
void problem4() { //배열과 정수형 변수 포인터를 전달받아 배열의 모든 요소들 평균값을 정수형 포인터로 반환
	printf("4. 배열과 정수형 변수의 포인터를 전달받아 배열 모든 요소의 평균을 변수형 포인터를 통해 반환하는 함수를 구현\n");
	int size;
	int avg = 0;
	int* avgP = &avg;
	printf("배열 길이 : ");
	scanf_s("%d", &size);
	int* numArr = (int*)malloc(sizeof(int) * size);
	printf("배열에 들어가 있는 수 : ");
	for (int i = 0; i < size; i++) {
		//numArr[i] = i + 1;
		scanf_s("%d", &numArr[i], size);
		printf("%d\t", numArr[i]);
	}
	printf("\n평균 값 : %d\n", funcAvg(numArr, size, avgP));
	free(numArr);
	system("pause");
}
void problem5() { //학생 5명의 이름, 국,영,수 점수 입력 받은 후 세과목 평균 값 출력
	printf("5. 5x4 정수형 2차원 배열 선언 후 사용자로부터 5명의 국어, 영어, 수학, 점수를 입력받습니다.\n한 행의 마지막 열에 세 과목의 평균을 저장하는데 4번에서 구현한 함수를 이용해 저장하도록 구현하세요\n");
	char name[5][20] = no;
	int grade[5][4] = no;
	int avg = 0;
	int* avgP = &avg;

	for (int i = 0; i < 5; i++) {
		printf("%d번 째 학생 이름 : ", i + 1);
		scanf_s("%s", name[i], 5);
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				printf("국어 점수 : ");
				scanf_s("%d", &grade[i][j]);
			}
			else if (j == 1) {
				printf("수학 점수 : ");
				scanf_s("%d", &grade[i][j]);
			}
			else if (j == 2) {
				printf("영어 점수 : ");
				scanf_s("%d", &grade[i][j]);
			}
			else grade[i][3] = funcAvg(grade[i], 3, avgP);
		}
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("|\t%s 학생의 세 과목 평균 점수는 %d\t|\n", name[i], grade[i][3]);
	}
	system("pause");
}
void problem6() { //단어의 영단어와 한글뜻, 정수형 번호를 갖는 구조체를 이용해서 단어 맞추기 게임(대소문자 구분 안함)
	printf("6. 단어의 영어와 한글 문자열, 번호인 정수를 멤버로 갖는 구조체 10개를 만들어 초기화하세요.\n난수로 구조체 변수 10개 중 하나의 한글 단어를 출력한 후 영어 단어를 입력받아 맞혔는지 틀렸는지 출력합니다\n");
	Dictionary dict1 = { 1, "mirror", "거울" };
	Dictionary dict2 = { 2, "temperature","온도" };
	Dictionary dict3 = { 3, "traffic", "교통" };
	Dictionary dict4 = { 4, "hobby", "취미" };
	Dictionary dict5 = { 5, "bill", "지폐" };
	Dictionary dict6 = { 6, "regret", "후회" };
	Dictionary dict7 = { 7, "evil", "악" };
	Dictionary dict8 = { 8, "tail", "꼬리" };
	Dictionary dict9 = { 9, "voice", "목소리" };
	Dictionary dict10 = { 10, "guest","손님" };

	char answer[20];
	srand((unsigned int)time(NULL));
	int num = rand() % 10;
	switch (num){
	case 0: printf("한글 뜻 : %s\n영어 단어 : ", dict10.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict10.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;
		
	case 1: printf("한글 뜻 : %s\n영어 단어 : ", dict1.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict1.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 2: printf("한글 뜻 : %s\n영어 단어 : ", dict2.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict2.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 3: printf("한글 뜻 : %s\n영어 단어 : ", dict3.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict3.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 4: printf("한글 뜻 : %s\n영어 단어 : ", dict4.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict4.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 5: printf("한글 뜻 : %s\n영어 단어 : ", dict5.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict5.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 6: printf("한글 뜻 : %s\n영어 단어 : ", dict6.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict6.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 7: printf("한글 뜻 : %s\n영어 단어 : ", dict7.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict7.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 8: printf("한글 뜻 : %s\n영어 단어 : ", dict8.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict8.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;

	case 9: printf("한글 뜻 : %s\n영어 단어 : ", dict9.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict9.eng, answer)) printf("정답!\n");
		else printf("오답!\n");
		break;
	
	default:
		break;
	}
	system("pause");
}
void problem7() { //10명의 학생 성적 입력 후 성적 높은 사람부터 출력
	printf("7. 점수와 이름을 저장할 실수형변수와 문자열을 멤버로 갖는 student 구조체를 선언한 후 사용자로부터 10개의 구조체 값을 입력받습니다.\n저장된 10개 구조체를 성적순으로 정렬한 후 성적이 높은 사람부터 이름을 출력하도록 하세요\n");
	Student* S = no;
	S = (Student*)malloc(sizeof(Student) * 10);

	for (int i = 0; i < 10; i++) {
		printf("%d번째 학생 이름 : ", i+1);
		scanf_s("%s", &S[i].name, 20);
		printf("성적 : ");
		scanf_s("%f", &S[i].grade);
	}
	bubbleSort(S);
	for (int i = 0; i < 10; i++) {
		printf("%d등\t%s\t%0.2f점\n", i+1, S[i].name, S[i].grade);
	}
	free(S);
	system("pause");
}
int main() {
	int choiceNum;
	while (1) {
		system("cls");
		printf("1번. 1차원 배열 출력 | 2번. 2차원 배열 출력 | 3번. 정수 바꾸기 | 4번. 평균값 구하기\n5번. 국영수 점수 입력 평균출력 | 6번. 영단어 맞추기 게임 | 7번. 성적 높은순\n");
		printf("번호 선택(1~7)\n");
		scanf_s("%d", &choiceNum);
		switch (choiceNum) {
		case 1: problem1();
			break;
		case 2: problem2();
			break;
		case 3: problem3();
			break;
		case 4: problem4();
			break;
		case 5: problem5();
			break;
		case 6: problem6();
			break;
		case 7: problem7();
			break;
		default: goto END;
		}
	}
END:
	return 0;
}