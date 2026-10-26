#ifndef KNOWLEDGE_GRAPH_H
#define KNOWLEDGE_GRAPH_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

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
};

#endif