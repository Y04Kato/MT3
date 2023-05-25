#include <Novice.h>
#include "Matrix.h"

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

Vector3 Cross(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Vector3 v1{ 1.2f,-3.9f,2.5f };
	Vector3 v2{ 2.0f,0.4f,-1.3f };
	Vector3 cross = Cross(v1, v2);

	Vector3 rotate{};
	Vector3 translate{};

	Vector3 cameraPosition{ 0.0f,0.0f,-10.0f };
	Vector3 kLocalVertices[3]{
		{1.5f,1.0f,1.0f},
		{0.0f,-1.0f,1.0f},
		{3.0f,-1.0f,1.0f}
	};

	Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
	Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, cameraPosition);
	Matrix4x4 viewMatrix = Inverse(cameraMatrix);
	Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45, float(1280) / float(720), 0.1f, 100.0f);
	Matrix4x4 worldviewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
	Matrix4x4 viewportMatrix = MakeViweportMatrix(0, 0, float(1280), float(720), 0.0f, 1.0f);

	Vector3 screenVertices[3];
	for (uint32_t i = 0; i < 3; i++) {
		Vector3 ndcVertex = Transform(kLocalVertices[i], worldviewProjectionMatrix);
		screenVertices[i] = Transform(ndcVertex, viewportMatrix);
	}

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

		if (keys[DIK_W]) {
			translate.z += 0.1f;
		}
		else if (keys[DIK_S]) {
			translate.z += -0.1f;
		}
		else {}
		//左右
		if (keys[DIK_D]) {
			translate.x += 0.1f;
		}
		else if (keys[DIK_A]) {
			translate.x += -0.1f;
		}
		else {}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, cross, "Cross");
		Novice::DrawTriangle(
			int(screenVertices[0].x), int(screenVertices[0].y),
			int(screenVertices[1].x), int(screenVertices[1].y),
			int(screenVertices[2].x), int(screenVertices[2].y),RED,kFillModeSolid);
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

