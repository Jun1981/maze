#include "s_sort.h"
//#include "move.h"


//���󋵂ɉ����Č^��ύX����

 
int med3(int x, int y, int z)
/* x, y, z �̒��Ԓl��Ԃ� */
{
    if (x < y)
        if (y < z) return y; else if (z < x) return x; else return z; else
        if (z < y) return y; else if (x < z) return x; else return z;
}
 
//�\���̂̃����o�\�[�g
void s_sort(tmp* a, int left, int right)
/* �N�C�b�N�\�[�g
 * a     : �\�[�g����z����܂񂾂̌��̍\����
 * left  : �\�[�g����f�[�^�̊J�n�ʒu
 * right : �\�[�g����f�[�^�̏I���ʒu
 */
{
    if (left < right) {
        int i = left, j = right;
        int temp,temp2, pivot = med3(a->sortcnt[i], a->sortcnt[i + (j - i) / 2], a->sortcnt[j]); /* (i+j)/2�ł̓I�[�o�[�t���[���Ă��܂� */
        while (1) { /* a[] �� pivot �ȏ�ƈȉ��̏W�܂�ɕ������� */
            while (a->sortcnt[i] < pivot) i++; /* a[i] >= pivot �ƂȂ�ʒu������ */
            while (pivot < a->sortcnt[j]) j--; /* a[j] <= pivot �ƂȂ�ʒu������ */
            if (i >= j) break;
			temp = a->sortcnt[i]; temp2 = a->sortdir[i];
			a->sortcnt[i] = a->sortcnt[j]; a->sortdir[i] = a->sortdir[j];
			a->sortcnt[j] = temp; a->sortdir[j] = temp2; /* a[i],a[j] ������ */
            i++; j--;
        }
        s_sort(a, left, i - 1);  /* �������������ċA�I�Ƀ\�[�g */
        s_sort(a, j + 1, right); /* ���������E���ċA�I�Ƀ\�[�g */
    }
}