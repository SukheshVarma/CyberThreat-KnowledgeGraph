#ifndef KNOWLEDGE_GRAPH_H
#define KNOWLEDGE_GRAPH_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

struct Entity {
    string name;
    string type;
};

struct Relationship {
    string target;
    string relation;
};

class KnowledgeGraph {

private:

    unordered_map<string, Entity> entities;

    unordered_map<string, vector<Relationship>> graph;

public:

    void addEntity(string name, string type);

    void addRelationship(
        string source,
        string relation,
        string target
    );

    void displayGraph();

    void searchEntity(string name);
    void BFS(string start);
    void DFS(string start);
    void findAttackPath(
    string source,
    string destination
);

void loadSampleData();
};

#endif