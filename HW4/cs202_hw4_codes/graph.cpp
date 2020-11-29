 /*
* Title : Hash Tables, Graphs
* Author : Berk Yýldýz
* ID : 21502040
* Section : 2
* Assignment : 4
* Description : implementation of the graph
*/
/** @file Graph.cpp
 * An adjacency list representation of an undirected graph.
*/

#include "graph.h"
#include <iostream>
/*Do not add new libraries or files*/

Graph::Graph()
{
}  // end constructor

void Graph::addPerformer(string performerName)
{
     map<string, list<node> >::iterator it = adjList.find(performerName);
    if(it != adjList.end())
    {
          //cout<<"found in list"<<endl;
    }
    else
    {
        list<node> nodeList;
        adjList[performerName] = nodeList;
    }


}  // end addPerformer

void Graph::addEdge(string movieTitle, string performer1, string performer2, string director)
{
    node node1;
    node1.movie = movieTitle;
    node1.director = director;
    node1.name = performer2;

    map<string, list<node> >::iterator it = adjList.find(performer1);
    if (it != adjList.end())
        it->second.push_back(node1);

    //cout<<performer1<<" size: "<<adjList[performer1].size()<<endl;

    node node2;
    node2.movie = movieTitle;
    node2.director = director;
    node2.name = performer1;
    adjList[performer2].push_back(node2);


}  // end addEdge

list<string> Graph::getMovies(string performerName)
{
    //cout<<"Graph size: "<<adjList.size()<<endl;
    //cout<<"Search: "<<performerName<<endl;
    list<node> nodeList = adjList[performerName];
    //cout<<performerName<<" size: "<<nodeList.size()<<endl;
    // cout<<performerName<<" size: "<<adjList[performerName].size()<<endl;
    list<string> moviesList;

    list<node>::iterator it;
    for (it = nodeList.begin(); it != nodeList.end(); ++it)
    {
        moviesList.push_back(it->movie);
    }

    return moviesList;


}  // end getMovies

bool Contains(list<string> nodeList, string x)
{
    list<string>::iterator it;
    for (it = nodeList.begin(); it != nodeList.end(); ++it)
    {
        if(it->compare(x) == 0){
            return true;
        }
    }
    return false;
}

list<string> Graph::deletePerformers()
{
    list<string> performerList;

    for (auto const& x : adjList)
    {
        list<node> nodeList = x.second;

        for (auto const& y : nodeList)
        {
            if(x.first.compare(y.director) == 0)
            {
                if(!Contains(performerList,x.first))
                {
                    performerList.push_back(x.first);
                    /**
                     * remove it
                     */
                     map<string, list<node>>::iterator it = adjList.find(x.first);
                     adjList.erase(it);
                }
            }
        }
    }

    return performerList;
}  // end deletePerformers

map<string, int> Graph::getMostActivePerformers()
{
    map<string, int> mostActiveList;

    for (auto const& x : adjList)
    {
        mostActiveList[x.first] = x.second.size();
    }

    return mostActiveList;
}  // end getMostActivePerformers

map<string, int> Graph::getPerformerNumber(string performerName)
{
map<string, int> m;

    m[performerName] = 0;
    /*YOUR IMPLEMENTATION*/
    list<node> nodeList = adjList[performerName];
    /**
     * 1
     */
    for(auto const& x: nodeList)
    {

        map<string, int>::iterator it = m.find(x.name);
        if(it != m.end())
        {
            //  cout<<"found in list"<<endl;
        }
        else
        {
            m[x.name] = 1;
        }
    }

    /**
     *  2
     */
    for(auto const& y: m)
    {
        nodeList = adjList[y.first];

        for(auto const& x: nodeList)
        {

            map<string, int>::iterator it = m.find(x.name);
            if(it != m.end())
            {
                //  cout<<"found in list"<<endl;
            }
            else
            {
                m[x.name] = 2;
            }
        }
    }

    /**
    *  3
    */
    for(auto const& y: m)
    {
        if(y.second == 2 )
        {
            nodeList = adjList[y.first];

            for(auto const& x: nodeList)
            {

                map<string, int>::iterator it = m.find(x.name);
                if(it != m.end())
                {
                    //  cout<<"found in list"<<endl;
                }
                else
                {
                    m[x.name] = 3;
                }
            }
        }
    }
    return m;



}  // end getPerformerNumber

map<string, int> Graph::getFrequentPartner(string performerName)
{
     map<string, int>  frequentPartnerList;
    list<node> movies = adjList[performerName];
    for (auto const& x : movies)
    {
        frequentPartnerList[x.name]++;
    }

    return frequentPartnerList;


}  // end getFrequentPartner

map<string, int> Graph::getFrequentDirector(string performerName)
{
    map<string, int>  frequentDirectorList;
    list<node> movies = adjList[performerName];
    for (auto const& x : movies)
    {
        frequentDirectorList[x.director]++;
    }

    return frequentDirectorList;

}  // end getFrequentDirector

std::ostream & operator<<(std::ostream & Str,  node const & v)
{
    Str<<"Performer: "<<v.name<<"\tMovie: "<<v.movie<<"\tdirector: "<<v.director<<endl;
    return Str;
}


