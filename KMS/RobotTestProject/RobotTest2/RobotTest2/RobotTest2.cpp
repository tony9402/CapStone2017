// RobotTest2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int deg = 0;

#define height 12
#define width 20
#define PI 3.14159265358979
#define rad(x) (((x) / 90) * PI / 2)

typedef struct R {
	struct R *Rprev;
	struct R *Rnext;
	int x;
	int y;
}route;

typedef struct node {
	struct node *prev;
	struct node *next;
	int x;
	int y;
}Node;

route *Rhead = (route*)malloc(sizeof(route));
route *Rtail = (route*)malloc(sizeof(route));
Node *head = (Node*)malloc(sizeof(Node));
Node *tail = (Node*)malloc(sizeof(Node));
int size = 0;

void init();
void Searching(int(*robot)[width],int(*room)[width], int *px, int *py);
void Saving(int(*room)[width], int(*robot)[width]);
void Turn(int TurnValue);
void GO(int(*room)[width], int *px, int *py);
void Showing(int(*robot)[width], int(*room)[width], int *px, int *py);
int DoorTurnCheckFun(int(*room)[width], int *px, int *py);
int RoadTurnCheckFun(int(*room)[width], int *px, int *py, int *MyWay);
void degChecking();
void InputList(Node *Now, int *px, int *py);
void Delete();
void Route(int(*robot)[width], int *px, int *py, int x, int y);
void routeShow();

int main()
{
	int room[height][width] =
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,2,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int robot[height][width] =
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
		0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,2,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	init();
	Sleep(1000);
	int x = 1, y = 1;
	int *px, *py;
	px = &x;
	py = &y;
	Searching(robot,room, px, py);
    return 0;
}

void Searching(int(*robot)[width],int(*room)[width], int *px, int *py) {
	Node *Now = (Node*)malloc(sizeof(Node));
	int DoorTurnCheck = 5;
	int RoadTurnCheck = 5;
	int Chk = 5;
	int *MyWay;
	MyWay = &Chk;
	bool Check;
	while (1)
	{
		DoorTurnCheck = 5;
		RoadTurnCheck = 5;
		Showing(robot, room, px, py);
		DoorTurnCheck = DoorTurnCheckFun(room, px, py);
		if (DoorTurnCheck != 5) {
			Node *Now = (Node*)malloc(sizeof(Node));
			Turn(DoorTurnCheck);
			*MyWay = DoorTurnCheck;
			GO(room, px, py);
			InputList(Now, px, py);
		}
		else {
			RoadTurnCheck = RoadTurnCheckFun(room, px, py, MyWay);
			if (RoadTurnCheck != 5) {
				Turn(RoadTurnCheck);
				*MyWay = RoadTurnCheck;
				GO(room, px, py);
			}
			else {
				if (size != 0) {
//******************************************************************************************************************************************************************
					//Using Searching Version 2
					//Searching2(robot, px, py, tail->prev->x, tail->prev->y);
					Route(robot, px, py, tail->prev->x, tail->prev->y);
					if (Rtail->Rprev->x != NULL) {
						//routeShow();
						route *Now = (route*)malloc(sizeof(route));
						Now = Rhead;
						while (Now != Rtail->Rprev) {

							*px = Now->x;
							*py = Now->y;
							//printf("%d %d\n", *px, *py);
							Showing(robot, room, px, py);	
							Now = Now->Rnext;
						}
						*px = Rtail->x;
						*py = Rtail->y;
						//printf("%d %d\n", *px, *py);
						Showing(robot, room, px, py);
					}
					//Delete();
//******************************************************************************************************************************************************************
				}
				else {
					return;
				}
			}
		}
	}
}

void Saving(int(*room)[width], int(*robot)[width]) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			room[i][j] = robot[i][j];
		}
	}
	return;
}

