#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int *steps;
        queue<int> q;

        steps = new int[2 * n];
        for (int i = 0; i < 2*n; i++) steps[i] = -1;
        steps[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            int nextStep = now - 1;
            if (nextStep >=0 && steps[nextStep] == -1) {
                steps[nextStep] = steps[now] + 1;
                if (nextStep == n) break;
                q.push(nextStep);
            }

            nextStep = now + 1;
            if (steps[nextStep] == -1) {
                steps[nextStep] = steps[now] + 1;
                if (nextStep == n) break;
                q.push(nextStep);
            }

            nextStep = now * 2;
            if (steps[nextStep] == -1) {
                steps[nextStep] = steps[now] + 1;
                if (nextStep == n) break;
                q.push(nextStep);
            }
        }

        cout << steps[n];
    }

    return 0;
}