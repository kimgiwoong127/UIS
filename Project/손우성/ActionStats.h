#ifndef ACTIONSTATS_H
#define ACTIONSTATS_H

#include <unordered_map>
#include <string>

using namespace std;

struct ActionData {
    int totalAttempts = 0;
    int successfulAttempts = 0;
    double successRate() const {
        return totalAttempts > 0 ? (double)successfulAttempts / totalAttempts : 0.0;
    }
};

class ActionStats {
public:
    void recordAction(string action, bool success) {
        ActionData& data = actionStats[action];
        data.totalAttempts++;
        if (success) {
            data.successfulAttempts++;
        }
    }

    string getBestAction() {
        string bestAction;
        double highestSuccessRate = 0.0;
        for (const auto& pair : actionStats) {
            double rate = pair.second.successRate();
            if (rate > highestSuccessRate) {
                highestSuccessRate = rate;
                bestAction = pair.first;
            }
        }
        return bestAction;
    }

private:
    unordered_map<string, ActionData> actionStats;
};

#endif
