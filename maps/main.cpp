// Maps is C++

#include <iostream>
#include <vector>

#include <map>
#include <unordered_map>

struct CityRecords
{
    std::string Name;
    uint64_t Population;
    double longitude, latitude;

    /*CityRecords(std::string Name, uint64_t Population, double Longitude, double Latitude)
        : Name(Name), Population(Population), longitude(Longitude), latitude(Latitude)
    {}*/

    // this is used for comparison of different entries of map 
    bool operator<(const CityRecords& other) const { return Population < other.Population; }
};

// I don't know what the fuck is this but I will understand it one day!!
namespace std 
{ 
    template<>
    struct hash<CityRecords>
    {
        size_t operator()(const CityRecords& key)
        {
            return hash<std::string>()(key.Name);
        }
    };
}

int main()
{
    // Finding a city's population using a vector. (Remember that you need a constructor for this to work.)

    /*std::vector<CityRecords> cities;

    cities.emplace_back("New Delhi", 17000000, 2.3, 7.9);
    cities.emplace_back("Mumbai", 25000000, 2.3, 7.9);
    cities.emplace_back("Kolkata", 9000000, 2.3, 7.9);
    cities.emplace_back("Bangaluru", 12000000, 2.3, 7.9);
    cities.emplace_back("Hyderabad", 6000000, 2.3, 7.9);

    for (const auto& city : cities)
    {
        if (city.Name == "Kolkata")
        {
            std::cout << "population of Kolkata: " << city.Population << std::endl;
        }
    }*/

    // Finding a city's population using a map. (map takes in a key and a value)

    //std::unordered_map<std::string, CityRecords> CityMap;
    std::map<std::string, CityRecords> CityMap;

    CityMap["New Delhi"] = CityRecords {"New Delhi", 17000000, 2.3, 7.9};
    CityMap["Mumbai"] = CityRecords {"Mumbai", 25000000, 2.3, 7.9};
    CityMap["Kolkata"] = CityRecords {"Kolkata", 9000000, 2.3, 7.9};
    CityMap["Bangaluru"] = CityRecords {"Bangaluru", 12000000, 2.3, 7.9};
    CityMap["Hyderabad"] = CityRecords {"Hyderabad", 6000000, 2.3, 7.9};

    CityRecords& Mumbai = CityMap["Mumbai"];
    std::cout << "Population of Mumbai: " << Mumbai.Population << std::endl;

    // Custom datatypes like CityRecords are not hashable. Hence, we cannot use them as map keys.
    // However, we can make our own hash for custom datatypes and add it to standard library as 
    // we have done it upwards.

    std::map<CityRecords, uint32_t> foundedMap;

    foundedMap[CityRecords{"Bangaluru", 12000000, 2.3, 7.9}] = 1796;
    foundedMap[CityRecords{"New Delhi", 17000000, 2.3, 7.9}] = 1105;

    uint32_t date_of_birth = foundedMap[CityRecords{"Bangaluru", 12000000, 2.3, 7.9}];
    std::cout << "Date of birth of bangaluru: " << date_of_birth << std::endl;

    // how to add new data using maps.

    CityRecords& Chennai = CityMap["Chennai"]; 
    Chennai.Name = "Chennai";
    Chennai.Population = 13000000;
    Chennai.longitude = 6.1;
    Chennai.latitude = 9.5;

    // You see chennai does not exist on the already included keys and values. Still we don't get any 
    // errors because the [] operator creates a new entry in the map if the key does not exist.

    // .at() function in maps

    const auto& city = CityMap;

    if (city.find("Chennai") != city.end())
    {
        const CityRecords& Chennai = city.at("Chennai");
        std::cout << "Longitude of Chennai: " << Chennai.longitude << std::endl;
    }

    // the .at() function would just retrive the data and won't try to change it. Therefore, there can 
    // be a const version also.

    // how to erase an entry

    CityMap.erase("Kolkata");

    for (auto& kv : CityMap)
    {
        const std::string& name = kv.first;
        CityRecords& City = kv.second;

        std::cout << "Name: " << name << std::endl << "Population: " << City.Population << std::endl;
        foundedMap[City];
    }

    for (auto& kv : foundedMap)
    {
        const CityRecords& city = kv.first;
        int founded = kv.second;

        std::cout << "Name: " << city.Name << std::endl << "Population: " << city.Population << std::endl;
    }

    std::cin.get();

}