//=================================
//	���H�T���T���v��
//		����A�と�E���������̏��ɒʂ�邩�`�F�b�N����
//		���̃v���O�����́A��������𖞂������H�ł́A
//		��ɐi�܂Ȃ��Ȃ�B
//=================================


#include "shinnenn.h"
#include "maze.h"

#include "move.h"


//=================================
//	�v���[�����
//=================================
static	Funcs	funcs = { "�[���i����" , init, walkAround };

//=================================
//	���J�֐�
//=================================
Funcs*	getGroup05Info	( void ) { return &funcs; }


//�����֐�

map m;


static int once = 0;//�ŏ�����
static int	walkAround(void)
{
	if (once == 0){
		init();
		once = 1;


		return m.mv;
	}//�ŏ��̃`�F�b�N	



	move();//�ړ��v�Z

	//DrawFormatString(300, 300, "�J�E���g", m.cnt[1][20]);
	

	
	return m.mv;

}







 static void init(void){


	

	m.now = getCurrentPosition();



	m.cnt[m.now.x][m.now.y] = 1000;
	m.stat[m.now.x][m.now.y] = wall;//��
	m.old.x = m.now.x, m.old.y = m.now.y;


	if (m.now.x == 0) m.mv=m.dir = DirRight;//�X�^�[�g�n�_�����[��������
	else
		if (m.now.y == 0) m.dir = m.mv = DirDown;//��X�^�[�g
		else
			if (m.now.x == x_size-1) m.dir = m.mv = DirLeft;//�E�[
			else
				if (m.now.y == y_size-1)m.dir = m.mv = DirUp;//���[
}