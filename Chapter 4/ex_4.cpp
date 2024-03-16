#include <iostream>
#include <assert.h>
#include <cstring>
#include <algorithm>
using namespace std;

void ex_1()
{
    int num_int = 435;
    double num_double = 435.10f;
    char str_int[30];
    char str_double[30];

    itoa(num_int, str_int, 10);
    gcvt(num_double, 8, str_double);

    printf("str_int: %s\n", str_int);
    printf("str_double: %s\n", str_double);
}

void int2str(int n, char *str)
{
    char buf[10] = ""; // 初始化buf数组为空字符串
    int i = 0;
    int len = 0;
    int temp = n < 0 ? -n : n; // 获取n的绝对值

    if (str == NULL)
    {
        return;
    }

    while (temp)
    {
        buf[i++] = (temp % 10) + '0'; // 将temp的每一位上的数存入buf
        temp = temp / 10;
    }

    len = n < 0 ? ++i : i; // 如果n是负数，则多需要一位来存储负号
    str[i] = '\0';         // 末尾是结束符0

    while (1)
    {
        i--;
        if (buf[len - i - 1] == 0)
        {
            break;
        }
        str[i] = buf[len - i - 1]; // 把buf数组里的字符拷贝到字符串
        if (i == 0 && n < 0)
        {
            str[i] = '-'; // 如果是负数，添加一个负号
        }
    }
}

void ex_2()
{
    int nNum;
    char p[10];
    cout << "Please input an integer: ";
    cin >> nNum;
    cout << "output: ";
    int2str(nNum, p); // 整型数转换成字符串
    cout << p << endl;
}

void ex_3()
{
    int num_int;
    double num_double;
    char str_int[30] = "435";       // 将要被转换为整型值的字符串
    char str_double[30] = "436.55"; // 将要被转换为浮点型值的字符串

    num_int = atoi(str_int);       // 转换为整型值
    num_double = atof(str_double); // 转换为浮点型值

    cout << "num_int: " << num_int << endl;
    cout << "num_double: " << num_double << endl;
}

int str2int(const char *str)
{
    int temp = 0;
    const char *ptr = str;

    if (*str == '-' || *str == '+')
    {
        str++;
    }

    while (*str != 0)
    {
        if ((*str < '0') || (*str > '9')) // 不是数字
        {
            break;
        }
        temp = temp * 10 + (*str - '0');
        str++;
    }
    if (*ptr == '-')
    {
        temp = -temp;
    }
    return temp;
}

void ex_4()
{
    int n = 0;
    char p[10] = "";

    cin.getline(p, 20);
    n = str2int(p);

    cout << n << endl;
}

char* strcpy(char *strDest, const char* strSrc)
{
    if((strDest == NULL) || (strSrc == NULL))//判断参数strDest和strSrc的有效性
    {
        return NULL;
    } 
    char* strDestCopy = strDest; // 保存字符串的首地址

    while ((*strDest++ = *strSrc++)!='\0');

    return strDestCopy;
}

int getStrLen(const char* strSrc)
{
    int len = 0;
    while (*strSrc++ != '\0')
    {
        len ++;
    }
    return len;
}

void ex_5()
{
    char strSrc[] = "Hello, world!";
    char strDest[20];
    int len = 0;

    len = getStrLen(strcpy(strDest, strSrc));
    printf("strDest: %s\n", strDest);
    printf("Length of strDest: %d\n", len);
}

void *memcpy2(void *memTo, const void *memFrom, size_t size)
{
    assert((memTo !=NULL) && (memFrom != NULL)); //memTo 和 memFrom必须有效
    char* tempFrom = (char*) memFrom;
    char* tempTo   = (char*) memTo;

    while(size-- > 0)
    {
        *tempTo ++ = *tempFrom ++;
    }
    return memTo;
}

void ex_6()
{
    char strSrc[] = "Hello World!";
    char strDest[20];

    memcpy2(strDest, strSrc, 4);
    strDest[4] = '\0';
    printf("strDest: %s\n", strDest);
}

const char* strstr1(const char* src, const char* sub)
{
    const char* bp;
    const char* sp;

    if(src == NULL || sub== NULL)
    {
        return src;
    }

    while(*src)
    {
        bp = src;
        sp = sub;
        do
        {
            if(!*sp)
                return src;
        } while (*bp++ == *sp++);
        src += 1;
    }
    return NULL;
}

void ex_12()
{
    char p[] = "12345";
    char q[] = "34";

    const char *r = strstr(p,q);
    printf("r: %s\n", r);
}

