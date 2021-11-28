#include "Relations.h"

Relations::Relations()
{
    {
        for (int i = 0; i < SIZE; ++i)
            for(int j = 0; j < SIZE; ++j)
                _relations[i][j] = 0;
        
        _personsCount = 0;
    }
}

void Relations::addPerson(const std::string &name)
{
    if (_personsCount >= SIZE)
    {
        throw("Can't add person. Array full.");
    }
    if (getPersonIdByName(name) != -1)
        throw("Can't add person. Person name exist.");
  
    _persons.push_back(Person{name});
    _personsCount++;
}

void Relations::addRelation(const std::string &name1, const std::string &name2)
{
    int person_1_Id = getPersonIdByName(name1);
    int person_2_Id = getPersonIdByName(name2);

    if (person_1_Id == -1 || person_2_Id == -1)
        throw("Can't add relation. Not found names.");

    _relations[person_1_Id][person_2_Id] = _relations[person_2_Id][person_1_Id] = 1;
}

void Relations::showFriendsForNHandshakes(int count)
{
    std::cout << "Friends with " << count << " handshakes" << std::endl;

    for(int n = 0; n < _personsCount; ++n)
    {
        std::cout << _persons[n]._name << " : ";

        int visited[SIZE]; //-1 - unvisited, 0 - visited, 1,2...n - need visit
        int wave = 1;

        for(int i = 0; i < SIZE; ++i)
            visited[i] = -1; 
        
        visited[n] = 1; //visit at 1 wave

        while(wave <= count)
        {
            for (int i = 0; i < SIZE; ++i)
            {
                if(visited[i] == wave)
                {
                    for (int j = 0; j < SIZE; ++j)
                    {
                        if(_relations[i][j] == 1 && visited[j] == -1)
                            visited[j] = wave + 1;
                    }

                    visited[i] = 0;
                }
            }

            ++wave;
        }

        for(int i = 0; i < SIZE; ++i)
        {
            if (visited[i] !=-1 && i != n)
                std::cout << _persons[i]._name << " ";
        }

        std::cout << std::endl;
    }
}

int Relations::getPersonIdByName(const std::string name)
{
    for(int i = 0; i < _personsCount; ++i)
    {
        if (_persons[i]._name == name)
            return i;
    }

    return -1;
}
