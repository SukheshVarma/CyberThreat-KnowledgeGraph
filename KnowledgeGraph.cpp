#include "KnowledgeGraph.h"

void KnowledgeGraph::addEntity(string name, string type) {

    if (entities.find(name) != entities.end()) {

        cout << "Entity already exists!\n";

        return;
    }

    Entity newEntity;

    newEntity.name = name;
    newEntity.type = type;

    entities[name] = newEntity;

    graph[name] = {};

    cout << "Entity added successfully!\n";
}


void KnowledgeGraph::addRelationship(
    string source,
    string relation,
    string target
) {

    if (entities.find(source) == entities.end()) {

        cout << "Source entity does not exist!\n";

        return;
    }

    if (entities.find(target) == entities.end()) {

        cout << "Target entity does not exist!\n";

        return;
    }

    for (auto &relationship : graph[source]) {

        if (relationship.target == target &&
            relationship.relation == relation) {

            cout << "Relationship already exists!\n";

            return;
        }
    }

    Relationship newRelationship;

    newRelationship.target = target;
    newRelationship.relation = relation;

    graph[source].push_back(newRelationship);

    cout << "Relationship added successfully!\n";
}
void KnowledgeGraph::displayGraph() {

    cout << "\n========== KNOWLEDGE GRAPH ==========\n";

    if (entities.empty()) {
        cout << "Graph is empty!\n";
        return;
    }

    for (auto &entity : entities) {

        cout << "\n"
             << entity.second.name
             << " ["
             << entity.second.type
             << "]\n";

        for (auto &relationship : graph[entity.first]) {

            cout << "   "
                 << relationship.relation
                 << " -> "
                 << relationship.target
                 << "\n";
        }
    }

    cout << "\n=====================================\n";
}


void KnowledgeGraph::searchEntity(string name) {

    auto it = entities.find(name);

    if (it == entities.end()) {

        cout << "Entity not found!\n";

        return;
    }

    cout << "\nEntity Found!\n";

    cout << "Name : "
         << it->second.name
         << "\n";

    cout << "Type : "
         << it->second.type
         << "\n";
}
