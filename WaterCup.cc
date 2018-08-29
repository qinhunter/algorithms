#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

void showvec(const vector<int>& vec) {
    for(auto it = vec.begin();it != vec.end();it++) {
        cout << *it << " ";
    }
    // cout << endl;
}

class StupidSolution {
public:
    int findtheway(const vector<int> cupsize, const vector<int> target) {
        map<vector<int>, int> states;
        int size = cupsize.size();
        if(size < 1 || size != target.size()) {
            return -1;
        }
        for(int i = 0;i < size;i++) {
            if(cupsize[i] < 0 || target[i] < 0 || cupsize[i] < target[i]) {
                return -1;
            }
        }
        cout << "the cupsize and target is valid, we will start the calculation" << endl;
        vector<int> cups(size, 0);
        states[cups] = 0;
        showvec(cups);
        helper(cupsize, cups, states, 1);

        cout << "there are " << states.size() << " states" << endl;
        for(auto it = states.begin();it != states.end();it++) {
            for(int i = 0;i < size;i++) {
                cout << (it->first)[i] << " ";
            }
            cout << ", steps = " << it->second << endl;
        }

        if(states.find(target) != states.end()) {
            return states[target];
        }
        return -1;
    }

    void helper(const vector<int>& cupsize, vector<int> cupsnow, map<vector<int>, int>& states, int steps) {
        int size = cupsize.size();
        for(int i = 0;i < size;i++) {// every cup
            if(cupsnow[i] != cupsize[i]) {
                //fill the cup

                int temp = cupsnow[i];
                cupsnow[i] = cupsize[i];
                if(states.find(cupsnow) != states.end()) {//found
                    if(states[cupsnow] > steps) {
                        showvec(cupsnow);
                        cout << "old steps = " << states[cupsnow] << " steps = " << steps << endl;

                        states[cupsnow] = steps;
                        helper(cupsize, cupsnow, states, steps + 1);
                    }
                } else {//new state
                    states[cupsnow] = steps;
                    cout << "new state: ";
                    showvec(cupsnow);
                    cout << "steps = " << steps << endl;
                    helper(cupsize, cupsnow, states, steps + 1);
                }
                cupsnow[i] = temp;
            }
            if(cupsnow[i] > 0) {
                int temp = cupsnow[i];

                // empty the cup
                cupsnow[i] = 0;
                if(states.find(cupsnow) != states.end()) {//found
                    if(states[cupsnow] > steps) {
                        showvec(cupsnow);
                        cout << "old steps = " << states[cupsnow] << " steps = " << steps << endl;

                        states[cupsnow] = steps;
                        helper(cupsize, cupsnow, states, steps + 1);
                    }
                } else {//new state
                    states[cupsnow] = steps;
                    cout << "new state: ";
                    showvec(cupsnow);
                    cout << "steps = " << steps << endl;
                    helper(cupsize, cupsnow, states, steps + 1);
                }
                cupsnow[i] = temp;

                //move the water from the cup to another cup
                for(int j = 0;j < size;j++) {
                    if(j == i) {
                        continue;
                    }
                    if(cupsnow[j] < cupsize[j]) {
                        if(cupsize[j] - cupsnow[j] >= cupsnow[i]) {
                            int temp1 = cupsnow[j];
                            int temp2 = cupsnow[i];
                            cupsnow[j] += cupsnow[i];
                            cupsnow[i] = 0;

                            if(states.find(cupsnow) != states.end()) {//found
                                if(states[cupsnow] > steps) {
                                    showvec(cupsnow);
                                    cout << "old steps = " << states[cupsnow] << " steps = " << steps << endl;

                                    states[cupsnow] = steps;
                                    helper(cupsize, cupsnow, states, steps + 1);
                                }
                            } else {//new state
                                states[cupsnow] = steps;
                                cout << "new state: ";
                                showvec(cupsnow);
                                cout << "steps = " << steps << endl;
                                helper(cupsize, cupsnow, states, steps + 1);
                            }

                            cupsnow[j] = temp1;
                            cupsnow[i] = temp2;

                        } else {//cupsize[j] - cupsnow[j] < cupsnow[i]
                            int temp1 = cupsnow[j];
                            int temp2 = cupsnow[i];
                            cupsnow[i] -= (cupsize[j] - cupsnow[j]);
                            cupsnow[j] = cupsize[j];

                            if(states.find(cupsnow) != states.end()) {//found
                                if(states[cupsnow] > steps) {
                                    showvec(cupsnow);
                                    cout << "old steps = " << states[cupsnow] << " steps = " << steps << endl;

                                    states[cupsnow] = steps;
                                    helper(cupsize, cupsnow, states, steps + 1);
                                }
                            } else {//new state
                                states[cupsnow] = steps;
                                cout << "new state: ";
                                showvec(cupsnow);
                                cout << "steps = " << steps << endl;
                                helper(cupsize, cupsnow, states, steps + 1);
                            }

                            cupsnow[j] = temp1;
                            cupsnow[i] = temp2;
                        }
                    }
                }

            }
        }
    }

};

