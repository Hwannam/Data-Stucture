#include <iostream>
using namespace std;

struct LineType // A
{
	char info[80];
	LineType* next;
	LineType* back;
};

class TextEditor
{
public:
	TextEditor();
	~TextEditor();
	void GoToTop();
	void GoToBottom();

	void InsertLine(const char newline[]);
	void Print();
	void Printall();
private:
	LineType* Header;
	LineType* Trailer;
	LineType* currentLine;
};

TextEditor::TextEditor() // B
{
	Header = new LineType;
	Trailer = new LineType;
	strcpy_s(Header->info, "- - - Top of file - - -");
	strcpy_s(Trailer->info, "- - - Bottom of file - - -");

	Header->back = NULL;
	Header->next = Trailer;
	Trailer->back = Header;
	Trailer->next = NULL;
	currentLine = Header;
}

TextEditor::~TextEditor()
{
	LineType* temp;
	
	while ( Header!= NULL)
	{
		temp = Header;
		Header = Header->next;
		delete temp;
	}
}
void TextEditor::GoToTop() // C
                           // C�� Big-O�� list�ȿ� ����ִ� info�� ���� ���� �޶����Ƿ� O(N) �̴�.
{ 
	if (currentLine == Header || currentLine == Trailer)
	{
		currentLine = Trailer;
	}
	else
	{
		while (currentLine->back->back != NULL)
		{
			currentLine = currentLine->back;
		}
	}
}

void TextEditor::GoToBottom() // C
{
	if (currentLine == Header || currentLine == Trailer)
	{
		currentLine = Header;
	}
	else
	{
		while (currentLine->next->next != NULL)
		{
			currentLine = currentLine->next;
		}
	}
}

/* D

C�� Big-O�� list�ȿ� ����ִ� info�� ���� ���� �޶����Ƿ� O(N) �̴�.
�Ʒ��� ���� Header�� ���� ��尡 ù ����̰�, Trailer�� �� ��尡 �� ������� �̿��ϸ� O(1)�� �ȴ�.

void TextEditor::GoToTop()
{
	currentPos = Header.next;
}

void TextEditor::GoToBottom()
{
	currentPos = Trailer.back;
}
*/

void TextEditor::InsertLine(const char newline[]) // E
{
	LineType* newNode;
	newNode = new LineType;
	strcpy_s(newNode->info, newline);

	if (currentLine == Trailer)
	{
		newNode->back = Trailer->back;
		newNode->next = Trailer;
		Header->next = newNode;
		Trailer->back = newNode;
		currentLine = newNode;
	}
	else
	{
		newNode->back = currentLine;
		newNode->next = currentLine->next;
		currentLine->next->back = newNode;
		currentLine->next = newNode;
		currentLine = newNode;
	}
}

void TextEditor::Print()
{
	cout << currentLine->info << endl;
}

void TextEditor::Printall()
{
	LineType* newNode;
	newNode = Header;
	while (newNode != NULL)
	{
		cout << newNode->info << endl;
		newNode = newNode->next;
	}
}

int main()
{
	TextEditor t1;
	t1.GoToTop();
	cout << "��������� gototop" << endl;
	t1.Print();
	cout << endl;
	
	t1.GoToBottom();
	cout << "��������� gotobottom" << endl;
	t1.Print(); // ��������� gotobottom
	cout << endl;

	t1.InsertLine("Hello");
	t1.Print(); // Hello �߰�
	cout << endl;

	t1.InsertLine("World!");
	t1.Print(); // World �߰�
	cout << endl;

	cout << "���� list" << endl;
	t1.Printall();
	cout << endl;

	cout << "������� ������ gototop" << endl;
	t1.GoToTop(); // ������� ������ gototop
	t1.Print();
	cout << endl;

	cout << "������� ������ gotobottom" << endl;
	t1.GoToBottom(); // ������� ������ gotobottom
	t1.Print();
	cout << endl;
	return 0;
}