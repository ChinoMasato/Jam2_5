#include "DxLib.h"
#include "game.h"
//�Q�[���֘A�̏��
int score = 0;//�_��
bool gameOverFlag = false;//�Q�[���I�[�o�[����

//�Q�[���̏�����
void initGame()
{

}
//�Q�[�����e�̍X�V
void updateGame()
{

}
//�Q�[�����̕`��
void drawGame()
{
	DrawFormatString(0, 30, GetColor(255, 255, 0), "�N�� %d �~", score);

	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
	}
}