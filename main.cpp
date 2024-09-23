#include <fstream>
#include <sstream>
#include <unordered_map> 
#include <cstdlib>
#include <iostream>

void init_map(std::unordered_map<char, int>& map){
    // just letters
    char chr = 'a';
    for(int i = 0; i < 26; i++){
        map.insert({chr+i, 0});

    }
    // for other
    map.insert({'0', 0});
}

int main(int argc, char** argv) {

    if (argc != 2){
        system("echo Make sure to use only 1 argument");
        return -1;
    }

    // create map and init
    std::unordered_map<char, int> char_dict;
    init_map(char_dict);
    

    // open file
    std::ifstream file;
    file.open(argv[1]);

    if (!file.is_open()) {
        system("echo Only use one file");
    } 


    char x;
    int other = 0;

    while(!file.eof()) {
        file >> x;
        if (file.eof()) { //break if last char
            break;
        }
        if (isalpha(x)) {
            std::cout << x << std::endl;  
            char_dict[x] += 1;
        }
        
        else {
            other++;
            char_dict['0'] += 1;
        }
    }
    
    std::cout << "other : " << other << std::endl;

    for (auto itr = char_dict.begin(); itr != char_dict.end();itr++ )
    {
        std::cout << itr->first << ":" << itr->second << std::endl;
    }


    
    

    return 0;        
}

