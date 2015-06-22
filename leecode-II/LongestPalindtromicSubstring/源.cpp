#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;




class Solution {
public:
    string longestPalindromeWA(string s) {
        if (s.size() <= 1)
            return s;
        vector<vector<size_t>> grid(s.size() + 1, vector<size_t>(s.size() + 1, 0));
        string rs(s);
        reverse(s.begin(), s.end());
        size_t maxlength(0), maxposition(0);
        for (auto i = 0; i < rs.size(); ++i)
        {
            for (auto j = 0; j < s.size(); ++j)
            {
                grid.at(i + 1).at(j + 1) = rs.at(i) == s.at(j) ? grid.at(i).at(j) + 1 : 0;
                if (grid.at(i + 1).at(j + 1) > maxlength)
                {
                    maxlength = grid.at(i + 1).at(j + 1);
                    maxposition = j;
                }
            }
        }
        return s.substr(maxposition - maxlength + 1, maxlength);
    }

    string longestPalindromeWA(string s)
    {
        if (s.size() <= 1)
            return s;
        size_t maxlength(0), maxposition(0);

    }
};


int main()
{
    Solution s;
    string ss("esbtzjaaijqkgmtaajpsdfiqtvxsgfvijpxrvxgfumsuprzlyvhclgkhccmcnquukivlpnjlfteljvykbddtrpmxzcrdqinsnlsteonhcegtkoszzonkwjevlasgjlcquzuhdmmkhfniozhuphcfkeobturbuoefhmtgcvhlsezvkpgfebbdbhiuwdcftenihseorykdguoqotqyscwymtjejpdzqepjkadtftzwebxwyuqwyeegwxhroaaymusddwnjkvsvrwwsmolmidoybsotaqufhepinkkxicvzrgbgsarmizugbvtzfxghkhthzpuetufqvigmyhmlsgfaaqmmlblxbqxpluhaawqkdluwfirfngbhdkjjyfsxglsnakskcbsyafqpwmwmoxjwlhjduayqyzmpkmrjhbqyhongfdxmuwaqgjkcpatgbrqdllbzodnrifvhcfvgbixbwywanivsdjnbrgskyifgvksadvgzzzuogzcukskjxbohofdimkmyqypyuexypwnjlrfpbtkqyngvxjcwvngmilgwbpcsseoywetatfjijsbcekaixvqreelnlmdonknmxerjjhvmqiztsgjkijjtcyetuygqgsikxctvpxrqtuhxreidhwcklkkjayvqdzqqapgdqaapefzjfngdvjsiiivnkfimqkkucltgavwlakcfyhnpgmqxgfyjziliyqhugphhjtlllgtlcsibfdktzhcfuallqlonbsgyyvvyarvaxmchtyrtkgekkmhejwvsuumhcfcyncgeqtltfmhtlsfswaqpmwpjwgvksvazhwyrzwhyjjdbphhjcmurdcgtbvpkhbkpirhysrpcrntetacyfvgjivhaxgpqhbjahruuejdmaghoaquhiafjqaionbrjbjksxaezosxqmncejjptcksnoq");
    //string ss("abcdefgfedasdf");
    cout << s.longestPalindromeWA(ss) << endl;
    system("pause");
    return 0;
}