class Solution{
public:
    int findtheway(const vector<int> cupsize, const vector<int> target) {
        set<vector<int>> states;
        int size = cupsize.size();
        if(size < 1 || size != target.size()) {
            return -1;
        }
        for(int i = 0;i < size;i++) {
            if(cupsize[i] < 0 || target[i] < 0 || cupsize[i] < target[i]) {
                return -1;
            }
        }
        cout << "the cupsize and target is valid, we will start the calculation" << endl;
        vector<int> cups(size, 0);
        vector<vector<int>> nextstate;
        nextstate.push_back(cups);
        states.insert(cups);
        return helper(cupsize, nextstate, target, states, 1);

    }

    int helper(const vector<int>& cupsize, const vector<vector<int>>& cups, const vector<int>& target, set<vector<int>> states, int steps) {
        int size = cupsize.size();
        vector<int> cupsnow;
        vector<vector<int>> nextstate;
        //every start status
        for(int k = 0;k < cups.size();k++) {
            cupsnow = cups[k];
            for (int i = 0; i < size; i++) {// every cup
                if (cupsnow[i] != cupsize[i]) {
                    //fill the cup

                    int temp = cupsnow[i];
                    cupsnow[i] = cupsize[i];
                    if (states.find(cupsnow) == states.end()) {//not found, new state
                        if(cupsnow == target) {
                            return steps;
                        }
                        states.insert(cupsnow);
                        nextstate.push_back(cupsnow);
                    }
                    cupsnow[i] = temp;
                }
                if (cupsnow[i] > 0) {
                    int temp = cupsnow[i];

                    // empty the cup
                    cupsnow[i] = 0;
                    if (states.find(cupsnow) == states.end()) {//not found, new state
                        if(cupsnow == target) {
                            return steps;
                        }
                        states.insert(cupsnow);
                        nextstate.push_back(cupsnow);
                    }
                    cupsnow[i] = temp;

                    //move the water from the cup to another cup
                    for (int j = 0; j < size; j++) {
                        if (j == i) {
                            continue;
                        }
                        if (cupsnow[j] < cupsize[j]) {
                            if (cupsize[j] - cupsnow[j] >= cupsnow[i]) {
                                int temp1 = cupsnow[j];
                                int temp2 = cupsnow[i];
                                cupsnow[j] += cupsnow[i];
                                cupsnow[i] = 0;

                                if (states.find(cupsnow) == states.end()) {//not found, new state
                                    if(cupsnow == target) {
                                        return steps;
                                    }
                                    states.insert(cupsnow);
                                    nextstate.push_back(cupsnow);
                                }

                                cupsnow[j] = temp1;
                                cupsnow[i] = temp2;

                            } else {//cupsize[j] - cupsnow[j] < cupsnow[i]
                                int temp1 = cupsnow[j];
                                int temp2 = cupsnow[i];
                                cupsnow[i] -= (cupsize[j] - cupsnow[j]);
                                cupsnow[j] = cupsize[j];

                                if (states.find(cupsnow) == states.end()) {//not found, new state
                                    if(cupsnow == target) {
                                        return steps;
                                    }
                                    states.insert(cupsnow);
                                    nextstate.push_back(cupsnow);
                                }

                                cupsnow[j] = temp1;
                                cupsnow[i] = temp2;
                            }
                        }
                    }

                }
            }
        }
        if(nextstate.size() < 1) {
            return -1;
        }
        return helper(cupsize, nextstate, target, states, steps + 1);
    }
};

void testmapapi(void) {
    map<vector<int>, int> states;
    int s[4];
    vector<int> cups1;
    vector<int> cups2;
    for(int i = 0;i < 4;i++) {
        cups1.push_back(s[i]);
        cups2.push_back(s[i]);
    }
    cout << "There are " << states.size() << " states" << ", count = " << states.count(cups1) << endl;
    states[cups1] = 1;
    cout << "There are " << states.size() << " states" << ", count = " << states.count(cups1) << endl;
    // states[cups2] = 2;
    if(states.find(cups2) != states.end()) {
        if(cups1 == cups2) {
            cout << "equal" << endl;
        }
        cout << "cups2 " << "found" << ", value = " << states[cups2] << endl;
    }
    cout << "There are " << states.size() << " states" << ", count = " << states.count(cups2) << endl;
    return;
}


int main(int argc, char* argv[]) {
    int a[] = {0, 2, 3, 4, 5};
    int b[] = {0, 1 ,2, 4, 1};
    vector<int> cupsize(a, a + sizeof(a) / sizeof(int));
    vector<int> target(b, b + sizeof(b) / sizeof(int));
    cout << "cupsize:";
    for(auto it = cupsize.begin();it != cupsize.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "target:";
    for(auto it = target.begin();it != target.end();it++) {
        cout << *it << " ";
    }
    cout << endl;

    Solution sol;
    cout << "the answer to target is " << sol.findtheway(cupsize, target) << endl;
    return 0;
}