void Showing(int(*robot)[width], int(*room)[width], int *px, int *py)
{
	system("cls");
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (i == *py && j == *px) {
				printf(" 5");
			}
			else {
				printf(" %d", room[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			if (i == *py && j == *px) {
				printf(" 5");
			}
			else {
				printf(" %d", robot[i][j]);
			}
		}
		printf("\n");
	}
	return;
}

int DoorTurnCheckFun(int(*room)[width], int *px, int *py) {
	for (int i = 0; i < 3; i++) {
		if (room[*py - (int)cos(rad(deg + 90 * (i - 1)))][*px + (int)sin(rad(deg + 90 * (i - 1)))] == 2) {
			return i - 1;
		}
	}
	return 5;
}

int RoadTurnCheckFun(int(*room)[width], int *px, int *py, int *MyWay) {
	if (room[*py - (int)cos(rad(deg))][*px + (int)sin(rad(deg))] == 1) {
		if (-1 == *MyWay) {
			*MyWay = 5;
			return -1;
		}
	}
	if (room[*py - (int)cos(rad(deg - 90))][*px + (int)sin(rad(deg - 90))] == 1) {
		if (0 == *MyWay) {
			*MyWay = 5;
			return 0;
		}
	}
	if (room[*py - (int)cos(rad(deg + 90))][*px + (int)sin(rad(deg + 90))] == 1) {
		if (1 == *MyWay) {
			*MyWay = 5;
			return 1;
		}
	}
	if (room[*py - (int)cos(rad(deg))][*px + (int)sin(rad(deg))] == 1)return -1;
	if (room[*py - (int)cos(rad(deg - 90))][*px + (int)sin(rad(deg - 90))] == 1)return 0;
	if (room[*py - (int)cos(rad(deg + 90))][*px + (int)sin(rad(deg + 90))] == 1)return 1;
	return 5;
}

void Turn(int TurnValue)
{
	switch (TurnValue)
	{
	case 0:
		deg -= 90;
		degChecking();
		break;
	case 1:
		deg += 90;
		degChecking();
		break;
	case -1:
	default:
		break;
	}
	return;
}

void GO(int(*room)[width], int *px, int *py)
{
	if (room[*py - (int)cos(rad(deg))][*px + (int)sin(rad(deg))] != 2) {
		room[*py][*px] = 0;
	}
	*px += (int)sin(rad(deg));
	*py -= (int)cos(rad(deg));
	return;
}

void degChecking() {
	while (!(deg > -180 && deg <= 180)) {
		deg = deg > 180 ? deg - 360 : deg <= -180 ? deg + 360 : deg;
	}
	return;
}

void InputList(Node *Now, int *px, int *py)
{
	Node *New = (Node*)malloc(sizeof(Node));
	Now = tail;
	New->x = *px;
	New->y = *py;
	if (tail->prev == head) {
		tail->prev = New;
		New->next = tail;
		head->next = New;
		New->prev = head;
	}
	else {
		tail->prev->prev->next = New;
		New->prev = tail->prev->prev;
		tail->prev = New;
		New->next = tail;
	}
	size++;
	return;
}

void init()
{
	head->next = tail;
	tail->prev = head;
	head->prev = NULL;
	tail->next = NULL;
	Rhead->Rnext = Rtail;
	Rtail->Rprev = Rhead;
	Rhead->Rprev = NULL;
	Rtail->Rnext = NULL;

	return;
}

void Delete()
{
	Node *Now = (Node*)malloc(sizeof(Node));
	Now = tail->prev;
	tail->prev->prev->next = tail;
	tail->prev = tail->prev->prev;
	free(Now);
	size--;
	return;
}

void Route(int (*robot)[width], int *px ,int *py, int x, int y)
{
	route *Now = (route*)malloc(sizeof(route));
	Now = Rtail;
	Now->x = x;
	Now->y = y;
	while (x != *px || y != *py) {
		route *New = (route*)malloc(sizeof(route));
		int Checkx = x - *px < 0 ? -1 : x - *px > 0 ? 1 : 0;
		int Checky = y - *py < 0 ? -1 : y - *py > 0 ? 1 : 0;
		robot[y][x] = 0;
		if (robot[y-Checky][x] == 1) {
			y -= Checky;
		}
		else if (robot[y][x - Checkx] == 1) {
			x -= Checkx;
		}
		else if (robot[y + Checky][x] == 1) {
			y += Checky;
		}
		else if (robot[y][x + Checkx] == 1) {
			x += Checkx;
		}
		else {
			return;
		}
		New->x = x;
		New->y = y;
		Now->Rprev->Rnext = New;
		New->Rprev = Now->Rprev;
		Now->Rprev = New;
		New->Rnext = Now;
		Now = Now->Rprev;
	}
	Rhead->x = *px;
	Rhead->y = *py;
	return;
}

void routeShow()
{
	route *Test = (route*)malloc(sizeof(route));
	Test = Rhead;
	while (Test != Rtail->Rprev) {
		printf("%d %d\n", Test->x, Test->y);
	}
	printf("%d %d\n", Rtail->x, Rtail->y);
	return;
}