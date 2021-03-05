#include <bits/stdc++.h>

using namespace std;

void sort(long* list, int n) {
    bool control = true;
    while (control) {
        control = false;
        for (int i = 0; i < n-1; i++) {
            if (list[i] > list[i+1]) {
                long temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                control = true;
            }
        }
    }
}

bool isEqual(long list1[], long list2[], int n) {
    sort(list1, n);
    sort(list2, n);
    
    for (int i = 0; i < n; i++) {
        if (list1[i] != list2[i]) return false;
    }
    return true;
}

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {

    int n = container.size();
    
    long container_size[n];       
    long ball_types[n];
    
    for (int i = 0; i < n; i++) {
        container_size[i] = 0;
        ball_types[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            container_size[i] += container[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ball_types[i] += container[j][i];
        }
    }
    
    return (isEqual(container_size, ball_types, n)) ? "Possible" : "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}