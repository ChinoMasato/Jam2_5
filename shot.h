#pragma once
#include "en.h"

const int ShotNum = 1000nnn;
extern En shot[ShotNum];//���Ԑ�
extern En leaf1[ShotNum];//Thousant Leaf
extern En leaf2[ShotNum];
extern En leaf3[ShotNum];
extern En leaf4[ShotNum];

void initShot();//�e�̏�����
void updateShot();//�e�̍X�V
void drawShot();