#include "KnowledgeGraph.h"

int main() {

    KnowledgeGraph kg;

    cout << "\n====================================\n";
    cout << "   CYBER THREAT KNOWLEDGE GRAPH\n";
    cout << "        CORE STRUCTURE TEST\n";
    cout << "====================================\n";

    // Add cybersecurity entities

    kg.addEntity("Attacker_A", "Attacker");

    kg.addEntity("Malware_X", "Malware");

    kg.addEntity("CVE_101", "Vulnerability");

    // Add relationships

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

    cout << "\nCore knowledge graph structure tested successfully!\n";

    return 0;
}