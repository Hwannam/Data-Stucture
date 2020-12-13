#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream input_file(argv[1], ios::binary);
	ofstream output_file(argv[2], ios::binary);

	char ch;
	
	while (!input_file.eof())
	{
		input_file.get(ch);
		
		if (input_file.eof()) break;
		if (input_file.bad()) break;
		if (ch == 0x0D)
		{
			cout << "CR Ÿ��" << endl;
			output_file << char(0x0D) << char(0x0A);
		}
		else output_file << ch;
	}

	input_file.close();
	output_file.close();

}
