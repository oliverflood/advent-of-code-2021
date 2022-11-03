#include <bits/stdc++.h>
#include <unordered_set>
#include <iostream>
using namespace std;


struct Hallway {
    int size = 7;
    int array[7] = {0,0,0,0,0,0,0};
};

// all that needs to change between p1 and p2
struct Room {
    int size = 4;
    int array[4] = {0,0,0,0};
};

class Burrow {
public:
    Hallway hallway;
    Room rooms[4];

    int num_rooms = 4;
    int energy_total = 0;

    void print();
    bool complete();
};

bool operator==(Hallway h1, Hallway h2) {
    for (int i = 0; i < h1.size; ++i)
    {
        if (h1.array[i] != h2.array[i])
            return false;
    }
    return true;
}

bool operator==(Room r1, Room r2) {
    for (int i = 0; i < r1.size; ++i)
    {
        if (r1.array[i] != r2.array[i])
            return false;
    }
    return true;
}

bool operator==(Burrow b1, Burrow b2) {
    if (!(b1.hallway == b2.hallway)) 
        return false;
    for (int i = 0; i < b1.num_rooms; ++i)
    {
        if (!(b1.rooms[i] == b2.rooms[i]))
            return false;
    }
    return true;
}

class MyHashFunction {
public:
    // id is returned as hash function
    size_t operator()(const Burrow& b) const
    {
        size_t ans = hash<int>()(b.hallway.array[0]);
        for (int i = 1; i < b.hallway.size; ++i)
        {
            ans ^ hash<int>()(b.hallway.array[i]);
        }
        for (int i = 0; i < b.num_rooms; ++i)
        {
            for (int k = 0; k < b.rooms[i].size; ++k)
            {
                ans ^ hash<int>()(b.rooms[i].array[k]);
            }
        }

        return ans;
    }
};

int char_to_int(char c);
char int_to_char(int n);
Burrow get_input();

bool room_free(Room room, int amphipod) {
    if (room.array[0] != 0)
            return false;

    for (int i = 0; i < room.size; ++i)
    {
        // if not amphipod or empty then the room is not free
        // if (!(room.array[i] == amphipod || room.array[i] == 0))
        //     return false;

        if (room.array[i] != amphipod && room.array[i] != 0)
            return false;
    }

    // room is free
    return true;
}

bool hallway_free(Hallway hallway, int hallway_index, float room_num) {
    room_num += 1.5;

    for (int loop_index = 0; loop_index < hallway.size; ++loop_index)
    {
        int amphipod = hallway.array[loop_index];

        // if the hallway space in consideration is in between the room and hallway index
        if ((loop_index < hallway_index && loop_index > room_num) || 
            (loop_index > hallway_index && loop_index < room_num)) {

            // if there is an amphipod blocking the way
            if (amphipod != 0)
                // then hallway is not free
                return false;
        }
    }
    
    // hallway is free  
    return true;
}

// void place_amphipod_in_room(Room &room, int amphipod) {
//     for (int i = room.size-1; i >= 0; i--)
//     {
//         if (room.array[i] == 0) {
//             room.array[i] = amphipod;
//         }
//     }
// }
int place_amphipod_in_room(Room &room, int amphipod) {
    for (int i = room.size-1; i >= 0; i--)
    {
        if (room.array[i] == 0) {
            room.array[i] = amphipod;
            return i;
        }
    }
    //should never happen
    cout << "bad";
    exit(1);
}


void find_next_move(Burrow burrow);  
int find_lowest_energy_burrow(vector<Burrow> list);
void next_hallway_move(Burrow burrow);
void next_room_move(Burrow burrow);

///////////////////////////////////////////////////////////////////////////////

int global_lowest_energy = 70000;

int calc_dist(int hallway_index, int room_num, int room_index);

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("out.txt", "r", stdout);

    Burrow burrow = get_input();
    burrow.print();

    // burrow.hallway.array[2] = 2;
    // burrow.hallway.array[4] = 2;
    // burrow.print();
    // cout << hallway_free(burrow.hallway, 0, 2) << endl;
    // cout << hallway_free(burrow.hallway, 1, 2) << endl;
    // cout << hallway_free(burrow.hallway, 2, 2) << endl;
    // cout << hallway_free(burrow.hallway, 3, 2) << endl;
    // cout << hallway_free(burrow.hallway, 4, 2) << endl;
    // cout << hallway_free(burrow.hallway, 5, 2) << endl;
    // cout << hallway_free(burrow.hallway, 6, 2) << endl;
    

    find_next_move(burrow);

    cout << "fin" << endl;

    // for (int i = 0; i <=6 ; ++i)
    // {
    //     for (int k = 0; k <= 3; ++k)
    //     {
    //         for (int j = 0; j <= 3; ++j)
    //         {
    //             cout << i << " " << k << " " << j << "   " << calc_dist(i, k, j) << endl << endl;
    //         }
    //     }
    // }

}


