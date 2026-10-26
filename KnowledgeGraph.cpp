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


void KnowledgeGraph::BFS(string start) {

    if (entities.find(start) == entities.end()) {

        cout << "Starting entity does not exist!\n";
        return;
    }

    unordered_set<string> visited;

    queue<string> q;

    visited.insert(start);

    q.push(start);

    cout << "\nBFS Threat Traversal:\n";

    while (!q.empty()) {

        string current = q.front();

        q.pop();

        cout << current << " ";

        for (auto &relationship : graph[current]) {

            string next = relationship.target;

            if (visited.find(next) == visited.end()) {

                visited.insert(next);

                q.push(next);
            }
        }
    }

    cout << "\n";
}


void KnowledgeGraph::DFS(string start) {

    if (entities.find(start) == entities.end()) {

        cout << "Starting entity does not exist!\n";
        return;
    }

    unordered_set<string> visited;

    cout << "\nDFS Threat Traversal:\n";

    function<void(string)> dfs =
        [&](string current) {

            visited.insert(current);

            cout << current << " ";

            for (auto &relationship : graph[current]) {

                string next = relationship.target;

                if (visited.find(next) == visited.end()) {

                    dfs(next);
                }
            }
        };

    dfs(start);

    cout << "\n";
}


void KnowledgeGraph::findAttackPath(
    string source,
    string destination
) {

    if (entities.find(source) == entities.end()) {

        cout << "Source entity does not exist!\n";
        return;
    }

    if (entities.find(destination) == entities.end()) {

        cout << "Destination entity does not exist!\n";
        return;
    }

    if (source == destination) {

        cout << "\nSource and destination are the same.\n";
        cout << "Attack Path: " << source << "\n";

        return;
    }

    queue<string> q;

    unordered_set<string> visited;

    unordered_map<string, string> parent;

    q.push(source);

    visited.insert(source);

    bool found = false;

    while (!q.empty()) {

        string current = q.front();

        q.pop();

        for (auto &relationship : graph[current]) {

            string next = relationship.target;

            if (visited.find(next) == visited.end()) {

                visited.insert(next);

                parent[next] = current;

                q.push(next);

                if (next == destination) {

                    found = true;
                    break;
                }
            }
        }

        if (found) {
            break;
        }
    }

    if (!found) {

        cout << "\nNo attack path exists between "
             << source
             << " and "
             << destination
             << ".\n";

        return;
    }

    vector<string> path;

    string current = destination;

    while (current != source) {

        path.push_back(current);

        current = parent[current];
    }

    path.push_back(source);

    reverse(path.begin(), path.end());

    cout << "\n========== ATTACK PATH ==========\n";

    for (int i = 0; i < path.size(); i++) {

        cout << path[i];

        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << "\n=================================\n";
}


void KnowledgeGraph::loadSampleData() {

    cout << "\nLoading sample cybersecurity dataset...\n";

    // Entities

    addEntity("Attacker_A", "Attacker");
    addEntity("Attacker_B", "Attacker");

    addEntity("Malware_X", "Malware");
    addEntity("Malware_Y", "Malware");

    addEntity("CVE_101", "Vulnerability");
    addEntity("CVE_202", "Vulnerability");

    addEntity("Server_01", "Server");
    addEntity("Server_02", "Server");

    addEntity("Organization_A", "Organization");


    // Relationships

    addRelationship(
        "Attacker_A",
        "uses",
        "Malware_X"
    );

    addRelationship(
        "Attacker_B",
        "uses",
        "Malware_Y"
    );

    addRelationship(
        "Malware_X",
        "exploits",
        "CVE_101"
    );

    addRelationship(
        "Malware_Y",
        "exploits",
        "CVE_202"
    );

    addRelationship(
        "CVE_101",
        "affects",
        "Server_01"
    );

    addRelationship(
        "CVE_202",
        "affects",
        "Server_02"
    );

    addRelationship(
        "Malware_X",
        "targets",
        "Server_02"
    );

    addRelationship(
        "Server_01",
        "belongs_to",
        "Organization_A"
    );

    addRelationship(
        "Server_02",
        "belongs_to",
        "Organization_A"
    );

    cout << "\nSample dataset loaded successfully!\n";
}