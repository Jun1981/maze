#include	<stdio.h>
#include	<conio.h>
#include	<windows.h>
#include	<stdlib.h>

#if !defined	__MAZE_H__ 
#define	__MAZE_H__ 
#pragma	warning	( disable : 4996 )
//=================================
//	�萔
//=================================
//	�L�[�{�[�h
#define	KeyEscape	(0x1b)		//	�G�X�P�[�v�L�[

//	�}�b�v���
#define	MazeStart	'S'			//	�X�^�[�g�n�_
#define	MazeGoal	'G'			//	�S�[��
#define	MazeAisle	' '			//	�ʘH

//	��ԕ\���F
#define	ColorGoaled	( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY )
#define	ColorRunning	( BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY )
#define	ColorDefault	( BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY  )

//	�i�s����
#define	DirUp	(0)
#define	DirRight	(1)
#define	DirDown	(2)
#define	DirLeft	(3)
#define	DirInvalid	(4)

//=================================
//	�^�錾
//=================================
//	map�̏�
typedef	enum	{ MapWall = 0, MapStart = 1, MapAisle = 2, MapGoal = 3, MapInvalid = 4 } MapStatus;

//	�ʒu���
typedef	struct {
	int	x;
	int	y;
} Pos;

// �v���[�����Z�b�g������
typedef	struct	{
	char*		name;
	void	( *init )		( void );
	int		( *walkAround )	( void );
} Funcs;

//=================================
//	etc
//=================================
#if !defined ( __MAZE_C__ )
	#define	Extern	extern
	static	void	init	( void );
	static	int		walkAround	( void );
#else
	#define	Extern	extern "C"
#endif


//=================================
//	���J�֐��̃v���g�^�C�v�錾
//=================================
Extern	int	getMazeWidth	( void );
Extern	int	getMazeHeight	( void );
Extern	Pos	getCurrentPosition	( void );
Extern	MapStatus	canMove	( int );

#endif	( __MAZE_H__ )

