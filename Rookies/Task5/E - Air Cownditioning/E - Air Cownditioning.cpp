
//E
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Cow {
    int start, end, cooling;
};

struct AirConditioner {
    int start, end, power, cost;
};

int n, m;
Cow cows[20];
AirConditioner acs[10];
int minCost = INT_MAX;

void checkCooling(const vector<int>& acIndices) {
    int cooling[101] = { 0 };
    int cost = 0;

    for (int index : acIndices) {
        AirConditioner ac = acs[index];
        cost += ac.cost;
        for (int i = ac.start; i <= ac.end; i++) {
            cooling[i] += ac.power;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = cows[i].start; j <= cows[i].end; j++) {
            if (cooling[j] < cows[i].cooling) {
                return;
            }
        }
    }
    minCost = min(minCost, cost);
}

void findMinCost(int acIndex, vector<int>& acIndices) {
    if (acIndex == m) {
        checkCooling(acIndices);
        return;
    }

    // Choose the current air conditioner
    acIndices.push_back(acIndex);
    findMinCost(acIndex + 1, acIndices);
    acIndices.pop_back();

    // Do not choose the current air conditioner
    findMinCost(acIndex + 1, acIndices);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].cooling;
    }
    for (int i = 0; i < m; i++) {
        cin >> acs[i].start >> acs[i].end >> acs[i].power >> acs[i].cost;
    }

    vector<int> acIndices;
    findMinCost(0, acIndices);

    cout << minCost << endl;

    return 0;
}
