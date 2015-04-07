#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        stringstream ssi(path), sso;
        string tmp("");
        vector<string> stack;
        while (getline(ssi, tmp, '/'))
        {
            if (tmp == ".")
                continue;
            if (tmp == ".." && !stack.empty())
                stack.pop_back();
            if (tmp != ".." && !tmp.empty())
                stack.push_back(tmp);
        }
        if (stack.empty())
            return string("/");
        for (auto dir : stack)
            sso << "/" << dir;
        return sso.str();
    }
    string simplifyPathAC(string path) {
        if (path.empty())
            return path;
        vector<string> dirs;
        tokenize(path, dirs);
        vector<string> stack;
        for (auto dir : dirs)
        {
            if (dir == ".")
                continue;
            if (dir == "..")
            {
                if (stack.empty())
                    continue;
                else
                {
                    stack.pop_back();
                    continue;
                }
            }
            stack.push_back(dir);
        }
        if (stack.empty())
            return string("/");
        stringstream ss;
        for (auto dir : stack)
        {
            ss << "/" << dir;
        }
        return ss.str();
    }


    void tokenize(const string &path, vector<string> &dirs)
    {
        char *pch = strtok(const_cast<char *>(path.c_str()), "/");;
        while (pch!=nullptr)
        {
            dirs.push_back(pch);
            pch = strtok(NULL, "/");
        }
    }
};


int main()
{
    Solution s;

    vector<string> test = {
        "/home/",
        "/a/./b/../../c/",
        "/",
        "",
        "/../",
        "/..",
        "/home//foo"
    };
    
    //vector<string> tmp;
    for (auto t : test)
    {
        //tmp.clear();
        cout << t << " => "<<s.simplifyPath(t);
        //s.tokenize(t, tmp);
        
        /*for (auto d : tmp)
        {
            cout << "*" << d << ",";
        }*/
        cout << endl;
    }
    system("pause");
}