bool compare_burrows(Burrow b1, Burrow b2) {
    return (b1.energy_total < b2.energy_total);
}


int gcount = 0;
void find_next_move(Burrow burrow) {
    gcount++;
    if (gcount % 1000000 == 0)
        cout << gcount << endl;

    // if (gcount == 140)
    //     exit(0);


    // burrow.print();
    // cout << burrow.energy_total << endl << endl;
    

    if (burrow.complete()) {
        burrow.print();
        cout << burrow.energy_total << endl << endl;
        global_lowest_energy = burrow.energy_total;
    }

    // hallway moves
    next_hallway_move(burrow);

    // room moves
    next_room_move(burrow);
} 


int calc_dist(int hallway_index, int room_num, int room_index) {
    if (hallway_index < 0 || hallway_index > 6){
        cout << "bad";
        exit(0);
    }
    if (room_num < 0 || room_num > 3){
        cout << "bad";
        exit(0);
    }
    if (room_index < 0 || room_index > 3){
        cout << "bad";
        exit(0);
    }

    int ans = 0;

    int true_hallway_index;

    if (hallway_index == 0) {
        true_hallway_index = 0;
    }
    else if (hallway_index == 6) {
        true_hallway_index = 10;
    }
    else {
        true_hallway_index = (hallway_index*2)-1;
    }

    ans += abs(true_hallway_index - ((room_num*2) + 2));

    ans += room_index;

    ans += 1;

    return ans;
}

int get_first_clear_room_index(Room room) {
    for (int i = room.size-1; i >= 0; --i)
    {
        if (room.array[i] == 0) {
            return i;
        }
    }
    cout << "bad get_first_clear_room_index";
    exit(1);
}

void next_hallway_move(Burrow burrow) {

    // finding all legal moves
    vector<Burrow> legal_moves_list;
    for (int hallway_index = 0; hallway_index < burrow.hallway.size; ++hallway_index)
    {
        // if there is an amphipod in the indexed hallway space
        if (burrow.hallway.array[hallway_index] != 0) {
            int amphipod = burrow.hallway.array[hallway_index];
            int room_num = amphipod-1;

            // needs free room
            if (!room_free(burrow.rooms[room_num], amphipod))
                continue;
            
            // needs free hallway
            if (!hallway_free(burrow.hallway, hallway_index, room_num))
                continue;

            // move amphipod
            int room_index = get_first_clear_room_index(burrow.rooms[room_num]);

            int space_count = 0;
            Burrow new_burrow = burrow;
            new_burrow.hallway.array[hallway_index] = 0;
            space_count += 1+ place_amphipod_in_room(new_burrow.rooms[room_num], amphipod); // this is stupid

            // update energy (should be a seperate function)
            int true_hallway_index = 1000000;
            if (hallway_index == 0)
                true_hallway_index = 0;
            if (hallway_index == 6)
                true_hallway_index = 10;
            else 
                true_hallway_index = hallway_index*2 - 1;

            space_count += abs(true_hallway_index-(2+room_num*2));


            // if (space_count != calc_dist(hallway_index, room_num, room_index)) {
            //     cout << "DEBUG" << endl;
            //     burrow.print();
            //     new_burrow.print();
            //     cout << "space_count: " << space_count << endl;
            //     cout << "calc_dist: " << calc_dist(hallway_index, room_num, room_index) << endl;
            //     // cout << "hallway_index: " << hallway_index << endl;
            //     // cout << "room_num: " << room_num << endl;
            //     // cout << "room_index: " << room_index << endl;
            //     //exit(1);
            // }
            new_burrow.energy_total += pow(10, amphipod-1)*calc_dist(hallway_index, room_num, room_index);

            // add to legal moves
            legal_moves_list.push_back(new_burrow);
        }
    }

    if (legal_moves_list.size() == 0)
        return;

    // dont know if this works
    sort(legal_moves_list.begin(), legal_moves_list.end(), compare_burrows);
    for (int i = 0; i < legal_moves_list.size(); ++i)
    {
        //int next = find_lowest_energy_burrow(legal_moves_list);


        // if (uset.find(legal_moves_list[i]) != uset.end())
        //     continue;
        // uset.insert(legal_moves_list[i]);

////////////////////////////////////////////////////////////////////////////////////////

        // if (find(vec.begin(), vec.end(), legal_moves_list[i]) != vec.end())
        //     continue;
        // vec.push_back(legal_moves_list[i]);


        if (legal_moves_list[i].energy_total >= global_lowest_energy)
            return;
        find_next_move(legal_moves_list[i]);
        //legal_moves_list.erase(legal_moves_list.begin()+next);
    }
    
}

