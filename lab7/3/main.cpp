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
                           // C의 Big-O는 list안에 들어있는 info의 수에 따라 달라지므로 O(N) 이다.
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

C의 Big-O는 list안에 들어있는 info의 수에 따라 달라지므로 O(N) 이다.
아래와 같이 Header의 다음 노드가 첫 노드이고, Trailer의 전 노드가 끝 노드임을 이용하면 O(1)이 된다.

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
	cout << "비어있을때 gototop" << endl;
	t1.Print();
	cout << endl;
	
	t1.GoToBottom();
	cout << "비어있을때 gotobottom" << endl;
	t1.Print(); // 비어있을때 gotobottom
	cout << endl;

	t1.InsertLine("Hello");
	t1.Print(); // Hello 추가
	cout << endl;

	t1.InsertLine("World!");
	t1.Print(); // World 추가
	cout << endl;

	cout << "현재 list" << endl;
	t1.Printall();
	cout << endl;

	cout << "비어있지 않을때 gototop" << endl;
	t1.GoToTop(); // 비어있지 않을때 gototop
	t1.Print();
	cout << endl;

	cout << "비어있지 않을때 gotobottom" << endl;
	t1.GoToBottom(); // 비어있지 않을때 gotobottom
	t1.Print();
	cout << endl;
	return 0;
}