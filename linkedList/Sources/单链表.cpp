#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <WinBase.h>
#include <time.h>
#include <conio.h>

#define upkey 72// 宏定义
#define downkey 80
#define leftkey 75
#define rightkey 77

//用课设的界面来进行选择，高亮菜单，就不用输入数字检测了
// 该程序可使用回车确定来进行交互，也可以通过字母来进行交互
//定义单链表
struct singleADT
{
	int data;
	struct singleADT* next;
};


int singleLEN = sizeof(struct singleADT);
//函数声明
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

void menu_control(struct singleADT* pt)// 菜单控制函数
{
    char c1, c2, ch;
    int line, sec;
    long long j;// 记录时间
    time_t t;
    struct tm* lt;
    struct singleADT* head = NULL;// 用于存放数据的链表
    struct singleADT* head1 = NULL;// 用于存放奇偶调换后的链表
    char choose;

    while (1)
    {
        system("cls");   //清屏
        system("color 00");  //设置背景及字幕颜色
        Beep(2000, 250); //声音提示
        HideCursor();    //隐藏光标
        showinput(); //显示菜单
        line = 1;// 高亮位置
        gotoxy(0, line); 
        printf("\033[1;34;45mA.输入数据\n\033[0m"); //输出高亮

        for (; (c1 = _getch()) != '\r';)  // 读取上下按键的操作
        {
            //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
            if (c1 == -32)
            {
                c2 = _getch(); //读取按键
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
                system("cls");   //清屏
                gotoxy(0, 0);    //光标位置
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
        lt = localtime(&t); // 获取时间结构体
        sec = lt->tm_sec;

        do   // 用来计时停留的时间
        {
            time(&t);
            lt = localtime(&t);
            j = lt->tm_sec - sec;
            if (j < 0) j = j + 60;
        } while (j < 1);
    }
}

//开始界面展示
void showinput() {
	printf("==============\n");
	printf("A.输入数据\n");
	printf("B.单链表奇偶调换\n");
	printf("C.遍历单链表奇偶调换后的链表\n");
	printf("D.寻找单链表中间结点\n");
	printf("E.反转链表\n");
	printf("F.遍历链表\n");
	printf("G.删除链表结点\n");
	printf("H.清空链表\n");
	printf("I.退出\n");
	printf("==============\n");
}

//创建单链表
struct singleADT* creatlist(struct singleADT* head) {
    Beep(2000, 250); //声音提示
	struct singleADT* p1, * p2;
    if (head == NULL) {
       p1 = p2 = (struct singleADT*)malloc(singleLEN);
       head = p1;
    }
    else
    {
        p1 = head;
        for (; p1->next != NULL; p1 = p1->next) {}//找到最后一个节点
        p2 = (struct singleADT*)malloc(singleLEN);
    }
    p1->next = p2;
	printf("请输入数字\n");
	scanf_s("%d", &p2->data);
    printf("数据输入完毕");
    p2->next = NULL;
	return head;
};

// 光标移动的函数
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

// 隐藏光标
void HideCursor()
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);
}

// 输出高亮的一行
void show(int line)
{
	gotoxy(0, 0);
	showinput();
	gotoxy(0, line);
	if (line == 1)
		printf("\033[1;34;45mA.输入数据\n\033[0m");
	if (line == 2)
		printf("\033[1;34;45mB.单链表奇偶调换\n\033[0m");
	if (line == 3)
		printf("\033[1;34;45mC.遍历单链表奇偶调换后的链表\n\033[0m"); 
	if (line == 4)
		printf("\033[1;34;45mD.寻找单链表中间结点\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45mE.反转链表\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45mF.遍历链表\n\033[0m");
    if (line == 7)
        printf("\033[1;34;45mG.删除链表结点\n\033[0m");
    if (line == 8)
        printf("\033[1;34;45mH.清空链表\n\033[0m");
    if (line == 9)
        printf("\033[1;34;45mI.退出\n\033[0m");
}

//输出链表里面的值
void showlist(struct singleADT* head) {
    if (head == NULL) {
        printf("你还没有输入数据，请输入数据！！！");
        return;
    }
    printf("链表中的数据如下：\n");
    for (; head != NULL;head = head->next) {
        printf("%d\t", head->data);
    }
}

//单链表奇偶调换
struct singleADT* exchangeSingleDouble(struct singleADT* head) {
    if (head == NULL ) {
        printf("你还没有输入数据喔~~");
        return NULL;
    }
    if (head->next == NULL) {
        printf("你才输入了一个数据喔~~");
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
    int cnt=0;//用于记录操作的次数，若为0，则全为奇或偶
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
            printf("怎么全是偶数！！！");
        }
        else
        {
            printf("怎么全是奇数！！！");
        }
    }
    else
    {
        printf("调换完毕！！！");
    }
    return head1;
}

//寻找链表中间结点
struct singleADT* findMiddle(struct singleADT* head) {
    if (head == NULL) {
        printf("你还没有输入数据喔~~");
        return NULL;
    }
    if (head->next == NULL) {
        printf("你才输入了一个数据喔~~");
        return NULL;
    }
    struct singleADT* slow, * fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("中间结点数据为%d", slow->data);
    return slow;
}

//反转链表
struct singleADT* reversallist(struct singleADT* head) {
    if (head == NULL) {
        printf("你还没有输入数据喔~~");
        return NULL;
    }
    if (head->next == NULL) {
        printf("你才输入了一个数据喔~~");
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
    printf("反转成功！！！");
    return p1;
}

//删除链表结点
struct singleADT* deleteSingle(struct singleADT* head) {
    if (head == NULL) {
        printf("你还没有输入数据喔~~");
        return NULL;
    }
    int removedata;//记录要删除的数据
    int cnt = 0;//记录是否删除了数据
    struct singleADT* p1,*p2;
    p1 = head;
    printf("请输入你要删除的数据：");
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
        printf("删除成功！！！");
    }
    else
    {
        printf("没有该数据！！！");
    }
    return head;
}

//清空链表
struct singleADT* deleteAllSingleADT(struct singleADT* head) {
    if (head == NULL) {
        printf("你还没有输入数据喔~~");
        return NULL;
    }
    else
    {
        printf("清空成功！！！\n");
        struct singleADT* p;
        for (; head->next != NULL;) {
            p = head->next;
            free(head);
            head = p;
        }
        return NULL;
    }
}
