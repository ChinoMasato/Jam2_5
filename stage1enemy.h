#pragma once
#include "en.h"
const int EnemyNum = 10;//�G�̐�
extern En enemy[EnemyNum];//�G

void initstage1Enemy();//�G�̏�����
void updatestage1Enemy();//�G�̍X�V
void drawstage1Enemy();//�G�̕`��

bool canEnemyShot(En enemy);//�e�����Ă邩�m�F

void straightShot(int rad, En ene, int shifty);//�^����������
void aimShot(En ene);//�_���Č���

void explosion(En ene);//���������֐