/**
 * CS 202 - HW 4
 * A main file
 * Please make sure that your code compiles and runs with this main file
 */

 /*
* Title : Hash Tables, Graphs
* Author : Berk Yýldýz
* ID : 21502040
* Section : 2
* Assignment : 4
* Description : main class of the program
*/
#include "graph.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>

/*You can add additional libraries here to read and process the dataset*/

using namespace std;

void seeMoviesOfPerformer();
void deletePerformerDirectors();
void showHighestPlayedActors();


void showMenu()
{
    cout<<"\n\nWelcome to Movie Dataset\n"<<endl;
    cout<<"Select and option:\n"<<endl;

    cout<<"1- See movies of a performer"<<endl;
    cout<<"2- Delete performers who directed the movie in which s/he played"<<endl;
    cout<<"3- Find performers(s) who played in highest number of movies"<<endl;
    cout<<"4- Find performer number pf performers based on a given performer"<<endl;
    cout<<"5- Find performers(s) who played in highest number of movies with given performer"<<endl;
    cout<<"6- Find director(s) who directed highest number of movies of a given performer"<<endl;
    cout<<"7- Exit"<<endl;

}

int main()
{

    ifstream myfile;
    myfile.open ("movieDataset.txt");

    string line;
    string movieTitle,performer1,performer2,director;

    while(std::getline(myfile, line))
    {
        std::istringstream tokenizer(line);

        std::getline(tokenizer, movieTitle, ';');
        std::getline(tokenizer, performer1, ';');
        std::getline(tokenizer, performer2, ';');
        std::getline(tokenizer, director );

        addPerformer(performer1);
        addPerformer(performer2);

        addEdge(movieTitle,performer1,performer2,director);
        //cout<<movieTitle<<"\t"<<performer1<<"\t"<<performer2<<"\t"<<director<<endl;
    }
    int choice = 0;
    while(choice != 7)
    {
        showMenu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            seeMoviesOfPerformer();
            break;
        case 2:
            deletePerformerDirectors();
            break;
        case 3:
            showHighestPlayedActors();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            exit(0);
            break;
        }

    }
    return 0;
}
void showHighestPlayedActors()
{
    map<string, int> m =getMostActivePerformers();
    for (auto const& x : m)
    {
        if(x.second > 1){
           cout<<x.first<<"\t"<<x.second<<endl;
        }
    }
}

void deletePerformerDirectors()
{
    list<string> performerList = deletePerformers();

    for (auto const& y : performerList)
    {
        cout<<y<<endl;
    }
}
void seeMoviesOfPerformer()
{
    string actorName;
    cout<<"\nEnter performers name: "<<endl;
    cin.ignore(); // it cancels taken values before
    getline(cin,actorName); // gets words

    list<string> movieList = getMovies(actorName);

    list<string>::iterator it;
    for (it = movieList.begin(); it != movieList.end(); ++it)
    {
        cout << *it <<endl;
    }
    cout<<"\n"<<endl;
}

