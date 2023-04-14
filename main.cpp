#include <Novice.h>
#include <Vector3.h>
#include <math.h>

Vector3 add(const Vector3& v1, const Vector3& v2) {//加算
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

Vector3 Subtract(const Vector3& v1, const Vector3& v2) {//減算
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

Vector3 Multiply(float scalar, const Vector3& v1) {//スカラー倍
	Vector3 result;
	result.x = scalar* v1.x;
	result.y = scalar* v1.y;
	result.z = scalar* v1.z;
	return result;
}

float Dot(const Vector3& v1, const Vector3& v2) {//内積
	float result;
	result = v1.x* v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}

float Length(const Vector3& v) {//長さ(ノルム)
	float result;
	result = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return result;
}

Vector3 Normalize(const Vector3& v) {//正規化
	float length = Length(v);

	if (length != 0) {
		return { v.x / length,v.y / length,v.z / length };
	}

	return v;
}

static const int kColumnWidth = 60;
static const int kRowHeight = 20;
void VectorScreenPrinf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}

Vector3 v1(1.0f, 3.0f, -5.0f);
Vector3 v2{ 4.0f,-1.0f,2.0f };
float k = { 4.0f };

Vector3 resultAdd = add(v1, v2);
Vector3 resulatSubtract = Subtract(v1, v2);
Vector3 resultMultiply = Multiply(k, v1);
float resultDot = Dot(v1, v2);
float resultLength = Length(v1);
Vector3 resultNormalize = Normalize(v2);


const char kWindowTitle[] = "LE2B_07_カトウユウタ_タイトル";

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

		VectorScreenPrinf(0, 0, resultAdd, "   : add");
		VectorScreenPrinf(0, kRowHeight, resulatSubtract, "   : Subtract");
		VectorScreenPrinf(0, kRowHeight * 2, resultMultiply, "   : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%.02f  : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%.02f  : Length", resultLength);
		VectorScreenPrinf(0, kRowHeight * 5, resultNormalize, "   : Normalize");

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

