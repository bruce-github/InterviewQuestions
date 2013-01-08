// ReplaceBlank.cpp : Defines the entry point for the console application.
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

/*
void ReplaceBlank(char string[], int length)
{
    if(string == NULL && length <= 0)
        return;

    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        ++ originalLength;

        if(string[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(string[indexOfOriginal] == ' ')
        {
            string[indexOfNew --] = '0';
            string[indexOfNew --] = '2';
            string[indexOfNew --] = '%';
        }
        else
        {
            string[indexOfNew --] = string[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}
*/
//==============My code begin=========================
void MyReplaceBlank(string &str)
{
	if (str.empty())
		return;

	int countBlank = 0;
	for (string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == ' ')
		{
			++countBlank;
		}
	}

	string::reverse_iterator itPrev = str.rbegin();
	const int REPLACENUM = 2;
	str.resize(str.size() + REPLACENUM * countBlank);
	string::reverse_iterator itCurr = str.rbegin();

	for (; itPrev != str.rend(); ++itPrev)
	{
		if (*itPrev != ' ')
		{
			*itCurr = *itPrev;
			++itCurr;
		}
		else
		{
			*(itCurr++) = '0';
			*(itCurr++) = '2';
			*(itCurr++) = '%';
			
			--countBlank;
			if ( 0 == countBlank)
				break;
		}
	}

}

void ReplaceBlank(char str[], int length)
{
	if (str == NULL || length < 1)
		return;
	string strTmp(str);
	MyReplaceBlank(strTmp);

	if (length >= static_cast<int>(strTmp.size()))
	{
		memcpy(str, strTmp.data(), sizeof(char) * strTmp.size());
		str[strTmp.size()] = '\0';
	}
	return;
}
//================My code end===================

void Test(char* testName, char string[], int length, char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(string, length);

    if(expected == NULL && string == NULL)
        printf("passed.\n");
    else if(expected == NULL && string != NULL)
        printf("failed.\n");
    else if(strcmp(string, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int length = 100;

    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

void Test2()
{
    const int length = 100;

    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

void Test3()
{
    const int length = 100;

    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

void Test4()
{
    const int length = 100;

    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

void Test6()
{
    const int length = 100;

    char string[length] = "";
    Test("Test6", string, length, "");
}

void Test7()
{
    const int length = 100;

    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

void Test8()
{
    const int length = 100;

    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

void Test9()
{
    const int length = 100;

    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