void RevStr(char* src)
{
    char* start = src, *end = src, *ptr = src;
    while(*ptr++ != '\0') // 遍历字符串
    {
        if(*ptr == ' ' || *ptr =='\0')
        {
            end = ptr -1; //end指向单词末尾
            while(start < end)
            {
                swap(*start++, *end--);
            }
            start = end = ptr + 1;
        }
    }
    start = src, end = ptr - 2;
    while (start < end)
    {
        swap(*start++, *end--);
    }
}

void RevStr1(char *src)
{
    char* start = src;
    char* end = src;
    char* ptr = src;

    while(*ptr++ != '\0');
    end = ptr - 2; //找到字符串末尾
    while(start < end)
    {
        swap(*start++, *end--); //反转整个字符串
    }

    start = src, end = ptr-2;
    ptr = start;
    while(*ptr++ !='\0')
    {
        if(*ptr == ' ' || *ptr =='\0')
        {
            end = ptr - 1;
            while(start < end)
            {
                swap(*start++, *end--); //逆置单词
            }
            start = end = ptr + 1; //指向下一个单词开头 
        }
    }

}

void ex_13()
{
    char src[] = "I am from Shanghai";
    cout << src << endl;
    RevStr(src);
    cout << src << endl;
}

int IsRevStr(char* str)
{
    int len = strlen(str);
    int found = 1;    

    char* start = str;
    char* end = str + len - 1;

    if(str == NULL)
    {
        return -1;
    }

    while(start <= end)
    {
        if(*start++ != *end--)
        {
            found = 0;
            break;
        }
    }
    return found;
}

void ex_14()
{
    char str1[10] = "1234321";
    char str2[10] = "1234221";

    int test1 = IsRevStr(str1);
    int test2 = IsRevStr(str2);

    cout << "str1 is " << (test1 == 1 ? "": "not ") << "reverse string." << endl;
    cout << "str2 is " << (test2 == 1 ? "": "not ") << "reverse string." << endl;
}

int mystrcmp(const char* src, const char* dst)
{
    int ret = 0;

    while(*src && *dst)
    {
        if(*src!= *dst)
        {
            return (*src - *dst);
        }
        src ++;
        dst ++;
    }
    return (*src - * dst);
}

void ex_15()
{
    char str[10] = "1234567";
    char str1[10] = "1234567";
    char str2[10] = "12345678";
    char str3[10] = "1234566";

    int test1 = mystrcmp(str, str1);
    int test2 = mystrcmp(str, str2);
    int test3 = mystrcmp(str, str3);

    cout << "test1 = " << test1 << endl;
    cout << "test2 = " << test2 << endl;
    cout << "test3 = " << test3 << endl;
}


char* commonString(char* str1, char* str2)
{
    char* longStr = str1;
    char* shortStr = str2;
    char* subStr = NULL;

    if(NULL == str1 || NULL == str2)
    {
        return NULL;
    }

    if(strlen(str1) <= strlen(str2))
    {
        shortStr = str1;
        longStr  = str2;
    }
    else
    {
        shortStr = str2;
        longStr  = str1;
    }

    if(strstr(longStr, shortStr) !=NULL)
    {
        return shortStr;
    }

    subStr = (char*)malloc(sizeof(char) * (strlen(shortStr + 1)));

    for(int i = strlen(shortStr)-1; i>0; i--)
    {
        for(int j = 0; j <=strlen(shortStr) -i; j++)
        {
            memcpy(subStr, &shortStr[j], i);
            subStr[i] = '\0';
            if(strstr(longStr, subStr) !=NULL)
            {
                return subStr;
            }
        }
    }
    return NULL;
}

void ex_16()
{
    char str1[256];
    char str2[256];
    char* common;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // 移除换行符
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    common = commonString(str1, str2);
    printf("The longest common string is: %s\n", common);
}


char* get2String(long num) //得到二进制形式的字符串
{
    int i =0;
    char* buffer;
    char* temp;

    buffer = (char*)malloc(33);
    temp = buffer;
    for(i = 0; i< 32; i++)
    {
        temp[i] = num& (1 << (31 - i));
        temp[i] = temp[i] >> (31 - i);
        temp[i] = (temp[i] == 0) ? '0' : '1';
    }
    buffer[32] = '\0';
    return buffer;
}

