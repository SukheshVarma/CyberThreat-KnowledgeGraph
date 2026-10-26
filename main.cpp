#include "KnowledgeGraph.h"

int main() {

    KnowledgeGraph kg;

    cout << "\n====================================\n";
    cout << "   CYBER THREAT KNOWLEDGE GRAPH\n";
    cout << "        CORE STRUCTURE TEST\n";
    cout << "====================================\n";

    kg.addEntity("Attacker_A", "Attacker");
    kg.addEntity("Malware_X", "Malware");
    kg.addEntity("CVE_101", "Vulnerability");

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

    cout << "\n--- Display Graph ---\n";
    kg.displayGraph();

    cout << "\n--- Search Entity ---\n";
    kg.searchEntity("Malware_X");

    cout << "\n--- Search Missing Entity ---\n";
    kg.searchEntity("Unknown");

    return 0;
}