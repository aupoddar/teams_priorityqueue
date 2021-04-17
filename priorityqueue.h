//
// Created by Auboni Poddar on 2019-11-13.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include <vector>
#include <utility>
#include "json.hpp"

typedef double                  Key;
typedef std::pair<int, int>     Value; //Value.first() Value.second()
typedef std::pair<Key, Value>   KeyValuePair;

class PriorityQueue {
public:
    PriorityQueue(std::size_t max_nodes);
    void insert(Key k);
    void insert(KeyValuePair kv);
    KeyValuePair min();
    KeyValuePair removeMin();
    bool isEmpty() const;
    size_t size() const;
    nlohmann::json JSON() const;


    void heapifyUp(size_t i);
    void heapifyDown(size_t i);
    void removeNode(size_t i);
    Key getKey(size_t i);

    std::vector<KeyValuePair>   nodes_; //name of array nodes_.at(size_)
    size_t                      max_size_;
    size_t                      size_; //size_ = size_ + 1
    int                         maxheap;
    int                         numoperations;

    const static size_t         ROOT = 1;
};  // class PriorityQueue




#endif //PRIORITYQUEUE_PRIORITYQUEUE_H

