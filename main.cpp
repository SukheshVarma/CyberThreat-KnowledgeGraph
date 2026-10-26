#include "KnowledgeGraph.h"

int main() {

    KnowledgeGraph kg;

    cout << "\n====================================\n";
    cout << "   CYBER THREAT KNOWLEDGE GRAPH\n";
    cout << "          BFS / DFS TEST\n";
    cout << "====================================\n";

    kg.addEntity("Attacker_A", "Attacker");
    kg.addEntity("Malware_X", "Malware");
    kg.addEntity("CVE_101", "Vulnerability");
    kg.addEntity("Server_01", "Server");
    kg.addEntity("Organization_A", "Organization");

    kg.addRelationship(
        "Attacker_A",
        "uses",
        "Malware_X"
    );

    kg.addRelationship(
        "Malware_X",
        "exploits",
        "CVE_101"
    );

    kg.addRelationship(
        "CVE_101",
        "affects",
        "Server_01"
    );

    kg.addRelationship(
        "Server_01",
        "belongs_to",
        "Organization_A"
    );

    cout << "\n--- BFS Test ---\n";
    kg.BFS("Attacker_A");

    cout << "\n--- DFS Test ---\n";
    kg.DFS("Attacker_A");

    cout << "\n--- Invalid BFS Test ---\n";
    kg.BFS("Unknown");

    cout << "\n--- Invalid DFS Test ---\n";
    kg.DFS("Unknown");

    return 0;
}