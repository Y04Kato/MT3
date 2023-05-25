#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include <assert.h>
#include <cmath>

float contangent(float b, float a) {
	return(b / tan(a));
}

// 1 X����]�s��
Matrix4x4 MakeRotateXmatrix(float radian);

// 2 Y����]�s��
Matrix4x4 MakeRotateYmatrix(float radian);

// 3 Z����]�s��
Matrix4x4 MakeRotateZmatrix(float radian);

// ���s�ړ�
Matrix4x4 MakeTranslateMatrix(Vector3 translate);

// �g��k��
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// �A�t�B���ϊ�
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

//�r���[�|�[�g�ϊ��s��
Matrix4x4 MakeViweportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

//�������e�s��
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRadio, float nearClip, float farClip);

//���ˉe�s��
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

//�t�s��
Matrix4x4 Inverse(const Matrix4x4& m1);

//���W�ϊ�
Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);