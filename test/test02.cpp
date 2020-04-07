#include <iostream>

void replaceBlank(char str[], int len);
void mergeSortedArray(int A[], int numA, int const B[], int numB);

int main()
{
    char str[] = " We are happy!";
    replaceBlank(str, 20);
    std::cout << str << std::endl;

    int A[100] = {0, 2, 4, 6, 8, 10};
    int B[5] = {1, 3, 5, 7, 9};
    mergeSortedArray(A, 6, B, 5);
    for (int i = 0; i < 11; ++i) {
        std::cout << A[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}

void replaceBlank(char str[], int len)
{
    if (str == NULL || len <= 0)
        return;

    int numBlank = 0;
    int lenOrigin = 0;
    while (str[lenOrigin] != '\0')
    {
        if (str[lenOrigin] == ' ')
            numBlank++;
        lenOrigin++;
    }

    int lenNew = lenOrigin + numBlank * 2;
    if (lenNew > len)
        return;

    int indexOri = lenOrigin;
    int indexNew = lenNew;
    while (indexOri >= 0 && indexNew > indexOri)
    {
        if (str[indexOri] != ' ')
            str[indexNew--] = str[indexOri];
        else
        {
            str[indexNew--] = '0';
            str[indexNew--] = '2';
            str[indexNew--] = '%';
        }
        --indexOri;
    }
}

void mergeSortedArray(int A[], int numA, int const B[], int numB)
{
    if (A == NULL || B == NULL)
        return;

    int numANew = numA + numB;

    int indexANew = numANew - 1;
    int indexA = numA - 1;
    int indexB = numB - 1;

    while (indexANew > 0)
    {
        if (A[indexA] >= B[indexB])
        {
            A[indexANew] = A[indexA];
            --indexA;
        }
        else
        {
            A[indexANew] = B[indexB];
            --indexB;
        }
        --indexANew;
    }
}
