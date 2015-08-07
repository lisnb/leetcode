#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() <= 1)
            return true;
        vector<int> inorder(sequence);
        sort(inorder.begin(), inorder.end());
        return verify(inorder, 0, inorder.size() - 1, sequence, 0, inorder.size() - 1);
    }
private:
    bool verify(vector<int> &inorder, int ib, int ie, vector<int> &postorder, int pb, int pe)
    {
        cout << ib << " " << ie << " " << pb << " " << pe << endl;
        if (ib > ie)
            return true;
        if (ib == ie)
            return pb == pe && inorder.at(ib) == postorder.at(pb);
        auto riter = find(inorder.begin() + ib, inorder.begin() + ie + 1, postorder.at(pe));
        if (riter == inorder.begin() + ie + 1)
            return false;
        auto ri = riter - inorder.begin();
        return verify(inorder, ri + 1, ie, postorder, pe - (ie - ri), pe - 1)
            &&
            verify(inorder, ib, ri - 1, postorder, pb, pe - (ie - ri) - 1);

    }
};

int main()
{
    Solution s;
    vector<int> postorder = { 1, 0, 3, 5, 4, 2, 7, 9, 8, 10 };
    cout << s.VerifySquenceOfBST(postorder)<<endl;
    system("pause");
    return 0;
}