#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <WinBase.h>
#include <time.h>
#include <conio.h>

#define upkey 72// �궨��
#define downkey 80
#define leftkey 75
#define rightkey 77

//�ÿ���Ľ���������ѡ�񣬸����˵����Ͳ����������ּ����
// �ó����ʹ�ûس�ȷ�������н�����Ҳ����ͨ����ĸ�����н���
//���嵥����
struct singleADT
{
	int data;
	struct singleADT* next;
};


int singleLEN = sizeof(struct singleADT);
//��������
void gotoxy(int x, int y);
void HideCursor();
void show(int line);
void menu_control(struct singleADT* pt);
void showinput();
struct singleADT* creatlist(struct singleADT* head);
void showlist(struct singleADT* head);
struct singleADT* exchangeSingleDouble(struct singleADT* head);
struct singleADT* findMiddle(struct singleADT* head);
struct singleADT* reversallist(struct singleADT* head);
struct singleADT* deleteSingle(struct singleADT* head);
struct singleADT* deleteAllSingleADT(struct singleADT* head);


int main() {
    struct singleADT* head = NULL;
	HideCursor();
    menu_control(head);
	

}

void menu_control(struct singleADT* pt)// �˵����ƺ���
{
    char c1, c2, ch;
    int line, sec;
    long long j;// ��¼ʱ��
    time_t t;
    struct tm* lt;
    struct singleADT* head = NULL;// ���ڴ�����ݵ�����
    struct singleADT* head1 = NULL;// ���ڴ����ż�����������
    char choose;

    while (1)
    {
        system("cls");   //����
        system("color 00");  //���ñ�������Ļ��ɫ
        Beep(2000, 250); //������ʾ
        HideCursor();    //���ع��
        showinput(); //��ʾ�˵�
        line = 1;// ����λ��
        gotoxy(0, line); 
        printf("\033[1;34;45mA.��������\n\033[0m"); //�������

        for (; (c1 = _getch()) != '\r';)  // ��ȡ���°����Ĳ���
        {
            //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
            if (c1 == -32)
            {
                c2 = _getch(); //��ȡ����
                ch = c2;
                if (ch == upkey && line != 1)
                {
                    line--;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line != 9)
                {
                    line++;
                    show(line);
                    continue;
                }
                else if (ch == upkey && line == 1)
                {
                    line = 9;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line == 9)
                {
                    line = 1;
                    show(line);
                    continue;
                }
            }

            if (c1 == 'a' || c1 == 'A')
            {
                system("cls");   //����
                gotoxy(0, 0);    //���λ��
                line = 0;
                head = creatlist(head);
                Sleep(500);
                break;
            }
            else if (c1 == 'b' || c1 == 'B')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                head1 = exchangeSingleDouble(head);
                break;
            }
            else if (c1 == 'c' || c1 == 'C')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                showlist(head1);
                Sleep(1000);
                break;
            }
            else if (c1 == 'd' || c1 == 'D')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                findMiddle(head);
                break;
            }
            else if (c1 == 'e' || c1 == 'E')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                getchar();
                head = reversallist(head);
                Sleep(500);
                break;
            }
            else if (c1 == 'f' || c1 == 'F')
            {
                system("cls");
                gotoxy(0, 0);
                showlist(head);
                line = 0;
                break;
            }
            else if (c1 == 'g' || c1 == 'G')
            {
                system("cls");
                gotoxy(0, 0);
                head = deleteSingle(head);
                line = 0;
                break;
            }
            else if (c1 == 'h' || c1 == 'H')
            {
                system("cls");
                gotoxy(0, 0);
                head = deleteAllSingleADT(head);
                line = 0;
                break;
            }
            else if (c1 == 'i' || c1 == 'I')
            {
                system("cls");
                gotoxy(0, 0);
                exit(0);
                line = 0;
                break;
            }
        }

        if (line == 1)
        {
            system("cls");
            gotoxy(0, 0);
            head = creatlist(head);
            Sleep(500);
        }
        else if (line == 2)
        {
            system("cls");
            gotoxy(0, 0);
            head1 = exchangeSingleDouble(head);
            Sleep(1000);
        }
        else if (line == 3)
        {
            system("cls");
            gotoxy(0, 0);
            showlist(head1);
            Sleep(1000);
        }
        else if (line == 4)
        {
            system("cls");
            gotoxy(0, 0);
            findMiddle(head);
            Sleep(500);
        }
        else if (line == 5)
        {
            system("cls");
            gotoxy(0, 0);
            head = reversallist(head);
            Sleep(500);
        } 
        else if (line == 6)
        {
            system("cls");
            gotoxy(0, 0);
            showlist(head);
            Sleep(1000);
        }
        else if (line == 7)
        {
            system("cls");
            gotoxy(0, 0);
            head = deleteSingle(head);
        }
        else if (line == 8)
        {
            system("cls");
            gotoxy(0, 0);
            head = deleteAllSingleADT(head);
        }
        else if (line == 9)
        {
            system("cls");
            gotoxy(0, 0);
            exit(0);
            break;
        }
        time(&t);
        lt = localtime(&t); // ��ȡʱ��ṹ��
        sec = lt->tm_sec;

        do   // ������ʱͣ����ʱ��
        {
            time(&t);
            lt = localtime(&t);
            j = lt->tm_sec - sec;
            if (j < 0) j = j + 60;
        } while (j < 1);
    }
}

//��ʼ����չʾ
void showinput() {
	printf("==============\n");
	printf("A.��������\n");
	printf("B.��������ż����\n");
	printf("C.������������ż�����������\n");
	printf("D.Ѱ�ҵ������м���\n");
	printf("E.��ת����\n");
	printf("F.��������\n");
	printf("G.ɾ��������\n");
	printf("H.�������\n");
	printf("I.�˳�\n");
	printf("==============\n");
}

