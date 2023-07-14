#include "DxLib.h"
#include "player.h"
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "en.h"
#include "game.h"
#include "effect.h"
#include "bgsprite.h"
#include"UI.h"

void init();//初期化関数のプロトタイプ宣言
void titleUpdate();
void update();//更新関数のプロトタイプ宣言
void draw();//描画処理
void a();//ステージとステージの間に挟むやつ
int aa = 0;

enum GameScene
{
	Title,
	Game,
	Result,
	A
};
GameScene scene = Title;
int TitleLogo;
int PushEnterKey;
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	init();//初期化処理の呼び出し　起動時一度だけ呼び出す

	//メインループ処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		if (scene == Title)
		{
			titleUpdate();//更新処理の呼び出し
		}
		if (scene == Game)
		{
			update();//更新処理の呼び出し

			if (clearflag1 == true&&aa==0)
			{
				//ゲームの初期化
				initGame();
				//プレイヤーの初期化
				initPlayer();
				//弾の初期化
				initShot();
				initEnemyShot();
				//敵の初期化処理
				initstage1Enemy();
				//エフェクトの初期化
				initEffect();
				//背景スプライトの初期化
				initBg();
				scene = A;
			}
			if (clearflag2 == true && aa == 1)
			{
				//ゲームの初期化
				initGame();
				//プレイヤーの初期化
				initPlayer();
				//弾の初期化
				initShot();
				initEnemyShot();
				//敵の初期化処理
				initstage1Enemy();
				//エフェクトの初期化
				initEffect();
				//背景スプライトの初期化
				initBg();
				scene = A;
			}
			if (clearflag3 == true && aa == 2)
			{
				//ゲームの初期化
				initGame();
				//プレイヤーの初期化
				initPlayer();
				//弾の初期化
				initShot();
				initEnemyShot();
				//敵の初期化処理
				initstage1Enemy();
				//エフェクトの初期化
				initEffect();
				//背景スプライトの初期化
				initBg();
				scene = A;
			}
		}
		if (scene == A)
		{
			a();
		}
		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}
	//メインループ処理ここまで

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
//初期化関数　引数、戻り値なし
void init()
{
	//ゲームの初期化
	initGame();
	//プレイヤーの初期化
	initPlayer();
	//弾の初期化
	initShot();
	initEnemyShot();
	//敵の初期化処理
	initstage1Enemy();
	//エフェクトの初期化
	initEffect();
	//背景スプライトの初期化
	initBg();
	//タイトル画像読み込み
	TitleLogo = LoadGraph("タイトル.png");
	PushEnterKey = LoadGraph("pushenter.png");
	//タイトルBGM再生
	PlayMusic("maou_game_boss03.mp3", DX_PLAYTYPE_LOOP);
}
//タイトルシーンの更新
void titleUpdate()
{
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		scene = Game;
		PlayMusic("maou_game_vehicle03.mp3", DX_PLAYTYPE_LOOP);
	}
	DrawGraph(100, 220, TitleLogo, true);
	DrawGraph(280, 380, PushEnterKey, true);
}

//更新関数
void update()
{
	//ゲーム(審判)の更新
	updateGame();
	//プレイヤーの更新
	updatePlayer();

	//弾の更新
	updateShot();
	updateEnemyShot();
	//敵の更新
	if (clearflag1 == false) {
		updatestage1Enemy();
	}
	if (clearflag1 == true&&clearflag2==false) {
		updatestage2Enemy();
	}
	if (clearflag2 == true) {
		updatestage3Enemy();
	}
	//エフェクトの更新
	updateEffect();
	//背景スプライトの更新
	updateBg();

	//描画処理
	draw();
}

//描画処理
void draw()
{
	//背景スプライトの描画
	drawBg();
	//敵の描画
	if (clearflag1 == false) {
		drawstage1Enemy();
	}
	if (clearflag1 == true && clearflag2 == false) {
		drawstage2Enemy();
	}
	if (clearflag2 == true) {
		drawstage3Enemy();
	}
	//プレイヤーの描画
	drawPlayer();
	//弾の描画
	drawShot();
	drawEnemyShot();
	//エフェクトの描画
	drawEffect();
	//ゲーム関連の描画
	drawGame();
	//UI関連の描画
	drawUI();
}

void a()
{
	if (clearflag1 == true&&clearflag2==false)
	{
		DrawFormatString(350, 300, GetColor(255, 255, 255), "1面クリア！Enterで2面へ");

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			initstage2Enemy();
			aa++;
			scene = Game;
			PlayMusic("maou_game_vehicle03.mp3", DX_PLAYTYPE_LOOP);
		}
	}
	if (clearflag2 == true&&aa==1)
	{
		DrawFormatString(350, 300, GetColor(255, 255, 255), "2面クリア！Enterで3面へ");

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			initstage3Enemy();
			aa++;
			scene = Game;
			PlayMusic("maou_game_vehicle03.mp3", DX_PLAYTYPE_LOOP);
		}
	}
	if (clearflag3 == true)
	{
		DrawFormatString(270, 300, GetColor(255, 255, 255), "ゲームクリア！THANK YOU FOR PLAYING!");
	}
}
