#include "maze.h"
#include "shinnenn.h"

void kabegiwa_chk(){

	switch (m.dir){
	case 0:
		if (m.now.y == 1){//��[
			if (canMove(DirUp) == MapGoal){
				m.mv = DirUp; return;
			}
			else{
				m.cnt[m.now.x][m.now.y - 1] = 1000;//��
				//m.cnt[m.now.x][m.now.y] += 3;
			}
		}

		if (m.now.x == 1){//���[
			if (canMove(DirLeft) == MapGoal){
				m.mv = DirLeft;
				return;

			}
			else{
				m.cnt[m.now.x - 1][m.now.y] = 1000;//��
				//m.cnt[m.now.x][m.now.y] += 3;
			}
		}

		if (m.now.x == x_size - 2){//�E�[
			if (canMove(DirRight) == MapGoal){
				m.mv = DirRight;
				return;
			}
			else{
				m.cnt[m.now.x + 1][m.now.y] = 1000;//��
				//m.cnt[m.now.x][m.now.y] += 3;
			}

		}
		break;

	case 1:
		//�Ǎۂ̃S�[���m�F
		if (m.now.y == 1){//�E�����̏�
			if (canMove(DirUp) == MapGoal){
				m.mv = DirUp;
				return;
			}
			else
			{
				m.cnt[m.now.x][m.now.y - 1] = 1000;//��
				//	m.cnt[m.now.x][m.now.y] += 3;
			}

		}
		if (m.now.y == y_size - 2){//�E�����̉�
			if (canMove(DirDown) == MapGoal){
				m.mv = DirDown;
				return;
			}
			else{
				m.cnt[m.now.x][m.now.y + 1] = 1000;//��
				//m.cnt[m.now.x][m.now.y] += 3;
			}

		}
		//////////////////////////////////////////
		break;
	case 2:
		//�Ǎۂ̃S�[���m�F
		if (m.now.x == 1){//���������[
			if (canMove(DirLeft) == MapGoal){
				m.mv = DirLeft;
				return;
			}
			else
			{
				m.cnt[m.now.x - 1][m.now.y] = 1000;//��
				//m.cnt[m.now.x][m.now.y] += 3;
			}
		}


		if (m.now.x == x_size - 2){//�������E�[
			if (canMove(DirRight) == MapGoal){
				m.mv = DirRight;
				return;
			}
			else{
				//m.cnt[m.now.x][m.now.y] += 3;
				m.cnt[m.now.x + 1][m.now.y] = 1000;//��
			}
		}
		//////////////////////////////////////////
		break;
	case 3:

		//�Ǎۂ̃S�[���m�F
		if (m.now.y == 1){//��������[
			if (canMove(DirUp) == MapGoal){
				m.mv = DirUp;
				return;
			}
			else{
				//	m.cnt[m.now.x][m.now.y] += 3;
				m.cnt[m.now.x][m.now.y - 1] = 1000;//��
			}

		}
		if (m.now.y == y_size - 2){//���������[
			if (canMove(DirDown) == MapGoal){
				m.mv = DirDown;
				return;
			}
			else{
				//m.cnt[m.now.x][m.now.y] += 3;
				m.cnt[m.now.x][m.now.y + 1] = 1000;//��
			}
		}

		break;
	}
}