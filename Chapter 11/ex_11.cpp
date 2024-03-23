#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <map>
using namespace std;

void Order(vector<int>& data)
{
    int count = data.size();
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < count -i -1; j++)
        {
            if(data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j]  = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void ex_5()
{
    vector<int> data;
    ifstream in("./TXT/data.txt");
    if(!in)
    {
        cout << "infile error!" << endl;
        return;
    }
    int temp;
    while(!in.eof())
    {
        in >> temp;
        data.push_back(temp);
    }
    in.close();
    Order(data);
    ofstream out("./TXT/result.txt");
    if(!out)
    {
        cout << "outfile error!" << endl;
        return;
    }
    for(int i = 0; i < data.size(); ++ i)
    {
        out << data[i] << " ";
    }
    out.close();
}

void ex_11()
{
    set<string> strset;
    set<string>::iterator si;

    strset.insert("cantaloupes");
    strset.insert("apple");
    strset.insert("orange");
    strset.insert("banana");
    strset.insert("grapes");
    strset.insert("grapes");

    strset.erase("banana");

    for (si = strset.begin(); si != strset.end(); si++) {
        cout << *si << " ";
    }
    
    cout << endl;
}

void ex_12()
{
    map<int, string> mapstring;

    // 插入4个元素
    mapstring.insert(pair<int, string>(1, "one"));
    mapstring.insert(pair<int, string>(4, "four"));
    mapstring.insert(pair<int, string>(3, "three"));
    mapstring.insert(pair<int, string>(2, "two"));
    
    // 4已经存在，插入失败
    mapstring.insert(pair<int, string>(4, "four four"));
    
    // 1已经存在，修改键为1对应的值
    mapstring[1] = "one one";
    
    // 5不存在，添加键为5且值为"five"的元素
    mapstring[5] = "five";

    cout << mapstring[1] << endl; // 打印键为1对应元素的值

    mapstring.erase(2); // 删除键为2的元素
    
    // 查找键为2的元素
    map<int, string>::iterator f = mapstring.find(2);
    
    // 如果查找成功，则不相等
    if (f != mapstring.end()) {
        mapstring.erase(f);
        // 使用迭代器遍历map中所有元素
        map<int, string>::iterator it = mapstring.begin();
        while (it != mapstring.end()) {
            cout << (*it).first << " " << (*it).second << endl; // 打印元素的键和值
            it++;
        }
    }
}

int main(void)
{

    // ex_5();

    // ex_11();

    ex_12();

    return 0;
}