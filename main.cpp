#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <list.h>
#include <queue.h>
#include <Tree.h>
#include <graph.h>
#include <list>
#include <string>

template<typename T>
void printVector(const std::vector<T>& vec) {
    for(const auto& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
std::vector<size_t> generatePrimeNumbers(std::vector<size_t>& numbers, size_t N) {
    auto p = 2;
    size_t n = std::sqrt(N);
    std::iota(std::begin(numbers), std::end(numbers), 0);
    for(auto p = 2; p < N+1; ++p) {
        if (numbers[p] != 0) {
            for(auto j = p*p; j < N+1; j+=p) {
                numbers[j] = 0;
            }
            if (p*p > N) break;
        }
    }
    std::vector<size_t> prime_numbers;
    for(auto& i : numbers) {
        if(i != 0 && i != 1) prime_numbers.push_back(i);
    }
    return prime_numbers;
}

std::vector<size_t> getMultipliers(size_t N, const std::vector<size_t>& primes) {
    size_t number, index = 0;
    std::vector<size_t> mult;
    while (N != 1) {
        if(N%primes[index] == 0) {
            mult.push_back(primes[index]);
            N /= primes[index];
            index = 0;
        }
        else {
            index++;
        }
    }
    return mult;
}

std::vector<size_t> prefix_function(const std::string& string) {
    std::vector<size_t> out(string.size());
    for(auto i = 0; i < string.size(); ++i) {
        for(auto len = 1; len < i; ++len) {
            if(string.substr(0, len) == string.substr(i-len+1, len))
                out[i] = len;
        }
    }
    return out;
}

std::vector<size_t> prefix(const std::string& str) {
    std::vector<size_t> out(str.size());
    for(auto i = 0; i < str.size(); ++i) {
        for(auto len = 0; len < i; len++) {
            std::string s1 = str.substr(0, len);
            std::string s2 = str.substr(i-len+1, len);
            if(s1 == s2)
                out[i] = len;
        }
    }
    return out;
}

std::vector<size_t> fast_prefix(const std::string& str) {
    std::vector<size_t> p(str.size(),0);
    for(size_t i = 1; i < str.size(); ++i) {
        size_t cur = p[i-1];
        while((str[i] != str[cur]) && cur > 0 )
            cur = p[cur-1];
        if(str[i] == str[cur])
            p[i] = cur + 1;
    }
    return p;
}

std::vector<size_t> find(const std::string& word, const std::string& string) {
    std::vector<size_t> index(fast_prefix(word + '#' + string));
    std::vector<size_t> out;
    for(auto i = 0; i < index.size(); ++i) {
        if(index[i] == word.size()) {
            out.push_back(i-2*word.size());
        }
    }
    return out;
}

std::vector<size_t> z_function(const std::string& str) {
    size_t n = str.size();
    std::vector<size_t> z(n, 0);
    for(auto i = 1; i < str.size(); ++i) {
        while(i+z[i] < n && str[z[i]] == str[i+z[i]]) {
            ++z[i];
        }
    }
    return z;
}

std::vector<size_t> fast_z_function(const std::string& str) {
    size_t n = str.size();
    std::vector<size_t> z(n, 0);
    for(size_t i = 1, left = 0, right = 0; i < n; ++i) {
        if(i <= right) {
            z[i] = std::min(right-i+1, z[i-left]);
        }
        while(i+z[i] < n && str[z[i]] == str[i+z[i]])
            ++z[i];
        if(i+z[i]-1 > right) {
            left = i;
            right = i + z[i]-1;
        }
    }
    return z;
}

std::vector<size_t> find_z(const std::string& word, const std::string& string) {
    std::vector<size_t> index(fast_z_function(word + '#' + string));
    std::vector<size_t> out;
    for(auto i = 0; i < index.size(); ++i) {
        if(index[i] == word.size()) {
            out.push_back(i);
        }
    }
    return out;
}

std::pair<size_t, size_t> maxSum(const std::vector<int>& lhs, const std::vector<int>& rhs) {

    std::pair<size_t, size_t> out{0,0};
    int max_l{INT_MIN};
    std::pair<size_t, int> max_r_buffer{0, INT_MIN};
    bool wait = false;
    for(size_t i = 0; i < lhs.size(); ++i) {
        if(rhs[i] > max_r_buffer.second) {
            max_r_buffer = {i,rhs[i]};
            wait = true;
            if(i < out.second) out.first = i;
        }
        if(lhs[i] > max_l) {
            max_l = lhs[i];
            out.second = i;
            if(wait) {
                if(i > max_r_buffer.first) {
                    wait = false;
                    out.first = max_r_buffer.first;
                }
            }
        }
    }

    return out;
}


int main()
{
//    WeightedGraph g(9);
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);
//    g.primMST();


    std::string s = "cho?se";
    std::string t = "chopse life. chotse a job. chotse a career. chopse a family. chopse a fu...";
//    std::string s1 = "abcabcd";
//    printVector(fast_prefix(s1));
    std::string s2 = "aaabaab";
//    printVector(z_function(s2));
//    printVector(fast_z_function(s2));
//    printVector(fast_z_function(s + '#'+t));
//    printVector(find_z(s, t));
    //printVector(find(s, t));

    std::vector<int> rhs = {1, 3, 4, 1};
    std::vector<int> lhs = {1, 2, 1, 6};
    auto index = maxSum(lhs, rhs);
    std::cout << index.first << ' ' << index.second << std::endl;
    return 0;     
}