//����������
struct singleADT* creatlist(struct singleADT* head) {
    Beep(2000, 250); //������ʾ
	struct singleADT* p1, * p2;
    if (head == NULL) {
       p1 = p2 = (struct singleADT*)malloc(singleLEN);
       head = p1;
    }
    else
    {
        p1 = head;
        for (; p1->next != NULL; p1 = p1->next) {}//�ҵ����һ���ڵ�
        p2 = (struct singleADT*)malloc(singleLEN);
    }
    p1->next = p2;
	printf("����������\n");
	scanf_s("%d", &p2->data);
    printf("�����������");
    p2->next = NULL;
	return head;
};

// ����ƶ��ĺ���
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

// ���ع��
void HideCursor()
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);
}

// ���������һ��
void show(int line)
{
	gotoxy(0, 0);
	showinput();
	gotoxy(0, line);
	if (line == 1)
		printf("\033[1;34;45mA.��������\n\033[0m");
	if (line == 2)
		printf("\033[1;34;45mB.��������ż����\n\033[0m");
	if (line == 3)
		printf("\033[1;34;45mC.������������ż�����������\n\033[0m"); 
	if (line == 4)
		printf("\033[1;34;45mD.Ѱ�ҵ������м���\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45mE.��ת����\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45mF.��������\n\033[0m");
    if (line == 7)
        printf("\033[1;34;45mG.ɾ��������\n\033[0m");
    if (line == 8)
        printf("\033[1;34;45mH.�������\n\033[0m");
    if (line == 9)
        printf("\033[1;34;45mI.�˳�\n\033[0m");
}

//������������ֵ
void showlist(struct singleADT* head) {
    if (head == NULL) {
        printf("�㻹û���������ݣ����������ݣ�����");
        return;
    }
    printf("�����е��������£�\n");
    for (; head != NULL;head = head->next) {
        printf("%d\t", head->data);
    }
}

//��������ż����
struct singleADT* exchangeSingleDouble(struct singleADT* head) {
    if (head == NULL ) {
        printf("�㻹û�����������~~");
        return NULL;
    }
    if (head->next == NULL) {
        printf("���������һ�������~~");
        return NULL;
    }
    struct singleADT* head1 = NULL;
    struct singleADT* p1, * p2;
    p1 = p2 = (struct singleADT*)malloc(singleLEN);
    for (; head != NULL; head = head->next) {
        if (head1 == NULL) {
            head1 = p1;
            p2 = (struct singleADT*)malloc(singleLEN);
            p1->next = p2;
            p1->data = head->data;

        }
        else
        {
            p1 = p1->next;
            p1->data = head->data;
            p2 = (struct singleADT*)malloc(singleLEN);
            p1->next = p2;
        }
    }
    p1->next = NULL;
    struct singleADT* p3, * p4 = NULL;
    p3 = p4 = head1;
    //p4 = p4->next;
    int cnt=0;//���ڼ�¼�����Ĵ�������Ϊ0����ȫΪ���ż
    for (; p4 != NULL && p3 != NULL;) {
        if ((p3->data % 2) != (p4->data % 2)) {
            int mid = p3->data;
            p3->data = p4->data;
            p4->data = mid;
            p3 = p4->next;
            p4 = p4->next;
            cnt++;
        }
        else
        {
            p4 = p4->next;
        }
    }
    if (cnt == 0) {
        if (head1->next->data % 2 == 0) {
            printf("��ôȫ��ż��������");
        }
        else
        {
            printf("��ôȫ������������");
        }
    }
    else
    {
        printf("������ϣ�����");
    }
    return head1;
}

//Ѱ�������м���
struct singleADT* findMiddle(struct singleADT* head) {
    if (head == NULL) {
        printf("�㻹û�����������~~");
        return NULL;
    }
    if (head->next == NULL) {
        printf("���������һ�������~~");
        return NULL;
    }
    struct singleADT* slow, * fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("�м�������Ϊ%d", slow->data);
    return slow;
}

//��ת����
struct singleADT* reversallist(struct singleADT* head) {
    if (head == NULL) {
        printf("�㻹û�����������~~");
        return NULL;
    }
    if (head->next == NULL) {
        printf("���������һ�������~~");
        return head;
    }
    struct singleADT* p1 = NULL;
    struct singleADT* p2 = head;
    while (p2 != NULL) {
        struct singleADT* next = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = next;
    }
    printf("��ת�ɹ�������");
    return p1;
}

//ɾ��������
struct singleADT* deleteSingle(struct singleADT* head) {
    if (head == NULL) {
        printf("�㻹û�����������~~");
        return NULL;
    }
    int removedata;//��¼Ҫɾ��������
    int cnt = 0;//��¼�Ƿ�ɾ��������
    struct singleADT* p1,*p2;
    p1 = head;
    printf("��������Ҫɾ�������ݣ�");
    scanf_s("%d", &removedata);
    for (; p1->next != NULL; p1 = p1->next) {
        if (p1->next->data == removedata) {
            p2 = p1->next;
            p1->next = p1->next->next;
            free(p2);
            cnt++;
            break;
        }
    }
    if (cnt == 1) {
        printf("ɾ���ɹ�������");
    }
    else
    {
        printf("û�и����ݣ�����");
    }
    return head;
}

//�������
struct singleADT* deleteAllSingleADT(struct singleADT* head) {
    if (head == NULL) {
        printf("�㻹û�����������~~");
        return NULL;
    }
    else
    {
        printf("��ճɹ�������\n");
        struct singleADT* p;
        for (; head->next != NULL;) {
            p = head->next;
            free(head);
            head = p;
        }
        return NULL;
    }
}
