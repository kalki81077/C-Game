#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include "GAME.h"

/* この実習で学んだ様々なものを使って簡単なCUIのゲームを作ってみよう。
 * 作成するものは何でもよいが下記の要件を満たす事。
 * タイトル ゲームシーケンス 結果表示が存在しそれらがステートマシンによってコントロールされていること（任意)
 * クラスの多態性を用いたオブジェクト管理が入っていること(任意)
 * 自分が作成した Poolアロケータが使われていること(必須)
 * 何かしらの処理にスレッドを用いた並行処理が入っていること(任意)
 * ゲームエンジンの使用は不可
 * 使用 する言語は C ++
 */

int main()
{
	// エスケープシーケンスを有効に
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdOut, &mode);
	SetConsoleMode(hStdOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	// カーソルを消す
	printf("\x1b[?25l");

	/* {
		// テンキー or wasdで@マークが移動するだけのサンプル
		// サンプルなので消しても大丈夫です。
		int x = 0; // X座標
		int y = 0; // Y座標
		int i; // キー入力値
		do
		{
			printf("\x1b[%d;%dH@", y, x); // 今の座標に'@'表示
			i = _getch(); // キー入力待ち
			printf("\x1b[%d;%dH ", y, x); // 前の座標に' '表示
			// キー入力で座標更新
			switch (i) {
			case '2':
			case 's':
				++y;
				break;
			case '4':
			case 'a':
				--x;
				break;
			case '6':
			case 'd':
				++x;
				break;
			case '8':
			case 'w':
				--y;
				break;
			}
		} while ('q' != i); // 'q'キーで終了
	}*/



	GAME game;
	game.run();

	


	// カーソルを表示
	printf("\x1b[?25h");
	return EXIT_SUCCESS;
}
