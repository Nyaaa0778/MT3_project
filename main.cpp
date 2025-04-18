#include <Novice.h>
#include <cmath>

const char kWindowTitle[] = "LE2B_27_ヤマダ_ナオ_0_5_確認課題";

typedef struct Matrix4x4 {
  float m[4][4];
} Matrix4x4;

typedef struct Vector3 {
  float x;
  float y;
  float z;
} Vector3;

/// <summary>
/// 行列の積
/// </summary>
/// <param name="m1"></param>
/// <param name="m2"></param>
/// <returns></returns>
Matrix4x4 Multiply(const Matrix4x4 &m1, const Matrix4x4 &m2) {
  Matrix4x4 result;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      result.m[i][j] = 0;
      for (int k = 0; k < 4; ++k) {
        result.m[i][j] += m1.m[i][k] * m2.m[k][j];
      }
    }
  }

  return result;
}

/// <summary>
/// 拡縮行列
/// </summary>
/// <param name="scale"></param>
/// <returns></returns>
Matrix4x4 MakeScaleMatrix(const Vector3 &scale) {
  Matrix4x4 result;

  result.m[0][0] = scale.x;
  result.m[0][1] = 0.0f;
  result.m[0][2] = 0.0f;
  result.m[0][3] = 0.0f;
  result.m[1][0] = 0.0f;
  result.m[1][1] = scale.y;
  result.m[1][2] = 0.0f;
  result.m[1][3] = 0.0f;
  result.m[2][0] = 0.0f;
  result.m[2][1] = 0.0f;
  result.m[2][2] = scale.z;
  result.m[2][3] = 0.0f;
  result.m[3][0] = 0.0f;
  result.m[3][1] = 0.0f;
  result.m[3][2] = 0.0f;
  result.m[3][3] = 1.0f;

  return result;
}

/// <summary>
/// X軸周りの回転行列
/// </summary>
/// <param name="radian"></param>
/// <returns></returns>
Matrix4x4 MakeRotateXMatrix(float radian) {
  Matrix4x4 result;
  result.m[0][0] = 1.0f;
  result.m[0][1] = 0.0f;
  result.m[0][2] = 0.0f;
  result.m[0][3] = 0.0f;
  result.m[1][0] = 0.0f;
  result.m[1][1] = std::cos(radian);
  result.m[1][2] = std::sin(radian);
  result.m[1][3] = 0.0f;
  result.m[2][0] = 0.0f;
  result.m[2][1] = -std::sin(radian);
  result.m[2][2] = std::cos(radian);
  result.m[2][3] = 0.0f;
  result.m[3][0] = 0.0f;
  result.m[3][1] = 0.0f;
  result.m[3][2] = 0.0f;
  result.m[3][3] = 1.0f;

  return result;
}

/// <summary>
/// Y軸周りの回転行列
/// </summary>
/// <param name="radian"></param>
/// <returns></returns>
Matrix4x4 MakeRotateYMatrix(float radian) {
  Matrix4x4 result;
  result.m[0][0] = std::cos(radian);
  result.m[0][1] = 0.0f;
  result.m[0][2] = -std::sin(radian);
  result.m[0][3] = 0.0f;
  result.m[1][0] = 0.0f;
  result.m[1][1] = 1.0f;
  result.m[1][2] = 0.0f;
  result.m[1][3] = 0.0f;
  result.m[2][0] = std::sin(radian);
  result.m[2][1] = 0.0f;
  result.m[2][2] = std::cos(radian);
  result.m[2][3] = 0.0f;
  result.m[3][0] = 0.0f;
  result.m[3][1] = 0.0f;
  result.m[3][2] = 0.0f;
  result.m[3][3] = 1.0f;

  return result;
}

/// <summary>
/// Z軸周りの回転行列
/// </summary>
/// <param name="radian"></param>
/// <returns></returns>
Matrix4x4 MakeRotateZMatrix(float radian) {
  Matrix4x4 result;
  result.m[0][0] = std::cos(radian);
  result.m[0][1] = std::sin(radian);
  result.m[0][2] = 0.0f;
  result.m[0][3] = 0.0f;
  result.m[1][0] = -std::sin(radian);
  result.m[1][1] = std::cos(radian);
  result.m[1][2] = 0.0f;
  result.m[1][3] = 0.0f;
  result.m[2][0] = 0.0f;
  result.m[2][1] = 0.0f;
  result.m[2][2] = 1.0f;
  result.m[2][3] = 0.0f;
  result.m[3][0] = 0.0f;
  result.m[3][1] = 0.0f;
  result.m[3][2] = 0.0f;
  result.m[3][3] = 1.0f;

  return result;
}

/// <summary>
/// 平行移動行列
/// </summary>
/// <param name="translate"></param>
/// <returns></returns>
Matrix4x4 MakeTranslateMatrix(const Vector3 &translate) {
  Matrix4x4 result;
  result.m[0][0] = 1.0f;
  result.m[0][1] = 0.0f;
  result.m[0][2] = 0.0f;
  result.m[0][3] = 0.0f;
  result.m[1][0] = 0.0f;
  result.m[1][1] = 1.0f;
  result.m[1][2] = 0.0f;
  result.m[1][3] = 0.0f;
  result.m[2][0] = 0.0f;
  result.m[2][1] = 0.0f;
  result.m[2][2] = 1.0f;
  result.m[2][3] = 0.0f;
  result.m[3][0] = translate.x;
  result.m[3][1] = translate.y;
  result.m[3][2] = translate.z;
  result.m[3][3] = 1.0f;

  return result;
}

/// <summary>
/// アフィン変換行列
/// </summary>
/// <param name="scale"></param>
/// <param name="rotate"></param>
/// <param name="translate"></param>
/// <returns></returns>
Matrix4x4 MakeAffineMatrix(const Vector3 &scale, const Vector3 &rotate,
                           const Vector3 &translate) {

  Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);

  Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
  Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
  Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);

  Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);

  Matrix4x4 worldMatrix = Multiply(
      Multiply(Multiply(Multiply(scaleMatrix, rotateXMatrix), rotateYMatrix),
               rotateZMatrix),
      translateMatrix);


  return worldMatrix;
}

// 行列の表示
static const int kRowHeight = 30;
static const int kColumnWidth = 60;

void MatrixScreenPrintf(int x, int y, const Matrix4x4 &matrix,
                        const char *label) {
  Novice::ScreenPrintf(x, y, "%s", label);

  for (int row = 0; row < 4; ++row) {
    for (int column = 0; column < 4; ++column) {
      Novice::ScreenPrintf(x + column * kColumnWidth, 30 + y + row * kRowHeight,
                           "%6.02f", matrix.m[row][column]);
    }
  }
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

  // ライブラリの初期化
  Novice::Initialize(kWindowTitle, 1280, 720);

  // キー入力結果を受け取る箱
  char keys[256] = {0};
  char preKeys[256] = {0};

  Vector3 scale{1.2f, 0.79f, -2.1f};
  Vector3 rotate{0.4f, 1.43f, -0.8f};
  Vector3 translate{2.7f, -4.15f, 1.57f};
  Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);

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

    MatrixScreenPrintf(0, 0, worldMatrix, "worldMatrix");

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
