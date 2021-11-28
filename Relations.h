#pragma once
#include <iostream>
#include <vector>

#define SIZE 10

class Relations
{
public:
    Relations();

    void addPerson(const std::string &name);
    void addRelation(const std::string &name1, const std::string &name2);

    void showFriendsForNHandshakes(int count); 

    struct Person
    {
        Person(const std::string &name) : _name(name) {};

        const std::string _name;
   };

private:
    int getPersonIdByName(const std::string name);
    void showVisitedFriend();

    std::vector<Person> _persons;
    int _relations[SIZE][SIZE];
    int _personsCount;
};