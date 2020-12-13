RelationType StrType::ComparedTo1(StrType& otherString) //strcmp�� ���
{
    int ans;
    ans = strcmp(letters, otherString.letters);
    if (ans == -1)
    {
        return LESS;
    }
    else if (ans == 0)
    {
        return EQUAL;
    }
    else if (ans == 1)
    {
        return GREATER;
    }
}

RelationType StrType::ComparedTo2(StrType otherString) // ���� ��
{
    int idx = 0;
    bool eq = 1;
    while (letters[idx] != '\0' && eq)
    {
        if (letters[idx] != otherString.letters[idx])
        {
            eq = -1;
            if (letters[idx] < otherString.letters[idx])
                return LESS;
            else if (letters[idx] > otherString.letters[idx])
                return GREATER;
        }
        else idx++;

        if (letters[idx] == '\0' && otherString.letters[idx] == '\0') return EQUAL;
        else if (letters[idx] == '\0') return LESS;
    }
}
