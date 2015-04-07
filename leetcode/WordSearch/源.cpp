#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool exist(vector<string > &board, string word) {
        bool re;
        int m = board.size();
        int n = board.at(0).size();
        for (auto i = 0; i < board.size(); ++i)
            for (auto j = 0; j < board.at(0).size(); ++j)
            {
                if (board.at(i).at(j) == word.at(0))
                {
                    re = exist(board, word, 0, i, j, m, n);
                    if (re)
                        return true;
                }
            }
        return false;
    }

private:
    bool exist(vector<string> &board, const string &word, string::size_type wordindex, int cm, int cn, int m, int n)
    {
        if (wordindex == word.size())
            return true;
        if (cm < 0 || cm >= m || cn < 0 || cn >= n || board.at(cm).at(cn) != word.at(wordindex))
            return false;
        char temp = board.at(cm).at(cn);
        board.at(cm).at(cn) = '.';
        bool bt = exist(board, word, wordindex + 1, cm - 1, cn, m, n);
        if (bt)
        {
            board.at(cm).at(cn) = temp;
            return bt;
        }
        bool bl = exist(board, word, wordindex + 1, cm, cn - 1, m, n);
        if (bl)
        {
            board.at(cm).at(cn) = temp;
            return bl;
        }
        bool bd = exist(board, word, wordindex + 1, cm + 1, cn, m, n);
        if (bd)
        {
            board.at(cm).at(cn) = temp;
            return bd;
        }
        bool br = exist(board, word, wordindex + 1, cm, cn + 1, m, n);
        if (br)
        {
            board.at(cm).at(cn) = temp;
            return br;
        }
        board.at(cm).at(cn) = temp;
        return false;

    }
};


int main()
{
    Solution s;
    /*vector<string> test = {
        "ABCE",
        "SFCS",
        "ADEE"
    };*/
    vector<string> test = {
        "CAA",
        "AAA",
        "BCD"
    };
    cout << s.exist(test, "AAB") << endl;
    system("pause");
}