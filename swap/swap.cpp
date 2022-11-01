/**
 * ubuntu@VM-4-8-ubuntu:~/hw/swap$ g++ ./swap.cpp
 * ubuntu@VM-4-8-ubuntu:~/hw/swap$ ./a.out < ./swap.in
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <list>
#include <time.h>

using namespace std;

enum Strategy {FIFO, LRU, RANDOM};

unsigned int n_visit;
unsigned int n_frame;
unsigned int n_hits = 0;
unsigned int n_misses = 0;
unsigned int n_count = 0;
Strategy strategy = RANDOM;
int g_tmp = -1;

list<int> visits;
list<int> frames;
map<int, unsigned int> frame_visit_timestamps;

bool page_has(int visit) {
    for (std::list<int>::iterator it = frames.begin(); it != frames.end(); ++it) {
        if (visit == *it) {
            return true;
        }
    }
    return false;
}

int swap_by_RAND(int visit) {
    int rand_pos = rand() % frames.size();
    int tmp_count = 0;
    std::list<int>::iterator to_drop;
    for (std::list<int>::iterator it = frames.begin(); it != frames.end(); ++it) {
        if (tmp_count == rand_pos) {
            to_drop = it;
            break;
        }
        ++tmp_count;
    }
    int drop_value = *to_drop;
    frames.erase(to_drop);
    frames.push_back(visit);
    return drop_value;
}

int swap_by_LRU(int visit) {
    unsigned int minim_visit_time = n_count + 1;
    std::list<int>::iterator to_drop;
    for (std::list<int>::iterator it = frames.begin(); it != frames.end(); ++it) {
        unsigned int this_visit_time = frame_visit_timestamps[*it];
        if (this_visit_time < minim_visit_time) {
            minim_visit_time = this_visit_time;
            to_drop = it;
        }
    }
    int to_drop_value = *to_drop;
    frames.erase(to_drop);
    frames.push_back(visit);
    frame_visit_timestamps[visit] = n_count;
    frame_visit_timestamps.erase(frame_visit_timestamps.find(to_drop_value));
    return to_drop_value;
}

int swap_by_FIFO(int visit) {
    int top = frames.front();
    frames.pop_front();
    frames.push_back(visit);
    return top;
}

int do_swap(Strategy s, int visit) {
    if (s == FIFO) {
        return swap_by_FIFO(visit);
    } else if (s == LRU) {
        return swap_by_LRU(visit);
    }
    return swap_by_RAND(visit);
}

void do_log(Strategy s, int visit, unsigned int n_count) {
    if (s == LRU) {
        // update
        frame_visit_timestamps[visit] = n_count;
    } else if (s == FIFO) {
        // nothing
    }
}

string get_frame_str() {
    std::string res = "[ ";
    for (std::list<int>::iterator it = frames.begin(); it != frames.end(); ++it) {
        res.append(to_string(*it));
        res.append(" ");
    }
    res.append("]");
    return res;
}

int main(int argc, char const *argv[])
{
    srand (time(NULL));
    cout << "Please input the strategy number: 1 - FIFO, 2 - LRU, others - RANDOM:\n";
    cin >> g_tmp;
    if (g_tmp == 1) {
        strategy = FIFO;
    } else if (g_tmp == 2) {
        strategy = LRU;
    }
    cout << "Please input the number of visits, and number of page frames:\n";
    cin >> n_visit >> n_frame;
    cout << "Please input the visits:\n";
    for (unsigned int i = 0; i < n_visit; ++i) {
        int tmp = 0;
        cin >> tmp;
        visits.push_back(tmp);
    }
    for (std::list<int>::iterator it = visits.begin(); it != visits.end(); ++it) {
        ++n_count;
        int visit = *it;
        bool has_flag = page_has(visit);
        bool replaces = false;
        int dropped = -1;
        if (has_flag) {
            ++n_hits;
            do_log(strategy, visit, n_count);
        } else if (n_frame > (unsigned int) frames.size()) {
            ++n_misses;
            frames.push_back(visit);
            frame_visit_timestamps[visit] = n_count;
        } else {
            ++n_misses;
            replaces = true;
            dropped = do_swap(strategy, visit);
        }
        cout << "Access: " << visit << " "
            << (has_flag ? "HIT " : "MISS") << " ";
        cout << "FRAMES -> " << get_frame_str();
        cout << " Replaced : " << (replaces ? to_string(dropped) : "-") << " ";
        cout << "[Hits: " << n_hits << " Misses: " << n_misses << " ]\n";
    }
    cout << endl << "FINALSTATS : " << "hits " << n_hits << " misses " << n_misses
        << " hitrate " << to_string(100 * n_hits / n_count) << "%" << endl;
    return 0;
}
