#include"maze.h"
#include "shinnenn.h"

#include "s_sort.h"
#include <stdlib.h>//qsort$BMQ(B

//#include "move.h"

#include "s_move.h"

#include "kabegiwa.h"

int t_cnt[4] = { 0 };//�ꎞ�J�E���g



//void r_move(void);
//int mv_chk(mp* x);//$B<~0O$NDL9T2s?t$r%A%'%C%/$70lHV>/$J$$J}8~$XJV$9!J>e#0!$1&#1!$2<#2!":8#3!K(B
static int dirsort(void);//$B<~0O$NDL9T2s?t%A%'%C%/$7$F0lHV>/$J$$J}8~$rJV$9(B
static int mv_chk(mp* x);


void s_move(void){
	int same;

	//if (m.cnt[m.now.x][m.now.y] == 6){
	// m.cnt[m.now.x][m.now.y] = 1000; //$BJI(B
	//}
	m.now = getCurrentPosition();//$B8=:_0LCV$r<hF@(B
	same = mv_chk(&m);


	m.cnt[m.now.x][m.now.y]++; //���݈ʒu�J�E���g


	switch (m.dir){
	case 0://��

		//�O�ƍ��W���ς���ĂȂ����������O��ǂƂ���
		if (same == 1){ m.cnt[m.now.x][m.now.y - 1] = 1000; }



		//�ǂ̋߂��ŃS�[���`�F�b�N
		if (kabegiwa() != -1){
			m.dir = m.mv = kabegiwa(); break;
		}


		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;


		//�オ�O��������i��
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ m.dir = m.mv = 0; break; }

		//�E���O��������i��
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ m.dir = m.mv = 1;  break; }
		
		//�����O��������i��
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ m.dir = m.mv = 3;  break; }
		//�����O��������i��
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ m.dir = m.mv = 2;  break; }

		m.dir = m.mv = dirsort();





		//�O�R�����̉񐔂��`�F�b�N���Ĉ�ԏ��Ȃ���������(�i�s�����D��j




		break;
	case 1://�E		
		//�O�ƍ��W���ς���ĂȂ����������O��ǂƂ���
		if (same == 1){ m.cnt[m.now.x + 1][m.now.y] = 1000; }


		if (self_chk == 1)
			if (m.cnt[2][12] = 1000){
			self_chk = 2;
			m.dir = m.mv = DirDown;
			break;

			}

		if (self_chk == 3){

			m.dir = m.mv = DirRight;
			break;


		}



		//�ǂ̋߂��ŃS�[���`�F�b�N
		if (kabegiwa() != -1){
			m.dir = m.mv = kabegiwa(); break;
		}



		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;


		//�E���O��������i��
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ m.dir = m.mv = 1;  break; }
		//�����O��������i��
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ m.dir = m.mv = 2;  break; }
	

		//�オ�O��������i��
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ m.dir = m.mv = 0; break; }
		//�����O��������i��
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ m.dir = m.mv = 3;  break; }


		m.dir = m.mv = dirsort();








		break;
	case 2://��




		if (self_chk == 2){

			if (m.now.x = 1 && m.now.y == 15){
				self_chk = 3;
				m.dir = m.mv = DirRight;
			}
			else
				m.dir = m.mv = DirDown;
			break;

		}





		//�O�ƍ��W���ς���ĂȂ����������O��ǂƂ���
		if (same == 1){ m.cnt[m.now.x][m.now.y + 1] = 1000; }

		//�ǂ̋߂��ŃS�[���`�F�b�N
		if (kabegiwa() != -1){
			m.dir = m.mv = kabegiwa(); break;
		}


		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;


		//�����O��������i��
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ m.dir = m.mv = 2;  break; }
		//�����O��������i��
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ m.dir = m.mv = 3;  break; }
		

		//�E���O��������i��
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ m.dir = m.mv = 1;  break; }
		//�オ�O��������i��
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ m.dir = m.mv = 0; break; }

		m.dir = m.mv = dirsort();









		break;
	case 3://��


		//�O�ƍ��W���ς���ĂȂ����������O��ǂƂ���
		if (same == 1){ m.cnt[m.now.x - 1][m.now.y] = 1000; }

		//�ǂ̋߂��ŃS�[���`�F�b�N
		if (kabegiwa() != -1){
			m.dir = m.mv = kabegiwa(); break;
		}


		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;


		//�����O��������i��
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ m.dir = m.mv = 3;  break; }
		//�オ�O��������i��
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ m.dir = m.mv = 0; break; }
		

		//�����O��������i��
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ m.dir = m.mv = 2;  break; }

		//�E���O��������i��
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ m.dir = m.mv = 1;  break; }

		m.dir = m.mv = dirsort();




		break;
	}


	//m.dir = m.mv = dirsort();
	m.old.x = m.now.x; m.old.y = m.now.y;
}
//$BA0$HF1$8$@$C$?$i#1$r$=$l0J30$O#0$rJV$9(B
int mv_chk(mp* x){
	if (x->now.x == x->old.x &&x->now.y == x->old.y)
		return 1;
	else
		return 0;
}
static int dirsort(void){
	tmp _t;
	tmp *pt;
	pt = &_t;



	//�E����
	switch (m.dir){
	case 0://��



		_t.sortcnt[0] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up  
		_t.sortdir[0] = 0;



		_t.sortcnt[1] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left		
		_t.sortdir[1] = 3;

		_t.sortcnt[2] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		_t.sortdir[2] = 1;

		 _t.sortcnt[3] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down
		 _t.sortdir[3] = 2;

		s_sort(&_t, 0, 3);
		//s_sort(&_t, 0, 2);

		if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;
		else 	if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;
		else 	if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;
		    else 	if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;




		break;
	case 1://Right

		_t.sortcnt[0] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		_t.sortdir[0] = 1;
		_t.sortcnt[1] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up
		_t.sortdir[1] = 0;

		_t.sortcnt[2] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down
		_t.sortdir[2] = 2;

		 _t.sortcnt[3] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left
		 _t.sortdir[3] = 3;
		//
		s_sort(&_t, 0, 3);
		//s_sort(&_t, 0, 2);

		if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;
		else if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;
		else 	if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;
		  else 	if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;





		break;

	case 2://Down
		_t.sortcnt[0] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down
		_t.sortdir[0] = 2;
		_t.sortcnt[1] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		_t.sortdir[1] = 1;


		_t.sortcnt[2] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left
		_t.sortdir[2] = 3;

		 _t.sortcnt[3] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up
		 _t.sortdir[3] = 0;


		s_sort(&_t, 0, 3);
		//s_sort(&_t, 0, 2);
		if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;
		else if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;
		else 	if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;
		  else 	if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;

		break;
	case 3://Left

		_t.sortcnt[0] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left       
		_t.sortdir[0] = 3;
		_t.sortcnt[1] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down        
		_t.sortdir[1] = 2;


		_t.sortcnt[2] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up
		_t.sortdir[2] = 0;

		 _t.sortcnt[3] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		 _t.sortdir[3] = 1;

		 s_sort(&_t, 0, 3);
		 //s_sort(&_t, 0, 2);

		 if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;
		else if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;
		else 	if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;
		  else 	if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;



		break;
	}
	return _t.sortdir[0];
}