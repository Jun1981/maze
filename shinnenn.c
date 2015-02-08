//•½¬27”N2Œ9“ú@‚RF‚S‚V

//=================================
// $BLBO)C5:w%5%s%W%k(B
// $BKh2s!">e"*1&"*2<"*:8$N=g$KDL$l$k$+%A%'%C%/$9$k(B
// $B$3$N%W%m%0%i%`$O!"$"$k>r7o$rK~$?$9LBO)$G$O!"(B
// $B@h$K?J$^$J$/$J$k!#(B
//=================================
#include "shinnenn.h"
#include "maze.h"
//#include "move.h"
  #include "r_move.h"

//#include "s_move.h"
//=================================
// $B%W%l!<%d>pJs(B
//=================================
static	Funcs funcs = { "_X‚Ì—V‚Ñ", init, walkAround };
//=================================
// $B8x3+4X?t(B
//=================================
Funcs* getGroup05Info(void) { return &funcs; }


int x_size, y_size;

int self_chk= 0;//©•ª‚Ìƒ}ƒbƒvƒ`ƒFƒbƒN—p




//$BFbIt4X?t(B
mp m;
static int once = 0;//$B:G=i$@$1(B


static int	walkAround(void){
	
		x_size = getMazeWidth();
		y_size = getMazeHeight();
	

	if (once == 0){
		init();
		once = 1;
		return m.mv;
	}
	r_move();//‰E—Dæ	
	return m.mv;
}


static void init(void){

	int i, j;

	//ƒ}ƒbƒvƒJƒEƒ“ƒ^‚ğƒŠƒZƒbƒg
	for (i = 0; i < 50; i++){
		for (j = 0; j < 30; j++){
			m.cnt[i][j] = 0;
		}
	}
	m.now = getCurrentPosition();

	if (m.now.x == 0 && m.now.y == 12)self_chk=1;//©ŒÈƒ}ƒbƒv‘æˆêğŒŠm”F

	m.cnt[m.now.x][m.now.y] = 1000;
	m.stat[m.now.x][m.now.y] = wall;//$BJI(B
	m.old.x = m.now.x, m.old.y = m.now.y;
	if (m.now.x == 0){
		
	    if (canMove(DirDown) == MapGoal)m.mv = DirDown;
		else if (canMove(DirUp) == MapGoal)m.mv = DirUp;
		else m.mv = m.dir = DirRight;
	}

	if (m.now.y == 0)
	if (canMove(DirRight) == MapGoal)m.mv = DirRight;
		else if (canMove(DirLeft) == MapGoal)m.mv = DirLeft;
		
		else m.dir = m.mv = DirDown;//$B>e%9%?!<%H(B

	if (m.now.x == x_size - 1) {
		
		if (canMove(DirDown) == MapGoal)m.mv = DirDown;
		else if (canMove(DirUp) == MapGoal)m.mv = DirUp;
		else m.dir = m.mv = DirLeft;//$B1&C<(B
	}


	if (m.now.y == y_size - 1){
		if (canMove(DirRight) == MapGoal)m.mv = DirRight;
		else if (canMove(DirLeft) == MapGoal)m.mv = DirLeft;
		else  m.dir = m.mv = DirUp;//$B2<C<(B
	}
}

//Š®¬Œ`H

//2015”N2Œ8“ú


#include"maze.h"
#include "shinnenn.h"

#include "s_sort.h"
#include <stdlib.h>//qsort$BMQ(B

//#include "move.h"

#include "r_move.h"

#include "kabegiwa.h"

int t_cnt[4] = { 0 };//ˆêƒJƒEƒ“ƒg

static int old_dir;

static int times = 0;

static int stk_cnt[100][100] = { 0 };



//void r_move(void);
//int mv_chk(mp* x);//$B<~0O$NDL9T2s?t$r%A%'%C%/$70lHV>/$J$$J}8~$XJV$9!J>e#0!$1&#1!$2<#2!":8#3!K(B
static int dirsort(void);//$B<~0O$NDL9T2s?t%A%'%C%/$7$F0lHV>/$J$$J}8~$rJV$9(B
static int mv_chk(mp* x);


