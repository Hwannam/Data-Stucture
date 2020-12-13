#pragma once

enum RelationType { LESS, EQUAL, GREATER };

class StrType
{
public:
	
	RelationType ComparedTo1(StrType& otherString);
	RelationType ComparedTo2(StrType otherString);

};