char* get16String(long num) //得到十六进制形式的字符串
{
    int i = 0;
    char* buffer = (char*)malloc(11);
    char* temp;
    buffer[0] = '0';
    buffer[1] = 'x';
    buffer[10] = '\0';
    temp = buffer + 2;

    for(i = 0; i < 8; i++)
    {
        temp[i] = (char)(num << (4 * i) >> 28);
        temp[i] = temp[i] >=0 ? temp[i] : temp[i] +16;
        temp[i] = temp[i] < 10 ? temp[i] + 48 : temp[i] + 55;
    }
    return buffer;
}

void ex_17()
{
    long num = 1;

    char* binaryStr = get2String(num);
    std::cout << "Binary: " << binaryStr << std::endl;
    //free(binaryStr); // 释放内存

    char* hexStr = get16String(num);
    std::cout << "Hexadecimal: " << hexStr << std::endl;
    //free(hexStr); // 释放内存
}


char* transformation(const char* str) {
    int len = strlen(str); // 获取输入字符串的长度
    char* result = (char*)malloc(2 * len + 1); // 分配足够的空间来存储转换后的字符串
    char countBuf[10]; // 用于将数字转换为字符串的缓冲区

    int count = 1; // 统计相邻字符相同的个数
    int idx = 0; // 用于遍历输入字符串
    int pos = 0; // 用于遍历输出字符串

    // 遍历输入字符串
    while (str[idx] != '\0') {
        // 如果当前字符与下一个字符相同，则增加计数
        if (str[idx] == str[idx + 1]) {
            count++;
        } else {
            // 否则，将当前字符以及计数插入到结果字符串中
            result[pos++] = str[idx];
            sprintf(countBuf, "%d", count);
            int countLen = strlen(countBuf);
            strncpy(result + pos, countBuf, countLen);
            pos += countLen;
            count = 1; // 重置计数
        }
        idx++;
    }

    // 添加结尾的空字符
    result[pos] = '\0';

    return result;
}

void ex_18()
{
    char str[200];

    // 提示用户输入一个字符串并读取
    printf("Please input a string: ");
    scanf("%s", str);

    // 打印转换前的字符串
    printf("Before transformation: %s\n", str);

    // 调用转换函数，得到转换后的字符串
    char* pstr = transformation(str);

    // 打印转换后的字符串
    printf("After transformation: %s\n", pstr);
}

void encodeString(char* str)
{
    if(str == NULL)
    {
        return;
    }

    int len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        if(isalpha(str[i]))
        {
            char replacement = str[i] + 4;
            if((isupper(replacement) && replacement > 'Z') 
            ||  islower(replacement) && replacement > 'z')
            {
                replacement -= 26;
            }
        }
    }

    // 反转字符串
    for(int i = 0; i < len / 2; ++i)
    {
        char temp = str[i];
        str[i] = str[len - i -1];
        str[len - i -1] = temp;
    }
}

void ex_19()
{
    char str[20];
    std::cout << "Enter a string (max length 19): ";
    std::cin.getline(str, 20);

    encodeString(str);

    std::cout << "Encoded string: " << str << std::endl;
}

// 反转字符串
void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// 反转字符串，但保留子串顺序不变
void reverseExceptSubstring(char* str, const char* substr) {
    int strLen = strlen(str);
    int subLen = strlen(substr);
    int start = 0;

    // 找到子串在字符串中的位置
    char* found = strstr(str, substr);
    if (found == nullptr) {
        // 如果子串不存在，则直接反转整个字符串
        reverseString(str, 0, strLen - 1);
        return;
    }
    start = found - str; // 子串在字符串中的起始位置

    // 创建临时缓冲区，用于保存子串
    char* temp = new char[subLen + 1];
    strncpy(temp, found, subLen);
    temp[subLen] = '\0'; // 确保临时缓冲区以 null 结尾

    // 反转子串之前的部分
    reverseString(str, 0, start - 1);

    // 反转子串之后的部分
    reverseString(str, start + subLen, strLen - 1);

    // 打印结果
    std::cout << "before reverse: " << str << std::endl;
    std::cout << "temp substring: " << temp << std::endl;

    // 删除动态分配的临时缓冲区
    delete[] temp;
}

void ex_20()
{
    char str[] = "welcome you,my friend";
    char substr[] = "you";
    reverseExceptSubstring(str, substr);
}

// 两个开始和结尾的指针交换
char* strrev1(const char* str)
{
    int len = strlen(str);
    char* temp = new char[len + 1];

    strcpy(temp, str);
    for(int i = 0; i < len / 2 ; ++i)
    {
        char c = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = c;
    }
    return temp;
}

