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

void print_char_stats(std::unordered_map<char, int>& map, int total_chars){
    for(char i = 'a'; i <= 'z'; i++){
        printf("%c: %7d (%3.2f%c)\n", i, map[i], ((float)map[i]/(float)total_chars)*100, '%');
    }
    printf("other: %7d (%3.2f%c)\n", map['0'], ((float)map['0']/(float)(total_chars + map['0']))*100, '%');
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
    int total_chars = 0;

    while(!file.eof()) {
        file >> x;
        if (file.eof()) { //break if last char
            break;
        }
        if (isalpha(x)) {
            total_chars++;
            char_dict[x] += 1;
        }
        
        else {
            char_dict['0'] += 1;
        }
    }
    
    //std::cout << "other : " << other << std::endl;

    // for (auto itr = char_dict.begin(); itr != char_dict.end();itr++ )
    // {
    //     std::cout << itr->first << ":" << itr->second << std::endl;
    // }


    print_char_stats(char_dict, total_chars);
    

    return 0;        
}

