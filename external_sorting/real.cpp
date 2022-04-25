#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > pp;

vector<int> mergeArrays(vector<vector<int> > a){
    vector<int> o;
    priority_queue<pp, vector<pp>, greater<pp> > pq;
    for (int i = 0; i < a.size(); i++){
        pq.push({ a[i][0], { i, 0 } });
    }
    while (pq.empty() == false) {
        pp current = pq.top();
        pq.pop();
        int i = current.second.first;
        int j = current.second.second;
        o.push_back(current.first);
        if (j + 1 < a[i].size()){
            pq.push({ a[i][j + 1], { i, j + 1 } });
        }
    }
    return o;
}

int main(){
    int buffer_pages, record_page, total_record;
    cin >> buffer_pages >> record_page >> total_record;

    int page = int(ceil(double(total_record) / double(record_page)));
    int run_size = buffer_pages * record_page;
    int runs = int(ceil(double(page)/double(buffer_pages)));
    int record_lastrun = total_record - run_size*int(floor(double(total_record)/double(run_size)));

    int temp = runs;
    int pass = 0;
    vector<vector<int>> v;

    while(temp > 0){
        vector <int> vi;
        int y;
        if(temp==1){
            for(int i=0;i<record_lastrun;i++){
                cin>>y;
                vi.push_back(y);
            }
        }
        else{
            for(int i=0;i<run_size;i++){
                cin>>y;
                vi.push_back(y);
            }
        }
        temp--;
        sort(vi.begin(),vi.end());
        v.push_back(vi);
    }

    while(runs > 1){
        int g = int(ceil(double(runs) / double(buffer_pages-1)));
        pass++;
        int h =0;
        int f = int(ceil(double(runs) / double(buffer_pages)));
        vector <vector <int>> out;
        for(int i=0;i<g;i++){
            vector <vector <int>> temp1;
            if(h<buffer_pages-1){
                for(int x=0;x<buffer_pages-1 && h<v.size();h++,x++){
                    temp1.push_back(v[h]);
                }
            }
            else{
                for(int x=0;x<f && h<v.size();h++,x++){
                    temp1.push_back(v[h]);
                }
            }
            vector<int> output = mergeArrays(temp1);
            out.push_back(output);
        }
        runs = int(ceil(double(runs) / double(buffer_pages-1)));
        v.clear();
        for(int i=0;i<out.size();i++){
            v.push_back(out[i]);
        }
    }

    for(int i=0;i<v[0].size();i++){
        cout<<v[0][i]<<" ";
    }
}