char* strrev2(const char* str)
{
    int len = strlen(str);
    char* temp = new char[len + 1];
    strcpy(temp, str);
    char* ret = temp;
    char* p = temp + len -1;

    while(temp < p)
    {
        char t = *temp;
        *temp = *p;
        *p = t;

        --p;
        ++temp;
    }
    
    return ret;
}


char* strrev3(const char* str)
{
    int len = strlen(str);
    char* temp = new char[len + 1];
    strcpy(temp, str);
    char* ret = temp;
    char* p = temp + len -1;

    while(temp < p)
    {
        *p ^= *temp;
        *temp ^= *p;
        *p ^= *temp;

        --p;
        ++temp;
    }
    return ret;
}

// void ex_21()
// {
//     char* str1 = "123456";
//     cout << str1 << endl;
//     char* str11 = strrev1(str1);
//     cout << "reverse1:" << str11 << endl;

//     char* str2 = "123456";
//     cout << str2 << endl;
//     char* str22 = strrev2(str2);
//     cout << "reverse2:" << str22 << endl;

//     char* str3 = "123456";
//     cout << str3 << endl;
//     char* str33 = strrev3(str3);
//     cout << "reverse3:" << str33 << endl;

// }

// char* add(const char* num1, const char* num2)
// {
//     int len1 = strlen(num1);
//     int len2 = strlen(num2);
//     int maxlen = std::max(len1, len2);
//     char* result = new char[maxlen + 2];
//     result[maxlen + 1] = '\0';

//     int carry = 0;
//     for(int i = 0; i < maxlen || carry; ++i)
//     {
//         int digit1 = i < len1 ? num1[len1 - 1 - i] - '0' : 0;
//         int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0;
//         int sum =  digit1 + digit2 + carry;
//         carry = sum / 10;
//         result[maxlen - i] = (sum % 10) + '0';
//     }

//     if (result[0] == '0') {
//         // 如果最高位是0，去掉前导0
//         char* trimmed_result = new char[maxlen + 1];
//         strcpy(trimmed_result, result + 1);
//         delete[] result;
//         return trimmed_result;
//     }

//     return result;
// }

// void ex_22()
// {
//     const char* num1 = "123456789323";
//     const char* num2 = "45671254563123";
//     char* sum = add(num1, num2);
//     std::cout << "Sum: " << sum << std::endl;
//     delete[] sum;
// }


void rightRotateString(char* str, int k) 
{
    int len = strlen(str);
    if(len == 0 || k == 0)
    {
        return;
    }
    k %= len;

    char* temp = new char[len + 1];
    temp[len] = '\0';
    strncpy(temp, str + len - k, k);
    strncpy(temp + k, str, len -k);

    strcpy(str, temp);
    delete[] temp;
}

void ex_23()
{
    char str[] = "HelloWorld";
    int k = 3;
    
    std::cout << "Original string: " << str << std::endl;
    rightRotateString(str, k);
    std::cout << "After right rotation by " 
    << k << " characters: " << str << std::endl;
}

void deleteChars(char* str, int start, int length)
{
    if (str == nullptr || start < 0 || length <= 0) {
        return; // 非法输入
    }

    int len = strlen(str);
    if(start >= len)
    {
        return;
    }

    for(int i = start; i < len - length; ++i)
    {
        str[i] = str[i + length];
    }

    str[len - length] = '\0';
}

void ex_24()
{
    char str[] = "HelloWorld";
    int start = 3; // 起始位置
    int length = 2; // 要删除的字符长度

    std::cout << "Original string: " << str << std::endl;
    deleteChars(str, start, length);
    std::cout << "After deletion: " << str << std::endl;
}

