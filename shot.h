#pragma once
#include "en.h"

const int ShotNum = 1000nnn;
extern En shot[ShotNum];//落花生
extern En leaf1[ShotNum];//Thousant Leaf
extern En leaf2[ShotNum];
extern En leaf3[ShotNum];
extern En leaf4[ShotNum];

void initShot();//弾の初期化
void updateShot();//弾の更新
void drawShot();