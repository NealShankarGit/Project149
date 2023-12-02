#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// my hashMap class
class hashMap {
public:
    // defaulting to 50
    int numBuckets = 50;
    // the data structure to store the incoming data
    vector<vector<pair<int, int>>> hashmap;
    // constructor
    hashMap(int buckets) : numBuckets(buckets), hashmap(buckets) {}

    // insert function that uses hash value to decide which bucket to put the employee in
    void insert(int id, int perf_num){
        // run id through hash function and get bucket index
        hash<int> hasher;
        // store hashed value
        size_t hash_val = hasher(id) % numBuckets;
        // create pair of ints
        pair<int, int> employee(id, perf_num);
        // put id and perf_num into bucket
        hashmap[hash_val].push_back(employee);
    }

    // search function that returns perf_num
    int& searchiD (int id){
        if (hashmap.empty()){
            throw runtime_error("Nothing in employee database!");
        }
        // run id through hash function and get bucket index
        hash<int> hasher;
        // store hashed value
        size_t hash_val = hasher(id) % numBuckets;
        // search through the vector[hash_val]
        for (int i = 0; i < hashmap[hash_val].size(); i++){
            if (hashmap[hash_val][i].first == id) {
                return hashmap[hash_val][i].second;
            }
        }
    }

    // search function that returns id of lowest productivity score
    pair <int, int> searchforBottom (){
        // error message if hashmap is empty
        if (hashmap.empty()){
            throw runtime_error("Nothing in employee database!");
        }

        int min = INT_MAX;
        int id = -1;
        // loop through entire hashmap
        for (int i = 0; i < hashmap.size(); i++){
            for (int j = 0; j < hashmap[i].size(); j++){
                // checks to see if the element is the lowest yet
                if (hashmap[i][j].second < min){
                    // reassigns the minimum
                    min = hashmap[i][j].second;
                    id = hashmap[i][j].first;
                }
            }
        }
        // if no id found as bottom performer
        if (id == -1){
            throw runtime_error("No valid iD found");
        }

        // create a pair of the bottom performer to return it
        pair<int, int> bottom = make_pair(id, min);
        return bottom;
    }
};
