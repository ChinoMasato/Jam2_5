//�v���C���[�̒e�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include "shot.h"

En shot[ShotNum];//���Ԑ�
En leaf1[ShotNum];//Thousant Leaf
En leaf2[ShotNum];
En leaf3[ShotNum];
En leaf4[ShotNum];
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

		leaf1[i].r = 5;
		leaf1[i].color = GetColor(255, 255, 0);
		leaf1[i].fill = true;
		leaf1[i].vx = 5.0;
		leaf1[i].vy = 3.0;
		leaf1[i].enable = false;

		leaf2[i].r = 5;
		leaf2[i].color = GetColor(255, 255, 0);
		leaf2[i].fill = true;
		leaf2[i].vx = 5.0;
		leaf2[i].vy = -3.0;
		leaf2[i].enable = false;

		leaf3[i].r = 5;
		leaf3[i].color = GetColor(255, 255, 0);
		leaf3[i].fill = true;
		leaf3[i].vx = 5.0;
		leaf3[i].vy = 1.0;
		leaf3[i].enable = false;

		leaf4[i].r = 5;
		leaf4[i].color = GetColor(255, 255, 0);
		leaf4[i].fill = true;
		leaf4[i].vx = 5.0;
		leaf4[i].vy = -1.0;
		leaf4[i].enable = false;


		leafimg = LoadGraph("�t����.png");
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
		

		if (leaf1[i].enable == true) {
			leaf1[i].x = leaf1[i].x + leaf1[i].vx;
			leaf1[i].y = leaf1[i].y + leaf1[i].vy;
			if (leaf1[i].x >= 800 || leaf1[i].y >= 600 || leaf1[i].x <= 0 || leaf1[i].y <= 0) {
				leaf1[i].enable = false;
			}
		}

		if (leaf2[i].enable == true) {
			leaf2[i].x = leaf2[i].x + leaf2[i].vx;
			leaf2[i].y = leaf2[i].y + leaf2[i].vy;
			if (leaf2[i].x >= 800 || leaf2[i].y >= 600 || leaf2[i].x <= 0 || leaf2[i].y <= 0) {
				leaf2[i].enable = false;
			}
		}

		if (leaf3[i].enable == true) {
			leaf3[i].x = leaf3[i].x + leaf3[i].vx;
			leaf3[i].y = leaf3[i].y + leaf3[i].vy;
			if (leaf3[i].x >= 800 || leaf3[i].y >= 600 || leaf3[i].x <= 0 || leaf3[i].y <= 0) {
				leaf3[i].enable = false;
			}
		}

		if (leaf4[i].enable == true) {
			leaf4[i].x = leaf4[i].x + leaf4[i].vx;
			leaf4[i].y = leaf4[i].y + leaf4[i].vy;
			if (leaf4[i].x >= 800 || leaf4[i].y >= 600 || leaf4[i].x <= 0 || leaf4[i].y <= 0) {
				leaf4[i].enable = false;
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
			DrawCircle(shot[i].x, shot[i].y, shot[i].r, shot[i].color, false);

			DrawGraph(shot[i].x-40, shot[i].y - 35, shotimg, true);
		}


		if (leaf1[i].enable == true)
		{
			DrawCircle(leaf1[i].x, leaf1[i].y, leaf1[i].r, leaf1[i].color, false);
		}

		if (leaf2[i].enable == true)
		{
			DrawCircle(leaf2[i].x, leaf2[i].y, leaf2[i].r, leaf2[i].color, false);
		}

		if (leaf3[i].enable == true)
		{
			DrawCircle(leaf3[i].x, leaf3[i].y, leaf3[i].r, leaf3[i].color, false);
		}

		if (leaf4[i].enable == true)
		{
			DrawCircle(leaf4[i].x, leaf4[i].y, leaf4[i].r, leaf4[i].color, false);
		}
	}
}