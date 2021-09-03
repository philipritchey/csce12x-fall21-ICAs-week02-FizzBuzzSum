#include <iostream>
#include <utility>
#include <tuple>
#include <list>
#include "code.h"

/*
This file unit tests the function(s) in code.cpp
Dr. Ritchey had to write this because Replit doesn't support unit testing for C++ (smh)
By the end of 121, you could be able to write this (and better), too.
*/

std::pair<int,int> test(std::list<std::pair<std::pair<int,int>,int>> tests) {
    int pass_cnt = 0, fail_cnt = 0;

    for (auto testcase : tests) {
        int lower = testcase.first.first;
        int upper = testcase.first.second;
        int expected = testcase.second;
        int actual = fizz_buzz_sum(lower, upper);
        if (actual != expected) {
            std::cout << "[FAIL] expected fizz_buzz_sum("<<lower<<", "<<upper<<") to be " << expected << ", got " << actual << std::endl;
            fail_cnt++;
        } else {
            std::cout << "[PASS] fizz_buzz_sum("<<lower<<", "<<upper<<") = " << actual << std::endl;
            pass_cnt++;
        }
    }

    return std::make_pair(pass_cnt, fail_cnt);
}

int main() {
    std::list<std::pair<std::pair<int,int>,int>> tests = {
        {{0, 8}, 14},
        {{0, 0}, 0},
        {{0, 5}, 8},
        {{0, 9}, 23},
        {{0, 2}, 0},
        {{0, 3}, 3},
        {{0, 6}, 14},
        {{0, 10}, 33},
        {{0, 20}, 83},
        {{0, 100}, 2103},
        {{0, 250}, 12753},
        {{867, 5309}, 5488707},
        {{77, 843}, 140838},
        {{100, 200}, 6000}
        };

    int pass_cnt, fail_cnt;

    std::tie(pass_cnt,fail_cnt) = test(tests);

    std::cout << "passing " << pass_cnt << std::endl;
    std::cout << "failing " << fail_cnt << std::endl;
}