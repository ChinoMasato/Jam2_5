#pragma once
#include "en.h"

const int ShotNum = 100;
extern En shot[ShotNum];//落花生
extern En leaf[ShotNum];//Thousant Leaf

void initShot();//弾の初期化
void updateShot();//弾の更新
void drawShot();