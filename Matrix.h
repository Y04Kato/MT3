#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include <assert.h>
#include <cmath>

float contangent(float b, float a) {
	return(b / tan(a));
}

// 1 X軸回転行列
Matrix4x4 MakeRotateXmatrix(float radian);

// 2 Y軸回転行列
Matrix4x4 MakeRotateYmatrix(float radian);

// 3 Z軸回転行列
Matrix4x4 MakeRotateZmatrix(float radian);

// 平行移動
Matrix4x4 MakeTranslateMatrix(Vector3 translate);

// 拡大縮小
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// アフィン変換
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

//ビューポート変換行列
Matrix4x4 MakeViweportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

//透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRadio, float nearClip, float farClip);

//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

//逆行列
Matrix4x4 Inverse(const Matrix4x4& m1);

//座標変換
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);