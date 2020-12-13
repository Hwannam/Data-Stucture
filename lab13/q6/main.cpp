#include <iostream>
using namespace std;

template <class ItemType>
int GetHeight(ItemType values[], int start, int numValues);

template <class ItemType>
int GetHeightSum(ItemType values[ ], int numValues)
{
  int  index, sum=0;
  // non-leaf ��忡 ���� �� ��带 ��Ʈ�� �ϴ� subtree�� height ���
  for (index =0; index<numValues; index++)
      sum += GetHeight ( values, index , numValues - 1 ) ;

  cout << "sum of heights = " << sum << endl;
  return sum;
} 

template <class ItemType>
int GetHeight(ItemType values[ ], int start, int numValues)
{
  if (start*2+1>numValues || start >numValues) return 0; // start�� leaf�̰ų� tree �ۿ� �ִ� ���
  int l_height = GetHeight(values, start*2+1, numValues); // left subtree�� height
  int r_height = GetHeight(values, start * 2 + 2, numValues); // right subtree�� height
  return max(l_height, r_height)+1; // ��subtree height �� ū �� + 1�� �� ����
} 

int main()
{
	int ary[9] = { 25,17,36,2,3,100,1,19,7 };
	
	GetHeightSum(ary, 9);
	
	return 0;
}