void r_move(void){
	int same;

	//if (m.cnt[m.now.x][m.now.y] == 6){
	// m.cnt[m.now.x][m.now.y] = 1000; //$BJI(B
	//}
	m.now = getCurrentPosition();//$B8=:_0LCV$r<hF@(B
	same = mv_chk(&m);

	times++;//¡‰½è–Ú‚©

	stk_cnt[m.now.x][m.now.y] = times;


	m.cnt[m.now.x][m.now.y]++; //Œ»İˆÊ’uƒJƒEƒ“ƒg


	switch (m.dir){
	case 0://ã


		/*if (self_chk == 4){
		if (m.now.x == 4 && m.now.y == 12){
		self_chk = 5;

		old_dir = m.dir = m.mv = DirRight;

		break;
		}
		}*/

		//‘O‚ÆÀ•W‚ª•Ï‚í‚Á‚Ä‚È‚©‚Á‚½‚çˆê•à‘O‚ğ•Ç‚Æ‚·‚é
		if (same == 1){ m.cnt[m.now.x][m.now.y - 1] = 1000; }



		//•Ç‚Ì‹ß‚­‚ÅƒS[ƒ‹ƒ`ƒFƒbƒN
		if (kabegiwa() != -1){
			old_dir = m.dir = m.mv = kabegiwa(); break;
		}


		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;



		//‰E‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 1;  break; }

		//ã‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ old_dir = m.dir = m.mv = 0; break; }


		//////*‰E‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç(ƒ‹[ƒ€’Eo—pj
		if (m.cnt[m.now.x + 1][m.now.y] >= 1 && m.cnt[m.now.x + 1][m.now.y] != 1000 && same != 1 && m.cnt[m.now.x][m.now.y - 1] > 0){
			if (m.cnt[m.now.x + 1][m.now.y - 1] == 1000 && m.cnt[m.now.x + 1][m.now.y + 1] == 1000){
				old_dir = m.dir = m.mv = 1; break;
			}
		}
		////////¶ã‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚çi‚Ş
		if (m.cnt[m.now.x - 1][m.now.y - 1] >= 1 && m.cnt[m.now.x - 1][m.now.y - 1] != 1000 && same == 1 && m.cnt[m.now.x + 1][m.now.y] > 0 && m.cnt[m.now.x][m.now.y + 1] != 1000){
			if (m.cnt[m.now.x - 2][m.now.y - 1] == 1000 && m.cnt[m.now.x][m.now.y - 1] == 1000){
				old_dir = m.dir = m.mv = 3; break;
			}
		}
		//////*‰Eã‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç(ƒ‹[ƒ€’Eo—pj
		if (m.cnt[m.now.x + 1][m.now.y - 1] >= 1 && m.cnt[m.now.x + 1][m.now.y - 1] != 1000 && same != 1 && m.cnt[m.now.x][m.now.y + 1] > 0 && m.cnt[m.now.x - 1][m.now.y] != 1000){
			if (m.cnt[m.now.x + 1][m.now.y] == 1000 && m.cnt[m.now.x + 1][m.now.y - 2] == 1000){
				old_dir = m.dir = m.mv = 0; break;
			}
		}

		//¶‚Q‚Â‚ª
		if (m.cnt[m.now.x - 2][m.now.y ] >= 1 && m.cnt[m.now.x - 2][m.now.y] != 1000 && same == 1 && m.cnt[m.now.x + 1][m.now.y] > 0 && m.cnt[m.now.x][m.now.y + 1] != 1000){
			if ( m.cnt[m.now.x-2][m.now.y + 1] == 1000){
				old_dir = m.dir = m.mv = 3; break;
			}
		}




		//¶‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 3;  break; }
		//‰º‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ old_dir = m.dir = m.mv = 2;  break; }

		old_dir = m.dir = m.mv = dirsort();
			

		break;
	case 1://‰E		
		//‘O‚ÆÀ•W‚ª•Ï‚í‚Á‚Ä‚È‚©‚Á‚½‚çˆê•à‘O‚ğ•Ç‚Æ‚·‚é
		if (same == 1){ m.cnt[m.now.x + 1][m.now.y] = 1000; }


		/*if (self_chk == 1){

		if (m.now.x == 1 && m.now.y == 12){
		if (canMove(DirRight) == MapAisle)
		old_dir = m.dir = m.mv = DirRight;
		break;
		}


		if (m.now.x==2 && m.now.y==12){

		if (canMove(DirRight) == MapWall){
		self_chk = 2;
		old_dir = m.dir = m.mv = DirDown;
		break;
		}
		}else
		old_dir = m.dir = m.mv = DirRight;
		break;
		}

		if (self_chk == 3){
		if (m.now.x==4&& m.now.y==13){
		self_chk = 4;
		old_dir = m.dir = m.mv = DirUp;

		break;


		}else
		old_dir = m.dir = m.mv = DirRight;

		}
		if (self_chk == 5){
		old_dir = m.dir = m.mv = DirRight;
		break;

		}*/



		//•Ç‚Ì‹ß‚­‚ÅƒS[ƒ‹ƒ`ƒFƒbƒN
		if (kabegiwa() != -1){
			old_dir = m.dir = m.mv = kabegiwa(); break;
		}



		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;



		//‰º‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ old_dir = m.dir = m.mv = 2;  break; }

		//‰E‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 1;  break; }

		//////*‰º‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç
		if (m.cnt[m.now.x][m.now.y + 1] >= 1 && m.cnt[m.now.x][m.now.y + 1] != 1000 && same != 1 && m.cnt[m.now.x + 1][m.now.y] > 0){
			if (m.cnt[m.now.x - 1][m.now.y + 1] == 1000 && m.cnt[m.now.x + 1][m.now.y + 1] == 1000){
				old_dir = m.dir = m.mv = 2; break;
			}
		}
		//////*‰Eã‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç(ƒ‹[ƒ€’Eo—pj
		if (m.cnt[m.now.x + 1][m.now.y - 1] >= 1 && m.cnt[m.now.x + 1][m.now.y - 1] != 1000 && same == 1 && m.cnt[m.now.x][m.now.y + 1] > 0 && m.cnt[m.now.x - 1][m.now.y] != 1000){
			if (m.cnt[m.now.x + 1][m.now.y] == 1000 && m.cnt[m.now.x + 1][m.now.y - 2] == 1000){
				old_dir = m.dir = m.mv = 0; break;
			}
		}
		////‰E‰º‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç
		if (m.cnt[m.now.x + 1][m.now.y + 1] >= 1 && m.cnt[m.now.x + 1][m.now.y + 1] != 1000 && same != 1 && m.cnt[m.now.x - 1][m.now.y] > 0 && m.cnt[m.now.x][m.now.y - 1] != 1000){
			if (m.cnt[m.now.x][m.now.y + 1] == 1000 && m.cnt[m.now.x + 2][m.now.y + 1] == 1000){
				old_dir = m.dir = m.mv = 1; break;
			}
		}

		//ã‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ old_dir = m.dir = m.mv = 0; break; }
		//¶‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 3;  break; }


		old_dir = m.dir = m.mv = dirsort();
		

		break;
	case 2://‰º




		/*if (self_chk == 2){
		if (m.now.x == 2 && m.now.y == 13){
		self_chk = 3;
		old_dir = m.dir = m.mv = DirRight;
		break;
		}


		}
		*/




		//‘O‚ÆÀ•W‚ª•Ï‚í‚Á‚Ä‚È‚©‚Á‚½‚çˆê•à‘O‚ğ•Ç‚Æ‚·‚é
		if (same == 1){ m.cnt[m.now.x][m.now.y + 1] = 1000; }

		//•Ç‚Ì‹ß‚­‚ÅƒS[ƒ‹ƒ`ƒFƒbƒN
		if (kabegiwa() != -1){
			old_dir = m.dir = m.mv = kabegiwa(); break;
		}


		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;



		//¶‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 3;  break; }

		//‰º‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ old_dir = m.dir = m.mv = 2;  break; }

		////*¶‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç(ƒ‹[ƒ€’Eo—pj
		if (m.cnt[m.now.x - 1][m.now.y] >= 1 && m.cnt[m.now.x - 1][m.now.y] != 1000 && same != 1 && m.cnt[m.now.x][m.now.y + 1] > 0){
			if (m.cnt[m.now.x - 1][m.now.y - 1] == 1000 && m.cnt[m.now.x - 1][m.now.y + 1] == 1000){
				old_dir = m.dir = m.mv = 3; break;
			}
		}
		////‰E‰º‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç
		if (m.cnt[m.now.x + 1][m.now.y + 1] >= 1 && m.cnt[m.now.x + 1][m.now.y + 1] != 1000 && same == 1 && m.cnt[m.now.x - 1][m.now.y] > 0 && m.cnt[m.now.x][m.now.y - 1] != 1000){
			if (m.cnt[m.now.x][m.now.y + 1] == 1000 && m.cnt[m.now.x + 2][m.now.y + 1] == 1000){
				old_dir = m.dir = m.mv = 1; break;
			}
		}
		//////*¶‰º‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç(ƒ‹[ƒ€’Eo—pj
		if (m.cnt[m.now.x - 1][m.now.y + 1] >= 1 && m.cnt[m.now.x - 1][m.now.y + 1] != 1000 && same != 1 && m.cnt[m.now.x][m.now.y - 1] > 0 && m.cnt[m.now.x + 1][m.now.y] != 1000){
			if (m.cnt[m.now.x - 1][m.now.y] == 1000 && m.cnt[m.now.x - 1][m.now.y + 2] == 1000){
				old_dir = m.dir = m.mv = 2; break;
			}
		}

		//‰E‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 1;  break; }
		//ã‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ old_dir = m.dir = m.mv = 0; break; }

		old_dir = m.dir = m.mv = dirsort();
		
		break;
	case 3://¶


		//‘O‚ÆÀ•W‚ª•Ï‚í‚Á‚Ä‚È‚©‚Á‚½‚çˆê•à‘O‚ğ•Ç‚Æ‚·‚é
		if (same == 1){ m.cnt[m.now.x - 1][m.now.y] = 1000; }

		//•Ç‚Ì‹ß‚­‚ÅƒS[ƒ‹ƒ`ƒFƒbƒN
		if (kabegiwa() != -1){
			old_dir = m.dir = m.mv = kabegiwa(); break;
		}

		//••½
		if (m.cnt[m.now.x - 1][m.now.y] + m.cnt[m.now.x + 1][m.now.y] + m.cnt[m.now.x][m.now.y - 1] + m.cnt[m.now.x][m.now.y + 1] >= 3000)
			m.cnt[m.now.x][m.now.y] = 1000;



		//ã‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y - 1] == 0){ old_dir = m.dir = m.mv = 0; break; }


		//////ã‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y - 1] >= 1 && m.cnt[m.now.x][m.now.y - 1] != 1000 && same != 1 && m.cnt[m.now.x - 1][m.now.y] > 0){
			if (m.cnt[m.now.x - 1][m.now.y - 1] == 1000 && m.cnt[m.now.x + 1][m.now.y - 1] == 1000){
				old_dir = m.dir = m.mv = 0; break;
			}
		}
		//////*¶‰º‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚ç(ƒ‹[ƒ€’Eo—pj
		if (m.cnt[m.now.x - 1][m.now.y + 1] >= 1 && m.cnt[m.now.x - 1][m.now.y + 1] != 1000 && same == 1 && m.cnt[m.now.x][m.now.y - 1] > 0 && m.cnt[m.now.x + 1][m.now.y] != 1000){
			if (m.cnt[m.now.x - 1][m.now.y] == 1000 && m.cnt[m.now.x - 1][m.now.y + 2] == 1000){
				old_dir = m.dir = m.mv = 2; break;
			}
		}

		////////¶ã‚ª‚P‚Å•Ç‚ÉˆÍ‚Ü‚ê‚Ä‚½‚çi‚Ş
		if (m.cnt[m.now.x - 1][m.now.y - 1] >= 1 && m.cnt[m.now.x - 1][m.now.y - 1] != 1000 && same != 1 && m.cnt[m.now.x + 1][m.now.y] > 0 && m.cnt[m.now.x][m.now.y + 1] != 1000){
			if (m.cnt[m.now.x - 2][m.now.y - 1] == 1000 && m.cnt[m.now.x][m.now.y - 1] == 1000){
				old_dir = m.dir = m.mv = 3; break;
			}
		}

		//¶‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x - 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 3;  break; }



		//‰º‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x][m.now.y + 1] == 0){ old_dir = m.dir = m.mv = 2;  break; }

		//‰E‚ª‚O‚¾‚Á‚½‚çi‚Ş
		if (m.cnt[m.now.x + 1][m.now.y] == 0){ old_dir = m.dir = m.mv = 1;  break; }

		old_dir = m.dir = m.mv = dirsort();
		
		break;
	}


	//old_dir=m.dir=m.mv = dirsort();
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



	//‰E‚©‚ç
	switch (m.dir){
	case 0://ã



		_t.sortcnt[0] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up  
		_t.sortdir[0] = 0;



		_t.sortcnt[1] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left		
		_t.sortdir[1] = 3;

		_t.sortcnt[2] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		_t.sortdir[2] = 1;

		//_t.sortcnt[3] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down
		//_t.sortdir[3] = 2;

		//s_sort(&_t, 0, 3);
		s_sort(&_t, 0, 2);

		if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;
		else 	if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;
		else 	if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;
		//else 	if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;

		break;
	case 1://Right

		_t.sortcnt[0] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		_t.sortdir[0] = 1;
		_t.sortcnt[1] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up
		_t.sortdir[1] = 0;

		_t.sortcnt[2] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down
		_t.sortdir[2] = 2;

		//_t.sortcnt[3] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left
		//_t.sortdir[3] = 3;
		//
		//s_sort(&_t, 0, 3);
		s_sort(&_t, 0, 2);

		if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;
		else if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;
		else 	if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;
		//else 	if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;





		break;

	case 2://Down
		_t.sortcnt[0] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down
		_t.sortdir[0] = 2;
		_t.sortcnt[1] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		_t.sortdir[1] = 1;


		_t.sortcnt[2] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left
		_t.sortdir[2] = 3;

		//_t.sortcnt[3] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up
		//_t.sortdir[3] = 0;


		//s_sort(&_t, 0, 3);
		s_sort(&_t, 0, 2);

		if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;
		else if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;
		else 	if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;
		//else 	if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;

		break;
	case 3://Left

		_t.sortcnt[0] = t_cnt[3] = m.cnt[m.now.x - 1][m.now.y];//Left       
		_t.sortdir[0] = 3;
		_t.sortcnt[1] = t_cnt[2] = m.cnt[m.now.x][m.now.y + 1];//Down        
		_t.sortdir[1] = 2;


		_t.sortcnt[2] = t_cnt[0] = m.cnt[m.now.x][m.now.y - 1];//Up
		_t.sortdir[2] = 0;

		//_t.sortcnt[3] = t_cnt[1] = m.cnt[m.now.x + 1][m.now.y];//Right
		//_t.sortdir[3] = 1;

		//s_sort(&_t, 0, 3);
		s_sort(&_t, 0, 2);
		
		if (_t.sortcnt[0] == t_cnt[0])_t.sortdir[0] = 0;
		else if (_t.sortcnt[0] == t_cnt[3])_t.sortdir[0] = 3;
		else 	if (_t.sortcnt[0] == t_cnt[2])_t.sortdir[0] = 2;
		//else 	if (_t.sortcnt[0] == t_cnt[1])_t.sortdir[0] = 1;



		break;
	}
	return _t.sortdir[0];
}

