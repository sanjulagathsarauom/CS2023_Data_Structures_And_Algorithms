#include <iostream>
#include <limits>

#define INF 9999

using namespace std;

int V = 6; // Number of vertices
int src = 5; // Source vertex

bool visited[6] = {0, 0, 0, 0, 0, 0};
int parent[6];


int cost[6][6] = {
    { 0, 10, INF, INF, 15, 5 },
    { 10, 0, 10, 30, INF, INF },
    { INF, 10, 0, 12, 5, INF },
    { INF, 30, 12, 0, INF, 20 },
    { 15, INF, 5, INF, 0, INF },
    { 5, INF, INF, 20, INF, 0 }
};

int time3[6];

void init() {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        time3[i] = INF;
    }
    time3[src] = 0;
}

int getNearest() {
    int minValue = INF;
    int minNode = 0;

    for (int i = 0; i < V; i++) {
        if (time3[i] < minValue && visited[i] == 0) {
            minValue = time3[i];
            minNode = i;
        }
    }

    return minNode;
}

void djikstra() {
    for (int i = 0; i < V; i++) {
        int nearest = getNearest();
        visited[nearest] = true;

        for (int adj = 0; adj < V; adj++) {
            if (cost[nearest][adj] != INF && time3[adj] > time3[nearest] + cost[nearest][adj]) {
                time3[adj] = time3[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void display() {
    cout<<endl;
    cout<<endl;
    cout<<"Source - "<<src<<endl;
    cout<<endl;
    cout << "Node:\t\t\tShortest Distance:\t Path" << endl;

    for (int i = 0; i < V; i++) {
        cout << i << "\t\t\t" << time3[i] << "\t\t\t" << i << " ";
        int parNode = parent[i];

        while (parNode != src) {
            cout << " <- " << parNode << " ";
            parNode = parent[parNode];
        }
        cout << endl;
        
    }
    cout << endl;
    cout << "Average Time from city "<<src<<" to others = "<<(time3[0]+time3[1]+time3[2]+time3[3]+time3[4]+time3[5])/5<<endl;
    cout << endl;
}

int main() {
    init();
    djikstra();
    display();

    return 0;
}
