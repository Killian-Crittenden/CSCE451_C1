#include <fstream>
#include <sstream>
#include <unordered_map> 
#include <cstdlib>
#include <iostream>
#include <queue>

void init_map(std::unordered_map<char, int>& map){
    // just letters
    char chr = 'a';
    for(int i = 0; i < 26; i++){
        map.insert({chr+i, 0});
    }
    // for other
    map.insert({'0', 0});
}

int process_queue(std::queue<char>& q){
    //8 is a temp length for now
    if(q.size() == 8){
        //grab the front char from the queue
        unsigned char curr_char = q.front();
        int total_char = 0;

        for(int i = 0; i < 8; i++){
            std::cout << curr_char;
            //add the current char to the sum of the key word chars
            total_char += curr_char;

            //push the front char to the end and then pop it from the queue
            q.push(curr_char);
            q.pop();

            //move to the next char in the queue
            curr_char = q.front();
        }
        std::cout << ": " << total_char << std::endl;

        q.pop();

        if(total_char == 1028){
            //do hidden function
            return total_char;
        }
    }
    else{
        //can add useless code/functions here
        return -1;
    }
    return 0;
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

    //create char queue
    std::queue<char> q;
    

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
        q.push(x);
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

        if(q.size() == 8){
            process_queue(q);
        }
    }

    print_char_stats(char_dict, total_chars);
    

    return 0;        
}

