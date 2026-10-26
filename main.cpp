#include "KnowledgeGraph.h"

int main() {

    KnowledgeGraph kg;

    cout << "\n====================================\n";
    cout << "   CYBER THREAT KNOWLEDGE GRAPH\n";
    cout << "      SAMPLE DATASET TEST\n";
    cout << "====================================\n";

    kg.loadSampleData();

    cout << "\n--- Attack Path From Attacker_A ---\n";

    kg.findAttackPath(
        "Attacker_A",
        "Organization_A"
    );

    cout << "\n--- Attack Path From Attacker_B ---\n";

    kg.findAttackPath(
        "Attacker_B",
        "Organization_A"
    );

    cout << "\n--- Invalid Entity Test ---\n";

    kg.findAttackPath(
        "Unknown",
        "Organization_A"
    );

    return 0;
}