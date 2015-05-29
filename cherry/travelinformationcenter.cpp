#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;


/*!
 * \class   City
 * \brief   Store the information of a city: 
 *              1. indexes of neighbor cities
 *              2. whether it has been festive already
 *              3. the closest city (itself if it is festive)
 *              4. the shortest distance from the city to the closest festive city (0 if it is festive)
 * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
 * \date    May 27, 2015
 */
class City
{
public:
    City() :closestcity(-1), closestdistance(numeric_limits<int>::max()), isfestive(false){}; /* constructor */
    bool isfestive;         /*> if itself has been festive already, default false*/
    vector<int> neighbors;  /*> the indexes of the neighbors, zero based, default empty */
    int closestcity;        /*> the closest city (itself if it is festive), default -1 */
    int closestdistance;    /*> the shortest distance from the city to the closest festive city 
                                (0 if it is festive), default INT_MAX*/

};


/*!
 * \class   Solution
 * \brief   all the cities are stored in the "cities" member
 *          the island is represented with adjacency lists
 *          it is kind of a BFS problem
 *          in this solution, when an inquiry comes, 
 *              if it's a government anouncement
 *                  update the shortest distance of those cities that is close to the new festive one
 *              else 
 *                  just return the closestdistance, which is guarunteed to be the shortest distance
 *          instead of calculating the shortest distance everytime whenever an inquiry comes
 * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
 * \date    May 27, 2015
 */
class Solution
{
public:
    Solution(){};

    /*!
     * \fn      Solution (int citynum)
     * \brief   the constructor, initialize a solution instance
     * \param   [in]    citynum
     *          the city number of one case, aka 'n' in the problem
     * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
     * \date    May 27, 2015
     */
    Solution(int citynum){
        assert(citynum >= 0);//must gte zero
        for (auto i = 0; i < citynum; ++i)
            cities.push_back(City());
    }



    /*!
     * \fn      void update(int cityi)
     * \brief   update the shortest distance of those cities that is close to cityi
     *          with bfs
     *          only update the cities whose original closestdistance is 
     *              greater than its distance to cityi
     *          or stop searching its neighbor
     * \param   [in]    cityi
     *          the index of the new festive city
     * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
     * \date    May 27, 2015
     */
    void update(int cityi)
    {
        if (cityi >= this->cities.size() || cityi < 0)
            return;
        //already festive
        if (cities.at(cityi).isfestive)
            return;
        
        //update the city's own property
        cities.at(cityi).closestdistance = 0;
        cities.at(cityi).isfestive = true;
        cities.at(cityi).closestcity = cityi;

        //bfs subprocedure
        queue<int> q;
        q.push(cityi);
        int distance(0);
        int levelsize(0);
        int curcity;
        //vector<int> tmpneighbors;
        while (!q.empty())
        {
            levelsize = q.size();
            ++distance;
            while (levelsize > 0)
            {
                curcity = q.front();
                q.pop();
                --levelsize;
                //tmpneighbors = this->cities.at(curcity).neighbors;
                for (auto neighbor: this->cities.at(curcity).neighbors)// vector<int>::size_type nei = 0; nei<tmpneighbors.size(); ++nei)
                {
                    if (this->cities.at(neighbor).closestdistance > distance)
                    {
                        //only update the cities that are close to the new one
                        this->cities.at(neighbor).closestdistance = distance;
                        this->cities.at(neighbor).closestcity = cityi;
                        q.push(neighbor);
                    }
                }
            }
        }
    }



    /*!
     * \fn      int getclosestdistance(int cityi)
     * \brief   get the shortest distance to the closest city of cityi
     * \param   [in]    cityi
     *          the inquiry
     * \return  int
     *          the shortest distance to the closest city of cityi
     *          just return the member closetdistance of cityi
     *          if cityi is not valid, return -1
     * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
     * \date    May 27, 2015
     */
    int getclosestdistance(int cityi)
    {
        if (cityi >= this->cities.size() || cityi < 0)
            return -1;

        return this->cities.at(cityi).closestdistance;
    }

    /*!
     * \fn      void addhighway(int from, int to)
     * \brief   add highway between city[from] and city[to]
     *          the graph is bidirectional, so both city should be append to the other's neighbors 
     * \param   [in]    from
     *          the first city index, zero based
     * \param   [in]    to
     *          the second city index, zero based
     * \author  XiPeng Li   ( lixipeng.ict@hotmail.com )
     * \date    May 27, 2015
    */
    void addhighway(int from, int to)
    {
        if (from >= this->cities.size() || to >= this->cities.size() || from < 0 || to < 0)
            return;
        //bidirectional
        this->cities.at(from).neighbors.push_back(to);
        this->cities.at(to).neighbors.push_back(from);
    }

    vector<City> cities;

};



int main()
{
    int n, m;
    cin >> n >> m;
    Solution s(n);

    //all input is convert to zero based index
    int from(0), to(0);
    while (n-- > 1)
    {
        cin >> from >> to;
        s.addhighway(from - 1, to - 1);
    }
    //cout << "city input over" << endl;
    s.update(0);
    while (m-- > 0)
    {
        cin >> from >> to;
        if (from == 1)
        {
            s.update(to - 1);
        }
        else if (from == 2)
        {
            cout << s.getclosestdistance(to - 1) << endl;
        }   
    }
    //system("pause");
    return 0;

}

