#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> skillLevels(n);
    for (int i = 0; i < n; ++i) {
        cin >> skillLevels[i];
    }

    sort(skillLevels.begin(), skillLevels.end());

    int maxTeamSize = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && skillLevels[j] - skillLevels[i] <= 5) {
            j++;
        }
        maxTeamSize = max(maxTeamSize, j - i);
    }

    cout << maxTeamSize << endl;
    return 0;
}
