//�v���C���[�̒e�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include "shot.h"

En shot[ShotNum];//���Ԑ�
En leaf[ShotNum];//Thousant Leaf
//�e�̏�����
void initShot()
{
	for (int i = 0; i < ShotNum; i++) {
		shot[i].r = 10;
		shot[i].color = GetColor(255, 255, 0);
		shot[i].fill = true;
		shot[i].vx = 10.0;
		shot[i].vy = 0.0;
		shot[i].enable = false;

		shotimg = LoadGraph("���Ԑ�.png");

		leaf[i].r = 5;
		leaf[i].color = GetColor(255, 255, 0);
		leaf[i].fill = true;
		leaf[i].vx = 5.0;
		leaf[i].vy = 2.5;
		leaf[i].enable = false;

		shotimg = LoadGraph("�t����.png");
	}
}
//�e�̍X�V
void updateShot()
{
	//�e���L���ȂƂ��ɒe�𓮂���
	for (int i = 0; i < ShotNum; i++)
	{
		if (shot[i].enable == true) {
			shot[i].x = shot[i].x + shot[i].vx;
			shot[i].y = shot[i].y + shot[i].vy;
			if (shot[i].x >= 800) {
				shot[i].enable = false;
			}
		}

		if (leaf[i].enable == true) {
			leaf[i].x = leaf[i].x + leaf[i].vx;
			leaf[i].y = leaf[i].y + leaf[i].vy;
			if (leaf[i].x >= 800 || leaf[i].y >= 600) {
				leaf[i].enable = false;
			}
		}
	}
}
//�e�̕`��
void drawShot()
{
	for (int i = 0; i < ShotNum; i++) {
		if (shot[i].enable == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);//������
			DrawCircle(shot[i].x, shot[i].y, shot[i].r, shot[i].color, shot[i].fill);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//�s����
			DrawCircle(shot[i].x, shot[i].y, shot[i].r * 0.5, shot[i].color, shot[i].fill);

			DrawGraph(shot[i].x-40, shot[i].y - 35, shotimg, true);
		}
	}
}