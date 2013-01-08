#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char *pData)
{
    if(pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

void CMyString::Print()
{
	cout << m_pData << endl;
}

//===============My code begin========================
CMyString &CMyString::operator = (const CMyString &str)
{
	if (&str != this)
	{
		CMyString tmp(str);

		char *pTmpDate = tmp.m_pData;
		tmp.m_pData = m_pData;
		m_pData = pTmpDate;
	}

	return *this;
}
//====================My code end=================================

//=====================test==================

void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
}

void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
}

void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
}

int main()
{
	Test1();
	Test2();
	Test3();

	return 0;
}




















