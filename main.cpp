#include "KnowledgeGraph.h"

int main() {

    KnowledgeGraph kg;

    int choice;

    do {

        cout << "\n============================================\n";
        cout << "       CYBER THREAT KNOWLEDGE GRAPH\n";
        cout << "============================================\n";

        cout << "1. Add Entity\n";
        cout << "2. Add Relationship\n";
        cout << "3. Display Graph\n";
        cout << "4. Search Entity\n";
        cout << "5. BFS Threat Traversal\n";
        cout << "6. DFS Threat Traversal\n";
        cout << "7. Find Attack Path\n";
        cout << "8. Load Sample Dataset\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {

            cout << "\nInvalid input! Please enter a number.\n";

            cin.clear();
            cin.ignore(1000, '\n');

            continue;
        }

        switch (choice) {

            case 1: {

                string name;
                string type;

                cout << "\nEnter entity name: ";
                cin >> name;

                cout << "Enter entity type: ";
                cin >> type;

                kg.addEntity(name, type);

                break;
            }

            case 2: {

                string source;
                string relation;
                string target;

                cout << "\nEnter source entity: ";
                cin >> source;

                cout << "Enter relationship: ";
                cin >> relation;

                cout << "Enter target entity: ";
                cin >> target;

                kg.addRelationship(
                    source,
                    relation,
                    target
                );

                break;
            }

            case 3:

                kg.displayGraph();

                break;

            case 4: {

                string name;

                cout << "\nEnter entity name to search: ";
                cin >> name;

                kg.searchEntity(name);

                break;
            }

            case 5: {

                string start;

                cout << "\nEnter starting entity for BFS: ";
                cin >> start;

                kg.BFS(start);

                break;
            }

            case 6: {

                string start;

                cout << "\nEnter starting entity for DFS: ";
                cin >> start;

                kg.DFS(start);

                break;
            }

            case 7: {

                string source;
                string destination;

                cout << "\nEnter source entity: ";
                cin >> source;

                cout << "Enter destination entity: ";
                cin >> destination;

                kg.findAttackPath(
                    source,
                    destination
                );

                break;
            }

            case 8:

                kg.loadSampleData();

                break;

            case 9:

                cout << "\nExiting program...\n";

                break;

            default:

                cout << "\nInvalid choice! Please select 1-9.\n";
        }

    } while (choice != 9);

    return 0;
}