#include "s_sort.h"
#include "shinnenn.h"



//–ó‹µ‚É‰‚¶‚ÄŒ^‚ğ•ÏX‚·‚é


int med3(int x, int y, int z)
/* x, y, z ‚Ì’†ŠÔ’l‚ğ•Ô‚· */
{
	if (x < y)
		if (y < z) return y; else if (z < x) return x; else return z; else
			if (z < y) return y; else if (x < z) return x; else return z;
}

//\‘¢‘Ì‚Ìƒƒ“ƒoƒ\[ƒg
void s_sort(tmp* a, int left, int right)
/* ƒNƒCƒbƒNƒ\[ƒg
* a     : ƒ\[ƒg‚·‚é”z—ñ‚ğŠÜ‚ñ‚¾‚ÌŒ³‚Ì\‘¢‘Ì
* left  : ƒ\[ƒg‚·‚éƒf[ƒ^‚ÌŠJnˆÊ’u
* right : ƒ\[ƒg‚·‚éƒf[ƒ^‚ÌI—¹ˆÊ’u
*/


{



	if (left < right) {
		int i = left, j = right;
		int temp, temp2, pivot = med3(a->sortcnt[i], a->sortcnt[i + (j - i) / 2], a->sortcnt[j]); /* (i+j)/2‚Å‚ÍƒI[ƒo[ƒtƒ[‚µ‚Ä‚µ‚Ü‚¤ */
		while (1) { /* a[] ‚ğ pivot ˆÈã‚ÆˆÈ‰º‚ÌW‚Ü‚è‚É•ªŠ„‚·‚é */
			while (a->sortcnt[i] < pivot) i++; /* a[i] >= pivot ‚Æ‚È‚éˆÊ’u‚ğŒŸõ */
			while (pivot < a->sortcnt[j]) j--; /* a[j] <= pivot ‚Æ‚È‚éˆÊ’u‚ğŒŸõ */
			if (i >= j) break;
			temp = a->sortcnt[i]; temp2 = a->sortdir[i];
			a->sortcnt[i] = a->sortcnt[j]; a->sortdir[i] = a->sortdir[j];
			a->sortcnt[j] = temp; a->sortdir[j] = temp2; /* a[i],a[j] ‚ğŒğŠ· */
			i++; j--;
		}
		s_sort(a, left, i - 1);  /* •ªŠ„‚µ‚½¶‚ğÄ‹A“I‚Éƒ\[ƒg */
		s_sort(a, j + 1, right); /* •ªŠ„‚µ‚½‰E‚ğÄ‹A“I‚Éƒ\[ƒg */
	}
}

