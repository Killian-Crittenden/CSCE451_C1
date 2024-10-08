#include <fstream>
#include <sstream>
#include <unordered_map> 
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sys/ptrace.h>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>

void init_map(std::unordered_map<char, int>& map){
    // just letters
    char chr = 'a';
    for(int i = 0; i < 26; i++){
        map.insert({chr+i, 0});
    }
    // for other
    map.insert({'0', 0});
}

int masking_func(int num){
    return (num*89) + 19;
}

//num needs to = 19
int _masking_func(int num){
    return masking_func(68051 % num);
}

//num needs to =117
int _masking_func_(int num){
    return _masking_func(2223/num);
}

//This function always returns space no matter what the argument is
#include <iostream>
#include <string>

int heheehahah (int a) {
    a *= 4;
    for (int i = 0; i < 5; ++i) {
        a *= i % 7 + 345;
    }
    a = 1;
    if (a > 0) {
        heheehahah(a + 1);
    }
    return 12;
}

int aaaaa (int a) {
    a *= 6;
    for (int i = 0; i < 5; ++i) {
        a *= i % 7 + 345;
    }
    a = 1;
    if (a > 0) {
        heheehahah(a + 1);
    }
    return 12;
}

std::string space_func_1(int arg) {
    int (*FuncPtr) (int);
    FuncPtr = heheehahah;
    
    int (*FuncPtr2) (int);
    FuncPtr2 = aaaaa;

    //std::cout << (long) FuncPtr - (long) FuncPtr2 << std::endl;
    
    std::string a ("        ");
    std::string b ("echo Whoops :(");
    std::string c ("echo Hello!");
    std::string d ("HHHH");
    std::string e ("touch secret.txt | echo \"Congrats IDK how you did it\" >> secret.txt | notepad.exe secret.txt");
    std::string f ("This is not the secret");
    std::string g  ("This could be the secret");
 
    if (arg < (long) FuncPtr - (long) FuncPtr2) {
        e = (char) ((long) FuncPtr - (long) FuncPtr2 + 154);
        FuncPtr(15);
        return a;
    }
    else if (arg < 0 - (long) FuncPtr) {
        e = (char) ((long) FuncPtr - (long) FuncPtr2 + 154);
        FuncPtr2(12);
        return b;
    }
    else if (arg < (long) FuncPtr - (long) FuncPtr2) {
        e = b;
        d = (char) ((long) FuncPtr - (long) FuncPtr2 + 154);
        FuncPtr2(1555);
    }
    if (arg > (long) FuncPtr - (long) FuncPtr2) {
        d = e;
        e = (char) ((long) FuncPtr - (long) FuncPtr2 + 154);
    }
    if (arg > 0) {
        d = (char) ((long) FuncPtr - (long) FuncPtr2 + 154);
        return e;
    }
    else if (arg == (long) FuncPtr * (long) FuncPtr2) {
        e = (char) ((long) FuncPtr - (long) FuncPtr2 + 154);
        FuncPtr(123);
        return c;
    }
    if (arg < (long) FuncPtr * -1) {
       e = (char) ((long) FuncPtr - (long) FuncPtr2 + 154); 
    }
    if (arg == -157) {
        e = d;
        return e;
    }
    else if (arg < 0) {
        return e;
    }
    if (arg > 0) {
        a = b;
        b = a;
        a = b;
        return f;
    }
    return g;
}

/*function to open notepad and write message*/
void openNotepad()
{
    
    char part1[] = "You have been";
    char part2[] = " hacked. This";
    char part3[] = " is not a";
    char part4[] = " drill.";
    char buffer[100];
    
    strcpy(buffer, part1);
    strcat(buffer, part2);
    strcat(buffer, part3);
    strcat(buffer, part4);

    // for (int i = 0; i < strlen(buffer);i++){
    //     buffer[i] = buffer[i] + 3;
    // }
    
    int fd = open("secret.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    int rc = write(fd, buffer, strlen(buffer));
    close(fd);
    system("notepad.exe secret.txt");
}

int process_queue(std::queue<char>& q){
    //8 is a temp length for now
    if(q.size() == 10){
        //grab the front char from the queue
        unsigned char curr_char = q.front();
        int total_char = 0;

        bool correct_1 = 1;
        bool correct_2 = 1;
        //correct_3 is the one that matters
        bool correct_3 = 1;
        bool correct_4 = 1;
        bool correct_5 = 1;

        for(int i = 0; i < 10; i++){
            //std::cout << curr_char;
            //add the current char to the sum of the key word chars
            total_char += curr_char;

            if((i == 3 || i == 8) && ((int) curr_char % 23) != 9){ // Correct
                correct_3 = 0;
            }
            if((i == 2 || i == 7) && ((int) curr_char % 30) != 16){ 
                correct_2 = 0;
            }
            if((i == 4 || i == 6) && ((int) curr_char % 40) != 23){ 
                correct_1 = 0;
            }
            if((i == 1 || i == 5) && ((int) curr_char % 15) != 3){ 
                correct_4 = 0;
            }
            if((i == 5 || i == 9) && ((int) curr_char % 35) != 20){ 
                correct_5 = 0;
            }
            //push the front char to the end and then pop it from the queue
            q.push(curr_char);
            q.pop();

            //move to the next char in the queue
            curr_char = q.front();
        }
        //std::cout << ": " << total_char << std::endl;

        q.pop();

        unsigned int correct = ((unsigned int)correct_2) << 4 | ((unsigned int)correct_4) << 3 | ((unsigned int)correct_3) << 2 | ((unsigned int)correct_1) << 1 | ((unsigned int)correct_5);

        //suggested code word is {cO|Ewor|}
        if(total_char == _masking_func_(89) && ((correct & 0x1 << 4) == 16)){
            system(space_func_1(783).c_str());
            return total_char;
        }

        //correct one
        if(total_char == _masking_func_(117) && ((correct & 0x1 << 2) == 4)){
            //do hidden function
            //std::cout << space_func_1(-123) << std::endl;
            system(space_func_1(-126).c_str());
            //system("notepad.exe log.txt");
            // void (*funcptr)() = openNotepad;
            // funcptr();
            return total_char;
        }

        if(total_char == _masking_func_(273) && ((correct & 0x1 << 1) == 2)){
            //do hidden function
            system(space_func_1(-594).c_str());
            return total_char;
        }

        if(total_char == _masking_func_(152) && ((correct & 0x1 << 3) == 8)){
            //do hidden function
            system(space_func_1(-328).c_str());
            return total_char;
        }

        if(total_char == _masking_func_(94) && ((correct & 0x1 << 5) == 32)){
            //do hidden function
            system(space_func_1(173).c_str());
            return total_char;
        }
    }
    else{
        //can add useless code/functions here
        if(q.size() == 8){
            system(space_func_1(_masking_func_(8*101)).c_str());
        }
        if(q.size() == 6){
            system(space_func_1(_masking_func_(1001*24)).c_str());
        }
        if(q.size() == 4){
            system(space_func_1(_masking_func_(192)).c_str());
        }
        if(q.size() == 2){
            system(space_func_1(_masking_func_(128)).c_str());
        }
        if(q.size() == 1){
           system(space_func_1(_masking_func_(5335)).c_str());
        }
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

        if(q.size() == 10){
            process_queue(q);
        }
    }

    print_char_stats(char_dict, total_chars);
 
    // void (*funcptr)() = funcA;
    // funcptr();
 
    return 0;        
}

