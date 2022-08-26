#include<bits/stdc++.h>
#include<vector>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop{
    int start_time, duration, end_time;
};

struct Available_Workshops{
    int n;  // Number of workshops the student signed up for
    vector<Workshop> arr;
};

bool compare(Workshop w1, Workshop w2){
    return w1.end_time < w2.end_time;
}

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops *out = new Available_Workshops();
    out->n = n;
    for(int i = 0; i < n; i++){
        Workshop w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        out->arr.push_back(w);
    }
    sort(out->arr.begin(), out->arr.end(), compare);
    return out;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int count = 0;
    int current_time = 0;
    for(int i = 0; i < ptr->n; i++){
        if(ptr->arr[i].start_time >= current_time){
            count++;
            current_time = ptr->arr[i].end_time;
        }
    }
    return count;
}


// Locked code
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
