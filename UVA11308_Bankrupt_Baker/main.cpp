#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.156s
Description: data structures - maps, sorting
*/

using namespace std;

#define read cin

typedef struct {
    string recipeName;
    int cost;
} Recipe;

bool compare(Recipe ra, Recipe rb) {
    if (ra.cost < rb.cost) return true;
    else if (ra.cost > rb.cost) return false;
    return ra.recipeName < rb.recipeName;
}

int main() {
    int nbinders, mi, n, b, cost, nIngredients, quantity;
    string line, binderName, ingredient;
    map<string, int> m;
    vector<Recipe> v;
    read >> nbinders; getline(read, line);
    while (nbinders--) {
        m.clear(); v.clear();
        getline(read, binderName);
        transform(binderName.begin(), binderName.end(), binderName.begin(), ::toupper);
        getline(read, line);
        stringstream ss(line);
        ss >> mi >> n >> b;
        for (int i = 0; i < mi; i++) {
            getline(read, line);
            stringstream ss2(line);
            ss2 >> ingredient >> cost;
            m[ingredient] = cost;
        }
        for (int i = 0; i < n; i++) {
            Recipe r;
            int tempCost = 0;
            getline(read, r.recipeName);
            read >> nIngredients; getline(read, line);
            for (int j = 0; j < nIngredients; j++) {
                read >> line >> quantity;
                if (tempCost <= b) { /* Prevent overflow */
                    tempCost += quantity*m[line];
                }
                getline(read, line);
            }
            if (tempCost <= b) {
                r.cost = tempCost;
                v.push_back(r);
            }
        }
        cout << binderName << endl;
        if (v.size() == 0)
            cout << "Too expensive!" << endl;
        else {
            sort(v.begin(), v.end(), compare);
            for (vector<Recipe>::iterator it = v.begin(); it != v.end(); it++)
                cout << (*it).recipeName << endl;
        }
        cout << endl;
    }
    return 0;
}