void mysort(char* str, int num)
{

    int temp = 0;

    for(int i = 0; i < num; ++i)
    {
        for(int j = i + 1; j < num; ++j)
        {
            if(str[i] < str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

}

char* splitAndSortString(char* str)
{
    int len = 0;
    char* start = NULL;
    if(str == NULL)
    {
        return NULL;
    }

    start = str; //保存头部位置
    while(*str++);
    len = str - start -1;
    len = len / 2; //排序个数
    str = start;

    mysort(str, len);
    return str;
}

void ex_25()
{
    char str[] = "ADZDDJKJFIEJHGI";
    cout << splitAndSortString(str);
}


char* deleteChar(char *str, char c)
{
    char* head = NULL;
    char* p = NULL;

    if(str == NULL)
    {
        return NULL;
    }

    head = p = str;
    while(*p ++)
    {
        if(*p != c)
        {
            *str++ = *p;
        }
    }
    *str = '\0';
    return head;
}

void ex_26()
{
    char string[] = "cabcdefcgchci";
    char c = 0;

    printf("Input character to delete: ");
    scanf("%c", &c);

    printf("Before delete: %s\n", string);
    deleteChar(string, c);
    printf("After delete: %s\n", string);
}

// void ex_27()
// {
//     char *str1 = "hello";
//     char *str2 = "  china";
//     char *str3 = NULL;
    
//     str3 = new char[strlen(str1) + strlen(str2) + 1];
//     str3[0] = '\0'; // Corrected: Initialize str3 to an empty string
    
//     strcat(str3, str1);
//     strcat(str3, str2);
    
//     cout << str3 << endl;
    
//     delete[] str3; // Corrected: Deallocate memory allocated with new[]
// }

char* mystrcat(char* dest, const char* src)
{
    char * ret;

    ret = dest;
    while(*dest++);
    dest--;
    while (*dest++ = *src++);

    return ret;
}


void ex_28()
{
    const char* str1 = "Hello ";
    const char* str2 = "World!";

    char* dest = (char*)malloc(256);
    *dest = '\0';
    mystrcat(mystrcat(dest, str1), str2);
    printf("dest: %s\n", dest);
    free(dest);
    dest = NULL;
}

// 判断字符是否为汉字（UTF-8编码）
bool isChinese(char ch) {
    return (ch & 0x80) && !(ch & 0x40);
}

// 计算含有汉字的字符串长度
int chineseStringLength(const char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isChinese(str[i])) {
            length += 2; // 汉字占两个字节
        } else {
            length += 1; // 英文字符和其他字符占一个字节
        }
    }
    return length;
}

void ex_29()
{
    const char* str = "Hello, 你好！";
    cout << "String length with Chinese characters: " << chineseStringLength(str) << endl;
}


void Caculate(const char* str, int *max0, int *max1)
{
    int temp0 = 0; 
    int temp1 = 0;
    while(*str)
    {
        if(*str == '0')
        {
            (*max0)++;
            if(*(str + 1) == '1')
            {
                if(temp0  < *max0)
                {
                    temp0 = *max0;
                }
                *max0 = 0;
            }
        }
        else if(*str == '1')
        {
            (*max1)++;
            if(*(str + 1) == '0')
            {
                if(temp1 < *max1)
                {
                    temp1 = *max1;
                }
                *max1 = 0;
            }
        }
        str++;
    }
    *max0 = temp0;
    *max1 = temp1;
}

void ex_30()
{
    char string[] = "00001110110000001100110101101001010101011111010";

    int max0 = 0;
    int max1 = 0;

    Caculate(string, &max0, &max1);
    cout << "max0 = " << max0 << endl;
    cout << "max1 = " << max1 << endl;
}

// 函数用于在字符串中替换指定的子串
char* replaceSubstring(char* original, const char* target, const char* replacement) 
{
    char* result;
    char* temp;
    char* newString;
    int len;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);
    int count = 0;

    temp = original;
    while ((temp = strstr(temp, target))) {
        count++;
        temp += targetLen;
    }

    len = strlen(original) + count * (replacementLen - targetLen) + 1;
    newString = (char*)malloc(len);

    result = newString;
    while (*original) {
        if (strstr(original, target) == original) {
            strcpy(result, replacement);
            result += replacementLen;
            original += targetLen;
        } else {
            *result++ = *original++;
        }
    }
    *result = '\0';

    return newString;
}

void ex_31()
{
    char str[] = "hello world hello world hello";
    char target[] = "hello";
    char replacement[] = "hi";

    char* result = replaceSubstring(str, target, replacement);
    printf("替换后的字符串: %s\n", result);
}

int main()
{

    // ex_1();

    // ex_2();

    // ex_3();

    //ex_4();

    //ex_5();

    //ex_6();

    // ex_12();

    //ex_13();

    //ex_14();

    //ex_15();

    //ex_16();

    //ex_17();

    //ex_18();

    //ex_19();

    //ex_20();

    //ex_21();

    //ex_22();

    //ex_23();

    //ex_24(); 

    //ex_25();

    //ex_26();

    //ex_27();

    //ex_28();

    //ex_29();

    //ex_30();

    ex_31();

    return 0;
}