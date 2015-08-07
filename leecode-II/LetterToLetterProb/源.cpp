#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    void addword(const string &word)
    {
        if (word.empty())
            return;
        ++matrix.at(0).at(word.front() - 'a');
        ++matrix.at(0).back();
        int i(1);
        for (; i < word.size(); ++i)
        {
            ++matrix.at(word.at(i - 1) - 'a').at(word.at(i) - 'a');
            ++matrix.at(word.at(i - 1) - 'a').back();
        }
        ++matrix.back().at(word.back() - 'a');
        ++matrix.back().back();
    }

    double getprob(char from, char to)
    {
        if (from == '.'&&to == '.')
            return 0;
        if (from == '.')
            return matrix.front().at(to-'a')==0?0: (double)(matrix.front().at(to - 'a')) / matrix.front().back();
        if (to == '.')
            return matrix.back().at(from - 'a')==0?0:(double)(matrix.back().at(from - 'a')) / matrix.back().back();
        return matrix.at(from - 'a').at(to - 'a') == 0 ? 0: (double)(matrix.at(from - 'a').at(to - 'a')) / matrix.at(from - 'a').back();
    }

    Solution()
    {
        for (auto i = 0; i < 28; ++i)
        {
            //last column is row sum
            matrix.push_back(vector<int>(27, 0));
        }
    }
private:
    vector<vector<int>> matrix;
};



int main()
{
    Solution s;
    s.addword("aba");
    s.addword("acb");
    cout << s.getprob('a', 'b') << endl;
    cout << s.getprob('a', 'c') << endl;
    cout << s.getprob('b', 'a') << endl;
    cout << s.getprob('b', '.') << endl;
    cout << s.getprob('.', 'a') << endl;
    cout << s.getprob('a', '.') << endl;
    system("pause");
    return 0;
}