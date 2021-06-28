#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define no {NULL}

void func1(int* arr, int len) { //1�����迭 ��� (1��)
	for (int i = 0; i < len; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
void func2(int** arr, int x, int y) {//2�����迭 ��� (2��)
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("(%d)\t", arr[i][j]);
		}
		printf("\n");
	}
}
void swapNum(int* a, int* b) { //�ΰ��� �� �ڸ� �ٲٱ� (3��)
	int temp = *a;
	*a = *b;
	*b = temp;
}
int funcAvg(int* arr, int len, int* result) { //��հ� ���� (4, 5��)
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
		//printf("%d\t", arr[i]);
	}
	result = sum / len;
	return result;
}
typedef struct { //������ ��ȣ, ���ܾ�, �ѱ۶� ����ü (6��)
	int number;
	char eng[20];
	char kor[40];
}Dictionary;

typedef struct { //�л� ���� ����ü (7��)
	char name[20];
	float grade;
}Student;

void bubbleSort(Student* S) { //���� ���� (7��)
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

void problem1() { //1���� �迭�� ���޹޾� �迭�� ��Ҹ� ��� ����ϴ� �Լ� func1
	printf("1. 1���� �迭�� ���޹޾� �迭�� ��Ҹ� ��� ����ϴ� �Լ��� ����\n");
	int size;
	printf("�迭 ���� : ");
	scanf_s("%d", &size);
	int* numArr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		numArr[i] = i+1;
	}
	func1(numArr, size);
	free(numArr);
	system("pause");
}
void problem2() { //2���� �迭�� ���޹޾� �迭�� ��Ҹ� ��� ���� ��� func2
	printf("2. 2���� �迭�� ���޹޾� �迭�� ��Ҹ� 2������ ��� ���� ���");
	int positX;
	int positY;
	printf("��� ũ��(�Է¼���:x y) : ");
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
void problem3() { //2���� ������ �Է¹޾� call-by-reference�� ���� �ٲ��ִ� �Լ� swapNum
	printf("3. 2�� ���� ���� �Է¹޾� �� ���� ���� �ٲ��ִ� �Լ��� ���� (call-by-reference�� ����)\n");
	int num1, num2 = 0;
	printf("�� ���� ���� �Է� : ");
	scanf_s("%d %d", &num1, &num2);
	printf("���� �� : %d %d\n", num1, num2);
	swapNum(&num1, &num2);
	printf("���� �� : %d %d\n", num1, num2);
	system("pause");
}
void problem4() { //�迭�� ������ ���� �����͸� ���޹޾� �迭�� ��� ��ҵ� ��հ��� ������ �����ͷ� ��ȯ
	printf("4. �迭�� ������ ������ �����͸� ���޹޾� �迭 ��� ����� ����� ������ �����͸� ���� ��ȯ�ϴ� �Լ��� ����\n");
	int size;
	int avg = 0;
	int* avgP = &avg;
	printf("�迭 ���� : ");
	scanf_s("%d", &size);
	int* numArr = (int*)malloc(sizeof(int) * size);
	printf("�迭�� �� �ִ� �� : ");
	for (int i = 0; i < size; i++) {
		//numArr[i] = i + 1;
		scanf_s("%d", &numArr[i], size);
		printf("%d\t", numArr[i]);
	}
	printf("\n��� �� : %d\n", funcAvg(numArr, size, avgP));
	free(numArr);
	system("pause");
}
void problem5() { //�л� 5���� �̸�, ��,��,�� ���� �Է� ���� �� ������ ��� �� ���
	printf("5. 5x4 ������ 2���� �迭 ���� �� ����ڷκ��� 5���� ����, ����, ����, ������ �Է¹޽��ϴ�.\n�� ���� ������ ���� �� ������ ����� �����ϴµ� 4������ ������ �Լ��� �̿��� �����ϵ��� �����ϼ���\n");
	char name[5][20] = no;
	int grade[5][4] = no;
	int avg = 0;
	int* avgP = &avg;

	for (int i = 0; i < 5; i++) {
		printf("%d�� ° �л� �̸� : ", i + 1);
		scanf_s("%s", name[i], 5);
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				printf("���� ���� : ");
				scanf_s("%d", &grade[i][j]);
			}
			else if (j == 1) {
				printf("���� ���� : ");
				scanf_s("%d", &grade[i][j]);
			}
			else if (j == 2) {
				printf("���� ���� : ");
				scanf_s("%d", &grade[i][j]);
			}
			else grade[i][3] = funcAvg(grade[i], 3, avgP);
		}
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("|\t%s �л��� �� ���� ��� ������ %d\t|\n", name[i], grade[i][3]);
	}
	system("pause");
}
void problem6() { //�ܾ��� ���ܾ�� �ѱ۶�, ������ ��ȣ�� ���� ����ü�� �̿��ؼ� �ܾ� ���߱� ����(��ҹ��� ���� ����)
	printf("6. �ܾ��� ����� �ѱ� ���ڿ�, ��ȣ�� ������ ����� ���� ����ü 10���� ����� �ʱ�ȭ�ϼ���.\n������ ����ü ���� 10�� �� �ϳ��� �ѱ� �ܾ ����� �� ���� �ܾ �Է¹޾� �������� Ʋ�ȴ��� ����մϴ�\n");
	Dictionary dict1 = { 1, "mirror", "�ſ�" };
	Dictionary dict2 = { 2, "temperature","�µ�" };
	Dictionary dict3 = { 3, "traffic", "����" };
	Dictionary dict4 = { 4, "hobby", "���" };
	Dictionary dict5 = { 5, "bill", "����" };
	Dictionary dict6 = { 6, "regret", "��ȸ" };
	Dictionary dict7 = { 7, "evil", "��" };
	Dictionary dict8 = { 8, "tail", "����" };
	Dictionary dict9 = { 9, "voice", "��Ҹ�" };
	Dictionary dict10 = { 10, "guest","�մ�" };

	char answer[20];
	srand((unsigned int)time(NULL));
	int num = rand() % 10;
	switch (num){
	case 0: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict10.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict10.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;
		
	case 1: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict1.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict1.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 2: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict2.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict2.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 3: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict3.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict3.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 4: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict4.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict4.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 5: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict5.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict5.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 6: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict6.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict6.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 7: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict7.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict7.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 8: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict8.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict8.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;

	case 9: printf("�ѱ� �� : %s\n���� �ܾ� : ", dict9.kor);
		scanf_s("%s", answer, 20);
		if (!stricmp(dict9.eng, answer)) printf("����!\n");
		else printf("����!\n");
		break;
	
	default:
		break;
	}
	system("pause");
}
void problem7() { //10���� �л� ���� �Է� �� ���� ���� ������� ���
	printf("7. ������ �̸��� ������ �Ǽ��������� ���ڿ��� ����� ���� student ����ü�� ������ �� ����ڷκ��� 10���� ����ü ���� �Է¹޽��ϴ�.\n����� 10�� ����ü�� ���������� ������ �� ������ ���� ������� �̸��� ����ϵ��� �ϼ���\n");
	Student* S = no;
	S = (Student*)malloc(sizeof(Student) * 10);

	for (int i = 0; i < 10; i++) {
		printf("%d��° �л� �̸� : ", i+1);
		scanf_s("%s", &S[i].name, 20);
		printf("���� : ");
		scanf_s("%f", &S[i].grade);
	}
	bubbleSort(S);
	for (int i = 0; i < 10; i++) {
		printf("%d��\t%s\t%0.2f��\n", i+1, S[i].name, S[i].grade);
	}
	free(S);
	system("pause");
}
int main() {
	int choiceNum;
	while (1) {
		system("cls");
		printf("1��. 1���� �迭 ��� | 2��. 2���� �迭 ��� | 3��. ���� �ٲٱ� | 4��. ��հ� ���ϱ�\n5��. ������ ���� �Է� ������ | 6��. ���ܾ� ���߱� ���� | 7��. ���� ������\n");
		printf("��ȣ ����(1~7)\n");
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