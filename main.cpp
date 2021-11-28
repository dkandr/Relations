#include "Relations.h"

int main()
{
    Relations group;

    try
    {
        group.addPerson("Dima");
        group.addPerson("Olga");
        group.addPerson("Andrey");
        group.addPerson("Ekaterina");
        group.addPerson("Alex");
        group.addPerson("Sveta");
        group.addPerson("Igor");
        group.addPerson("Tanya");
    
        group.addRelation("Dima", "Olga");
        group.addRelation("Olga", "Andrey");
        group.addRelation("Andrey", "Ekaterina");
        group.addRelation("Ekaterina", "Alex");
        group.addRelation("Alex", "Sveta");
        group.addRelation("Sveta", "Igor");
        group.addRelation("Igor", "Tanya");
        group.addRelation("Tanya", "Dima");
     }
    catch(char const* ex)
    {
        std::cout << "Error : " << ex << std::endl;
    } 

    group.showFriendsForNHandshakes(3);

    return 0;
}