#include "maze.h"
#include "shinnenn.h"
#include "kabegiwa.h"

int kabegiwa(){

	switch (m.dir){
	case 0:
		

		if (m.now.x == 1){//¶’[
			if (canMove(DirLeft) == MapGoal){
				
				return DirLeft;;

			}
			else{
				m.cnt[m.now.x - 1][m.now.y] = 1000;//•Ç
				//m.cnt[m.now.x][m.now.y] += 3;
			}
		}

		if (m.now.x == x_size - 2){//‰E’[
			if (canMove(DirRight) == MapGoal){
				
				return DirRight;
			}
			else{
				m.cnt[m.now.x + 1][m.now.y] = 1000;//•Ç
				return -1;
				//m.cnt[m.now.x][m.now.y] += 3;
			}

		}
		break;

	case 1:
		//•ÇÛ‚ÌƒS[ƒ‹Šm”F
		if (m.now.y == 1){//‰EŒü‚«‚Ìã
			if (canMove(DirUp) == MapGoal){
				
				return DirUp;
			}
			else
			{
				m.cnt[m.now.x][m.now.y - 1] = 1000;//•Ç
				//	m.cnt[m.now.x][m.now.y] += 3;
			}

		}
		if (m.now.y == y_size - 2){//‰EŒü‚«‚Ì‰º
			if (canMove(DirDown) == MapGoal){
				
				return DirDown;
			}
			else{
				m.cnt[m.now.x][m.now.y + 1] = 1000;//•Ç
				//m.cnt[m.now.x][m.now.y] += 3;
				return -1;
			}

		}
		//////////////////////////////////////////
		break;
	case 2:
		//•ÇÛ‚ÌƒS[ƒ‹Šm”F
		if (m.now.x == 1){//‰ºŒü‚«¶’[
			if (canMove(DirLeft) == MapGoal){
				
				return DirLeft;
			}
			else
			{
				m.cnt[m.now.x - 1][m.now.y] = 1000;//•Ç
				//m.cnt[m.now.x][m.now.y] += 3;
			}
		}


		if (m.now.x == x_size - 2){//‰ºŒü‚«‰E’[
			if (canMove(DirRight) == MapGoal){
				
				return DirRight;
			}
			else{
				//m.cnt[m.now.x][m.now.y] += 3;
				m.cnt[m.now.x + 1][m.now.y] = 1000;//•Ç
				return -1;
			}
		}
		//////////////////////////////////////////
		break;
	case 3:

		//•ÇÛ‚ÌƒS[ƒ‹Šm”F
		if (m.now.y == 1){//¶Œü‚«ã’[
			if (canMove(DirUp) == MapGoal){
			
				return DirUp;
			}
			else{
				//	m.cnt[m.now.x][m.now.y] += 3;
				m.cnt[m.now.x][m.now.y - 1] = 1000;//•Ç
			}

		}
		if (m.now.y == y_size - 2){//¶Œü‚«‰º’[
			if (canMove(DirDown) == MapGoal){
				
				return DirDown;
			}
			else{
				//m.cnt[m.now.x][m.now.y] += 3;
				m.cnt[m.now.x][m.now.y + 1] = 1000;//•Ç
				return -1;
			}
		}

		break;
	}


	return -1;
}