int find_free_room_index(Room room) {
    for (int i = 0; i < room.size; ++i)
    {
        if (room.array[i] != 0)
            return i;
    }

    return -1;
}

bool room_should_be_left_alone_ffs(Room room, int room_num) {
    for (int i = 0; i < room.size; ++i)
    {
        if (!(room.array[i] == room_num+1 || room.array[i] == 0))
            return false;
    }

    return true;
}

void next_room_move(Burrow burrow) {
    vector<Burrow> legal_moves_list;

    for (int room_num = 0; room_num < burrow.num_rooms; ++room_num)
    {
        if (room_should_be_left_alone_ffs(burrow.rooms[room_num], room_num))
            continue;

        int room_index = find_free_room_index(burrow.rooms[room_num]);

        if (room_index == -1)
            continue;

        int amphipod = burrow.rooms[room_num].array[room_index];

        for (int hallway_index = 0; hallway_index < burrow.hallway.size; ++hallway_index)
        {
            if (hallway_free(burrow.hallway, hallway_index, room_num) && burrow.hallway.array[hallway_index] == 0) {
                // now we're cookin

                // move amphipod
                Burrow new_burrow = burrow;
                new_burrow.hallway.array[hallway_index] = amphipod;
                new_burrow.rooms[room_num].array[room_index] = 0;

                // update energy
                int space_count = 0;

                int true_hallway_index = 1000000;
                if (hallway_index == 0)
                    true_hallway_index = 0;
                else if (hallway_index == 6)
                    true_hallway_index = 10;
                else 
                    true_hallway_index = hallway_index*2 - 1;

                space_count += abs(true_hallway_index-(2+room_num*2));

                space_count += room_index + 1;

                // if (space_count != calc_dist(hallway_index, room_num, room_index)) {
                //     cout << "DEBUG" << endl;
                //     burrow.print();
                //     new_burrow.print();
                //     cout << "space_count: " << space_count << endl;
                //     cout << "calc_dist: " << calc_dist(hallway_index, room_num, room_index) << endl;
                //     // cout << "hallway_index: " << hallway_index << endl;
                //     // cout << "room_num: " << room_num << endl;
                //     // cout << "room_index: " << room_index << endl;
                //     // exit(1);
                // }
                new_burrow.energy_total += pow(10, amphipod-1)*calc_dist(hallway_index, room_num, room_index);

                // add to legal moves
                legal_moves_list.push_back(new_burrow);
            }
        }
    }

    if (legal_moves_list.size() == 0)
        return;

    // dont know if this works
    sort(legal_moves_list.begin(), legal_moves_list.end(), compare_burrows);
    for (int i = 0; i < legal_moves_list.size(); ++i)
    {
        // int next = find_lowest_energy_burrow(legal_moves_list);



        // if (uset.find(legal_moves_list[i]) != uset.end())
        //     continue;
        // uset.insert(legal_moves_list[i]);

////////////////////////////////////////////////////////////////////////////////////////


        // if (find(vec.begin(), vec.end(), legal_moves_list[i]) != vec.end())
        //     continue;
        // vec.push_back(legal_moves_list[i]);


        if (legal_moves_list[i].energy_total >= global_lowest_energy)
            return;
        find_next_move(legal_moves_list[i]);
        //legal_moves_list.erase(legal_moves_list.begin()+next);
    }
}



int char_to_int(char c) {
    return int(c)-64;
}



char int_to_char(int n) {
    if (n == 0)
        return '.';
    else 
        return (char)(n+64);
}



void Burrow::print() {
    for (int i = 0; i < this->hallway.size; ++i)
    {
        cout << int_to_char(this->hallway.array[i]);
        if (i != 0 && i != 5 && i != 6) 
            cout << ".";
    }
    cout << endl;

    for (int i = 0; i < this->rooms[0].size; ++i)
    {
        cout << "  ";
        for (int k = 0; k < this->num_rooms; ++k)
        {
            cout << int_to_char(rooms[k].array[i]) << " ";
        }
        cout << endl;
    }
}



bool Burrow::complete() {
    for (int i = 0; i < this->hallway.size; ++i)
    {
        if (hallway.array[i] != 0)
            return false;
    }

    for (int i = 0; i < this->num_rooms; ++i)
    {
        for (int k = 0; k < this->rooms[i].size; ++k)
        {
            if (this->rooms[i].array[k] != i+1)
                return false;
        }
    }

    return true;
}



Burrow get_input() {
    Burrow burrow;

    string str;
    
    for (int i = 0; i < burrow.rooms[0].size; ++i)
    {
        cin >> str;
        for (int k = 0; k < 4; k++)
        {
            burrow.rooms[k].array[i] = char_to_int(str.at(k));
        }
    }

    return burrow;
}