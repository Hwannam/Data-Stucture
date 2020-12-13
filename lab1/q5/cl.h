#pragma once

const int MAX_ROWS = 50;
class SquareMatrix
{
private:
	int matrix[50][50];
	int size;
public:
	void MakeEmpty(int);
	void StoreValue(int, int, int);
	void Add(SquareMatrix);
	void Subtract(SquareMatrix);
	void Copy(SquareMatrix);
	void show();
};

/* ADT

<구조>
N x N 크기의 정수 값을 갖는 정사각형 행렬

<연산>

MakeEmpty(int n)
-기능: Matrix의 n행 열 내부를 0으로 초기화
-조건: N의 최대 크기는 50
-결과: N안의 행 열은 0으로 초기화 

StoreValue(int i, int j ,int value)
-기능: Matrix의 i행 j열에 value 값을 저장 
-조건: Matrix가 초기화되어 있고, i, j 값은 0이상 (Matrix의 크기-1)이하 
-결과: Matrix의 i행 j열에 value 값을 저장됨 

Add(SquareMatrix A)
-기능: Matrix에 A Matrix를 더한다.
-조건: 두 Matrix가 초기화되어있고, 크기가 같아야 한다.
-결과: Matrix에 A Matrix가 더해진다. (Matrix = Matrix + A.Matrix)

Substract(SquareMatrix A)
-기능: Matrix에서 A Matrix를 뺀다.
-조건: 두 Matrix가 초기화되어있고, 크기가 같아야 한다.
-결과: Matrix에서 A Matrix가 빼진다. (Matrix = Matrix – A.Matrix)

Copy(SquareMatrix A)
-기능: A Matrix를 Matrix에 복사한다.
-조건: 두 Matrix가 초기화되어있고, 크기가 같아야 한다.
-기능: Matrix에 A Matrix 값이 저장됨. (Matrix = A.Matrix)

show()
-기능: Matrix를 화면에 출력시켜준다.
-조건: Matrix가 초기화되어있어야 한다.
-결과: 화면에 Matrix 값들이 행 열에 맞추어 출력된다.*/


/* 계획 작성
                                input                                  output
                                                        
MakeEmpty                        5                                    0 0 0 0 0
                                                                      0 0 0 0 0
                                                                      0 0 0 0 0
                                                                      0 0 0 0 0
                                                                      0 0 0 0 0

                                 0                                       X

                                 50                         0으로 이루어진 50x50행렬

StoreValue                  1, 1, 7                                   0 0 0 0 0
                                                                      0 7 0 0 0
                                                                      0 0 0 0 0
                                                                      0 0 0 0 0
                                                                      0 0 0 0 0

Add                       0 0 0 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 7 0 0 0 
                          0 0 6 0 0                                  0 0 6 0 0
                          0 0 0 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 0 0 0 0



Substract                 0 0 0 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 7 0 0 0 
                          0 0 6 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 0 0 0 0

Copy                      0 0 0 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 0 0 0 0 
                          0 0 6 0 0                                  0 0 6 0 0
                          0 0 0 0 0                                  0 0 0 0 0
                          0 0 0 0 0                                  0 0 0 0 0 */