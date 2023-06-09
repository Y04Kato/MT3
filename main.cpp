#include <Novice.h>
#include "Vector3.h"
#include "Matrix4x4.h"

const char kWindowTitle[] = "LE2B_07_カトウユウタ_タイトル";

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3& vector3, const char* name) {
	Novice::ScreenPrintf(x + 1 * kColumnWidth, y + kRowHeight, "%6.02f", vector3.x);
	Novice::ScreenPrintf(x + 2 * kColumnWidth, y + kRowHeight, "%6.02f", vector3.y);
	Novice::ScreenPrintf(x + 3 * kColumnWidth, y + kRowHeight, "%6.02f", vector3.z);
	Novice::ScreenPrintf(x + 4 * kColumnWidth, y + kRowHeight, "%s", name);
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* name) {
	Novice::ScreenPrintf(x, y, "%s", name);
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight + 20, "%6.02f", matrix.m[row][column]);
		}
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

