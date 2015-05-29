#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;




/*!
 * \class   Solution
 * \brief   it's a backtracking solution
 *          when the snake arrive a cell, it tries the surround cells 
 *          except the left one and the last one
 *          those cell that are visited are labeled
 *          when teleport occurs, the points is reset to zero
 *          return the max points get in each route
 * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
 * \date    May 27, 2015
 */
class Solution
{
public:
    /*!
     * \fn      int game(vector<vector<int>> grid)
     * \brief   the entry of this solution
     *          get the max point by calculating the point 
     *          of the route starting from each cell of the first column
     *          with maxpoints subprocedure.
     * \param   [in]    grid
     *          the game grid represented by a vector of vector of int.
     * \return  int
     *          return the max point one can get given the grid
     *          return -1 if it is impossible to get the right column
     * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
     * \date    May 27, 2015 
     */
    int game(vector<vector<int>> grid)
    {
        int maxpoint = -1;
        int tmp(0);
        for (auto i = 0; i < grid.size(); ++i)
        {
            tmp = 0;
            maxpoints(grid, i, 0, tmp);
            maxpoint = max(maxpoint,tmp);
        }
        return maxpoint;
    }

private:

    /*!
     * \fn      void maxpoints(vector<vector<int>> &grid, int cr, int cc, int &cp)
     * \brief   calculate the max point one can get starting from cell grid[cr][cc]
     * \param   [in]    grid
     *          the game grid
     * \param   [in]    cr
     *          the row index of current cell
     * \param   [in]    cc
     *          the column index of current cell
     * \param   [in][out]   cp
     *          the points that has already get right before the snake visits the cell
     * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
     * \date    May 27, 2015 
     */
    void maxpoints(vector<vector<int>> &grid, int cr, int cc, int &cp)
    {
        if (cr < 0)
        {
            //the snake teleports from the top to the bottom
            //its point cp is reset to 0
            //current row is the last row
            cr = grid.size() - 1;
            cp = 0;
        }
        if (cr == grid.size())
        {
            //the snake teleports from the bottom to the top
            cr = 0;
            cp = 0;
        }
        if (cc == grid.at(0).size())
        {
            //the snake reaches the right side
            //mission complete!
            return ;
        }
        if (grid.at(cr).at(cc) == -2 || grid.at(cr).at(cc) == -1)
        {
            //current cell is either a block one or has been visited
            //backtrack 
            cp = -1;
            return ;
        }
        else
        {

            //keep the value of the current cell
            //then label the cell visited by assigning it with -2
            int tmp = grid.at(cr).at(cc); 
            grid.at(cr).at(cc) = -2;

            //get the maxpoints if the snake goes up from here
            int uppoints(cp+tmp);
            maxpoints(grid, cr - 1, cc, uppoints);

            //get the maxpoints if the snake goes right from here
            int rightpoints(cp+tmp);
            maxpoints(grid, cr, cc + 1, rightpoints);

            //get the maxpoints if the snake gose down from here
            int downpoints(cp+tmp);
            maxpoints(grid, cr + 1, cc, downpoints);

            //recover the value of the current cell
            grid.at(cr).at(cc) = tmp;

            //set the point after visiting this cell with the max one of those three routes
            cp = max({ uppoints, downpoints, rightpoints });
        }   
    }
};


int main()
{

    int row(0), column(0);
    cin >> row >> column;
    if (row == 0 && column == 0)
        return 0;
    vector<vector<int>> grid;     //store the game grid
    vector<int> tmprow;
    int tcolumn(0), tmpcell(0);
    while (row-- > 0)
    {
        tcolumn = column;
        tmprow.clear();
        while (tcolumn-- > 0)
        {
            cin >> tmpcell;
            tmprow.push_back(tmpcell);
        }
        grid.push_back(tmprow);
    }
    
    Solution s;
    int maxpoint = s.game(grid);
    cout << maxpoint << endl;
    //system("pause");
    return 0;
}