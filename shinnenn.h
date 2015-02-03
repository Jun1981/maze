
#pragma once

#include	<stdio.h>
#include	<conio.h>
#include	<windows.h>
#include	<stdlib.h>



#include "maze.h"

//#define map20x20
#define map50x30
//�}�b�v�T�C�Y�@20x20

#ifdef map20x20

#define x_size 20 
#define y_size 20
#endif

//�}�b�v�T�C�Y�T�O���R�O
#ifdef map50x30
#define x_size 50  
#define y_size 30
#endif 


enum mstat{ aile = 0, wall = 1 };


//���@�֌W
typedef struct MAP{

	int dir;//���@/�����Ă������
	int mv;//���̈ړ�
	Pos now;//���݈ʒu
	Pos old;//�ЂƂO�̈ʒu

	int cnt[x_size][y_size];//�ʍs�񐔃J�E���g
	//int sortcnt[4];//
	//int sortdir[4];//
	//
	enum mstat stat[x_size][y_size];//������W���ǂ��ʘH��

}map;
extern map m;