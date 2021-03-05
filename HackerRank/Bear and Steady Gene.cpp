#include <bits/stdc++.h>

using namespace std;

// Complete the steadyGene function below.
int steadyGene(string gene) {
    int count[4] = {0}; // G-C-T-A
    int limit = gene.length() / 4;
    int len = gene.length();
    for (int i = 0; i < len; i++) {
        if (gene[i] == 'G') count[0]++;
        else if (gene[i] == 'C') count[1]++;
        else if (gene[i] == 'T') count[2]++;
        else if (gene[i] == 'A') count[3]++;
    }
    count[0] = (count[0] > limit) ? count[0] - limit : 0;
    count[1] = (count[1] > limit) ? count[1] - limit : 0;
    count[2] = (count[2] > limit) ? count[2] - limit : 0;
    count[3] = (count[3] > limit) ? count[3] - limit : 0;
    
    int count2[4] = {0};
    int left = 0, right = 0;
    bool change = false;
    if (gene[0] == 'G') count2[0]++; 
    if (gene[0] == 'C') count2[1]++; 
    if (gene[0] == 'T') count2[2]++; 
    if (gene[0] == 'A') count2[3]++;
    int min = 500001;
    while (left != len && right != len) {
        if (!change) {
            if (gene[++right] == 'G') count2[0]++;
            else if (gene[right] == 'C') count2[1]++;
            else if (gene[right] == 'T') count2[2]++;
            else if (gene[right] == 'A') count2[3]++;
            bool control = true;
            for (int i = 0; i < 4; i++) {
                if (count[i] > count2[i]) {
                    control = false;
                }
            }
            if (control) {
                change = true;
                if (right - left + 1 < min) min = right - left + 1;
            }
        }
        else if (change) {
            if (gene[left] == 'G') count2[0]--;
            else if (gene[left] == 'C') count2[1]--;
            else if (gene[left] == 'T') count2[2]--;
            else if (gene[left] == 'A') count2[3]--;
            left++;
            bool control = true;
            for (int i = 0; i < 4; i++) {
                if (count[i] > count2[i]) {
                    control = false;
                }
            }
            if (!control) change = false;
            else {
                if (right - left + 1 < min) min = right - left + 1;
            }
        }
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}