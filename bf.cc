/**
 * A Brainfucj interpreter in C++. 
 * Taken from the russian Wikipedia <https://ru.wikipedia.org/wiki/Brainfuck>. 
 */

#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
int main(int argc, char **argv)
{
 
    vector<char> acc;
    char ch;
    ifstream infile(argv[1]);
    while(infile)
    {
        infile.get(ch);
        acc.push_back(ch);
    }
    infile.close();
    char *j = new char[30000]; 
    int brc = 0;
    for(int i = 0; i < acc.size(); ++i)
    {
        if(acc[i] == '>') ++j;
        if(acc[i] == '<') --j;
        if(acc[i] == '+') ++*j;
        if(acc[i] == '-') --*j;
        if(acc[i] == '.') cout << *j;
        if(acc[i] == ',') cin >> *j;
        if(acc[i] == '[')
        {
            if(!cpu[j])
            {
                ++brc;
                while(brc)
                {
                    ++i;
                    if (acc[i] == '[') ++brc;
                    if (acc[i] == ']') --brc;
                }
            }else continue;
        }
        else if(acc[i] == ']')
        {
            if(!cpu[j])
            {
                continue;
            }
            else
            {
                if(acc[i] == ']') brc++;
                while(brc)
                {
                    --i;
                    if(acc[i] == '[') brc--;
                    if(acc[i] == ']') brc++;
                }
                --i;
            }
        }
    }
}
