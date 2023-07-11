//�v���C���[�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"
#include"game.h"

extern bool gameOverFlag = false;//�Q�[���I�[�o�[����

En player;//�v���C���[
int shotse;//�V���b�gSE
int leafcooltime = 0;
//�v���C���[�̏�����
void initPlayer()
{
	shotse = LoadSoundMem("maou_se_battle16.mp3");
	player.x = 100;
	player.y = 200;
	player.r = 10;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;

	player.hp = 10;
	player.inv = 0;
	player.nage = 0;

	playerimg = LoadGraph("player_1.png");
}

//�v���C���[�̍X�V
void updatePlayer()
{
	//�v���C���[�𓮂���
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		player.x = player.x + 3.0;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		player.x = player.x - 3.0;
	}
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		player.y = player.y - 3.0;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		player.y = player.y + 3.0;
	}
	if (player.x < 0) {
		//�������[�ɏo����
		player.x = 0;
	}
	if (player.x >= 800) {
		//�����E�[�ɏo����
		player.x = 800;
	}
	if (player.y < 0) {
		//�������[�ɏo����
		player.y = 0;
	}
	if (player.y >= 600) {
		//�����E�[�ɏo����
		player.y = 600;
	}

	//�e��������
	if (CheckHitKey(KEY_INPUT_N) == 1)
	{
		player.nage++;
		//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
		for (int i = 0; i < ShotNum; i++)
		{
			//���Ă�e���݂���
			if (shot[i].enable == false && player.cooltime <= 0) {
				//�e������
				shot[i].x = player.x;
				shot[i].y = player.y;
				shot[i].enable = true;
				player.cooltime = 50;//�A�ˑ��x�@�������قǘA�˂ł���
				PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
			}
			

			if (leaf1[i].enable == false && leaf2[i].enable == false && leaf3[i].enable == false && leaf4[i].enable == false && leafcooltime <= 0) {
				
				leaf1[i].x = player.x;
				leaf1[i].y = player.y;
				leaf1[i].enable = true;

				leaf2[i].x = player.x;
				leaf2[i].y = player.y;
				leaf2[i].enable = true;

				leaf3[i].x = player.x;
				leaf3[i].y = player.y;
				leaf3[i].enable = true;

				leaf4[i].x = player.x;
				leaf4[i].y = player.y;
				leaf4[i].enable = true;
				leafcooltime = 20;
				break;

			}
		}
	}

	if (player.nage%30<=10) {
		playerimg = LoadGraph("player_1.png");
	}
	if (player.nage % 30 < 20&&player.nage%30>10) {
		playerimg = LoadGraph("�J���.png");
	}
	if (player.nage % 30 > 20) {
		playerimg = LoadGraph("�J��\��.png");
	}

	if (CheckHitKey(KEY_INPUT_N) == 0)
	{
		player.nage = 0;
	}

	//�e���₷����
	if (player.cooltime > 0) {
		player.cooltime--;
	}
	if (leafcooltime > 0) {
		leafcooltime--;
	}

	if (player.hp <= 0) {
		gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
	}
	if (player.inv > 0) {
		player.inv--;
	}


}

//�v���C���[�̕`��
void drawPlayer()
{
	if (player.inv % 5 < 2) {
		DrawCircle(player.x, player.y, player.r, player.color, false);

		if (player.nage % 30 <= 10) {
			DrawGraph(player.x - 115, player.y - 60, playerimg, true);
		}
		if (player.nage % 30 > 10) {
			DrawGraph(player.x - 45, player.y - 50, playerimg, true);
		}

	}
}